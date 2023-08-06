// MFCActiveXControl1-tools.cpp: CMFCActiveXControl1toolsApp 的實作與 DLL 註冊。

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl1-tools.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCActiveXControl1toolsApp theApp;

const GUID CDECL _tlid = {0x51c7b87e,0x4b4b,0x4d2f,{0x93,0xac,0xcd,0x78,0xa5,0x24,0xa2,0x33}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCActiveXControl1toolsApp::InitInstance - DLL 初始設定

BOOL CMFCActiveXControl1toolsApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此加入您自己的模組初始化程式碼。
	}

	return bInit;
}



// CMFCActiveXControl1toolsApp::ExitInstance - DLL 終止

int CMFCActiveXControl1toolsApp::ExitInstance()
{
	// TODO:  在此加入您自己的模組終止程式碼。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 將項目加入到系統登錄

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 從系統登錄移除項目

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
