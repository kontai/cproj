
// MFCApplication1-toolsView.h: CMFCApplication1toolsView 類別的介面
//

#pragma once


class CMFCApplication1toolsView : public CView
{
protected: // 僅從序列化建立
	CMFCApplication1toolsView() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1toolsView)

// 屬性
public:
	CMFCApplication1toolsDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CMFCApplication1toolsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 對 MFCApplication1-toolsView.cpp 中的版本進行偵錯
inline CMFCApplication1toolsDoc* CMFCApplication1toolsView::GetDocument() const
   { return reinterpret_cast<CMFCApplication1toolsDoc*>(m_pDocument); }
#endif

