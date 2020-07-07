

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IInitDone,0xAB634001,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IPropertyProfile,0xAB634002,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAsyncEvent,0xab634004,0xf13d,0x11d0,0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea);


MIDL_DEFINE_GUID(IID, IID_ILocale,0xE88A191E,0x8F52,0x4261,0x9F,0xAE,0xFF,0x7A,0xA8,0x4F,0x5D,0x7E);


MIDL_DEFINE_GUID(IID, IID_ILanguageExtender,0xAB634003,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IStatusLine,0xab634005,0xf13d,0x11d0,0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea);


MIDL_DEFINE_GUID(IID, IID_IExtWndsSupport,0xefe19ea0,0x09e4,0x11d2,0xa6,0x01,0x00,0x80,0x48,0xda,0x00,0xde);


MIDL_DEFINE_GUID(IID, IID_IMsgBox,0x3C2136B5,0xB35A,0x4FAC,0x9A,0xC3,0xF7,0x7F,0x36,0x1E,0x94,0x67);


MIDL_DEFINE_GUID(IID, IID_IPlatformInfo,0xAAABE126,0x2230,0x4a7d,0x9D,0xDA,0x89,0x87,0xFD,0x2A,0x62,0xBA);


MIDL_DEFINE_GUID(IID, IID_IPropertyLink,0x52512A61,0x2A9D,0x11d1,0xA4,0xD6,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAddInCOM,0xD0DAA417,0x4643,0x4BBD,0xB8,0xF6,0x78,0xC2,0xB2,0x0F,0x28,0x63);


MIDL_DEFINE_GUID(IID, LIBID_AddInLib,0x854E9F5E,0xC698,0x4D33,0x92,0x57,0x86,0x3F,0x94,0xE7,0x31,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AddInCOM,0xA4A0B0A1,0x9D70,0x4175,0x89,0x35,0x29,0x43,0xDD,0x94,0xAF,0x58);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



