// MFCActiveXControl1toolsCtrl.cpp: CMFCActiveXControl1toolsCtrl ActiveX 控制項類別的實作。

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl1-tools.h"
#include "MFCActiveXControl1toolsCtrl.h"
#include "MFCActiveXControl1toolsPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1toolsCtrl, COleControl)

// 訊息對應

BEGIN_MESSAGE_MAP(CMFCActiveXControl1toolsCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 分派對應

BEGIN_DISPATCH_MAP(CMFCActiveXControl1toolsCtrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1toolsCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件對應

BEGIN_EVENT_MAP(CMFCActiveXControl1toolsCtrl, COleControl)
END_EVENT_MAP()

// 屬性頁

// TODO:  視需要加入更多屬性頁。請記得增加計數!
BEGIN_PROPPAGEIDS(CMFCActiveXControl1toolsCtrl, 1)
	PROPPAGEID(CMFCActiveXControl1toolsPropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1toolsCtrl)

// 初始化 Class Factory 和 GUID

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1toolsCtrl, "MFCACTIVEXCONTRO.MFCActiveXControl1toolsCtrl.1",
	0x6dafc997,0x98e7,0x4a8b,0xb2,0x5a,0x5c,0x12,0x15,0x5f,0x85,0x42)

// 類型程式庫 ID 和版本

IMPLEMENT_OLETYPELIB(CMFCActiveXControl1toolsCtrl, _tlid, _wVerMajor, _wVerMinor)

// 介面 ID

const IID IID_DMFCActiveXControl1tools = {0x82dc5345,0x5a96,0x4801,{0xad,0x3f,0x34,0x0b,0x2c,0x3e,0x20,0xa0}};
const IID IID_DMFCActiveXControl1toolsEvents = {0x32f2575e,0x84a3,0x4c5b,{0xa7,0xb0,0xdd,0x7d,0xf0,0x00,0x47,0x3c}};

// 控制項類型資訊

static const DWORD _dwMFCActiveXControl1toolsOleMisc =
	OLEMISC_SIMPLEFRAME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1toolsCtrl, IDS_MFCACTIVEXCONTROL1TOOLS, _dwMFCActiveXControl1toolsOleMisc)

// CMFCActiveXControl1toolsCtrl::CMFCActiveXControl1toolsCtrlFactory::UpdateRegistry -
// 新增或移除 CMFCActiveXControl1toolsCtrl 的系統登錄項目

BOOL CMFCActiveXControl1toolsCtrl::CMFCActiveXControl1toolsCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  驗證您的控制項是否符合 Apartment Model 執行緒規則。
	// 如需詳細資訊，請參閱 MFC TechNote 64。
	// 如果您的控制項不符合 Apartment Model 規則，
	// 那麼您必須修改下列程式碼，將第 6 個參數從
	// afxRegApartmentThreading 到 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL1TOOLS,
			IDB_MFCACTIVEXCONTROL1TOOLS,
			afxRegApartmentThreading,
			_dwMFCActiveXControl1toolsOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXControl1toolsCtrl::CMFCActiveXControl1toolsCtrl - 建構函式

CMFCActiveXControl1toolsCtrl::CMFCActiveXControl1toolsCtrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1tools, &IID_DMFCActiveXControl1toolsEvents);

	EnableSimpleFrame();
	// TODO:  在此初始化控制項的執行個體資料。
}

// CMFCActiveXControl1toolsCtrl::~CMFCActiveXControl1toolsCtrl - 解構函式

CMFCActiveXControl1toolsCtrl::~CMFCActiveXControl1toolsCtrl()
{
	// TODO:  在此清除控制項的執行個體資料。
}

// CMFCActiveXControl1toolsCtrl::OnDraw - 繪圖函式

void CMFCActiveXControl1toolsCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  請用您自己的繪圖程式碼取代下列程式碼。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1toolsCtrl::DoPropExchange - 持續性支援

void CMFCActiveXControl1toolsCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  對每個永續性自訂屬性呼叫 PX_ 函式。
}


// CMFCActiveXControl1toolsCtrl::OnResetState - 將控制項重設為預設狀態

void CMFCActiveXControl1toolsCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重設 DoPropExchange 中的預設值

	// TODO:  在此重設任何其他控制項狀態。
}


// CMFCActiveXControl1toolsCtrl::AboutBox - 對使用者顯示 [關於] 方塊

void CMFCActiveXControl1toolsCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEXCONTROL1TOOLS);
	dlgAbout.DoModal();
}


// CMFCActiveXControl1toolsCtrl 訊息處理常式
