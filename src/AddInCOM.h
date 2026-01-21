// AddInCOM.h : Declaration of the CAddInCOM

#pragma once
#include "resource.h"       // main symbols
#include <atlstr.h>
#include "AddIn_i.h"
#include "ComponentBase.h"
#include "types.h"
#include "MyMemoryManager.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

class CAddInDefBaseProxy;

///////////////////////////////////////////////////////////////////////////////
// class CAddInCOM
class ATL_NO_VTABLE CAddInCOM :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CAddInCOM, &CLSID_AddInCOM>,
    public IDispatch,
    public IInitDone,
    public ILanguageExtender,
    public ILocale,
    public IUserInterfaceLanguage,
    public IAddInCOM
{
public:
    enum
    {
        eMethSetDriverName = 999
    };

    CAddInCOM();

DECLARE_REGISTRY_RESOURCEID(IDR_ADDINCOM)

BEGIN_COM_MAP(CAddInCOM)
    COM_INTERFACE_ENTRY(IAddInCOM)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IInitDone)
    COM_INTERFACE_ENTRY(ILanguageExtender)
    COM_INTERFACE_ENTRY(ILocale)
    COM_INTERFACE_ENTRY(IUserInterfaceLanguage)
END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct()
    {
        return S_OK;
    }

    void FinalRelease();

// IInitDone
public:
    STDMETHOD(Init)(IDispatch *pConnection);
    STDMETHOD(Done)();
    STDMETHOD(GetInfo)(SAFEARRAY **pInfo);

// IDispatch
public:
    STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
    STDMETHOD(GetTypeInfo)(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
    STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
                             LCID lcid, DISPID* rgDispId);
    STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
                      DISPPARAMS* pDispParams, VARIANT* pVarResult,
                      EXCEPINFO* pExcepInfo, UINT* puArgErr);

// ILanguageExtender
public:
    STDMETHOD(RegisterExtensionAs)(BSTR *bstrExtensionName);

    STDMETHOD(GetNProps)(long *plProps);
    STDMETHOD(FindProp)(BSTR bstrPropName,long *plPropNum);
    STDMETHOD(GetPropName)(long lPropNum,long lPropAlias,BSTR *pbstrPropName);
    STDMETHOD(GetPropVal)(long lPropNum,VARIANT *pvarPropVal);
    STDMETHOD(SetPropVal)(long lPropNum,VARIANT *pvarPropVal);
    STDMETHOD(IsPropReadable)(long lPropNum,BOOL *pboolPropRead);
    STDMETHOD(IsPropWritable)(long lPropNum,BOOL *pboolPropWrite);

    STDMETHOD(GetNMethods)(long *plMethods);
    STDMETHOD(FindMethod)(BSTR bstrMethodName,long *plMethodNum);
    STDMETHOD(GetMethodName)(long lMethodNum,long lMethodAlias,BSTR *pbstrMethodName);
    STDMETHOD(GetNParams)(long lMethodNum,long *plParams);
    STDMETHOD(GetParamDefValue)(long lMethodNum,long lParamNum,VARIANT *pvarParamDefValue);
    STDMETHOD(HasRetVal)(long lMethodNum,BOOL *pboolRetValue);
    STDMETHOD(CallAsProc)(long lMethodNum,SAFEARRAY **paParams);
    STDMETHOD(CallAsFunc)(long lMethodNum,VARIANT *pvarRetValue,SAFEARRAY **paParams);
// ILocale
public:
    STDMETHOD(SetLocale)(BSTR bstrLocale);
//IUserInterfaceLanguage
public:
    STDMETHOD(SetUserInterfaceLanguageCode)(BSTR bstrLangCode);

private:
    friend class CAddInDefBaseProxy;

    HRESULT CallSetDriverName(SAFEARRAY **paParams);
    HRESULT LoadNative(const CAtlStringW& path, const CAtlStringW& dllName);
    void UnloadNative();

    bool GetParamString(SAFEARRAY *pParams, long index, CAtlStringW& outValue);
    bool GetVariantString(const VARIANT& value, CAtlStringW& outValue);
    bool VariantToTVariant(const VARIANT& src, tVariant* dst, bool& isByRef);
    bool VariantToTVariantValue(const VARIANT& src, tVariant* dst);
    bool TVariantToVariant(const tVariant& src, VARIANT* dst);
    bool UpdateByRefVariant(VARIANT& dstByRef, const tVariant& src);
    void ClearTVariant(tVariant* var);
    void AddError(UINT code, const wchar_t* source, const wchar_t* description);

    bool ConvertBstrToWcharT(BSTR src, WCHAR_T** dest, uint32_t* len);
    BSTR ConvertWcharTToBstr(const WCHAR_T* src, uint32_t len);
    void FreeShortStr(WCHAR_T** value);
    bool GetFirstClassName(CAtlStringW& className);
    void SetNativeLocale();

private:
    IDispatch* m_iConnect;
    IErrorLog *m_iErrorLog;
    IPropertyProfile *m_iProfile;
    IStatusLine *m_iStatusLine;
    IAsyncEvent *m_iAsyncEvent;
    IMsgBox *m_iMsgBox;
    IPlatformInfo *m_iPlatformInfo;
    IAttachedInfo *m_iAttachedInfo;

    CAtlStringW m_locale;
    CAtlStringW m_langCode;

    HMODULE m_hModule;
    GetClassObjectPtr m_getClassObject;
    DestroyObjectPtr m_destroyObject;
    GetClassNamesPtr m_getClassNames;
    SetPlatformCapabilitiesPtr m_setPlatformCapabilities;
    GetAttachTypePtr m_getAttachType;
    IComponentBase* m_native;

    MyMemoryManager m_memoryManager;
    CAddInDefBaseProxy* m_addinProxy;
};

OBJECT_ENTRY_AUTO(__uuidof(AddInCOM), CAddInCOM)
