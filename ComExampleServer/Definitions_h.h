

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for Definitions.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0620 
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
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Definitions_h_h__
#define __Definitions_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IExample_FWD_DEFINED__
#define __IExample_FWD_DEFINED__
typedef interface IExample IExample;

#endif 	/* __IExample_FWD_DEFINED__ */


#ifndef __ExampleObject_FWD_DEFINED__
#define __ExampleObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class ExampleObject ExampleObject;
#else
typedef struct ExampleObject ExampleObject;
#endif /* __cplusplus */

#endif 	/* __ExampleObject_FWD_DEFINED__ */


#ifndef __ExampleObjectFactory_FWD_DEFINED__
#define __ExampleObjectFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class ExampleObjectFactory ExampleObjectFactory;
#else
typedef struct ExampleObjectFactory ExampleObjectFactory;
#endif /* __cplusplus */

#endif 	/* __ExampleObjectFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IExample_INTERFACE_DEFINED__
#define __IExample_INTERFACE_DEFINED__

/* interface IExample */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IExample;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F175F8EF-A526-4A47-A702-48BCA3010ED5")
    IExample : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE exampleMethod( 
            /* [in] */ int n) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExample * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExample * This);
        
        HRESULT ( STDMETHODCALLTYPE *exampleMethod )( 
            IExample * This,
            /* [in] */ int n);
        
        END_INTERFACE
    } IExampleVtbl;

    interface IExample
    {
        CONST_VTBL struct IExampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExample_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExample_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExample_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExample_exampleMethod(This,n)	\
    ( (This)->lpVtbl -> exampleMethod(This,n) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExample_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


