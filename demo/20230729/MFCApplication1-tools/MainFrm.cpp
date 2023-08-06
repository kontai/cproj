
// MainFrm.cpp: CMainFrame 類別的實作
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1-tools.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 狀態列指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 建構/解構

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此加入成員初始化程式碼
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // 其他可用樣式...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // 設定為 FALSE 可在索引標籤區域右側放置關閉按鈕
	mdiTabParams.m_bTabIcons = FALSE;    // 設定為 TRUE 可在 MDI 索引標籤上啟用文件圖示
	mdiTabParams.m_bAutoColor = TRUE;    // 設定為 FALSE 可停用 MDI 索引標籤的自動著色
	mdiTabParams.m_bDocumentMenu = TRUE; // 啟用索引標籤區域右側的文件功能表
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("無法建立工具列\n");
		return -1;      // 無法建立
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("無法建立狀態列\n");
		return -1;      // 無法建立
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果您不要可以固定工具列，請刪除這三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	// 在視窗標題列上切換文件名稱與應用程式名稱的順序。
	// 這可提升工具列的可用性，因為文件名稱會隨著縮圖顯示。
	ModifyStyle(0, FWS_PREFIXTITLE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return TRUE;
}

// CMainFrame 診斷

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 訊息處理常式

