
// MFCApplication1-toolsView.cpp: CMFCApplication1toolsView 類別的實作
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFCApplication1-tools.h"
#endif

#include "MFCApplication1-toolsDoc.h"
#include "MFCApplication1-toolsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1toolsView

IMPLEMENT_DYNCREATE(CMFCApplication1toolsView, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1toolsView, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplication1toolsView 建構/解構

CMFCApplication1toolsView::CMFCApplication1toolsView() noexcept
{
	// TODO: 在此加入建構程式碼

}

CMFCApplication1toolsView::~CMFCApplication1toolsView()
{
}

BOOL CMFCApplication1toolsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1toolsView 繪圖

void CMFCApplication1toolsView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1toolsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}


// CMFCApplication1toolsView 列印

BOOL CMFCApplication1toolsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1toolsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CMFCApplication1toolsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// CMFCApplication1toolsView 診斷

#ifdef _DEBUG
void CMFCApplication1toolsView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1toolsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1toolsDoc* CMFCApplication1toolsView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1toolsDoc)));
	return (CMFCApplication1toolsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1toolsView 訊息處理常式
