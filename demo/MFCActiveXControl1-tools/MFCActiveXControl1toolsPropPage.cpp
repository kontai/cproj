// MFCActiveXControl1toolsPropPage.cpp : CMFCActiveXControl1toolsPropPage 屬性頁類別的實作。

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl1-tools.h"
#include "MFCActiveXControl1toolsPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1toolsPropPage, COlePropertyPage)

// 訊息對應

BEGIN_MESSAGE_MAP(CMFCActiveXControl1toolsPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化 Class Factory 和 GUID

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1toolsPropPage, "MFCACTIVEXCONT.MFCActiveXControl1toolsPropPage.1",
	0x84b146ec,0x0736,0x4c6d,0xae,0x0d,0x5d,0x35,0xee,0xdd,0x00,0x75)

// CMFCActiveXControl1toolsPropPage::CMFCActiveXControl1toolsPropPageFactory::UpdateRegistry -
// 新增或移除 CMFCActiveXControl1toolsPropPage 的系統登錄項目

BOOL CMFCActiveXControl1toolsPropPage::CMFCActiveXControl1toolsPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL1TOOLS_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CMFCActiveXControl1toolsPropPage::CMFCActiveXControl1toolsPropPage - 建構函式

CMFCActiveXControl1toolsPropPage::CMFCActiveXControl1toolsPropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL1TOOLS_PPG_CAPTION)
{
}

// CMFCActiveXControl1toolsPropPage::DoDataExchange - 在頁面與屬性之間移動資料

void CMFCActiveXControl1toolsPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCActiveXControl1toolsPropPage 訊息處理常式
