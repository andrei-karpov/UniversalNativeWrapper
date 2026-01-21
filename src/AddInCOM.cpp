// AddInCOM.cpp : Implementation of CAddInCOM

#include "stdafx.h"
#include "AddInCOM.h"
#define IMsgBox IMsgBoxNative
#define IPlatformInfo IPlatformInfoNative
#define IAttachedInfo IAttachedInfoNative
#include "AddInDefBase.h"
#undef IMsgBox
#undef IPlatformInfo
#undef IAttachedInfo
#include <vector>
#include <wchar.h>
#include <stdarg.h>

namespace
{
    const wchar_t* kExtName = L"UniversalNativeWrapper";
    const wchar_t* kMethodSetDriverNameEn = L"setDriverName";
    const wchar_t* kMethodSetDriverNameRu = L"УстановитьДрайвер";
    const wchar_t* kErrorSource = L"UniversalNativeWrapper";

    void WriteLogLine(const wchar_t* message);
    void WriteLogFormat(const wchar_t* fmt, ...);

    const wchar_t* VariantTypeToString(VARTYPE vt)
    {
        VARTYPE base = (vt & ~VT_BYREF);
        switch (base)
        {
        case VT_EMPTY: return L"VT_EMPTY";
        case VT_NULL: return L"VT_NULL";
        case VT_I2: return L"VT_I2";
        case VT_I4: return L"VT_I4";
        case VT_R4: return L"VT_R4";
        case VT_R8: return L"VT_R8";
        case VT_CY: return L"VT_CY";
        case VT_DATE: return L"VT_DATE";
        case VT_BSTR: return L"VT_BSTR";
        case VT_DISPATCH: return L"VT_DISPATCH";
        case VT_ERROR: return L"VT_ERROR";
        case VT_BOOL: return L"VT_BOOL";
        case VT_VARIANT: return L"VT_VARIANT";
        case VT_UNKNOWN: return L"VT_UNKNOWN";
        case VT_DECIMAL: return L"VT_DECIMAL";
        case VT_I1: return L"VT_I1";
        case VT_UI1: return L"VT_UI1";
        case VT_UI2: return L"VT_UI2";
        case VT_UI4: return L"VT_UI4";
        case VT_I8: return L"VT_I8";
        case VT_UI8: return L"VT_UI8";
        case VT_INT: return L"VT_INT";
        case VT_UINT: return L"VT_UINT";
        case VT_ARRAY: return L"VT_ARRAY";
        default: return L"VT_UNKNOWN";
        }
    }

#ifdef NONAMELESSUNION
#define UNW_TV_STR_LEN(X) ((X)->u.str.strLen)
#define UNW_TV_WSTR_LEN(X) ((X)->u.wstr.wstrLen)
#else
#define UNW_TV_STR_LEN(X) ((X)->strLen)
#define UNW_TV_WSTR_LEN(X) ((X)->wstrLen)
#endif

    const wchar_t* TVariantTypeToString(TYPEVAR vt)
    {
        TYPEVAR base = vt & VTYPE_TYPEMASK;
        switch (base)
        {
        case VTYPE_EMPTY: return L"VTYPE_EMPTY";
        case VTYPE_NULL: return L"VTYPE_NULL";
        case VTYPE_I2: return L"VTYPE_I2";
        case VTYPE_I4: return L"VTYPE_I4";
        case VTYPE_R4: return L"VTYPE_R4";
        case VTYPE_R8: return L"VTYPE_R8";
        case VTYPE_DATE: return L"VTYPE_DATE";
        case VTYPE_PSTR: return L"VTYPE_PSTR";
        case VTYPE_INTERFACE: return L"VTYPE_INTERFACE";
        case VTYPE_ERROR: return L"VTYPE_ERROR";
        case VTYPE_BOOL: return L"VTYPE_BOOL";
        case VTYPE_VARIANT: return L"VTYPE_VARIANT";
        case VTYPE_I1: return L"VTYPE_I1";
        case VTYPE_UI1: return L"VTYPE_UI1";
        case VTYPE_UI2: return L"VTYPE_UI2";
        case VTYPE_UI4: return L"VTYPE_UI4";
        case VTYPE_I8: return L"VTYPE_I8";
        case VTYPE_UI8: return L"VTYPE_UI8";
        case VTYPE_INT: return L"VTYPE_INT";
        case VTYPE_UINT: return L"VTYPE_UINT";
        case VTYPE_HRESULT: return L"VTYPE_HRESULT";
        case VTYPE_PWSTR: return L"VTYPE_PWSTR";
        case VTYPE_BLOB: return L"VTYPE_BLOB";
        case VTYPE_CLSID: return L"VTYPE_CLSID";
        default: return L"VTYPE_UNKNOWN";
        }
    }

    void LogTVariantSummary(const tVariant& value, const wchar_t* prefix)
    {
        TYPEVAR vt = TV_VT(&value);
        const wchar_t* name = TVariantTypeToString(vt);
        const wchar_t* byRef = (vt & VTYPE_BYREF) ? L" byref" : L"";
        WriteLogFormat(L"%s: vt=0x%04X (%s%s)", prefix, (unsigned)vt, name, byRef);

        TYPEVAR base = vt & VTYPE_TYPEMASK;
        switch (base)
        {
        case VTYPE_I4:
            WriteLogFormat(L"%s: I4=%ld", prefix, (long)TV_I4(&value));
            break;
        case VTYPE_I2:
            WriteLogFormat(L"%s: I2=%d", prefix, (int)TV_I2(&value));
            break;
        case VTYPE_I8:
            WriteLogFormat(L"%s: I8=%lld", prefix, (long long)TV_I8(&value));
            break;
        case VTYPE_UI4:
            WriteLogFormat(L"%s: UI4=%lu", prefix, (unsigned long)TV_UI4(&value));
            break;
        case VTYPE_UI8:
            WriteLogFormat(L"%s: UI8=%llu", prefix, (unsigned long long)TV_UI8(&value));
            break;
        case VTYPE_BOOL:
            WriteLogFormat(L"%s: BOOL=%d", prefix, TV_BOOL(&value) ? 1 : 0);
            break;
        case VTYPE_PWSTR:
            WriteLogFormat(L"%s: PWSTR len=%u", prefix, (unsigned)UNW_TV_WSTR_LEN(&value));
            break;
        case VTYPE_PSTR:
        case VTYPE_BLOB:
            WriteLogFormat(L"%s: STR len=%u", prefix, (unsigned)UNW_TV_STR_LEN(&value));
            break;
        default:
            break;
        }
    }

    extern "C" IMAGE_DOS_HEADER __ImageBase;

    bool GetModuleDir(CAtlStringW& outDir)
    {
        wchar_t path[MAX_PATH] = {0};
        DWORD len = ::GetModuleFileNameW((HMODULE)&__ImageBase, path, MAX_PATH);
        if (len == 0 || len >= MAX_PATH)
            return false;

        for (int i = (int)len - 1; i >= 0; --i)
        {
            if (path[i] == L'\\' || path[i] == L'/')
            {
                path[i] = 0;
                break;
            }
        }

        outDir = path;
        return !outDir.IsEmpty();
    }

    bool TrimLastPathSegment(CAtlStringW& path)
    {
        int pos = path.ReverseFind(L'\\');
        if (pos < 0)
            pos = path.ReverseFind(L'/');
        if (pos < 0)
            return false;
        path = path.Left(pos);
        return !path.IsEmpty();
    }

    bool FileExists(const CAtlStringW& path)
    {
        DWORD attrs = ::GetFileAttributesW(path.GetString());
        return (attrs != INVALID_FILE_ATTRIBUTES &&
                (attrs & FILE_ATTRIBUTE_DIRECTORY) == 0);
    }

    bool FindRepoRoot(CAtlStringW& outDir)
    {
        CAtlStringW current;
        if (!GetModuleDir(current))
            return false;

        for (int i = 0; i < 5; ++i)
        {
            CAtlStringW cmake = current + L"\\CMakeLists.txt";
            CAtlStringW rules = current + L"\\.cursorrules";
            if (FileExists(cmake) || FileExists(rules))
            {
                outDir = current;
                return true;
            }
            if (!TrimLastPathSegment(current))
                break;
        }
        return false;
    }

    void WriteLogLine(const wchar_t* message)
    {
#ifndef UNW_ENABLE_LOG
        // Логирование включается только при заданном флаге компиляции.
        (void)message;
        return;
#endif
        CAtlStringW repoDir;
        if (!FindRepoRoot(repoDir))
        {
            if (!GetModuleDir(repoDir))
                return;
        }

        CAtlStringW tempDir = repoDir + L"\\temp";
        ::CreateDirectoryW(tempDir.GetString(), NULL);

        CAtlStringW logPath = tempDir + L"\\UniversalNativeWrapper.log";
        if (logPath.GetLength() >= MAX_PATH)
            return;

        HANDLE hFile = ::CreateFileW(logPath.GetString(), FILE_APPEND_DATA,
                                     FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                                     OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            return;

        DWORD size = ::GetFileSize(hFile, NULL);
        if (size == 0 || size == INVALID_FILE_SIZE)
        {
            WORD bom = 0xFEFF;
            DWORD written = 0;
            ::WriteFile(hFile, &bom, sizeof(bom), &written, NULL);
        }

        SYSTEMTIME st;
        ::GetLocalTime(&st);

        wchar_t line[1024] = {0};
        _snwprintf_s(line, _countof(line), _TRUNCATE,
                     L"[%04u-%02u-%02u %02u:%02u:%02u.%03u] %s\r\n",
                     st.wYear, st.wMonth, st.wDay,
                     st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
                     message ? message : L"(null)");

        DWORD written = 0;
        ::WriteFile(hFile, line, (DWORD)(wcslen(line) * sizeof(wchar_t)), &written, NULL);
        ::CloseHandle(hFile);
    }

    void WriteLogFormat(const wchar_t* fmt, ...)
    {
#ifndef UNW_ENABLE_LOG
        // Логирование включается только при заданном флаге компиляции.
        (void)fmt;
        return;
#endif
        if (!fmt)
            return;
        wchar_t buffer[1024] = {0};
        va_list args;
        va_start(args, fmt);
        _vsnwprintf_s(buffer, _countof(buffer), _TRUNCATE, fmt, args);
        va_end(args);
        WriteLogLine(buffer);
    }
}

class CAddInDefBaseProxy : public IAddInDefBaseEx
{
public:
    explicit CAddInDefBaseProxy(CAddInCOM* owner)
        : m_owner(owner),
          m_errorLog(NULL),
          m_profile(NULL),
          m_statusLine(NULL),
          m_asyncEvent(NULL),
          m_msgBox(NULL),
          m_platformInfo(NULL),
          m_attachedInfo(NULL)
    {
    }

    void SetInterfaces(IErrorLog* errorLog,
                       IPropertyProfile* profile,
                       IStatusLine* statusLine,
                       IAsyncEvent* asyncEvent,
                       IMsgBox* msgBox,
                       IPlatformInfo* platformInfo,
                       IAttachedInfo* attachedInfo)
    {
        m_errorLog = errorLog;
        m_profile = profile;
        m_statusLine = statusLine;
        m_asyncEvent = asyncEvent;
        m_msgBox = msgBox;
        m_platformInfo = platformInfo;
        m_attachedInfo = attachedInfo;
        m_msgBoxProxy.SetOwner(m_owner, m_msgBox);
        m_platformInfoProxy.SetOwner(m_owner, m_platformInfo);
        m_attachedInfoProxy.SetOwner(m_attachedInfo);
    }

    virtual bool ADDIN_API AddError(unsigned short wcode, const WCHAR_T* source,
                                    const WCHAR_T* descr, long scode)
    {
        if (!m_errorLog || !m_owner)
            return false;

        BSTR bstrSource = m_owner->ConvertWcharTToBstr(source, 0);
        BSTR bstrDescr = m_owner->ConvertWcharTToBstr(descr, 0);
        EXCEPINFO ei;
        memset(&ei, 0, sizeof(ei));
        ei.wCode = wcode;
        ei.scode = scode;
        ei.bstrSource = bstrSource ? bstrSource : ::SysAllocString(kErrorSource);
        ei.bstrDescription = bstrDescr ? bstrDescr : ::SysAllocString(L"");
        BSTR bstrEmpty = ::SysAllocString(L"");
        m_errorLog->AddError(bstrEmpty, &ei);
        ::SysFreeString(bstrEmpty);
        if (ei.bstrSource)
            ::SysFreeString(ei.bstrSource);
        if (ei.bstrDescription)
            ::SysFreeString(ei.bstrDescription);
        return true;
    }

    virtual bool ADDIN_API Read(WCHAR_T* wszPropName, tVariant* pVal,
                                long *pErrCode, WCHAR_T** errDescriptor)
    {
        if (!m_profile || !m_owner || !pVal)
            return false;

        VARIANT v;
        ::VariantInit(&v);
        BSTR bstrName = m_owner->ConvertWcharTToBstr(wszPropName, 0);
        HRESULT hr = m_profile->Read(bstrName, &v, NULL);
        ::SysFreeString(bstrName);

        if (FAILED(hr))
        {
            if (pErrCode)
                *pErrCode = hr;
            if (errDescriptor)
                *errDescriptor = 0;
            ::VariantClear(&v);
            return false;
        }

        bool byRef = false;
        bool ok = m_owner->VariantToTVariant(v, pVal, byRef);
        ::VariantClear(&v);
        return ok;
    }

    virtual bool ADDIN_API Write(WCHAR_T* wszPropName, tVariant *pVar)
    {
        if (!m_profile || !m_owner || !pVar)
            return false;

        VARIANT v;
        ::VariantInit(&v);
        if (!m_owner->TVariantToVariant(*pVar, &v))
            return false;

        BSTR bstrName = m_owner->ConvertWcharTToBstr(wszPropName, 0);
        HRESULT hr = m_profile->Write(bstrName, &v);
        ::SysFreeString(bstrName);
        ::VariantClear(&v);
        return SUCCEEDED(hr);
    }

    virtual bool ADDIN_API RegisterProfileAs(WCHAR_T* wszProfileName)
    {
        if (!m_profile || !m_owner)
            return false;

        BSTR bstrName = m_owner->ConvertWcharTToBstr(wszProfileName, 0);
        HRESULT hr = m_profile->RegisterProfileAs(bstrName);
        ::SysFreeString(bstrName);
        return SUCCEEDED(hr);
    }

    virtual bool ADDIN_API SetEventBufferDepth(long lDepth)
    {
        if (!m_asyncEvent)
            return false;
        return SUCCEEDED(m_asyncEvent->SetEventBufferDepth(lDepth));
    }

    virtual long ADDIN_API GetEventBufferDepth()
    {
        if (!m_asyncEvent)
            return 0;
        long depth = 0;
        m_asyncEvent->GetEventBufferDepth(&depth);
        return depth;
    }

    virtual bool ADDIN_API ExternalEvent(WCHAR_T* wszSource,
                                         WCHAR_T* wszMessage,
                                         WCHAR_T* wszData)
    {
        if (!m_asyncEvent || !m_owner)
            return false;

        BSTR bstrSource = m_owner->ConvertWcharTToBstr(wszSource, 0);
        BSTR bstrMessage = m_owner->ConvertWcharTToBstr(wszMessage, 0);
        BSTR bstrData = m_owner->ConvertWcharTToBstr(wszData, 0);
        HRESULT hr = m_asyncEvent->ExternalEvent(bstrSource, bstrMessage, bstrData);
        ::SysFreeString(bstrSource);
        ::SysFreeString(bstrMessage);
        ::SysFreeString(bstrData);
        return SUCCEEDED(hr);
    }

    virtual void ADDIN_API CleanEventBuffer()
    {
        if (m_asyncEvent)
            m_asyncEvent->CleanBuffer();
    }

    virtual bool ADDIN_API SetStatusLine(WCHAR_T* wszStatusLine)
    {
        if (!m_statusLine || !m_owner)
            return false;
        BSTR bstrStatus = m_owner->ConvertWcharTToBstr(wszStatusLine, 0);
        HRESULT hr = m_statusLine->SetStatusLine(bstrStatus);
        ::SysFreeString(bstrStatus);
        return SUCCEEDED(hr);
    }

    virtual void ADDIN_API ResetStatusLine()
    {
        if (m_statusLine)
            m_statusLine->ResetStatusLine();
    }

    virtual IInterface* ADDIN_API GetInterface(Interfaces iface)
    {
        switch (iface)
        {
        case eIMsgBox:
            return m_msgBox ? &m_msgBoxProxy : 0;
        case eIPlatformInfo:
            return m_platformInfo ? &m_platformInfoProxy : 0;
        case eIAttachedInfo:
            return m_attachedInfo ? &m_attachedInfoProxy : 0;
        default:
            return 0;
        }
    }

private:
    class CMsgBoxProxy : public IMsgBoxNative
    {
    public:
        CMsgBoxProxy()
            : m_owner(0), m_msgBox(0)
        {
        }

        void SetOwner(CAddInCOM* owner, IMsgBox* msgBox)
        {
            m_owner = owner;
            m_msgBox = msgBox;
        }

        virtual bool ADDIN_API Confirm(const WCHAR_T* queryText, tVariant* retVal)
        {
            if (!m_owner || !m_msgBox || !retVal)
                return false;

            BSTR bstr = m_owner->ConvertWcharTToBstr(queryText, 0);
            VARIANT v;
            ::VariantInit(&v);
            HRESULT hr = m_msgBox->Confirm(bstr, &v);
            ::SysFreeString(bstr);
            if (FAILED(hr))
            {
                ::VariantClear(&v);
                return false;
            }

            bool byRef = false;
            bool ok = m_owner->VariantToTVariant(v, retVal, byRef);
            ::VariantClear(&v);
            return ok;
        }

        virtual bool ADDIN_API Alert(const WCHAR_T* text)
        {
            if (!m_owner || !m_msgBox)
                return false;
            BSTR bstr = m_owner->ConvertWcharTToBstr(text, 0);
            HRESULT hr = m_msgBox->Alert(bstr);
            ::SysFreeString(bstr);
            return SUCCEEDED(hr);
        }

    private:
        CAddInCOM* m_owner;
        IMsgBox* m_msgBox;
    };

    class CPlatformInfoProxy : public IPlatformInfoNative
    {
    public:
        CPlatformInfoProxy()
            : m_owner(0), m_platformInfo(0),
              m_appVersion(0), m_userAgent(0),
              m_appVersionLen(0), m_userAgentLen(0)
        {
            memset(&m_info, 0, sizeof(m_info));
        }
        ~CPlatformInfoProxy()
        {
            ResetStrings();
        }

        void SetOwner(CAddInCOM* owner, IPlatformInfo* platformInfo)
        {
            m_owner = owner;
            m_platformInfo = platformInfo;
        }

        virtual const IPlatformInfoNative::AppInfo* ADDIN_API GetPlatformInfo()
        {
            if (!m_owner || !m_platformInfo)
                return 0;

            ::AppInfo* info = 0;
            HRESULT hr = m_platformInfo->GetPlatformInfo(&info);
            if (FAILED(hr) || !info)
                return 0;

            ResetStrings();
            if (!m_owner->ConvertBstrToWcharT(info->AppVersion, &m_appVersion, &m_appVersionLen))
                m_appVersion = 0;
            if (!m_owner->ConvertBstrToWcharT(info->UserAgentInformation, &m_userAgent, &m_userAgentLen))
                m_userAgent = 0;
            m_info.AppVersion = m_appVersion;
            m_info.UserAgentInformation = m_userAgent;
            m_info.Application = (IPlatformInfoNative::AppType)info->Application;
            return &m_info;
        }

    private:
        void ResetStrings()
        {
            if (m_owner)
            {
                if (m_appVersion)
                    m_owner->FreeShortStr(&m_appVersion);
                if (m_userAgent)
                    m_owner->FreeShortStr(&m_userAgent);
            }
            m_appVersion = 0;
            m_userAgent = 0;
            m_appVersionLen = 0;
            m_userAgentLen = 0;
        }

    private:
        CAddInCOM* m_owner;
        IPlatformInfo* m_platformInfo;
        IPlatformInfoNative::AppInfo m_info;
        WCHAR_T* m_appVersion;
        WCHAR_T* m_userAgent;
        uint32_t m_appVersionLen;
        uint32_t m_userAgentLen;
    };

    class CAttachedInfoProxy : public IAttachedInfoNative
    {
    public:
        CAttachedInfoProxy()
            : m_attachedInfo(0)
        {
        }

        void SetOwner(IAttachedInfo* attachedInfo)
        {
            m_attachedInfo = attachedInfo;
        }

        virtual const IAttachedInfoNative::AttachedType ADDIN_API GetAttachedInfo()
        {
            if (!m_attachedInfo)
                return IAttachedInfoNative::eAttachedNotIsolated;
            ::AttachedType type = ::eAttachedNotIsolated;
            m_attachedInfo->GetAttachedInfo(&type);
            return (IAttachedInfoNative::AttachedType)type;
        }

    private:
        IAttachedInfo* m_attachedInfo;
    };

private:
    CAddInCOM* m_owner;
    IErrorLog* m_errorLog;
    IPropertyProfile* m_profile;
    IStatusLine* m_statusLine;
    IAsyncEvent* m_asyncEvent;
    IMsgBox* m_msgBox;
    IPlatformInfo* m_platformInfo;
    IAttachedInfo* m_attachedInfo;

    CMsgBoxProxy m_msgBoxProxy;
    CPlatformInfoProxy m_platformInfoProxy;
    CAttachedInfoProxy m_attachedInfoProxy;
};

// CAddInCOM
//---------------------------------------------------------------------------//
CAddInCOM::CAddInCOM()
    : m_iConnect(NULL),
      m_iErrorLog(NULL),
      m_iProfile(NULL),
      m_iStatusLine(NULL),
      m_iAsyncEvent(NULL),
      m_iMsgBox(NULL),
      m_iPlatformInfo(NULL),
      m_iAttachedInfo(NULL),
      m_hModule(NULL),
      m_getClassObject(NULL),
      m_destroyObject(NULL),
      m_getClassNames(NULL),
      m_setPlatformCapabilities(NULL),
      m_getAttachType(NULL),
      m_native(NULL),
      m_addinProxy(NULL)
{
    m_addinProxy = new CAddInDefBaseProxy(this);
    WriteLogLine(L"CAddInCOM создан.");
}

void CAddInCOM::FinalRelease()
{
    UnloadNative();
    if (m_addinProxy)
    {
        delete m_addinProxy;
        m_addinProxy = NULL;
    }
}

//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::Init(IDispatch *pConnection)
{
    if (!pConnection)
        return E_INVALIDARG;

    m_iConnect = pConnection;
    m_iConnect->AddRef();

    m_iConnect->QueryInterface(IID_IErrorLog,(void **)&m_iErrorLog);
    m_iConnect->QueryInterface(IID_IAsyncEvent,(void **)&m_iAsyncEvent);
    m_iConnect->QueryInterface(IID_IStatusLine,(void **)&m_iStatusLine);
    m_iConnect->QueryInterface(IID_IPropertyProfile,(void **)&m_iProfile);

    m_iConnect->QueryInterface(IID_IMsgBox, (void**)&m_iMsgBox);
    m_iConnect->QueryInterface(IID_IPlatformInfo, (void**)&m_iPlatformInfo);
    m_iConnect->QueryInterface(IID_IAttachedInfo, (void**)&m_iAttachedInfo);

    if (m_addinProxy)
    {
        m_addinProxy->SetInterfaces(m_iErrorLog, m_iProfile, m_iStatusLine,
                                    m_iAsyncEvent, m_iMsgBox, m_iPlatformInfo, m_iAttachedInfo);
    }

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::Done()
{
    UnloadNative();

    if (m_iStatusLine)
        m_iStatusLine->Release();

    if (m_iProfile)
        m_iProfile->Release();

    if (m_iAsyncEvent)
        m_iAsyncEvent->Release();

    if (m_iErrorLog)
        m_iErrorLog->Release();

    if (m_iMsgBox)
        m_iMsgBox->Release();

    if (m_iPlatformInfo)
        m_iPlatformInfo->Release();

    if (m_iAttachedInfo)
        m_iAttachedInfo->Release();

    if (m_iConnect)
        m_iConnect->Release();

    m_iConnect = NULL;
    m_iErrorLog = NULL;
    m_iProfile = NULL;
    m_iStatusLine = NULL;
    m_iAsyncEvent = NULL;
    m_iMsgBox = NULL;
    m_iPlatformInfo = NULL;
    m_iAttachedInfo = NULL;

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetInfo(SAFEARRAY **pInfo)
{
    if (!pInfo || !*pInfo)
        return E_INVALIDARG;

    long lInd = 0;
    VARIANT varVersion;
    ::VariantInit(&varVersion);
    V_VT(&varVersion) = VT_I4;
    V_I4(&varVersion) = 2000;
    SafeArrayPutElement(*pInfo,&lInd,&varVersion);

    return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
// IDispatch
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetTypeInfoCount(UINT* pctinfo)
{
    if (!pctinfo)
        return E_INVALIDARG;
    *pctinfo = 0;
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
{
    UNREFERENCED_PARAMETER(iTInfo);
    UNREFERENCED_PARAMETER(lcid);
    if (ppTInfo)
        *ppTInfo = 0;
    return E_NOTIMPL;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                                      LCID lcid, DISPID* rgDispId)
{
    UNREFERENCED_PARAMETER(riid);
    UNREFERENCED_PARAMETER(lcid);
    if (!rgszNames || !rgDispId || cNames == 0)
        return E_INVALIDARG;

    long methodNum = -1;
    HRESULT hr = FindMethod(rgszNames[0], &methodNum);
    if (hr != S_OK || methodNum < 0)
        return DISP_E_UNKNOWNNAME;

    rgDispId[0] = (DISPID)methodNum;
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
                               DISPPARAMS* pDispParams, VARIANT* pVarResult,
                               EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
    UNREFERENCED_PARAMETER(riid);
    UNREFERENCED_PARAMETER(lcid);
    UNREFERENCED_PARAMETER(pExcepInfo);
    UNREFERENCED_PARAMETER(puArgErr);

    if (!pDispParams)
        return E_INVALIDARG;

    long methodNum = (long)dispIdMember;
    UINT argCount = pDispParams->cArgs;
    WriteLogFormat(L"Invoke: dispId=%ld flags=0x%X args=%u", methodNum, (unsigned)wFlags, argCount);

    if (methodNum == eMethSetDriverName)
    {
        if (argCount < 2)
        {
            AddError(ADDIN_E_FAIL, kErrorSource, L"Недостаточно параметров setDriverName.");
            return E_INVALIDARG;
        }

        CAtlStringW path;
        CAtlStringW className;
        if (!GetVariantString(pDispParams->rgvarg[1], path) ||
            !GetVariantString(pDispParams->rgvarg[0], className))
        {
            AddError(ADDIN_E_FAIL, kErrorSource, L"Неверные параметры setDriverName.");
            return E_INVALIDARG;
        }

        WriteLogFormat(L"setDriverName(Invoke): path='%s' class='%s'",
                       path.GetString(), className.GetString());
        HRESULT hr = LoadNative(path, className);
        if (pVarResult)
        {
            ::VariantInit(pVarResult);
            V_VT(pVarResult) = VT_BOOL;
            V_BOOL(pVarResult) = (hr == S_OK) ? VARIANT_TRUE : VARIANT_FALSE;
        }
        return hr;
    }

    SAFEARRAY* params = 0;
    if (argCount > 0)
    {
        params = SafeArrayCreateVector(VT_VARIANT, 0, argCount);
        if (!params)
            return E_OUTOFMEMORY;

        VARIANT* data = 0;
        if (FAILED(SafeArrayAccessData(params, (void**)&data)))
        {
            SafeArrayDestroy(params);
            return E_FAIL;
        }
        for (UINT i = 0; i < argCount; ++i)
        {
            ::VariantInit(&data[i]);
            ::VariantCopy(&data[i], &pDispParams->rgvarg[argCount - 1 - i]);
        }
        SafeArrayUnaccessData(params);
    }

    HRESULT hr = S_OK;
    SAFEARRAY* paramsPtr = params;
    if ((wFlags & DISPATCH_METHOD) || (wFlags & DISPATCH_PROPERTYGET))
    {
        if (pVarResult)
            hr = CallAsFunc(methodNum, pVarResult, &paramsPtr);
        else
            hr = CallAsProc(methodNum, &paramsPtr);
    }
    else
    {
        hr = DISP_E_MEMBERNOTFOUND;
    }

    if (params)
        SafeArrayDestroy(params);

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
// ILanguageExtender
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::RegisterExtensionAs(BSTR *bstrExtensionName)
{
    if (!bstrExtensionName)
        return E_INVALIDARG;

    *bstrExtensionName = ::SysAllocString(kExtName);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNProps(long *plProps)
{
    if (!plProps)
        return E_INVALIDARG;

    *plProps = 0;
    if (m_native)
        *plProps = m_native->GetNProps();

    WriteLogFormat(L"GetNProps: count=%ld", *plProps);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::FindProp(BSTR bstrPropName,long *plPropNum)
{
    if (!plPropNum)
        return E_INVALIDARG;

    *plPropNum = -1;
    WriteLogFormat(L"FindProp: name='%s'", bstrPropName ? bstrPropName : L"(null)");
    if (!m_native)
        return S_FALSE;

    WCHAR_T* name = 0;
    uint32_t len = 0;
    if (!ConvertBstrToWcharT(bstrPropName, &name, &len))
        return E_FAIL;

    long res = m_native->FindProp(name);
    m_memoryManager.FreeMemory((void**)&name);
    *plPropNum = res;

    WriteLogFormat(L"FindProp: result=%ld", *plPropNum);
    return (*plPropNum == -1) ? S_FALSE : S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetPropName(long lPropNum,long lPropAlias,
                                    BSTR *pbstrPropName)
{
    if (!pbstrPropName)
        return E_INVALIDARG;

    WriteLogFormat(L"GetPropName: prop=%ld alias=%ld", lPropNum, lPropAlias);
    if (!m_native)
        return S_FALSE;

    const WCHAR_T* name = m_native->GetPropName(lPropNum, lPropAlias);
    if (!name)
        return S_FALSE;

    *pbstrPropName = ConvertWcharTToBstr(name, 0);
    WCHAR_T* tmp = const_cast<WCHAR_T*>(name);
    m_memoryManager.FreeMemory((void**)&tmp);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
    if (!pvarPropVal)
        return E_INVALIDARG;

    WriteLogFormat(L"GetPropVal: prop=%ld", lPropNum);
    if (!m_native)
        return S_FALSE;

    tVariant val;
    tVarInit(&val);
    if (!m_native->GetPropVal(lPropNum, &val))
        return S_FALSE;

    bool ok = TVariantToVariant(val, pvarPropVal);
    ClearTVariant(&val);

    WriteLogFormat(L"GetPropVal: ok=%d ret vt=0x%04X", ok ? 1 : 0, (unsigned)pvarPropVal->vt);
    return ok ? S_OK : E_FAIL;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::SetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
    if (!pvarPropVal)
        return E_INVALIDARG;

    WriteLogFormat(L"SetPropVal: prop=%ld vt=0x%04X", lPropNum, (unsigned)pvarPropVal->vt);
    if (!m_native)
        return S_FALSE;

    tVariant val;
    tVarInit(&val);
    bool byRef = false;
    if (!VariantToTVariant(*pvarPropVal, &val, byRef))
        return E_FAIL;

    bool ok = m_native->SetPropVal(lPropNum, &val);
    ClearTVariant(&val);

    WriteLogFormat(L"SetPropVal: ok=%d", ok ? 1 : 0);
    return ok ? S_OK : S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::IsPropReadable(long lPropNum,BOOL *pboolPropRead)
{
    if (!pboolPropRead)
        return E_INVALIDARG;

    WriteLogFormat(L"IsPropReadable: prop=%ld", lPropNum);
    if (!m_native)
        return S_FALSE;

    *pboolPropRead = m_native->IsPropReadable(lPropNum) ? TRUE : FALSE;
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::IsPropWritable(long lPropNum,BOOL *pboolPropWrite)
{
    if (!pboolPropWrite)
        return E_INVALIDARG;

    WriteLogFormat(L"IsPropWritable: prop=%ld", lPropNum);
    if (!m_native)
        return S_FALSE;

    *pboolPropWrite = m_native->IsPropWritable(lPropNum) ? TRUE : FALSE;
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNMethods(long *plMethods)
{
    if (!plMethods)
        return E_INVALIDARG;

    long nativeCount = 0;
    if (m_native)
        nativeCount = m_native->GetNMethods();

    *plMethods = nativeCount + 1;
    WriteLogFormat(L"GetNMethods: native=%ld wrapper=%ld", nativeCount, *plMethods);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::FindMethod(BSTR bstrMethodName, long *plMethodNum)
{
    if (!plMethodNum)
        return E_INVALIDARG;

    *plMethodNum = -1;
    const wchar_t* methodName = bstrMethodName ? bstrMethodName : L"(null)";
    WriteLogFormat(L"FindMethod: name='%s'", methodName);
    CAtlStringW name(bstrMethodName);
    if (name.CompareNoCase(kMethodSetDriverNameEn) == 0 ||
        name.CompareNoCase(kMethodSetDriverNameRu) == 0)
    {
        *plMethodNum = eMethSetDriverName;
        WriteLogFormat(L"FindMethod: matched wrapper method index=%ld", *plMethodNum);
        return S_OK;
    }

    if (!m_native)
    {
        WriteLogLine(L"FindMethod: native component is not initialized.");
        return S_FALSE;
    }

    WCHAR_T* shortName = 0;
    uint32_t len = 0;
    if (!ConvertBstrToWcharT(bstrMethodName, &shortName, &len))
        return E_FAIL;

    long nativeIndex = m_native->FindMethod(shortName);
    m_memoryManager.FreeMemory((void**)&shortName);

    if (nativeIndex >= 0)
    {
        *plMethodNum = nativeIndex;
        WriteLogFormat(L"FindMethod: native index=%ld, wrapper index=%ld", nativeIndex, *plMethodNum);
        return S_OK;
    }

    WriteLogFormat(L"FindMethod: method not found (native index=%ld).", nativeIndex);
    return S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetMethodName(long lMethodNum,long lMethodAlias,
                                      BSTR *pbstrMethodName)
{
    if (!pbstrMethodName)
        return E_INVALIDARG;

    WriteLogFormat(L"GetMethodName: method=%ld alias=%ld", lMethodNum, lMethodAlias);
    if (lMethodNum == eMethSetDriverName)
    {
        if (lMethodAlias == 1)
            *pbstrMethodName = ::SysAllocString(kMethodSetDriverNameRu);
        else
            *pbstrMethodName = ::SysAllocString(kMethodSetDriverNameEn);
        return S_OK;
    }

    if (!m_native)
        return S_FALSE;

    const WCHAR_T* name = m_native->GetMethodName(lMethodNum, lMethodAlias);
    if (!name)
        return S_FALSE;

    *pbstrMethodName = ConvertWcharTToBstr(name, 0);
    WCHAR_T* tmp = const_cast<WCHAR_T*>(name);
    m_memoryManager.FreeMemory((void**)&tmp);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNParams(long lMethodNum,long *plParams)
{
    if (!plParams)
        return E_INVALIDARG;

    if (lMethodNum == eMethSetDriverName)
    {
        *plParams = 2;
        WriteLogFormat(L"GetNParams: method=%ld wrapper params=%ld", lMethodNum, *plParams);
        return S_OK;
    }

    if (!m_native)
    {
        WriteLogFormat(L"GetNParams: method=%ld native not initialized", lMethodNum);
        return S_FALSE;
    }

    *plParams = m_native->GetNParams(lMethodNum);
    WriteLogFormat(L"GetNParams: method=%ld native params=%ld", lMethodNum, *plParams);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetParamDefValue(long lMethodNum,long lParamNum,
                                         VARIANT *pvarParamDefValue)
{
    if (!pvarParamDefValue)
        return E_INVALIDARG;

    ::VariantInit(pvarParamDefValue);
    WriteLogFormat(L"GetParamDefValue: method=%ld param=%ld", lMethodNum, lParamNum);

    if (lMethodNum == eMethSetDriverName)
        return S_OK;

    if (!m_native)
        return S_FALSE;

    tVariant val;
    tVarInit(&val);
    if (!m_native->GetParamDefValue(lMethodNum, lParamNum, &val))
        return S_FALSE;

    bool ok = TVariantToVariant(val, pvarParamDefValue);
    if (ok)
    {
        const WCHAR_T* methodName = m_native->GetMethodName(lMethodNum, 0);
        if (methodName)
        {
            BSTR bstrName = ConvertWcharTToBstr(methodName, 0);
            WCHAR_T* tmp = const_cast<WCHAR_T*>(methodName);
            m_memoryManager.FreeMemory((void**)&tmp);
            if (bstrName)
            {
                CAtlStringW name(bstrName);
                ::SysFreeString(bstrName);
                if (name.CompareNoCase(L"ПолучитьОписание") == 0)
                {
                    WriteLogFormat(L"GetParamDefValue: method='ПолучитьОписание' vt=0x%04X",
                                   (unsigned)pvarParamDefValue->vt);
                }
            }
        }
    }
    ClearTVariant(&val);

    return ok ? S_OK : E_FAIL;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::HasRetVal(long lMethodNum,BOOL *pboolRetValue)
{
    if (!pboolRetValue)
        return E_INVALIDARG;

    if (lMethodNum == eMethSetDriverName)
    {
        *pboolRetValue = TRUE;
        WriteLogFormat(L"HasRetVal: method=%ld wrapper ret=TRUE", lMethodNum);
        return S_OK;
    }

    if (!m_native)
    {
        WriteLogFormat(L"HasRetVal: method=%ld native not initialized", lMethodNum);
        return S_FALSE;
    }

    *pboolRetValue = m_native->HasRetVal(lMethodNum) ? TRUE : FALSE;
    WriteLogFormat(L"HasRetVal: method=%ld native ret=%d", lMethodNum, *pboolRetValue ? 1 : 0);
    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::CallAsProc(long lMethodNum, SAFEARRAY **paParams)
{
    WriteLogFormat(L"CallAsProc: enter method=%ld params=0x%p",
                   lMethodNum, (paParams && *paParams) ? *paParams : 0);
    if (lMethodNum == eMethSetDriverName)
    {
        WriteLogLine(L"CallAsProc: setDriverName");
        return CallSetDriverName(paParams);
    }

    if (!m_native)
    {
        WriteLogLine(L"CallAsProc: native component is not initialized.");
        return S_FALSE;
    }

    WriteLogFormat(L"CallAsProc: method=%ld", lMethodNum);

    SAFEARRAY* params = (paParams) ? *paParams : 0;
    long count = 0;
    long lBound = 0;
    long uBound = -1;
    VARIANT* data = 0;
    HRESULT hr = S_OK;
    if (params)
    {
        SafeArrayGetLBound(params, 1, &lBound);
        SafeArrayGetUBound(params, 1, &uBound);
        if (uBound >= lBound)
            count = uBound - lBound + 1;
        hr = SafeArrayAccessData(params, (void**)&data);
        if (FAILED(hr))
            return E_FAIL;
    }
    WriteLogFormat(L"CallAsProc: params bounds [%ld..%ld], count=%ld", lBound, uBound, count);

    tVariant* tParams = (count > 0) ? new tVariant[count] : 0;
    bool* byRef = (count > 0) ? new bool[count] : 0;

    for (long i = 0; i < count; ++i)
    {
        tVarInit(&tParams[i]);
        VARTYPE vt = data[i].vt;
        WriteLogFormat(L"CallAsProc: param[%ld] vt=%s (0x%04X) byref=%d",
                       i, VariantTypeToString(vt), (unsigned)vt, (vt & VT_BYREF) ? 1 : 0);
        if (!VariantToTVariant(data[i], &tParams[i], byRef[i]))
        {
            WriteLogFormat(L"CallAsProc: VariantToTVariant failed for param[%ld].", i);
            for (long j = 0; j <= i; ++j)
                ClearTVariant(&tParams[j]);
            if (params)
                SafeArrayUnaccessData(params);
            delete[] tParams;
            delete[] byRef;
            return E_FAIL;
        }
    }

    WriteLogFormat(L"CallAsProc: native вызов, params=%ld", count);
    bool ok = false;
    __try
    {
        ok = m_native->CallAsProc(lMethodNum, tParams, count);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        DWORD code = GetExceptionCode();
        WriteLogFormat(L"CallAsProc: native exception 0x%08X", code);
        ok = false;
    }
    WriteLogFormat(L"CallAsProc: native вернул %s", ok ? L"true" : L"false");

    for (long i = 0; i < count; ++i)
    {
        ::VariantClear(&data[i]);
        if (!TVariantToVariant(tParams[i], &data[i]))
            WriteLogFormat(L"CallAsProc: overwrite param[%ld] failed.", i);
        ClearTVariant(&tParams[i]);
    }

    delete[] tParams;
    delete[] byRef;

    if (params)
        SafeArrayUnaccessData(params);

    return ok ? S_OK : S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::CallAsFunc(long lMethodNum,VARIANT *pvarRetValue,
                                   SAFEARRAY **paParams)
{
    WriteLogFormat(L"CallAsFunc: enter method=%ld ret=0x%p params=0x%p",
                   lMethodNum, pvarRetValue, (paParams && *paParams) ? *paParams : 0);
    if (!pvarRetValue)
        return E_INVALIDARG;

    ::VariantInit(pvarRetValue);

    if (lMethodNum == eMethSetDriverName)
    {
        WriteLogLine(L"CallAsFunc: setDriverName");
        HRESULT hr = CallSetDriverName(paParams);
        V_VT(pvarRetValue) = VT_BOOL;
        V_BOOL(pvarRetValue) = (hr == S_OK) ? VARIANT_TRUE : VARIANT_FALSE;
        return hr;
    }

    if (!m_native)
    {
        WriteLogLine(L"CallAsFunc: native component is not initialized.");
        return S_FALSE;
    }

    WriteLogFormat(L"CallAsFunc: method=%ld", lMethodNum);

    SAFEARRAY* params = (paParams) ? *paParams : 0;
    long count = 0;
    long lBound = 0;
    long uBound = -1;
    VARIANT* data = 0;
    HRESULT hr = S_OK;
    if (params)
    {
        SafeArrayGetLBound(params, 1, &lBound);
        SafeArrayGetUBound(params, 1, &uBound);
        if (uBound >= lBound)
            count = uBound - lBound + 1;
        hr = SafeArrayAccessData(params, (void**)&data);
        if (FAILED(hr))
            return E_FAIL;
    }
    WriteLogFormat(L"CallAsFunc: params bounds [%ld..%ld], count=%ld", lBound, uBound, count);
    if (count > 0 && data)
    {
        VARTYPE rawVt = data[0].vt;
        WriteLogFormat(L"CallAsFunc: raw param[0].vt=%s (0x%04X) byref=%d",
                       VariantTypeToString(rawVt), (unsigned)rawVt, (rawVt & VT_BYREF) ? 1 : 0);
    }

    tVariant* tParams = (count > 0) ? new tVariant[count] : 0;
    bool* byRef = (count > 0) ? new bool[count] : 0;

    for (long i = 0; i < count; ++i)
    {
        tVarInit(&tParams[i]);
        VARTYPE vt = data[i].vt;
        WriteLogFormat(L"CallAsFunc: param[%ld] vt=%s (0x%04X) byref=%d",
                       i, VariantTypeToString(vt), (unsigned)vt, (vt & VT_BYREF) ? 1 : 0);
        if (!VariantToTVariant(data[i], &tParams[i], byRef[i]))
        {
            WriteLogFormat(L"CallAsFunc: VariantToTVariant failed for param[%ld].", i);
            for (long j = 0; j <= i; ++j)
                ClearTVariant(&tParams[j]);
            if (params)
                SafeArrayUnaccessData(params);
            delete[] tParams;
            delete[] byRef;
            return E_FAIL;
        }
    }

    tVariant retVal;
    tVarInit(&retVal);
    WriteLogFormat(L"CallAsFunc: native вызов, params=%ld", count);
    bool ok = false;
    __try
    {
        ok = m_native->CallAsFunc(lMethodNum, &retVal, tParams, count);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        DWORD code = GetExceptionCode();
        WriteLogFormat(L"CallAsFunc: native exception 0x%08X", code);
        ok = false;
    }
    WriteLogFormat(L"CallAsFunc: native вернул %s", ok ? L"true" : L"false");
    LogTVariantSummary(retVal, L"CallAsFunc: retVal");

    for (long i = 0; i < count; ++i)
    {
        ::VariantClear(&data[i]);
        if (!TVariantToVariant(tParams[i], &data[i]))
            WriteLogFormat(L"CallAsFunc: overwrite param[%ld] failed.", i);
        ClearTVariant(&tParams[i]);
    }

    delete[] tParams;
    delete[] byRef;

    if (params)
        SafeArrayUnaccessData(params);

    if (!ok)
    {
        ClearTVariant(&retVal);
        return S_FALSE;
    }

    bool converted = TVariantToVariant(retVal, pvarRetValue);
    WriteLogFormat(L"CallAsFunc: TVariantToVariant ok=%d ret vt=0x%04X",
                   converted ? 1 : 0, pvarRetValue ? (unsigned)pvarRetValue->vt : 0);
    ClearTVariant(&retVal);

    return converted ? S_OK : E_FAIL;
}
//---------------------------------------------------------------------------//
HRESULT CAddInCOM::SetLocale(BSTR bstrLocale)
{
    if (bstrLocale)
        m_locale = bstrLocale;
    SetNativeLocale();
    return S_OK;
}
//---------------------------------------------------------------------------//
HRESULT CAddInCOM::SetUserInterfaceLanguageCode(BSTR bstrLangCode)
{
    if (bstrLangCode)
        m_langCode = bstrLangCode;
    SetNativeLocale();
    return S_OK;
}
//---------------------------------------------------------------------------//
HRESULT CAddInCOM::CallSetDriverName(SAFEARRAY **paParams)
{
    WriteLogLine(L"setDriverName: вызван.");
    SAFEARRAY* params = (paParams) ? *paParams : 0;
    if (!params)
    {
        AddError(ADDIN_E_FAIL, kErrorSource, L"Отсутствуют параметры setDriverName.");
        return E_INVALIDARG;
    }

    CAtlStringW path;
    CAtlStringW className;
    if (!GetParamString(params, 0, path) || !GetParamString(params, 1, className))
    {
        AddError(ADDIN_E_FAIL, kErrorSource, L"Неверные параметры setDriverName.");
        return E_INVALIDARG;
    }

    WriteLogFormat(L"setDriverName: path='%s' class='%s'", path.GetString(), className.GetString());
    return LoadNative(path, className);
}
//---------------------------------------------------------------------------//
HRESULT CAddInCOM::LoadNative(const CAtlStringW& path, const CAtlStringW& classNameParam)
{
    CAtlStringW fullPath = path;

    if (fullPath.IsEmpty())
    {
        AddError(ADDIN_E_FAIL, kErrorSource, L"Пустой путь к native DLL.");
        return E_INVALIDARG;
    }

    WriteLogFormat(L"LoadNative: LoadLibraryW('%s')", fullPath.GetString());
    UnloadNative();

    m_hModule = ::LoadLibraryW(fullPath);
    if (!m_hModule)
    {
        WriteLogFormat(L"LoadNative: LoadLibraryW failed, GetLastError=%lu", ::GetLastError());
        AddError(ADDIN_E_FAIL, kErrorSource, L"Не удалось загрузить native DLL.");
        return E_FAIL;
    }

    m_getClassObject = (GetClassObjectPtr)::GetProcAddress(m_hModule, "GetClassObject");
    m_destroyObject = (DestroyObjectPtr)::GetProcAddress(m_hModule, "DestroyObject");
    m_getClassNames = (GetClassNamesPtr)::GetProcAddress(m_hModule, "GetClassNames");
    m_setPlatformCapabilities = (SetPlatformCapabilitiesPtr)::GetProcAddress(m_hModule, "SetPlatformCapabilities");
    m_getAttachType = (GetAttachTypePtr)::GetProcAddress(m_hModule, "GetAttachType");

    if (!m_getClassObject || !m_destroyObject || !m_getClassNames)
    {
        WriteLogFormat(L"LoadNative: отсутствуют экспорты (GetClassObject=%d DestroyObject=%d GetClassNames=%d)",
                       m_getClassObject ? 1 : 0, m_destroyObject ? 1 : 0, m_getClassNames ? 1 : 0);
        AddError(ADDIN_E_FAIL, kErrorSource, L"Не найдены обязательные экспорты native DLL.");
        UnloadNative();
        return E_FAIL;
    }

    CAtlStringW className = classNameParam;
    if (className.IsEmpty() && !GetFirstClassName(className))
    {
        WriteLogLine(L"LoadNative: GetFirstClassName вернул пустое имя.");
        AddError(ADDIN_E_FAIL, kErrorSource, L"Native DLL не вернула имя класса.");
        UnloadNative();
        return E_FAIL;
    }

    WriteLogFormat(L"LoadNative: className='%s'", className.GetString());

    std::vector<WCHAR_T> classNameShort;
    classNameShort.resize(className.GetLength() + 1);
    for (int i = 0; i < className.GetLength(); ++i)
        classNameShort[i] = (WCHAR_T)className[i];
    classNameShort[className.GetLength()] = 0;

    WriteLogLine(L"LoadNative: GetClassObject...");
    if (!m_getClassObject(classNameShort.empty() ? 0 : &classNameShort[0], &m_native) || !m_native)
    {
        WriteLogLine(L"LoadNative: GetClassObject failed.");
        AddError(ADDIN_E_FAIL, kErrorSource, L"Не удалось создать native объект.");
        UnloadNative();
        return E_FAIL;
    }

    WriteLogLine(L"LoadNative: setMemManager...");
    if (!m_native->setMemManager(&m_memoryManager))
    {
        WriteLogLine(L"LoadNative: setMemManager failed.");
        AddError(ADDIN_E_FAIL, kErrorSource, L"Native объект не принял менеджер памяти.");
        UnloadNative();
        return E_FAIL;
    }

    if (m_setPlatformCapabilities)
        m_setPlatformCapabilities(eAppCapabilitiesLast);

    WriteLogLine(L"LoadNative: Init...");
    if (!m_native->Init(m_addinProxy))
    {
        WriteLogLine(L"LoadNative: Init failed.");
        AddError(ADDIN_E_FAIL, kErrorSource, L"Init native компоненты завершился с ошибкой.");
        UnloadNative();
        return E_FAIL;
    }

    SetNativeLocale();
    WriteLogLine(L"LoadNative: OK");

    return S_OK;
}
//---------------------------------------------------------------------------//
void CAddInCOM::UnloadNative()
{
    if (m_native)
    {
        m_native->Done();
        if (m_destroyObject)
            m_destroyObject(&m_native);
        m_native = NULL;
    }

    if (m_hModule)
    {
        ::FreeLibrary(m_hModule);
        m_hModule = NULL;
    }

    m_getClassObject = NULL;
    m_destroyObject = NULL;
    m_getClassNames = NULL;
    m_setPlatformCapabilities = NULL;
    m_getAttachType = NULL;
}
//---------------------------------------------------------------------------//
bool CAddInCOM::GetParamString(SAFEARRAY *pParams, long index, CAtlStringW& outValue)
{
    if (!pParams)
        return false;

    WriteLogFormat(L"GetParamString: вход index=%ld pParams=0x%p.", index, pParams);
    long lBound = 0;
    long uBound = -1;
    SafeArrayGetLBound(pParams, 1, &lBound);
    SafeArrayGetUBound(pParams, 1, &uBound);
    WriteLogFormat(L"GetParamString: границы [%ld..%ld].", lBound, uBound);
    long actualIndex = lBound + index;
    if (actualIndex < lBound || actualIndex > uBound)
    {
        WriteLogFormat(L"GetParamString: index=%ld вне диапазона [%ld..%ld].", index, lBound, uBound);
        return false;
    }

    VARIANT v;
    ::VariantInit(&v);
    HRESULT hr = SafeArrayGetElement(pParams, &actualIndex, &v);
    if (FAILED(hr))
    {
        WriteLogFormat(L"GetParamString: SafeArrayGetElement failed, hr=0x%08X.", hr);
        return false;
    }
    BSTR bstr = 0;
    if ((v.vt & VT_BYREF) && (v.vt & VT_BSTR))
        bstr = (v.pbstrVal) ? *v.pbstrVal : 0;
    else if ((v.vt & VT_BYREF) && (v.vt & VT_VARIANT))
        bstr = (v.pvarVal && (v.pvarVal->vt == VT_BSTR)) ? v.pvarVal->bstrVal : 0;
    else if (v.vt == VT_BSTR)
        bstr = v.bstrVal;
    else if (v.vt == VT_EMPTY || v.vt == VT_NULL)
        bstr = 0;
    else
    {
        WriteLogFormat(L"GetParamString: неподдерживаемый vt=0x%04X.", v.vt);
        ::VariantClear(&v);
        return false;
    }

    outValue = (bstr) ? bstr : L"";
    ::VariantClear(&v);
    return true;
}
//---------------------------------------------------------------------------//
bool CAddInCOM::GetVariantString(const VARIANT& value, CAtlStringW& outValue)
{
    const VARIANT* v = &value;
    if ((v->vt & VT_BYREF) && (v->vt & VT_VARIANT) && v->pvarVal)
        v = v->pvarVal;

    BSTR bstr = 0;
    if ((v->vt & VT_BYREF) && (v->vt & VT_BSTR))
        bstr = (v->pbstrVal) ? *v->pbstrVal : 0;
    else if (v->vt == VT_BSTR)
        bstr = v->bstrVal;
    else if (v->vt == VT_EMPTY || v->vt == VT_NULL)
        bstr = 0;
    else
        return false;

    outValue = (bstr) ? bstr : L"";
    return true;
}
//---------------------------------------------------------------------------//
bool CAddInCOM::VariantToTVariant(const VARIANT& src, tVariant* dst, bool& isByRef)
{
    if (!dst)
        return false;

    tVarInit(dst);
    isByRef = false;

    if (src.vt & VT_BYREF)
    {
        isByRef = true;
        VARIANT val = src;
        VARTYPE vt = src.vt & ~VT_BYREF;
        switch (vt)
        {
        case VT_I2: val.vt = VT_I2; val.iVal = *src.piVal; break;
        case VT_I4: val.vt = VT_I4; val.lVal = *src.plVal; break;
        case VT_R4: val.vt = VT_R4; val.fltVal = *src.pfltVal; break;
        case VT_R8: val.vt = VT_R8; val.dblVal = *src.pdblVal; break;
        case VT_BOOL: val.vt = VT_BOOL; val.boolVal = *src.pboolVal; break;
        case VT_BSTR: val.vt = VT_BSTR; val.bstrVal = (src.pbstrVal) ? *src.pbstrVal : 0; break;
        case VT_DATE: val.vt = VT_DATE; val.date = *src.pdate; break;
        case VT_UI1: val.vt = VT_UI1; val.bVal = *src.pbVal; break;
        case VT_UI2: val.vt = VT_UI2; val.uiVal = *src.puiVal; break;
        case VT_UI4: val.vt = VT_UI4; val.ulVal = *src.pulVal; break;
        case VT_I8: val.vt = VT_I8; val.llVal = *src.pllVal; break;
        case VT_UI8: val.vt = VT_UI8; val.ullVal = *src.pullVal; break;
        case VT_VARIANT: val = (src.pvarVal) ? *src.pvarVal : val; break;
        default: break;
        }

        tVariant* ref = new tVariant;
        tVarInit(ref);
        if (!VariantToTVariantValue(val, ref))
        {
            delete ref;
            return false;
        }

        TV_VT(dst) = VTYPE_VARIANT | VTYPE_BYREF;
        dst->pvarVal = ref;
        return true;
    }

    return VariantToTVariantValue(src, dst);
}
//---------------------------------------------------------------------------//
bool CAddInCOM::VariantToTVariantValue(const VARIANT& val, tVariant* dst)
{
    if (!dst)
        return false;

    tVarInit(dst);

    switch (val.vt)
    {
    case VT_EMPTY:
        TV_VT(dst) = VTYPE_EMPTY;
        return true;
    case VT_NULL:
        TV_VT(dst) = VTYPE_NULL;
        return true;
    case VT_I2:
        TV_VT(dst) = VTYPE_I2;
        TV_I2(dst) = val.iVal;
        return true;
    case VT_I4:
        TV_VT(dst) = VTYPE_I4;
        TV_I4(dst) = val.lVal;
        return true;
    case VT_R4:
        TV_VT(dst) = VTYPE_R4;
        TV_R4(dst) = val.fltVal;
        return true;
    case VT_R8:
        TV_VT(dst) = VTYPE_R8;
        TV_R8(dst) = val.dblVal;
        return true;
    case VT_BOOL:
        TV_VT(dst) = VTYPE_BOOL;
        TV_BOOL(dst) = (val.boolVal == VARIANT_TRUE);
        return true;
    case VT_DATE:
        TV_VT(dst) = VTYPE_DATE;
        TV_DATE(dst) = val.date;
        return true;
    case VT_I1:
        TV_VT(dst) = VTYPE_I1;
        TV_I1(dst) = val.cVal;
        return true;
    case VT_UI1:
        TV_VT(dst) = VTYPE_UI1;
        TV_UI1(dst) = val.bVal;
        return true;
    case VT_UI2:
        TV_VT(dst) = VTYPE_UI2;
        TV_UI2(dst) = val.uiVal;
        return true;
    case VT_UI4:
        TV_VT(dst) = VTYPE_UI4;
        TV_UI4(dst) = val.ulVal;
        return true;
    case VT_I8:
        TV_VT(dst) = VTYPE_I8;
        TV_I8(dst) = val.llVal;
        return true;
    case VT_UI8:
        TV_VT(dst) = VTYPE_UI8;
        TV_UI8(dst) = val.ullVal;
        return true;
    case VT_INT:
        TV_VT(dst) = VTYPE_INT;
        TV_INT(dst) = val.intVal;
        return true;
    case VT_UINT:
        TV_VT(dst) = VTYPE_UINT;
        TV_UINT(dst) = val.uintVal;
        return true;
    case VT_ERROR:
        TV_VT(dst) = VTYPE_ERROR;
        dst->errCode = val.scode;
        return true;
    case VT_BSTR:
    {
        WCHAR_T* buf = 0;
        uint32_t len = 0;
        if (!ConvertBstrToWcharT(val.bstrVal, &buf, &len))
            return false;
        TV_VT(dst) = VTYPE_PWSTR;
        dst->pwstrVal = buf;
        dst->wstrLen = len;
        return true;
    }
    default:
        break;
    }

    if ((val.vt & VT_ARRAY) && (val.vt & VT_UI1))
    {
        SAFEARRAY* psa = val.parray;
        if (!psa)
            return false;
        BYTE* bytes = 0;
        if (FAILED(SafeArrayAccessData(psa, (void**)&bytes)))
            return false;

        long lBound = 0;
        long uBound = -1;
        SafeArrayGetLBound(psa, 1, &lBound);
        SafeArrayGetUBound(psa, 1, &uBound);
        long size = (uBound >= lBound) ? (uBound - lBound + 1) : 0;

        if (size > 0)
        {
            if (!m_memoryManager.AllocMemory((void**)&dst->pstrVal, size))
            {
                WriteLogFormat(L"VariantToTVariantValue: AllocMemory failed, size=%ld.", size);
                SafeArrayUnaccessData(psa);
                return false;
            }
            memcpy(dst->pstrVal, bytes, size);
        }
        dst->strLen = (uint32_t)size;
        TV_VT(dst) = VTYPE_BLOB;
        SafeArrayUnaccessData(psa);
        return true;
    }

    WriteLogFormat(L"VariantToTVariantValue: unsupported vt=0x%04X (%s).",
                   (unsigned)val.vt, VariantTypeToString(val.vt));
    return false;
}
//---------------------------------------------------------------------------//
bool CAddInCOM::TVariantToVariant(const tVariant& src, VARIANT* dst)
{
    if (!dst)
        return false;

    ::VariantInit(dst);
    TYPEVAR vt = TV_VT(&src);
    TYPEVAR base = vt & VTYPE_TYPEMASK;
    if ((vt & VTYPE_BYREF) && base == VTYPE_VARIANT && src.pvarVal)
        return TVariantToVariant(*src.pvarVal, dst);

    switch (base)
    {
    case VTYPE_EMPTY:
        V_VT(dst) = VT_EMPTY;
        return true;
    case VTYPE_NULL:
        V_VT(dst) = VT_NULL;
        return true;
    case VTYPE_I2:
        V_VT(dst) = VT_I2;
        V_I2(dst) = TV_I2(&src);
        return true;
    case VTYPE_I4:
        V_VT(dst) = VT_I4;
        V_I4(dst) = TV_I4(&src);
        return true;
    case VTYPE_R4:
        V_VT(dst) = VT_R4;
        V_R4(dst) = TV_R4(&src);
        return true;
    case VTYPE_R8:
        V_VT(dst) = VT_R8;
        V_R8(dst) = TV_R8(&src);
        return true;
    case VTYPE_DATE:
        V_VT(dst) = VT_DATE;
        V_DATE(dst) = TV_DATE(&src);
        return true;
    case VTYPE_BOOL:
        V_VT(dst) = VT_BOOL;
        V_BOOL(dst) = TV_BOOL(&src) ? VARIANT_TRUE : VARIANT_FALSE;
        return true;
    case VTYPE_I1:
        V_VT(dst) = VT_I1;
        V_I1(dst) = TV_I1(&src);
        return true;
    case VTYPE_UI1:
        V_VT(dst) = VT_UI1;
        V_UI1(dst) = TV_UI1(&src);
        return true;
    case VTYPE_UI2:
        V_VT(dst) = VT_UI2;
        V_UI2(dst) = TV_UI2(&src);
        return true;
    case VTYPE_UI4:
        V_VT(dst) = VT_UI4;
        V_UI4(dst) = TV_UI4(&src);
        return true;
    case VTYPE_I8:
        V_VT(dst) = VT_I8;
        V_I8(dst) = TV_I8(&src);
        return true;
    case VTYPE_UI8:
        V_VT(dst) = VT_UI8;
        V_UI8(dst) = TV_UI8(&src);
        return true;
    case VTYPE_INT:
        V_VT(dst) = VT_INT;
        V_INT(dst) = TV_INT(&src);
        return true;
    case VTYPE_UINT:
        V_VT(dst) = VT_UINT;
        V_UINT(dst) = TV_UINT(&src);
        return true;
    case VTYPE_ERROR:
        V_VT(dst) = VT_ERROR;
        V_ERROR(dst) = src.errCode;
        return true;
    case VTYPE_PWSTR:
        V_VT(dst) = VT_BSTR;
        V_BSTR(dst) = ConvertWcharTToBstr(src.pwstrVal, src.wstrLen);
        if (!V_BSTR(dst))
        {
            WriteLogLine(L"TVariantToVariant: ConvertWcharTToBstr failed.");
            return false;
        }
        return true;
    case VTYPE_PSTR:
    {
        V_VT(dst) = VT_BSTR;
        if (!src.pstrVal || src.strLen == 0)
        {
            V_BSTR(dst) = ::SysAllocString(L"");
            return true;
        }
        int needed = MultiByteToWideChar(CP_ACP, 0, src.pstrVal, src.strLen, 0, 0);
        if (needed <= 0)
        {
            WriteLogLine(L"TVariantToVariant: MultiByteToWideChar failed.");
            return false;
        }
        BSTR bstr = ::SysAllocStringLen(0, needed);
        MultiByteToWideChar(CP_ACP, 0, src.pstrVal, src.strLen, bstr, needed);
        V_BSTR(dst) = bstr;
        return true;
    }
    case VTYPE_BLOB:
    {
        SAFEARRAYBOUND bound;
        bound.lLbound = 0;
        bound.cElements = src.strLen;
        SAFEARRAY* psa = SafeArrayCreate(VT_UI1, 1, &bound);
        if (!psa)
        {
            WriteLogLine(L"TVariantToVariant: SafeArrayCreate failed.");
            return false;
        }
        BYTE* bytes = 0;
        if (FAILED(SafeArrayAccessData(psa, (void**)&bytes)))
        {
            SafeArrayDestroy(psa);
            return false;
        }
        if (src.strLen > 0)
            memcpy(bytes, src.pstrVal, src.strLen);
        SafeArrayUnaccessData(psa);
        V_VT(dst) = VT_ARRAY | VT_UI1;
        V_ARRAY(dst) = psa;
        return true;
    }
    default:
        break;
    }

    WriteLogFormat(L"TVariantToVariant: unsupported vt=0x%04X (%s).",
                   (unsigned)vt, TVariantTypeToString(vt));
    return false;
}
//---------------------------------------------------------------------------//
bool CAddInCOM::UpdateByRefVariant(VARIANT& dstByRef, const tVariant& src)
{
    if (!(dstByRef.vt & VT_BYREF))
        return true;

    const tVariant* value = &src;
    TYPEVAR srcVt = TV_VT(&src);
    if ((srcVt & VTYPE_BYREF) && ((srcVt & VTYPE_TYPEMASK) == VTYPE_VARIANT) && src.pvarVal)
        value = src.pvarVal;

    VARTYPE vt = dstByRef.vt & ~VT_BYREF;
    switch (vt)
    {
    case VT_I2:
        if (dstByRef.piVal)
            *dstByRef.piVal = TV_I2(value);
        return true;
    case VT_I4:
        if (dstByRef.plVal)
            *dstByRef.plVal = TV_I4(value);
        return true;
    case VT_R4:
        if (dstByRef.pfltVal)
            *dstByRef.pfltVal = TV_R4(value);
        return true;
    case VT_R8:
        if (dstByRef.pdblVal)
            *dstByRef.pdblVal = TV_R8(value);
        return true;
    case VT_BOOL:
        if (dstByRef.pboolVal)
            *dstByRef.pboolVal = TV_BOOL(value) ? VARIANT_TRUE : VARIANT_FALSE;
        return true;
    case VT_BSTR:
        if (dstByRef.pbstrVal)
        {
            BSTR bstr = ConvertWcharTToBstr(value->pwstrVal, value->wstrLen);
            ::SysFreeString(*dstByRef.pbstrVal);
            *dstByRef.pbstrVal = bstr;
        }
        return true;
    case VT_VARIANT:
        if (dstByRef.pvarVal)
        {
            VARIANT tmp;
            ::VariantInit(&tmp);
            if (!TVariantToVariant(*value, &tmp))
                return false;
            ::VariantClear(dstByRef.pvarVal);
            *dstByRef.pvarVal = tmp;
        }
        return true;
    default:
        return false;
    }
}
//---------------------------------------------------------------------------//
void CAddInCOM::ClearTVariant(tVariant* var)
{
    if (!var)
        return;

    TYPEVAR vt = TV_VT(var);
    TYPEVAR base = vt & VTYPE_TYPEMASK;
    if ((vt & VTYPE_BYREF) && base == VTYPE_VARIANT && var->pvarVal)
    {
        ClearTVariant(var->pvarVal);
        delete var->pvarVal;
        var->pvarVal = 0;
        tVarInit(var);
        return;
    }

    switch (base)
    {
    case VTYPE_PSTR:
    case VTYPE_BLOB:
        if (var->pstrVal)
            m_memoryManager.FreeMemory((void**)&var->pstrVal);
        break;
    case VTYPE_PWSTR:
        if (var->pwstrVal)
            m_memoryManager.FreeMemory((void**)&var->pwstrVal);
        break;
    default:
        break;
    }
    tVarInit(var);
}
//---------------------------------------------------------------------------//
void CAddInCOM::AddError(UINT code, const wchar_t* source, const wchar_t* description)
{
    WriteLogFormat(L"AddError: code=%u source='%s' desc='%s'",
                   code,
                   source ? source : L"",
                   description ? description : L"");
    if (!m_iErrorLog)
        return;

    EXCEPINFO ei;
    memset(&ei, 0, sizeof(ei));
    ei.wCode = (WORD)code;
    ei.scode = S_OK;
    ei.bstrSource = ::SysAllocString(source ? source : kErrorSource);
    ei.bstrDescription = ::SysAllocString(description ? description : L"");
    BSTR bstrEmpty = ::SysAllocString(L"");
    m_iErrorLog->AddError(bstrEmpty, &ei);
    ::SysFreeString(bstrEmpty);
    ::SysFreeString(ei.bstrSource);
    ::SysFreeString(ei.bstrDescription);
}
//---------------------------------------------------------------------------//
bool CAddInCOM::ConvertBstrToWcharT(BSTR src, WCHAR_T** dest, uint32_t* len)
{
    if (!dest || !len)
        return false;

    *dest = 0;
    *len = 0;
    if (!src)
        return true;

    UINT wlen = ::SysStringLen(src);
    if (!m_memoryManager.AllocMemory((void**)dest, (wlen + 1) * sizeof(WCHAR_T)))
        return false;

    for (UINT i = 0; i < wlen; ++i)
        (*dest)[i] = (WCHAR_T)src[i];
    (*dest)[wlen] = 0;
    *len = wlen;
    return true;
}
//---------------------------------------------------------------------------//
BSTR CAddInCOM::ConvertWcharTToBstr(const WCHAR_T* src, uint32_t len)
{
    if (!src)
        return ::SysAllocString(L"");
    if (len == 0)
        len = (uint32_t)wcslen((const wchar_t*)src);
    return ::SysAllocStringLen((const OLECHAR*)src, len);
}
//---------------------------------------------------------------------------//
void CAddInCOM::FreeShortStr(WCHAR_T** value)
{
    if (!value || !*value)
        return;
    m_memoryManager.FreeMemory((void**)value);
}
//---------------------------------------------------------------------------//
bool CAddInCOM::GetFirstClassName(CAtlStringW& className)
{
    if (!m_getClassNames)
        return false;

    const WCHAR_T* names = m_getClassNames();
    if (!names || !*names)
        return false;

    const WCHAR_T* end = names;
    while (*end && *end != (WCHAR_T)'|')
        ++end;

    className.SetString((const wchar_t*)names, (int)(end - names));
    return !className.IsEmpty();
}
//---------------------------------------------------------------------------//
void CAddInCOM::SetNativeLocale()
{
    if (!m_native)
        return;

    if (!m_locale.IsEmpty())
    {
        std::vector<WCHAR_T> loc;
        loc.resize(m_locale.GetLength() + 1);
        for (int i = 0; i < m_locale.GetLength(); ++i)
            loc[i] = (WCHAR_T)m_locale[i];
        loc[m_locale.GetLength()] = 0;
        m_native->SetLocale(loc.empty() ? 0 : &loc[0]);
    }

    if (!m_langCode.IsEmpty())
    {
        std::vector<WCHAR_T> lang;
        lang.resize(m_langCode.GetLength() + 1);
        for (int i = 0; i < m_langCode.GetLength(); ++i)
            lang[i] = (WCHAR_T)m_langCode[i];
        lang[m_langCode.GetLength()] = 0;
        m_native->SetUserInterfaceLanguageCode(lang.empty() ? 0 : &lang[0]);
    }
}
//---------------------------------------------------------------------------//
