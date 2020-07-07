// AddInCOM.cpp : Implementation of CAddInCOM

#include "stdafx.h"
#include "AddInCOM.h"


void FromNativeToCOM(tVariant* ValueNative, VARIANT* ValueCOM, MyMemoryManager* m_iMemory)
{
    if (!ValueNative)
    {
        ValueCOM = NULL;
        return;
    }

    VariantInit(ValueCOM);

    switch (TV_VT(ValueNative))
    {
    case VTYPE_EMPTY:
        V_VT(ValueCOM) = VT_EMPTY;
    case VTYPE_NULL:
        V_VT(ValueCOM) = VT_NULL;
        break;
    case VTYPE_I2:
        V_VT(ValueCOM) = VT_I2;
        V_I2(ValueCOM) = TV_I2(ValueNative);
        break;
    case VTYPE_I1:
        V_VT(ValueCOM) = VT_I1;
        V_I1(ValueCOM) = TV_I1(ValueNative);
        break;
    case VTYPE_I4:
        V_VT(ValueCOM) = VT_I4;
        V_I4(ValueCOM) = TV_I4(ValueNative);
        break;
    case VTYPE_R4:
        V_VT(ValueCOM) = VT_R4;
        V_R4(ValueCOM) = TV_R4(ValueNative);
        break;
    case VTYPE_R8:
        V_VT(ValueCOM) = VT_R8;
        V_R8(ValueCOM) = TV_R8(ValueNative);
        break;
    case VTYPE_DATE:
        V_VT(ValueCOM) = VT_DATE;
        V_DATE(ValueCOM) = TV_DATE(ValueNative);
        break;
    case VTYPE_BOOL:
        V_VT(ValueCOM) = VT_BOOL;
        V_BOOL(ValueCOM) = (BOOLEAN)TV_BOOL(ValueNative);
        break;
    case VTYPE_PSTR:
        V_VT(ValueCOM) = VT_BSTR;
        V_BSTR(ValueCOM) = SysAllocString((BSTR)TV_STR(ValueNative));
        break;
    case VTYPE_PWSTR:
        V_VT(ValueCOM) = VT_BSTR;
        if (ValueNative->wstrLen)
        {
            TV_WSTR(ValueNative)[ValueNative->wstrLen] = '\0';
            V_BSTR(ValueCOM) = SysAllocString(TV_WSTR(ValueNative));
            //m_iMemory->FreeMemory((void**)TV_WSTR(ValueNative));
        }
        break;
    default:
        break;
    }
}

void FromComToNative(tVariant* ValueNative, VARIANT* ValueCOM)
{
    if (!ValueCOM)
    {
        ValueNative = NULL;
        return;
    }

    tVarInit(ValueNative);

    switch (V_VT(ValueCOM))
    {
    case VT_EMPTY:
        TV_VT(ValueNative) = VTYPE_EMPTY;
    case VT_NULL:
        TV_VT(ValueNative) = VTYPE_NULL;
        break;
    case VT_I2:
        TV_VT(ValueNative) = VTYPE_I2;
        TV_I2(ValueNative) = V_I2(ValueCOM);
        break;
    case VT_I1:
        TV_VT(ValueNative) = VTYPE_I1;
        TV_I1(ValueNative) = V_I1(ValueCOM);
        break;
    case VT_I4:
        TV_VT(ValueNative) = VTYPE_I4;
        TV_I4(ValueNative) = V_I4(ValueCOM);
        break;
    case VT_R4:
        TV_VT(ValueNative) = VTYPE_R4;
        TV_R4(ValueNative) = V_R4(ValueCOM);
        break;
    case VT_R8:
        TV_VT(ValueNative) = VTYPE_R8;
        TV_R8(ValueNative) = V_R8(ValueCOM);
        break;
    case VT_DATE:
        TV_VT(ValueNative) = VTYPE_DATE;
        TV_DATE(ValueNative) = V_DATE(ValueCOM);
        break;
    case VT_BOOL:
        TV_VT(ValueNative) = VTYPE_BOOL;
        TV_BOOL(ValueNative) = V_BOOL(ValueCOM);
        break;
    case VT_BSTR:
        TV_VT(ValueNative) = VTYPE_PWSTR;
        ValueNative->wstrLen = wcslen(V_BSTR(ValueCOM));
        TV_WSTR(ValueNative) = SysAllocString(V_BSTR(ValueCOM));
        //if (ValueNative->wstrLen) 
        //{
        //    TV_WSTR(ValueNative)[ValueNative->wstrLen + 1] = '\0';
        //}
        break;
    default:
        break;
    }
}

long GetClassObject(IComponentBase** pInterface, HMODULE *hmod_libname, BSTR path_to_dll, BSTR name_dll)
{
    if (!*pInterface)
    {

        long (*GetClassFunc) (const WCHAR_T*, IComponentBase**);
        *hmod_libname = LoadLibraryW(path_to_dll);
        //DWORD err3 = GetLastError();
        GetClassFunc = (long (*) (const WCHAR_T*, IComponentBase**))GetProcAddress(*hmod_libname, "GetClassObject");
        long result = GetClassFunc(name_dll, pInterface);
        return (long)*pInterface;
    }
    return 0;
}


void DestroyClassObject(IComponentBase* native_component, HMODULE* hmod_libname)
{
    if (native_component) 
    {
        long (*DestroyFunc) (IComponentBase**);
        DestroyFunc = (long (*) (IComponentBase**))GetProcAddress(*hmod_libname, "DestroyObject");
        if (DestroyFunc)
        {
            long result = DestroyFunc(&native_component);
        }
        FreeLibrary(*hmod_libname);
    }
}

// CAddInCOM
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::Init(IDispatch *pConnection)
{
    if (!pConnection)
        return E_FAIL;

    m_iConnect = pConnection;
    m_iConnect->AddRef();

    m_iConnect->QueryInterface(IID_IErrorLog, (void**)&m_iErrorLog);

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::Done()
{
    if (native_component)
    {
        native_component->Done();
        DestroyClassObject(native_component, &LIB_NATIVE);
        native_component = NULL;
        LIB_NATIVE = NULL;
    }

    if (m_iMemory)
    {
        m_iMemory = nullptr;
    }

    if (m_iConnect) 
        m_iConnect->Release();

    if (m_iErrorLog)
        m_iErrorLog->Release();

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetInfo(SAFEARRAY **pInfo)
{
    // Component should put supported component technology version 
    // in VARIANT at index 0     
    long lInd = 0;
    VARIANT varVersion;
    V_VT(&varVersion) = VT_I4;
    // This component supports 2.0 version
    V_I4(&varVersion) = 2000;
    SafeArrayPutElement(*pInfo,&lInd,&varVersion);
    
    return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
// ILanguageExtender
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::RegisterExtensionAs(BSTR *bstrExtensionName)
{
    wchar_t* csExtenderName = L"UniversalNativeWrapper";
    *bstrExtensionName = ::SysAllocString(csExtenderName);

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNProps(long *plProps)
{
    //// You may delete next lines and add your own implementation code here

    if (native_component)
        *plProps = native_component->GetNProps();
    else
        *plProps = ePropLast;

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::FindProp(BSTR bstrPropName,long *plPropNum)
{
    *plPropNum = -1;

    if (native_component) {
        *plPropNum = native_component->FindProp((const WCHAR_T*)bstrPropName);
    }
    return (*plPropNum == -1) ? S_FALSE : S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetPropName(long lPropNum,long lPropAlias,
                                    BSTR *pbstrPropName)
{
    if (native_component) {
        const WCHAR_T* name_prop = native_component->GetPropName(lPropNum, lPropAlias);
        *pbstrPropName = SysAllocString(name_prop);
        m_iMemory->FreeMemory((void**)name_prop);
        return S_OK;
    }

    return S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
    ::VariantInit(pvarPropVal);

    return S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::SetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
    //switch(lPropNum)
    //{ 
    //case ePropIsEnabled:
    //    if (V_VT(pvarPropVal) != VT_I4)
    //        return S_FALSE;
    //    m_boolEnabled = V_I4(pvarPropVal)?1:0;
    //    break;
    //case ePropIsTimerPresent:
    //default:
    //    return S_FALSE;
    //}

    return S_FALSE;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::IsPropReadable(long lPropNum,BOOL *pboolPropRead)
{
    *pboolPropRead = (BOOL)TRUE;

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::IsPropWritable(long lPropNum,BOOL *pboolPropWrite)
{
    if (native_component) {
        *pboolPropWrite = (BOOL)native_component->IsPropWritable(lPropNum);
        return S_OK;
    }

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNMethods(long *plMethods)
{
    //if (native_component)
    //    *plMethods = native_component->GetNMethods();
    //else
    //    *plMethods = 999;
    //
    //*plMethods = *plMethods + eMethLast;
    *plMethods = 999;

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::FindMethod(BSTR bstrMethodName, long *plMethodNum)
{

    *plMethodNum = -1;

    if (!wcscmp((BSTR)L"SetDriverName", bstrMethodName))
        *plMethodNum = 999;
    else if (!wcscmp((BSTR)L"”становить»м€ƒрайвера", bstrMethodName))
        *plMethodNum = 999;
    else if (native_component) 
        *plMethodNum = native_component->FindMethod(bstrMethodName);

    return (*plMethodNum == -1) ? S_FALSE : S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetMethodName(long lMethodNum,long lMethodAlias,
                                      BSTR *pbstrMethodName)
{

    CAtlString csMethodName;

    if (lMethodNum == 999)
        csMethodName = (lMethodAlias == 1) ? L'”становить»м€ƒрайвера' : L'SetDriverName';
    else if (native_component) {
        csMethodName = native_component->GetMethodName(lMethodNum, lMethodAlias);
    }
    else
        return S_FALSE;

    *pbstrMethodName = ::SysAllocString(csMethodName);

    return S_OK;
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetNParams(long lMethodNum, long *plParams)
{
    *plParams = 0;
    if (lMethodNum == 999)
        *plParams = 2;
    else if (native_component) 
        *plParams = native_component->GetNParams(lMethodNum);
    else
        return S_FALSE;

    return S_OK;

    
}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::GetParamDefValue(long lMethodNum,long lParamNum,
                                         VARIANT *pvarParamDefValue)
{
    VariantInit(pvarParamDefValue);
    if (lMethodNum == 999)
        return S_OK;
    else if (native_component) {
        tVariant* V8ParamDefValue = NULL;
        if (native_component->GetParamDefValue(lMethodNum, lParamNum, V8ParamDefValue)) 
        {
            FromNativeToCOM(V8ParamDefValue, pvarParamDefValue, m_iMemory);
            return S_OK;
        }

    }
    return S_FALSE;

}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::HasRetVal(long lMethodNum,BOOL *pboolRetValue)
{
    if (lMethodNum == 999) {
        *pboolRetValue = TRUE;
        return S_OK;
    }

    if (native_component) {
        *pboolRetValue = (BOOL)native_component->HasRetVal(lMethodNum);
        return S_OK;
    }

    return S_FALSE;

}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::CallAsProc(long lMethodNum, SAFEARRAY **paParams)
{
    if (native_component)
    {
        long nParams = native_component->GetNParams(lMethodNum);
        tVariant* paParamsNative = getVarianParams(nParams, paParams);

        if (native_component->CallAsProc(lMethodNum, paParamsNative, nParams))
        {
            for (int counter = 0; counter < nParams; counter++)
            {
                VARIANT CurrentCOMParameter = GetNParam(*paParams, (long)counter);
                FromNativeToCOM(&paParamsNative[counter], &CurrentCOMParameter, m_iMemory);
                ::SafeArrayPutElement(*paParams, (long*)&counter, &CurrentCOMParameter);
            }
        }
    }
    return S_FALSE;

}
//---------------------------------------------------------------------------//
STDMETHODIMP CAddInCOM::CallAsFunc(long lMethodNum,VARIANT *ComRetValue,
                                   SAFEARRAY **paParamsCOM)
{
    ::VariantInit(ComRetValue);
    V_VT(ComRetValue) = VT_BOOL;
    V_BOOL(ComRetValue) = FALSE;

    //USES_CONVERSION;

    if (lMethodNum == 999)
    {
        if (native_component)
            return S_FALSE;

        VARIANT path_to_dll = GetNParam(*paParamsCOM, 0);
        VARIANT name_dll = GetNParam(*paParamsCOM, 1);
        if (V_VT(&path_to_dll) == VT_BSTR && V_VT(&name_dll) == VT_BSTR)
        {
            GetClassObject(&native_component, &LIB_NATIVE, V_BSTR(&path_to_dll), V_BSTR(&name_dll));
            //delete V_BSTR(&path_to_dll);
            //delete V_BSTR(&name_dll);

            if (native_component)
            {
                if (!m_iMemory)
                    m_iMemory = new MyMemoryManager;
                native_component->setMemManager(m_iMemory);
                native_component->Init(m_iConnect);
                native_component->SetLocale(L"rus_RUS");
                V_BOOL(ComRetValue) = TRUE;
                return S_OK;
            }
        }
        return S_FALSE;   
    }
    else if (native_component)
    {
        long nParams = native_component->GetNParams(lMethodNum);
        tVariant* paParamsNative = getVarianParams(nParams, paParamsCOM);
        tVariant* NativeReturnValue = new tVariant;
        tVarInit(NativeReturnValue);
        V_VT(NativeReturnValue) = VT_EMPTY;

        if (native_component->CallAsFunc(lMethodNum, NativeReturnValue, paParamsNative, nParams))
        {
            FromNativeToCOM(NativeReturnValue, ComRetValue, m_iMemory);
            for (int counter = 0; counter < nParams; counter++)
            {
                VARIANT CurrentCOMParameter = GetNParam(*paParamsCOM, (long)counter);
                FromNativeToCOM(&paParamsNative[counter], &CurrentCOMParameter, m_iMemory);
                ::SafeArrayPutElement(*paParamsCOM, (long *)&counter, &CurrentCOMParameter);

            }
            return S_OK;
        }
        //ShowLogString(L"ѕроизошла ошибка, проверьте корректно ли установлены драйвера", ADDIN_E_VERY_IMPORTANT);
        return S_FALSE;
    }
    return S_OK;;
}

tVariant* CAddInCOM::getVarianParams(long nParams, SAFEARRAY** paParams)
{
    
    if (nParams)
    {
        tVariant* VariantParams = new tVariant[nParams];
        for (int counter = 0; counter < nParams; counter++)
        {
            VariantParams[counter] = *new tVariant;
            FromComToNative(&VariantParams[counter], &GetNParam(*paParams, (long)counter));

        }
        return VariantParams;
    }
    else
        return NULL;
}

//---------------------------------------------------------------------------//
HRESULT CAddInCOM::SetLocale(BSTR bstrLocale)
{
    return S_OK;
}
//---------------------------------------------------------------------------//

VARIANT CAddInCOM::GetNParam(SAFEARRAY* pArray, long lIndex)
{
    _ASSERT(pArray);
    _ASSERT(pArray->fFeatures | FADF_VARIANT);

    VARIANT vt;
    HRESULT hRes = ::SafeArrayGetElement(pArray, &lIndex, &vt);
    _ASSERT(hRes == S_OK);

    return vt;
}

void CAddInCOM::ShowLogString(BSTR log_string, int MessageType) 
{
    if (m_iErrorLog)
    {
        CAtlString csNull = L"";
        EXCEPINFO eiInfo;
        eiInfo.wCode = ADDIN_E_VERY_IMPORTANT;
        eiInfo.scode = S_OK;
        eiInfo.bstrSource = L"UniversalNativeWrapper";
        eiInfo.bstrDescription = (BSTR) log_string;
        m_iErrorLog->AddError(csNull.AllocSysString(), &eiInfo);
        ::SysFreeString(eiInfo.bstrSource);
        ::SysFreeString(eiInfo.bstrDescription);
    }
}
