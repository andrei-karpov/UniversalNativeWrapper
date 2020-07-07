

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Jul 06 23:54:56 2020
 */
/* Compiler settings for AddIn.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AddIn_i_h__
#define __AddIn_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInitDone_FWD_DEFINED__
#define __IInitDone_FWD_DEFINED__
typedef interface IInitDone IInitDone;
#endif 	/* __IInitDone_FWD_DEFINED__ */


#ifndef __IPropertyProfile_FWD_DEFINED__
#define __IPropertyProfile_FWD_DEFINED__
typedef interface IPropertyProfile IPropertyProfile;
#endif 	/* __IPropertyProfile_FWD_DEFINED__ */


#ifndef __IAsyncEvent_FWD_DEFINED__
#define __IAsyncEvent_FWD_DEFINED__
typedef interface IAsyncEvent IAsyncEvent;
#endif 	/* __IAsyncEvent_FWD_DEFINED__ */


#ifndef __ILocale_FWD_DEFINED__
#define __ILocale_FWD_DEFINED__
typedef interface ILocale ILocale;
#endif 	/* __ILocale_FWD_DEFINED__ */


#ifndef __ILanguageExtender_FWD_DEFINED__
#define __ILanguageExtender_FWD_DEFINED__
typedef interface ILanguageExtender ILanguageExtender;
#endif 	/* __ILanguageExtender_FWD_DEFINED__ */


#ifndef __IStatusLine_FWD_DEFINED__
#define __IStatusLine_FWD_DEFINED__
typedef interface IStatusLine IStatusLine;
#endif 	/* __IStatusLine_FWD_DEFINED__ */


#ifndef __IExtWndsSupport_FWD_DEFINED__
#define __IExtWndsSupport_FWD_DEFINED__
typedef interface IExtWndsSupport IExtWndsSupport;
#endif 	/* __IExtWndsSupport_FWD_DEFINED__ */


#ifndef __IMsgBox_FWD_DEFINED__
#define __IMsgBox_FWD_DEFINED__
typedef interface IMsgBox IMsgBox;
#endif 	/* __IMsgBox_FWD_DEFINED__ */


#ifndef __IPlatformInfo_FWD_DEFINED__
#define __IPlatformInfo_FWD_DEFINED__
typedef interface IPlatformInfo IPlatformInfo;
#endif 	/* __IPlatformInfo_FWD_DEFINED__ */


#ifndef __IPropertyLink_FWD_DEFINED__
#define __IPropertyLink_FWD_DEFINED__
typedef interface IPropertyLink IPropertyLink;
#endif 	/* __IPropertyLink_FWD_DEFINED__ */


#ifndef __IAddInCOM_FWD_DEFINED__
#define __IAddInCOM_FWD_DEFINED__
typedef interface IAddInCOM IAddInCOM;
#endif 	/* __IAddInCOM_FWD_DEFINED__ */


#ifndef __AddInCOM_FWD_DEFINED__
#define __AddInCOM_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddInCOM AddInCOM;
#else
typedef struct AddInCOM AddInCOM;
#endif /* __cplusplus */

#endif 	/* __AddInCOM_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IInitDone_INTERFACE_DEFINED__
#define __IInitDone_INTERFACE_DEFINED__

/* interface IInitDone */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInitDone;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634001-F13D-11d0-A459-004095E1DAEA")
    IInitDone : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IDispatch *pConnection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Done( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [out][in] */ SAFEARRAY * *pInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInitDoneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInitDone * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInitDone * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInitDone * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IInitDone * This,
            /* [in] */ IDispatch *pConnection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Done )( 
            IInitDone * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            IInitDone * This,
            /* [out][in] */ SAFEARRAY * *pInfo);
        
        END_INTERFACE
    } IInitDoneVtbl;

    interface IInitDone
    {
        CONST_VTBL struct IInitDoneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInitDone_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInitDone_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInitDone_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInitDone_Init(This,pConnection)	\
    ( (This)->lpVtbl -> Init(This,pConnection) ) 

#define IInitDone_Done(This)	\
    ( (This)->lpVtbl -> Done(This) ) 

#define IInitDone_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInitDone_INTERFACE_DEFINED__ */


#ifndef __IPropertyProfile_INTERFACE_DEFINED__
#define __IPropertyProfile_INTERFACE_DEFINED__

/* interface IPropertyProfile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPropertyProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634002-F13D-11d0-A459-004095E1DAEA")
    IPropertyProfile : public IPropertyBag
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterProfileAs( 
            BSTR bstrProfileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyProfileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropertyProfile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropertyProfile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropertyProfile * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IPropertyProfile * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT *pVar,
            /* [unique][in] */ IErrorLog *pErrorLog);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IPropertyProfile * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT *pVar);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterProfileAs )( 
            IPropertyProfile * This,
            BSTR bstrProfileName);
        
        END_INTERFACE
    } IPropertyProfileVtbl;

    interface IPropertyProfile
    {
        CONST_VTBL struct IPropertyProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyProfile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyProfile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyProfile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyProfile_Read(This,pszPropName,pVar,pErrorLog)	\
    ( (This)->lpVtbl -> Read(This,pszPropName,pVar,pErrorLog) ) 

#define IPropertyProfile_Write(This,pszPropName,pVar)	\
    ( (This)->lpVtbl -> Write(This,pszPropName,pVar) ) 


#define IPropertyProfile_RegisterProfileAs(This,bstrProfileName)	\
    ( (This)->lpVtbl -> RegisterProfileAs(This,bstrProfileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyProfile_INTERFACE_DEFINED__ */


#ifndef __IAsyncEvent_INTERFACE_DEFINED__
#define __IAsyncEvent_INTERFACE_DEFINED__

/* interface IAsyncEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsyncEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab634004-f13d-11d0-a459-004095e1daea")
    IAsyncEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventBufferDepth( 
            long lDepth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventBufferDepth( 
            long *plDepth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExternalEvent( 
            BSTR bstrSource,
            BSTR bstrMessage,
            BSTR bstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CleanBuffer( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAsyncEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncEvent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncEvent * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventBufferDepth )( 
            IAsyncEvent * This,
            long lDepth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventBufferDepth )( 
            IAsyncEvent * This,
            long *plDepth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExternalEvent )( 
            IAsyncEvent * This,
            BSTR bstrSource,
            BSTR bstrMessage,
            BSTR bstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CleanBuffer )( 
            IAsyncEvent * This);
        
        END_INTERFACE
    } IAsyncEventVtbl;

    interface IAsyncEvent
    {
        CONST_VTBL struct IAsyncEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsyncEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsyncEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsyncEvent_SetEventBufferDepth(This,lDepth)	\
    ( (This)->lpVtbl -> SetEventBufferDepth(This,lDepth) ) 

#define IAsyncEvent_GetEventBufferDepth(This,plDepth)	\
    ( (This)->lpVtbl -> GetEventBufferDepth(This,plDepth) ) 

#define IAsyncEvent_ExternalEvent(This,bstrSource,bstrMessage,bstrData)	\
    ( (This)->lpVtbl -> ExternalEvent(This,bstrSource,bstrMessage,bstrData) ) 

#define IAsyncEvent_CleanBuffer(This)	\
    ( (This)->lpVtbl -> CleanBuffer(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsyncEvent_INTERFACE_DEFINED__ */


#ifndef __ILocale_INTERFACE_DEFINED__
#define __ILocale_INTERFACE_DEFINED__

/* interface ILocale */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILocale;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E88A191E-8F52-4261-9FAE-FF7AA84F5D7E")
    ILocale : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLocale( 
            BSTR bstrLocale) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILocaleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILocale * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILocale * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILocale * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLocale )( 
            ILocale * This,
            BSTR bstrLocale);
        
        END_INTERFACE
    } ILocaleVtbl;

    interface ILocale
    {
        CONST_VTBL struct ILocaleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILocale_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILocale_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILocale_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILocale_SetLocale(This,bstrLocale)	\
    ( (This)->lpVtbl -> SetLocale(This,bstrLocale) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILocale_INTERFACE_DEFINED__ */


#ifndef __ILanguageExtender_INTERFACE_DEFINED__
#define __ILanguageExtender_INTERFACE_DEFINED__

/* interface ILanguageExtender */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILanguageExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634003-F13D-11d0-A459-004095E1DAEA")
    ILanguageExtender : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterExtensionAs( 
            /* [out][in] */ BSTR *bstrExtensionName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNProps( 
            /* [out][in] */ long *plProps) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindProp( 
            /* [in] */ BSTR bstrPropName,
            /* [out][in] */ long *plPropNum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropName( 
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
            /* [out][in] */ BSTR *pbstrPropName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropVal( 
            /* [in] */ long lPropNum,
            /* [out][in] */ VARIANT *pvarPropVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPropVal( 
            /* [in] */ long lPropNum,
            /* [in] */ VARIANT *varPropVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropReadable( 
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropRead) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropWritable( 
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropWrite) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNMethods( 
            /* [out][in] */ long *plMethods) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindMethod( 
            BSTR bstrMethodName,
            /* [out][in] */ long *plMethodNum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMethodName( 
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
            /* [out][in] */ BSTR *pbstrMethodName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNParams( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ long *plParams) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParamDefValue( 
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
            /* [out][in] */ VARIANT *pvarParamDefValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE HasRetVal( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ BOOL *pboolRetValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CallAsProc( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ SAFEARRAY * *paParams) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CallAsFunc( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ VARIANT *pvarRetValue,
            /* [out][in] */ SAFEARRAY * *paParams) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILanguageExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILanguageExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILanguageExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILanguageExtender * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterExtensionAs )( 
            ILanguageExtender * This,
            /* [out][in] */ BSTR *bstrExtensionName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNProps )( 
            ILanguageExtender * This,
            /* [out][in] */ long *plProps);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindProp )( 
            ILanguageExtender * This,
            /* [in] */ BSTR bstrPropName,
            /* [out][in] */ long *plPropNum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropName )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
            /* [out][in] */ BSTR *pbstrPropName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropVal )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ VARIANT *pvarPropVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPropVal )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [in] */ VARIANT *varPropVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropReadable )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropRead);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropWritable )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropWrite);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNMethods )( 
            ILanguageExtender * This,
            /* [out][in] */ long *plMethods);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindMethod )( 
            ILanguageExtender * This,
            BSTR bstrMethodName,
            /* [out][in] */ long *plMethodNum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethodName )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
            /* [out][in] */ BSTR *pbstrMethodName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNParams )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ long *plParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetParamDefValue )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
            /* [out][in] */ VARIANT *pvarParamDefValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HasRetVal )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ BOOL *pboolRetValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CallAsProc )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ SAFEARRAY * *paParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CallAsFunc )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ VARIANT *pvarRetValue,
            /* [out][in] */ SAFEARRAY * *paParams);
        
        END_INTERFACE
    } ILanguageExtenderVtbl;

    interface ILanguageExtender
    {
        CONST_VTBL struct ILanguageExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILanguageExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILanguageExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILanguageExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILanguageExtender_RegisterExtensionAs(This,bstrExtensionName)	\
    ( (This)->lpVtbl -> RegisterExtensionAs(This,bstrExtensionName) ) 

#define ILanguageExtender_GetNProps(This,plProps)	\
    ( (This)->lpVtbl -> GetNProps(This,plProps) ) 

#define ILanguageExtender_FindProp(This,bstrPropName,plPropNum)	\
    ( (This)->lpVtbl -> FindProp(This,bstrPropName,plPropNum) ) 

#define ILanguageExtender_GetPropName(This,lPropNum,lPropAlias,pbstrPropName)	\
    ( (This)->lpVtbl -> GetPropName(This,lPropNum,lPropAlias,pbstrPropName) ) 

#define ILanguageExtender_GetPropVal(This,lPropNum,pvarPropVal)	\
    ( (This)->lpVtbl -> GetPropVal(This,lPropNum,pvarPropVal) ) 

#define ILanguageExtender_SetPropVal(This,lPropNum,varPropVal)	\
    ( (This)->lpVtbl -> SetPropVal(This,lPropNum,varPropVal) ) 

#define ILanguageExtender_IsPropReadable(This,lPropNum,pboolPropRead)	\
    ( (This)->lpVtbl -> IsPropReadable(This,lPropNum,pboolPropRead) ) 

#define ILanguageExtender_IsPropWritable(This,lPropNum,pboolPropWrite)	\
    ( (This)->lpVtbl -> IsPropWritable(This,lPropNum,pboolPropWrite) ) 

#define ILanguageExtender_GetNMethods(This,plMethods)	\
    ( (This)->lpVtbl -> GetNMethods(This,plMethods) ) 

#define ILanguageExtender_FindMethod(This,bstrMethodName,plMethodNum)	\
    ( (This)->lpVtbl -> FindMethod(This,bstrMethodName,plMethodNum) ) 

#define ILanguageExtender_GetMethodName(This,lMethodNum,lMethodAlias,pbstrMethodName)	\
    ( (This)->lpVtbl -> GetMethodName(This,lMethodNum,lMethodAlias,pbstrMethodName) ) 

#define ILanguageExtender_GetNParams(This,lMethodNum,plParams)	\
    ( (This)->lpVtbl -> GetNParams(This,lMethodNum,plParams) ) 

#define ILanguageExtender_GetParamDefValue(This,lMethodNum,lParamNum,pvarParamDefValue)	\
    ( (This)->lpVtbl -> GetParamDefValue(This,lMethodNum,lParamNum,pvarParamDefValue) ) 

#define ILanguageExtender_HasRetVal(This,lMethodNum,pboolRetValue)	\
    ( (This)->lpVtbl -> HasRetVal(This,lMethodNum,pboolRetValue) ) 

#define ILanguageExtender_CallAsProc(This,lMethodNum,paParams)	\
    ( (This)->lpVtbl -> CallAsProc(This,lMethodNum,paParams) ) 

#define ILanguageExtender_CallAsFunc(This,lMethodNum,pvarRetValue,paParams)	\
    ( (This)->lpVtbl -> CallAsFunc(This,lMethodNum,pvarRetValue,paParams) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILanguageExtender_INTERFACE_DEFINED__ */


#ifndef __IStatusLine_INTERFACE_DEFINED__
#define __IStatusLine_INTERFACE_DEFINED__

/* interface IStatusLine */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStatusLine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab634005-f13d-11d0-a459-004095e1daea")
    IStatusLine : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatusLine( 
            BSTR bstrStatusLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetStatusLine( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStatusLineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStatusLine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStatusLine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStatusLine * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatusLine )( 
            IStatusLine * This,
            BSTR bstrStatusLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetStatusLine )( 
            IStatusLine * This);
        
        END_INTERFACE
    } IStatusLineVtbl;

    interface IStatusLine
    {
        CONST_VTBL struct IStatusLineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStatusLine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStatusLine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStatusLine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStatusLine_SetStatusLine(This,bstrStatusLine)	\
    ( (This)->lpVtbl -> SetStatusLine(This,bstrStatusLine) ) 

#define IStatusLine_ResetStatusLine(This)	\
    ( (This)->lpVtbl -> ResetStatusLine(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStatusLine_INTERFACE_DEFINED__ */


#ifndef __IExtWndsSupport_INTERFACE_DEFINED__
#define __IExtWndsSupport_INTERFACE_DEFINED__

/* interface IExtWndsSupport */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IExtWndsSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("efe19ea0-09e4-11d2-a601-008048da00de")
    IExtWndsSupport : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAppMainFrame( 
            /* [out][in] */ HWND *hwnd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAppMDIFrame( 
            /* [out][in] */ HWND *hwnd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateAddInWindow( 
            /* [in] */ BSTR bstrProgID,
            /* [in] */ BSTR bstrWindowName,
            /* [in] */ long dwStyles,
            /* [in] */ long dwExStyles,
            /* [in] */ RECT *rctl,
            /* [in] */ long Flags,
            /* [out][in] */ HWND *pHwnd,
            /* [out][in] */ IDispatch **pDisp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtWndsSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExtWndsSupport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExtWndsSupport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExtWndsSupport * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAppMainFrame )( 
            IExtWndsSupport * This,
            /* [out][in] */ HWND *hwnd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAppMDIFrame )( 
            IExtWndsSupport * This,
            /* [out][in] */ HWND *hwnd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateAddInWindow )( 
            IExtWndsSupport * This,
            /* [in] */ BSTR bstrProgID,
            /* [in] */ BSTR bstrWindowName,
            /* [in] */ long dwStyles,
            /* [in] */ long dwExStyles,
            /* [in] */ RECT *rctl,
            /* [in] */ long Flags,
            /* [out][in] */ HWND *pHwnd,
            /* [out][in] */ IDispatch **pDisp);
        
        END_INTERFACE
    } IExtWndsSupportVtbl;

    interface IExtWndsSupport
    {
        CONST_VTBL struct IExtWndsSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtWndsSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExtWndsSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExtWndsSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExtWndsSupport_GetAppMainFrame(This,hwnd)	\
    ( (This)->lpVtbl -> GetAppMainFrame(This,hwnd) ) 

#define IExtWndsSupport_GetAppMDIFrame(This,hwnd)	\
    ( (This)->lpVtbl -> GetAppMDIFrame(This,hwnd) ) 

#define IExtWndsSupport_CreateAddInWindow(This,bstrProgID,bstrWindowName,dwStyles,dwExStyles,rctl,Flags,pHwnd,pDisp)	\
    ( (This)->lpVtbl -> CreateAddInWindow(This,bstrProgID,bstrWindowName,dwStyles,dwExStyles,rctl,Flags,pHwnd,pDisp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExtWndsSupport_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_AddIn_0000_0007 */
/* [local] */ 

typedef enum
{
    eAQDModeOK,
    eAQDModeOKCancel,
    eAQDModeAbortRetryIgnore,
    eAQDModeYesNoCancel,
    eAQDModeYesNo,
    eAQDModeRetryCancel,
} AddInQuestionDialogModeEnum;
typedef enum 
{
    eADlgRetCodeTimeout = -1,
    eADlgRetCodeOK = 1,
    eADlgRetCodeCancel,
    eADlgRetCodeAbort,
    eADlgRetCodeRetry,
    eADlgRetCodeIgnore,
    eADlgRetCodeYes,
    eADlgRetCodeNo,
} AddInDlgRetCodesEnum;
typedef struct _Button
    {
    VARIANT value;
    BSTR presentation;
    } 	Button;



extern RPC_IF_HANDLE __MIDL_itf_AddIn_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AddIn_0000_0007_v0_0_s_ifspec;

#ifndef __IMsgBox_INTERFACE_DEFINED__
#define __IMsgBox_INTERFACE_DEFINED__

/* interface IMsgBox */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMsgBox;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C2136B5-B35A-4FAC-9AC3-F77F361E9467")
    IMsgBox : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryBox( 
            /* [in] */ BSTR queryText,
            /* [in] */ Button *buttons,
            /* [in] */ UINT sizeButtons,
            /* [out][in] */ VARIANT *retVal,
            /* [defaultvalue][in] */ ULONG timeout = 0,
            /* [defaultvalue][in] */ UINT defButton = 0,
            /* [defaultvalue][in] */ BSTR caption = 0,
            /* [defaultvalue][in] */ UINT timeoutButton = 0) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MessageBox( 
            /* [in] */ BSTR text,
            /* [out][in] */ VARIANT *retVal,
            /* [defaultvalue][in] */ ULONG timeout = 0,
            /* [defaultvalue][in] */ BSTR caption = 0) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMsgBoxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMsgBox * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMsgBox * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMsgBox * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryBox )( 
            IMsgBox * This,
            /* [in] */ BSTR queryText,
            /* [in] */ Button *buttons,
            /* [in] */ UINT sizeButtons,
            /* [out][in] */ VARIANT *retVal,
            /* [defaultvalue][in] */ ULONG timeout,
            /* [defaultvalue][in] */ UINT defButton,
            /* [defaultvalue][in] */ BSTR caption,
            /* [defaultvalue][in] */ UINT timeoutButton);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MessageBox )( 
            IMsgBox * This,
            /* [in] */ BSTR text,
            /* [out][in] */ VARIANT *retVal,
            /* [defaultvalue][in] */ ULONG timeout,
            /* [defaultvalue][in] */ BSTR caption);
        
        END_INTERFACE
    } IMsgBoxVtbl;

    interface IMsgBox
    {
        CONST_VTBL struct IMsgBoxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMsgBox_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMsgBox_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMsgBox_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMsgBox_QueryBox(This,queryText,buttons,sizeButtons,retVal,timeout,defButton,caption,timeoutButton)	\
    ( (This)->lpVtbl -> QueryBox(This,queryText,buttons,sizeButtons,retVal,timeout,defButton,caption,timeoutButton) ) 

#define IMsgBox_MessageBox(This,text,retVal,timeout,caption)	\
    ( (This)->lpVtbl -> MessageBox(This,text,retVal,timeout,caption) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMsgBox_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_AddIn_0000_0008 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum _AppType
    {	eAppUnknown	= -1,
	eAppThinClient	= 0,
	eAppThickClient	= ( eAppThinClient + 1 ) ,
	eAppWebClient	= ( eAppThickClient + 1 ) ,
	eAppServer	= ( eAppWebClient + 1 ) ,
	eAppExtConn	= ( eAppServer + 1 ) 
    } 	AppType;

typedef struct _AppInfo
    {
    BSTR AppVersion;
    BSTR UserAgentInformation;
    const AppType Application;
    } 	AppInfo;



extern RPC_IF_HANDLE __MIDL_itf_AddIn_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AddIn_0000_0008_v0_0_s_ifspec;

#ifndef __IPlatformInfo_INTERFACE_DEFINED__
#define __IPlatformInfo_INTERFACE_DEFINED__

/* interface IPlatformInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPlatformInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAABE126-2230-4a7d-9DDA-8987FD2A62BA")
    IPlatformInfo : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPlatformInfo( 
            /* [retval][out] */ AppInfo **info) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlatformInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlatformInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlatformInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlatformInfo * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPlatformInfo )( 
            IPlatformInfo * This,
            /* [retval][out] */ AppInfo **info);
        
        END_INTERFACE
    } IPlatformInfoVtbl;

    interface IPlatformInfo
    {
        CONST_VTBL struct IPlatformInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlatformInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPlatformInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPlatformInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPlatformInfo_GetPlatformInfo(This,info)	\
    ( (This)->lpVtbl -> GetPlatformInfo(This,info) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPlatformInfo_INTERFACE_DEFINED__ */


#ifndef __IPropertyLink_INTERFACE_DEFINED__
#define __IPropertyLink_INTERFACE_DEFINED__

/* interface IPropertyLink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPropertyLink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52512A61-2A9D-11d1-A4D6-004095E1DAEA")
    IPropertyLink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            BOOL *boolEnabled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            BOOL boolEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyLinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropertyLink * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropertyLink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropertyLink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IPropertyLink * This,
            BOOL *boolEnabled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IPropertyLink * This,
            BOOL boolEnabled);
        
        END_INTERFACE
    } IPropertyLinkVtbl;

    interface IPropertyLink
    {
        CONST_VTBL struct IPropertyLinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyLink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyLink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyLink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyLink_get_Enabled(This,boolEnabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,boolEnabled) ) 

#define IPropertyLink_put_Enabled(This,boolEnabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,boolEnabled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyLink_INTERFACE_DEFINED__ */


#ifndef __IAddInCOM_INTERFACE_DEFINED__
#define __IAddInCOM_INTERFACE_DEFINED__

/* interface IAddInCOM */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAddInCOM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D0DAA417-4643-4BBD-B8F6-78C2B20F2863")
    IAddInCOM : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAddInCOMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddInCOM * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddInCOM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddInCOM * This);
        
        END_INTERFACE
    } IAddInCOMVtbl;

    interface IAddInCOM
    {
        CONST_VTBL struct IAddInCOMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddInCOM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAddInCOM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAddInCOM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAddInCOM_INTERFACE_DEFINED__ */



#ifndef __AddInLib_LIBRARY_DEFINED__
#define __AddInLib_LIBRARY_DEFINED__

/* library AddInLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AddInLib;

EXTERN_C const CLSID CLSID_AddInCOM;

#ifdef __cplusplus

class DECLSPEC_UUID("A4A0B0A1-9D70-4175-8935-2943DD94AF58")
AddInCOM;
#endif
#endif /* __AddInLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


