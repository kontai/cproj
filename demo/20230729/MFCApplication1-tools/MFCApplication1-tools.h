﻿
// MFCApplication1-tools.h: MFCApplication1-tools 應用程式的主要標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 在包含此檔案前先包含 'pch.h'"
#endif

#include "resource.h"       // 主要符號


// CMFCApplication1toolsApp:
// 查看 MFCApplication1-tools.cpp 以了解此類別的實作
//

class CMFCApplication1toolsApp : public CWinAppEx
{
public:
	CMFCApplication1toolsApp() noexcept;


// 覆寫
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1toolsApp theApp;
