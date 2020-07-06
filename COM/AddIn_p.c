

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Jul 06 19:47:48 2020
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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "AddIn_i.h"

#define TYPE_FORMAT_STRING_SIZE   1223                              
#define PROC_FORMAT_STRING_SIZE   1393                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   4            

typedef struct _AddIn_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } AddIn_MIDL_TYPE_FORMAT_STRING;

typedef struct _AddIn_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } AddIn_MIDL_PROC_FORMAT_STRING;

typedef struct _AddIn_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } AddIn_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const AddIn_MIDL_TYPE_FORMAT_STRING AddIn__MIDL_TypeFormatString;
extern const AddIn_MIDL_PROC_FORMAT_STRING AddIn__MIDL_ProcFormatString;
extern const AddIn_MIDL_EXPR_FORMAT_STRING AddIn__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IInitDone_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IInitDone_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPropertyProfile_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPropertyProfile_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAsyncEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAsyncEvent_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILocale_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILocale_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILanguageExtender_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILanguageExtender_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStatusLine_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStatusLine_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IExtWndsSupport_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IExtWndsSupport_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMsgBox_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMsgBox_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPlatformInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPlatformInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPropertyLink_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPropertyLink_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAddInCOM_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAddInCOM_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const AddIn_MIDL_PROC_FORMAT_STRING AddIn__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Init */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConnection */

/* 24 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetStatusLine */


	/* Procedure Done */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetInfo */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x5 ),	/* 5 */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 84 */	NdrFcShort( 0x1 ),	/* 1 */
/* 86 */	NdrFcShort( 0x1 ),	/* 1 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 90 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x410 ),	/* Type Offset=1040 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterProfileAs */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x5 ),	/* 5 */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 118 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x1 ),	/* 1 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrProfileName */

/* 126 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventBufferDepth */

/* 138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x3 ),	/* 3 */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 154 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lDepth */

/* 162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEventBufferDepth */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x4 ),	/* 4 */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	NdrFcShort( 0x1c ),	/* 28 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 190 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plDepth */

/* 198 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExternalEvent */

/* 210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x5 ),	/* 5 */
/* 218 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 224 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 226 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x1 ),	/* 1 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrSource */

/* 234 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 238 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter bstrMessage */

/* 240 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 244 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter bstrData */

/* 246 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 250 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CleanBuffer */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x6 ),	/* 6 */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStatusLine */


	/* Procedure SetLocale */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x3 ),	/* 3 */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x1 ),	/* 1 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrStatusLine */


	/* Parameter bstrLocale */

/* 312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */


	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterExtensionAs */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x3 ),	/* 3 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 342 */	NdrFcShort( 0x1 ),	/* 1 */
/* 344 */	NdrFcShort( 0x1 ),	/* 1 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrExtensionName */

/* 348 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNProps */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x4 ),	/* 4 */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x1c ),	/* 28 */
/* 372 */	NdrFcShort( 0x24 ),	/* 36 */
/* 374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plProps */

/* 384 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindProp */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x5 ),	/* 5 */
/* 404 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 406 */	NdrFcShort( 0x1c ),	/* 28 */
/* 408 */	NdrFcShort( 0x24 ),	/* 36 */
/* 410 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 412 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x1 ),	/* 1 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPropName */

/* 420 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter plPropNum */

/* 426 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPropName */

/* 438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x6 ),	/* 6 */
/* 446 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 448 */	NdrFcShort( 0x10 ),	/* 16 */
/* 450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 452 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 454 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 456 */	NdrFcShort( 0x1 ),	/* 1 */
/* 458 */	NdrFcShort( 0x1 ),	/* 1 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lPropNum */

/* 462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lPropAlias */

/* 468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrPropName */

/* 474 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPropVal */

/* 486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x7 ),	/* 7 */
/* 494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 500 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 502 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 506 */	NdrFcShort( 0x1 ),	/* 1 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lPropNum */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvarPropVal */

/* 516 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 520 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Return value */

/* 522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPropVal */

/* 528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 542 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 544 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lPropNum */

/* 552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varPropVal */

/* 558 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	NdrFcShort( 0x454 ),	/* Type Offset=1108 */

	/* Return value */

/* 564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsPropReadable */

/* 570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x9 ),	/* 9 */
/* 578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 580 */	NdrFcShort( 0x24 ),	/* 36 */
/* 582 */	NdrFcShort( 0x24 ),	/* 36 */
/* 584 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 586 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lPropNum */

/* 594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pboolPropRead */

/* 600 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsPropWritable */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0xa ),	/* 10 */
/* 620 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 622 */	NdrFcShort( 0x24 ),	/* 36 */
/* 624 */	NdrFcShort( 0x24 ),	/* 36 */
/* 626 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 628 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lPropNum */

/* 636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pboolPropWrite */

/* 642 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNMethods */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0xb ),	/* 11 */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x1c ),	/* 28 */
/* 666 */	NdrFcShort( 0x24 ),	/* 36 */
/* 668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plMethods */

/* 678 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindMethod */

/* 690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0xc ),	/* 12 */
/* 698 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 700 */	NdrFcShort( 0x1c ),	/* 28 */
/* 702 */	NdrFcShort( 0x24 ),	/* 36 */
/* 704 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 706 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x1 ),	/* 1 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrMethodName */

/* 714 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter plMethodNum */

/* 720 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMethodName */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0xd ),	/* 13 */
/* 740 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 742 */	NdrFcShort( 0x10 ),	/* 16 */
/* 744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 746 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 748 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 750 */	NdrFcShort( 0x1 ),	/* 1 */
/* 752 */	NdrFcShort( 0x1 ),	/* 1 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lMethodAlias */

/* 762 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrMethodName */

/* 768 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 772 */	NdrFcShort( 0x430 ),	/* Type Offset=1072 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNParams */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0xe ),	/* 14 */
/* 788 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 790 */	NdrFcShort( 0x24 ),	/* 36 */
/* 792 */	NdrFcShort( 0x24 ),	/* 36 */
/* 794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 796 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter plParams */

/* 810 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParamDefValue */

/* 822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0xf ),	/* 15 */
/* 830 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 832 */	NdrFcShort( 0x10 ),	/* 16 */
/* 834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 836 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 838 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 840 */	NdrFcShort( 0x1 ),	/* 1 */
/* 842 */	NdrFcShort( 0x1 ),	/* 1 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lParamNum */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvarParamDefValue */

/* 858 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 862 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Return value */

/* 864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 866 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasRetVal */

/* 870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x10 ),	/* 16 */
/* 878 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 880 */	NdrFcShort( 0x24 ),	/* 36 */
/* 882 */	NdrFcShort( 0x24 ),	/* 36 */
/* 884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 886 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pboolRetValue */

/* 900 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CallAsProc */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x11 ),	/* 17 */
/* 920 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 928 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 930 */	NdrFcShort( 0x1 ),	/* 1 */
/* 932 */	NdrFcShort( 0x1 ),	/* 1 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter paParams */

/* 942 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 946 */	NdrFcShort( 0x410 ),	/* Type Offset=1040 */

	/* Return value */

/* 948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CallAsFunc */

/* 954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x12 ),	/* 18 */
/* 962 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 970 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 972 */	NdrFcShort( 0x1 ),	/* 1 */
/* 974 */	NdrFcShort( 0x1 ),	/* 1 */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lMethodNum */

/* 978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvarRetValue */

/* 984 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 988 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Parameter paParams */

/* 990 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 994 */	NdrFcShort( 0x410 ),	/* Type Offset=1040 */

	/* Return value */

/* 996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 998 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAppMainFrame */

/* 1002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1018 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1022 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwnd */

/* 1026 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1030 */	NdrFcShort( 0x47a ),	/* Type Offset=1146 */

	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAppMDIFrame */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1054 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hwnd */

/* 1062 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	NdrFcShort( 0x47a ),	/* Type Offset=1146 */

	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateAddInWindow */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1082 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1084 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 1090 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrProgID */

/* 1098 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1102 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter bstrWindowName */

/* 1104 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter dwStyles */

/* 1110 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1112 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwExStyles */

/* 1116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1118 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rctl */

/* 1122 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1124 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1126 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */

	/* Parameter Flags */

/* 1128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1130 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHwnd */

/* 1134 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1136 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1138 */	NdrFcShort( 0x47a ),	/* Type Offset=1146 */

	/* Parameter pDisp */

/* 1140 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1142 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1144 */	NdrFcShort( 0x492 ),	/* Type Offset=1170 */

	/* Return value */

/* 1146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1148 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryBox */

/* 1152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1160 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1162 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1166 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 1168 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1172 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter queryText */

/* 1176 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1178 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1180 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter buttons */

/* 1182 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1184 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1186 */	NdrFcShort( 0x49a ),	/* Type Offset=1178 */

	/* Parameter sizeButtons */

/* 1188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 1194 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1196 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1198 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Parameter timeout */

/* 1200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1202 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter defButton */

/* 1206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1208 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter caption */

/* 1212 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1214 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1216 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter timeoutButton */

/* 1218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1220 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1226 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MessageBox */

/* 1230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1238 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1244 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1246 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1248 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1250 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter text */

/* 1254 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1258 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter retVal */

/* 1260 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1264 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Parameter timeout */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter caption */

/* 1272 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1276 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPlatformInfo */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1302 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter info */

/* 1308 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	NdrFcShort( 0x4ac ),	/* Type Offset=1196 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Enabled */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter boolEnabled */

/* 1344 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Enabled */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1364 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1372 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter boolEnabled */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const AddIn_MIDL_TYPE_FORMAT_STRING AddIn__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0x20400 ),	/* 132096 */
/*  8 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 20 */	
			0x11, 0x0,	/* FC_RP */
/* 22 */	NdrFcShort( 0x3fa ),	/* Offset= 1018 (1040) */
/* 24 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x13, 0x0,	/* FC_OP */
/* 30 */	NdrFcShort( 0x3e0 ),	/* Offset= 992 (1022) */
/* 32 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 34 */	NdrFcShort( 0x18 ),	/* 24 */
/* 36 */	NdrFcShort( 0xa ),	/* 10 */
/* 38 */	NdrFcLong( 0x8 ),	/* 8 */
/* 42 */	NdrFcShort( 0x70 ),	/* Offset= 112 (154) */
/* 44 */	NdrFcLong( 0xd ),	/* 13 */
/* 48 */	NdrFcShort( 0xa6 ),	/* Offset= 166 (214) */
/* 50 */	NdrFcLong( 0x9 ),	/* 9 */
/* 54 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (252) */
/* 56 */	NdrFcLong( 0xc ),	/* 12 */
/* 60 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (768) */
/* 62 */	NdrFcLong( 0x24 ),	/* 36 */
/* 66 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (816) */
/* 68 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 72 */	NdrFcShort( 0x30a ),	/* Offset= 778 (850) */
/* 74 */	NdrFcLong( 0x10 ),	/* 16 */
/* 78 */	NdrFcShort( 0x324 ),	/* Offset= 804 (882) */
/* 80 */	NdrFcLong( 0x2 ),	/* 2 */
/* 84 */	NdrFcShort( 0x33e ),	/* Offset= 830 (914) */
/* 86 */	NdrFcLong( 0x3 ),	/* 3 */
/* 90 */	NdrFcShort( 0x358 ),	/* Offset= 856 (946) */
/* 92 */	NdrFcLong( 0x14 ),	/* 20 */
/* 96 */	NdrFcShort( 0x372 ),	/* Offset= 882 (978) */
/* 98 */	NdrFcShort( 0xffff ),	/* Offset= -1 (97) */
/* 100 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 102 */	NdrFcShort( 0x2 ),	/* 2 */
/* 104 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 106 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 108 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 110 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 112 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (100) */
/* 118 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 120 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 122 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 124 */	NdrFcShort( 0x4 ),	/* 4 */
/* 126 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 132 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x1 ),	/* 1 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	0x13, 0x0,	/* FC_OP */
/* 148 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (112) */
/* 150 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 152 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 154 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 160 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 162 */	NdrFcShort( 0x4 ),	/* 4 */
/* 164 */	NdrFcShort( 0x4 ),	/* 4 */
/* 166 */	0x11, 0x0,	/* FC_RP */
/* 168 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (122) */
/* 170 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 172 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 174 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 186 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 188 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 190 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 192 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 202 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 206 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 208 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 210 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (174) */
/* 212 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 214 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x6 ),	/* Offset= 6 (226) */
/* 222 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 224 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 226 */	
			0x11, 0x0,	/* FC_RP */
/* 228 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (192) */
/* 230 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 240 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 244 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 246 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 248 */	NdrFcShort( 0xff0a ),	/* Offset= -246 (2) */
/* 250 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 252 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x6 ),	/* Offset= 6 (264) */
/* 260 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 262 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 264 */	
			0x11, 0x0,	/* FC_RP */
/* 266 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (230) */
/* 268 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 270 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 272 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 274 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 276 */	NdrFcShort( 0x2 ),	/* Offset= 2 (278) */
/* 278 */	NdrFcShort( 0x10 ),	/* 16 */
/* 280 */	NdrFcShort( 0x2f ),	/* 47 */
/* 282 */	NdrFcLong( 0x14 ),	/* 20 */
/* 286 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 288 */	NdrFcLong( 0x3 ),	/* 3 */
/* 292 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 294 */	NdrFcLong( 0x11 ),	/* 17 */
/* 298 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 300 */	NdrFcLong( 0x2 ),	/* 2 */
/* 304 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 306 */	NdrFcLong( 0x4 ),	/* 4 */
/* 310 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 312 */	NdrFcLong( 0x5 ),	/* 5 */
/* 316 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 318 */	NdrFcLong( 0xb ),	/* 11 */
/* 322 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 324 */	NdrFcLong( 0xa ),	/* 10 */
/* 328 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 330 */	NdrFcLong( 0x6 ),	/* 6 */
/* 334 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (566) */
/* 336 */	NdrFcLong( 0x7 ),	/* 7 */
/* 340 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 342 */	NdrFcLong( 0x8 ),	/* 8 */
/* 346 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (572) */
/* 348 */	NdrFcLong( 0xd ),	/* 13 */
/* 352 */	NdrFcShort( 0xff4e ),	/* Offset= -178 (174) */
/* 354 */	NdrFcLong( 0x9 ),	/* 9 */
/* 358 */	NdrFcShort( 0xfe9c ),	/* Offset= -356 (2) */
/* 360 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 364 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (576) */
/* 366 */	NdrFcLong( 0x24 ),	/* 36 */
/* 370 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (584) */
/* 372 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 376 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (584) */
/* 378 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 382 */	NdrFcShort( 0x100 ),	/* Offset= 256 (638) */
/* 384 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 388 */	NdrFcShort( 0xfe ),	/* Offset= 254 (642) */
/* 390 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 394 */	NdrFcShort( 0xfc ),	/* Offset= 252 (646) */
/* 396 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 400 */	NdrFcShort( 0xfa ),	/* Offset= 250 (650) */
/* 402 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 406 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (654) */
/* 408 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 412 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (658) */
/* 414 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 418 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (642) */
/* 420 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 424 */	NdrFcShort( 0xde ),	/* Offset= 222 (646) */
/* 426 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 430 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (662) */
/* 432 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 436 */	NdrFcShort( 0xde ),	/* Offset= 222 (658) */
/* 438 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 442 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (666) */
/* 444 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 448 */	NdrFcShort( 0xde ),	/* Offset= 222 (670) */
/* 450 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 454 */	NdrFcShort( 0xdc ),	/* Offset= 220 (674) */
/* 456 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 460 */	NdrFcShort( 0xda ),	/* Offset= 218 (678) */
/* 462 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 466 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (690) */
/* 468 */	NdrFcLong( 0x10 ),	/* 16 */
/* 472 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 474 */	NdrFcLong( 0x12 ),	/* 18 */
/* 478 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 480 */	NdrFcLong( 0x13 ),	/* 19 */
/* 484 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 486 */	NdrFcLong( 0x15 ),	/* 21 */
/* 490 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 492 */	NdrFcLong( 0x16 ),	/* 22 */
/* 496 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 498 */	NdrFcLong( 0x17 ),	/* 23 */
/* 502 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 504 */	NdrFcLong( 0xe ),	/* 14 */
/* 508 */	NdrFcShort( 0xbe ),	/* Offset= 190 (698) */
/* 510 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 514 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (708) */
/* 516 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 520 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (712) */
/* 522 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 526 */	NdrFcShort( 0x74 ),	/* Offset= 116 (642) */
/* 528 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 532 */	NdrFcShort( 0x72 ),	/* Offset= 114 (646) */
/* 534 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 538 */	NdrFcShort( 0x70 ),	/* Offset= 112 (650) */
/* 540 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 544 */	NdrFcShort( 0x66 ),	/* Offset= 102 (646) */
/* 546 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 550 */	NdrFcShort( 0x60 ),	/* Offset= 96 (646) */
/* 552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* Offset= 0 (556) */
/* 558 */	NdrFcLong( 0x1 ),	/* 1 */
/* 562 */	NdrFcShort( 0x0 ),	/* Offset= 0 (562) */
/* 564 */	NdrFcShort( 0xffff ),	/* Offset= -1 (563) */
/* 566 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 570 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 572 */	
			0x13, 0x0,	/* FC_OP */
/* 574 */	NdrFcShort( 0xfe32 ),	/* Offset= -462 (112) */
/* 576 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 578 */	NdrFcShort( 0x2 ),	/* Offset= 2 (580) */
/* 580 */	
			0x13, 0x0,	/* FC_OP */
/* 582 */	NdrFcShort( 0x1b8 ),	/* Offset= 440 (1022) */
/* 584 */	
			0x13, 0x0,	/* FC_OP */
/* 586 */	NdrFcShort( 0x20 ),	/* Offset= 32 (618) */
/* 588 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 590 */	NdrFcLong( 0x2f ),	/* 47 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 600 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 602 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 604 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 606 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 610 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 612 */	NdrFcShort( 0x4 ),	/* 4 */
/* 614 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 616 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 618 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 620 */	NdrFcShort( 0x10 ),	/* 16 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0xa ),	/* Offset= 10 (634) */
/* 626 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 628 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 630 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (588) */
/* 632 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 634 */	
			0x13, 0x0,	/* FC_OP */
/* 636 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (606) */
/* 638 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 640 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 642 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 644 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 646 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 648 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 652 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 654 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 656 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 658 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 660 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 662 */	
			0x13, 0x0,	/* FC_OP */
/* 664 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (566) */
/* 666 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 668 */	NdrFcShort( 0xffa0 ),	/* Offset= -96 (572) */
/* 670 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 672 */	NdrFcShort( 0xfe0e ),	/* Offset= -498 (174) */
/* 674 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 676 */	NdrFcShort( 0xfd5e ),	/* Offset= -674 (2) */
/* 678 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 680 */	NdrFcShort( 0x2 ),	/* Offset= 2 (682) */
/* 682 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 684 */	NdrFcShort( 0x2 ),	/* Offset= 2 (686) */
/* 686 */	
			0x13, 0x0,	/* FC_OP */
/* 688 */	NdrFcShort( 0x14e ),	/* Offset= 334 (1022) */
/* 690 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 692 */	NdrFcShort( 0x2 ),	/* Offset= 2 (694) */
/* 694 */	
			0x13, 0x0,	/* FC_OP */
/* 696 */	NdrFcShort( 0x14 ),	/* Offset= 20 (716) */
/* 698 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 700 */	NdrFcShort( 0x10 ),	/* 16 */
/* 702 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 704 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 706 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 708 */	
			0x13, 0x0,	/* FC_OP */
/* 710 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (698) */
/* 712 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 714 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 716 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 718 */	NdrFcShort( 0x20 ),	/* 32 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x0 ),	/* Offset= 0 (722) */
/* 724 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 726 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 728 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 730 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 732 */	NdrFcShort( 0xfe30 ),	/* Offset= -464 (268) */
/* 734 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 736 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 738 */	NdrFcShort( 0x4 ),	/* 4 */
/* 740 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 746 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 748 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 750 */	NdrFcShort( 0x4 ),	/* 4 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x1 ),	/* 1 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	0x13, 0x0,	/* FC_OP */
/* 762 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (716) */
/* 764 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 766 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 768 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x6 ),	/* Offset= 6 (780) */
/* 776 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 778 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 780 */	
			0x11, 0x0,	/* FC_RP */
/* 782 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (736) */
/* 784 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 786 */	NdrFcShort( 0x4 ),	/* 4 */
/* 788 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 794 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 796 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 798 */	NdrFcShort( 0x4 ),	/* 4 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x1 ),	/* 1 */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	0x13, 0x0,	/* FC_OP */
/* 810 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (618) */
/* 812 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 814 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 816 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x6 ),	/* Offset= 6 (828) */
/* 824 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 826 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 828 */	
			0x11, 0x0,	/* FC_RP */
/* 830 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (784) */
/* 832 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 836 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 838 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 840 */	NdrFcShort( 0x10 ),	/* 16 */
/* 842 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 844 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 846 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (832) */
			0x5b,		/* FC_END */
/* 850 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 852 */	NdrFcShort( 0x18 ),	/* 24 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0xa ),	/* Offset= 10 (866) */
/* 858 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 860 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 862 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (838) */
/* 864 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 866 */	
			0x11, 0x0,	/* FC_RP */
/* 868 */	NdrFcShort( 0xfd5c ),	/* Offset= -676 (192) */
/* 870 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* 1 */
/* 874 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 880 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 882 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 888 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 890 */	NdrFcShort( 0x4 ),	/* 4 */
/* 892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 894 */	0x13, 0x0,	/* FC_OP */
/* 896 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (870) */
/* 898 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 900 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 902 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 904 */	NdrFcShort( 0x2 ),	/* 2 */
/* 906 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 912 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 914 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 918 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 920 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 922 */	NdrFcShort( 0x4 ),	/* 4 */
/* 924 */	NdrFcShort( 0x4 ),	/* 4 */
/* 926 */	0x13, 0x0,	/* FC_OP */
/* 928 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (902) */
/* 930 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 932 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 934 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x4 ),	/* 4 */
/* 938 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 944 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 946 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 950 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 952 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 954 */	NdrFcShort( 0x4 ),	/* 4 */
/* 956 */	NdrFcShort( 0x4 ),	/* 4 */
/* 958 */	0x13, 0x0,	/* FC_OP */
/* 960 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (934) */
/* 962 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 964 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 966 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 970 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 976 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 978 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 982 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 986 */	NdrFcShort( 0x4 ),	/* 4 */
/* 988 */	NdrFcShort( 0x4 ),	/* 4 */
/* 990 */	0x13, 0x0,	/* FC_OP */
/* 992 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (966) */
/* 994 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 996 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 998 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1004 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1006 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1012 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1014 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1016 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1018 */	NdrFcShort( 0xffec ),	/* Offset= -20 (998) */
/* 1020 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1022 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1024 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1026 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1006) */
/* 1028 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1028) */
/* 1030 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1032 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1034 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1036 */	NdrFcShort( 0xfc14 ),	/* Offset= -1004 (32) */
/* 1038 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1040 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0xfc00 ),	/* Offset= -1024 (24) */
/* 1050 */	
			0x12, 0x0,	/* FC_UP */
/* 1052 */	NdrFcShort( 0xfc54 ),	/* Offset= -940 (112) */
/* 1054 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1058 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1050) */
/* 1064 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1066 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1068 */	
			0x11, 0x0,	/* FC_RP */
/* 1070 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1072) */
/* 1072 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1074 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1076 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0xfe04 ),	/* Offset= -508 (572) */
/* 1082 */	
			0x11, 0x0,	/* FC_RP */
/* 1084 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1090) */
/* 1086 */	
			0x13, 0x0,	/* FC_OP */
/* 1088 */	NdrFcShort( 0xfe8c ),	/* Offset= -372 (716) */
/* 1090 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1092 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1094 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1086) */
/* 1100 */	
			0x11, 0x0,	/* FC_RP */
/* 1102 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1108) */
/* 1104 */	
			0x12, 0x0,	/* FC_UP */
/* 1106 */	NdrFcShort( 0xfe7a ),	/* Offset= -390 (716) */
/* 1108 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1110 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1112 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1104) */
/* 1118 */	
			0x11, 0x0,	/* FC_RP */
/* 1120 */	NdrFcShort( 0x1a ),	/* Offset= 26 (1146) */
/* 1122 */	
			0x13, 0x0,	/* FC_OP */
/* 1124 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1126) */
/* 1126 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 1128 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1130 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1132 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1136 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1138 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1142 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1144 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1143) */
/* 1146 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1148 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1150 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1122) */
/* 1156 */	
			0x11, 0x0,	/* FC_RP */
/* 1158 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1160) */
/* 1160 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1162 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1164 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1166 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1168 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1170 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1172 */	NdrFcShort( 0xfb6e ),	/* Offset= -1170 (2) */
/* 1174 */	
			0x11, 0x0,	/* FC_RP */
/* 1176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1178) */
/* 1178 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1180 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1184) */
/* 1186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1188 */	NdrFcShort( 0xffb0 ),	/* Offset= -80 (1108) */
/* 1190 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1192 */	NdrFcShort( 0xff76 ),	/* Offset= -138 (1054) */
/* 1194 */	0x40,		/* FC_STRUCTPAD4 */
			0x5b,		/* FC_END */
/* 1196 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1198 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1200) */
/* 1200 */	
			0x13, 0x0,	/* FC_OP */
/* 1202 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1204) */
/* 1204 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1206 */	NdrFcShort( 0xc ),	/* 12 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1210) */
/* 1212 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1214 */	NdrFcShort( 0xff72 ),	/* Offset= -142 (1072) */
/* 1216 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1218 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (1072) */
/* 1220 */	0xe,		/* FC_ENUM32 */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            HWND_UserSize
            ,HWND_UserMarshal
            ,HWND_UserUnmarshal
            ,HWND_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IInitDone, ver. 0.0,
   GUID={0xAB634001,0xF13D,0x11d0,{0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IInitDone_FormatStringOffsetTable[] =
    {
    0,
    36,
    66
    };

static const MIDL_STUBLESS_PROXY_INFO IInitDone_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IInitDone_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IInitDone_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IInitDone_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IInitDoneProxyVtbl = 
{
    &IInitDone_ProxyInfo,
    &IID_IInitDone,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IInitDone::Init */ ,
    (void *) (INT_PTR) -1 /* IInitDone::Done */ ,
    (void *) (INT_PTR) -1 /* IInitDone::GetInfo */
};

const CInterfaceStubVtbl _IInitDoneStubVtbl =
{
    &IID_IInitDone,
    &IInitDone_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPropertyBag, ver. 0.0,
   GUID={0x55272A00,0x42CB,0x11CE,{0x81,0x35,0x00,0xAA,0x00,0x4B,0xB8,0x51}} */


/* Object interface: IPropertyProfile, ver. 0.0,
   GUID={0xAB634002,0xF13D,0x11d0,{0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IPropertyProfile_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    102
    };

static const MIDL_STUBLESS_PROXY_INFO IPropertyProfile_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IPropertyProfile_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPropertyProfile_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IPropertyProfile_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IPropertyProfileProxyVtbl = 
{
    &IPropertyProfile_ProxyInfo,
    &IID_IPropertyProfile,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IPropertyBag_Read_Proxy */ ,
    0 /* IPropertyBag::Write */ ,
    (void *) (INT_PTR) -1 /* IPropertyProfile::RegisterProfileAs */
};


static const PRPC_STUB_FUNCTION IPropertyProfile_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IPropertyProfileStubVtbl =
{
    &IID_IPropertyProfile,
    &IPropertyProfile_ServerInfo,
    6,
    &IPropertyProfile_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAsyncEvent, ver. 0.0,
   GUID={0xab634004,0xf13d,0x11d0,{0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea}} */

#pragma code_seg(".orpc")
static const unsigned short IAsyncEvent_FormatStringOffsetTable[] =
    {
    138,
    174,
    210,
    258
    };

static const MIDL_STUBLESS_PROXY_INFO IAsyncEvent_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IAsyncEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAsyncEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IAsyncEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IAsyncEventProxyVtbl = 
{
    &IAsyncEvent_ProxyInfo,
    &IID_IAsyncEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IAsyncEvent::SetEventBufferDepth */ ,
    (void *) (INT_PTR) -1 /* IAsyncEvent::GetEventBufferDepth */ ,
    (void *) (INT_PTR) -1 /* IAsyncEvent::ExternalEvent */ ,
    (void *) (INT_PTR) -1 /* IAsyncEvent::CleanBuffer */
};

const CInterfaceStubVtbl _IAsyncEventStubVtbl =
{
    &IID_IAsyncEvent,
    &IAsyncEvent_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILocale, ver. 0.0,
   GUID={0xE88A191E,0x8F52,0x4261,{0x9F,0xAE,0xFF,0x7A,0xA8,0x4F,0x5D,0x7E}} */

#pragma code_seg(".orpc")
static const unsigned short ILocale_FormatStringOffsetTable[] =
    {
    288
    };

static const MIDL_STUBLESS_PROXY_INFO ILocale_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &ILocale_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILocale_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &ILocale_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ILocaleProxyVtbl = 
{
    &ILocale_ProxyInfo,
    &IID_ILocale,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ILocale::SetLocale */
};

const CInterfaceStubVtbl _ILocaleStubVtbl =
{
    &IID_ILocale,
    &ILocale_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILanguageExtender, ver. 0.0,
   GUID={0xAB634003,0xF13D,0x11d0,{0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short ILanguageExtender_FormatStringOffsetTable[] =
    {
    324,
    360,
    396,
    438,
    486,
    528,
    570,
    612,
    654,
    690,
    732,
    780,
    822,
    870,
    912,
    954
    };

static const MIDL_STUBLESS_PROXY_INFO ILanguageExtender_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &ILanguageExtender_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ILanguageExtender_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &ILanguageExtender_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _ILanguageExtenderProxyVtbl = 
{
    &ILanguageExtender_ProxyInfo,
    &IID_ILanguageExtender,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::RegisterExtensionAs */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetNProps */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::FindProp */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetPropName */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetPropVal */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::SetPropVal */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::IsPropReadable */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::IsPropWritable */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetNMethods */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::FindMethod */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetMethodName */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetNParams */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::GetParamDefValue */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::HasRetVal */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::CallAsProc */ ,
    (void *) (INT_PTR) -1 /* ILanguageExtender::CallAsFunc */
};

const CInterfaceStubVtbl _ILanguageExtenderStubVtbl =
{
    &IID_ILanguageExtender,
    &ILanguageExtender_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IStatusLine, ver. 0.0,
   GUID={0xab634005,0xf13d,0x11d0,{0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea}} */

#pragma code_seg(".orpc")
static const unsigned short IStatusLine_FormatStringOffsetTable[] =
    {
    288,
    36
    };

static const MIDL_STUBLESS_PROXY_INFO IStatusLine_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IStatusLine_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IStatusLine_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IStatusLine_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IStatusLineProxyVtbl = 
{
    &IStatusLine_ProxyInfo,
    &IID_IStatusLine,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IStatusLine::SetStatusLine */ ,
    (void *) (INT_PTR) -1 /* IStatusLine::ResetStatusLine */
};

const CInterfaceStubVtbl _IStatusLineStubVtbl =
{
    &IID_IStatusLine,
    &IStatusLine_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IExtWndsSupport, ver. 0.0,
   GUID={0xefe19ea0,0x09e4,0x11d2,{0xa6,0x01,0x00,0x80,0x48,0xda,0x00,0xde}} */

#pragma code_seg(".orpc")
static const unsigned short IExtWndsSupport_FormatStringOffsetTable[] =
    {
    1002,
    1038,
    1074
    };

static const MIDL_STUBLESS_PROXY_INFO IExtWndsSupport_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IExtWndsSupport_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IExtWndsSupport_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IExtWndsSupport_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IExtWndsSupportProxyVtbl = 
{
    &IExtWndsSupport_ProxyInfo,
    &IID_IExtWndsSupport,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IExtWndsSupport::GetAppMainFrame */ ,
    (void *) (INT_PTR) -1 /* IExtWndsSupport::GetAppMDIFrame */ ,
    (void *) (INT_PTR) -1 /* IExtWndsSupport::CreateAddInWindow */
};

const CInterfaceStubVtbl _IExtWndsSupportStubVtbl =
{
    &IID_IExtWndsSupport,
    &IExtWndsSupport_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_AddIn_0000_0007, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IMsgBox, ver. 0.0,
   GUID={0x3C2136B5,0xB35A,0x4FAC,{0x9A,0xC3,0xF7,0x7F,0x36,0x1E,0x94,0x67}} */

#pragma code_seg(".orpc")
static const unsigned short IMsgBox_FormatStringOffsetTable[] =
    {
    1152,
    1230
    };

static const MIDL_STUBLESS_PROXY_INFO IMsgBox_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IMsgBox_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMsgBox_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IMsgBox_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IMsgBoxProxyVtbl = 
{
    &IMsgBox_ProxyInfo,
    &IID_IMsgBox,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IMsgBox::QueryBox */ ,
    (void *) (INT_PTR) -1 /* IMsgBox::MessageBox */
};

const CInterfaceStubVtbl _IMsgBoxStubVtbl =
{
    &IID_IMsgBox,
    &IMsgBox_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_AddIn_0000_0008, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IPlatformInfo, ver. 0.0,
   GUID={0xAAABE126,0x2230,0x4a7d,{0x9D,0xDA,0x89,0x87,0xFD,0x2A,0x62,0xBA}} */

#pragma code_seg(".orpc")
static const unsigned short IPlatformInfo_FormatStringOffsetTable[] =
    {
    1284
    };

static const MIDL_STUBLESS_PROXY_INFO IPlatformInfo_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IPlatformInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPlatformInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IPlatformInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IPlatformInfoProxyVtbl = 
{
    &IPlatformInfo_ProxyInfo,
    &IID_IPlatformInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPlatformInfo::GetPlatformInfo */
};

const CInterfaceStubVtbl _IPlatformInfoStubVtbl =
{
    &IID_IPlatformInfo,
    &IPlatformInfo_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPropertyLink, ver. 0.0,
   GUID={0x52512A61,0x2A9D,0x11d1,{0xA4,0xD6,0x00,0x40,0x95,0xE1,0xDA,0xEA}} */

#pragma code_seg(".orpc")
static const unsigned short IPropertyLink_FormatStringOffsetTable[] =
    {
    1320,
    1356
    };

static const MIDL_STUBLESS_PROXY_INFO IPropertyLink_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IPropertyLink_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPropertyLink_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IPropertyLink_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IPropertyLinkProxyVtbl = 
{
    &IPropertyLink_ProxyInfo,
    &IID_IPropertyLink,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPropertyLink::get_Enabled */ ,
    (void *) (INT_PTR) -1 /* IPropertyLink::put_Enabled */
};

const CInterfaceStubVtbl _IPropertyLinkStubVtbl =
{
    &IID_IPropertyLink,
    &IPropertyLink_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAddInCOM, ver. 0.0,
   GUID={0xD0DAA417,0x4643,0x4BBD,{0xB8,0xF6,0x78,0xC2,0xB2,0x0F,0x28,0x63}} */

#pragma code_seg(".orpc")
static const unsigned short IAddInCOM_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAddInCOM_ProxyInfo =
    {
    &Object_StubDesc,
    AddIn__MIDL_ProcFormatString.Format,
    &IAddInCOM_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAddInCOM_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AddIn__MIDL_ProcFormatString.Format,
    &IAddInCOM_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IAddInCOMProxyVtbl = 
{
    0,
    &IID_IAddInCOM,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IAddInCOMStubVtbl =
{
    &IID_IAddInCOM,
    &IAddInCOM_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    AddIn__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _AddIn_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IInitDoneProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPropertyProfileProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILanguageExtenderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAsyncEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStatusLineProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAddInCOMProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILocaleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPlatformInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPropertyLinkProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IExtWndsSupportProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMsgBoxProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _AddIn_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IInitDoneStubVtbl,
    ( CInterfaceStubVtbl *) &_IPropertyProfileStubVtbl,
    ( CInterfaceStubVtbl *) &_ILanguageExtenderStubVtbl,
    ( CInterfaceStubVtbl *) &_IAsyncEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IStatusLineStubVtbl,
    ( CInterfaceStubVtbl *) &_IAddInCOMStubVtbl,
    ( CInterfaceStubVtbl *) &_ILocaleStubVtbl,
    ( CInterfaceStubVtbl *) &_IPlatformInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IPropertyLinkStubVtbl,
    ( CInterfaceStubVtbl *) &_IExtWndsSupportStubVtbl,
    ( CInterfaceStubVtbl *) &_IMsgBoxStubVtbl,
    0
};

PCInterfaceName const _AddIn_InterfaceNamesList[] = 
{
    "IInitDone",
    "IPropertyProfile",
    "ILanguageExtender",
    "IAsyncEvent",
    "IStatusLine",
    "IAddInCOM",
    "ILocale",
    "IPlatformInfo",
    "IPropertyLink",
    "IExtWndsSupport",
    "IMsgBox",
    0
};

const IID *  const _AddIn_BaseIIDList[] = 
{
    0,
    &IID_IPropertyBag,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};


#define _AddIn_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _AddIn, pIID, n)

int __stdcall _AddIn_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _AddIn, 11, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _AddIn, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _AddIn, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _AddIn, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _AddIn, 11, *pIndex )
    
}

const ExtendedProxyFileInfo AddIn_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _AddIn_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _AddIn_StubVtblList,
    (const PCInterfaceName * ) & _AddIn_InterfaceNamesList,
    (const IID ** ) & _AddIn_BaseIIDList,
    & _AddIn_IID_Lookup, 
    11,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

