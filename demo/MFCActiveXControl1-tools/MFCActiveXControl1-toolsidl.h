

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MFCActiveXControl1tools.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __MFCActiveXControl12Dtoolsidl_h__
#define __MFCActiveXControl12Dtoolsidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef ___DMFCActiveXControl1tools_FWD_DEFINED__
#define ___DMFCActiveXControl1tools_FWD_DEFINED__
typedef interface _DMFCActiveXControl1tools _DMFCActiveXControl1tools;

#endif 	/* ___DMFCActiveXControl1tools_FWD_DEFINED__ */


#ifndef ___DMFCActiveXControl1toolsEvents_FWD_DEFINED__
#define ___DMFCActiveXControl1toolsEvents_FWD_DEFINED__
typedef interface _DMFCActiveXControl1toolsEvents _DMFCActiveXControl1toolsEvents;

#endif 	/* ___DMFCActiveXControl1toolsEvents_FWD_DEFINED__ */


#ifndef __MFCActiveXControl1tools_FWD_DEFINED__
#define __MFCActiveXControl1tools_FWD_DEFINED__

#ifdef __cplusplus
typedef class MFCActiveXControl1tools MFCActiveXControl1tools;
#else
typedef struct MFCActiveXControl1tools MFCActiveXControl1tools;
#endif /* __cplusplus */

#endif 	/* __MFCActiveXControl1tools_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MFCActiveXControl1tools_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_MFCActiveXControl1tools_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MFCActiveXControl1tools_0000_0000_v0_0_s_ifspec;


#ifndef __MFCActiveXControl1toolsLib_LIBRARY_DEFINED__
#define __MFCActiveXControl1toolsLib_LIBRARY_DEFINED__

/* library MFCActiveXControl1toolsLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_MFCActiveXControl1toolsLib;

#ifndef ___DMFCActiveXControl1tools_DISPINTERFACE_DEFINED__
#define ___DMFCActiveXControl1tools_DISPINTERFACE_DEFINED__

/* dispinterface _DMFCActiveXControl1tools */
/* [uuid] */ 


EXTERN_C const IID DIID__DMFCActiveXControl1tools;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("82dc5345-5a96-4801-ad3f-340b2c3e20a0")
    _DMFCActiveXControl1tools : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMFCActiveXControl1toolsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMFCActiveXControl1tools * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMFCActiveXControl1tools * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMFCActiveXControl1tools * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMFCActiveXControl1tools * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMFCActiveXControl1tools * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMFCActiveXControl1tools * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMFCActiveXControl1tools * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMFCActiveXControl1toolsVtbl;

    interface _DMFCActiveXControl1tools
    {
        CONST_VTBL struct _DMFCActiveXControl1toolsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMFCActiveXControl1tools_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMFCActiveXControl1tools_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMFCActiveXControl1tools_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMFCActiveXControl1tools_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMFCActiveXControl1tools_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMFCActiveXControl1tools_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMFCActiveXControl1tools_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMFCActiveXControl1tools_DISPINTERFACE_DEFINED__ */


#ifndef ___DMFCActiveXControl1toolsEvents_DISPINTERFACE_DEFINED__
#define ___DMFCActiveXControl1toolsEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DMFCActiveXControl1toolsEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DMFCActiveXControl1toolsEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("32f2575e-84a3-4c5b-a7b0-dd7df000473c")
    _DMFCActiveXControl1toolsEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMFCActiveXControl1toolsEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMFCActiveXControl1toolsEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMFCActiveXControl1toolsEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMFCActiveXControl1toolsEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMFCActiveXControl1toolsEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMFCActiveXControl1toolsEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMFCActiveXControl1toolsEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMFCActiveXControl1toolsEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMFCActiveXControl1toolsEventsVtbl;

    interface _DMFCActiveXControl1toolsEvents
    {
        CONST_VTBL struct _DMFCActiveXControl1toolsEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMFCActiveXControl1toolsEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMFCActiveXControl1toolsEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMFCActiveXControl1toolsEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMFCActiveXControl1toolsEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMFCActiveXControl1toolsEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMFCActiveXControl1toolsEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMFCActiveXControl1toolsEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMFCActiveXControl1toolsEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MFCActiveXControl1tools;

#ifdef __cplusplus

class DECLSPEC_UUID("6dafc997-98e7-4a8b-b25a-5c12155f8542")
MFCActiveXControl1tools;
#endif
#endif /* __MFCActiveXControl1toolsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


