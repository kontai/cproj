﻿#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 從 Windows 標頭排除不常使用的成員
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 明確定義部分的 CString 建構函式
#define _ATL_NO_AUTOMATIC_NAMESPACE             // 避免類別名稱衝突

#include <afxctl.h>         // MFC 支援的 ActiveX 控制項
#include <afxext.h>         // MFC 擴充功能
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 支援的 Internet Explorer 4 通用控制項
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC 支援的 Windows 通用控制項
#endif // _AFX_NO_AFXCMN_SUPPORT

// 請刪除以下兩個 Include 檔，如果您不想使用 MFC
//  資料庫類別
#ifndef _WIN64

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC 資料庫類別
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO 資料庫類別
#endif // _AFX_NO_DAO_SUPPORT

#endif // _WIN64

