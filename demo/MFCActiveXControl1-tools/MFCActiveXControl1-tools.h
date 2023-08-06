#pragma once

// MFCActiveXControl1-tools.h: MFCActiveXControl1-tools.DLL 的主要標頭檔

#if !defined( __AFXCTL_H__ )
#error "在包含此檔案前先包含 'afxctl.h'"
#endif

#include "resource.h"       // 主要符號


// CMFCActiveXControl1toolsApp: 查看 MFCActiveXControl1-tools.cpp 以了解實作。

class CMFCActiveXControl1toolsApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

