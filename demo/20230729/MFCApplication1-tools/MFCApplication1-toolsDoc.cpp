
// MFCApplication1-toolsDoc.cpp: CMFCApplication1toolsDoc 類別的實作
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFCApplication1-tools.h"
#endif

#include "MFCApplication1-toolsDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1toolsDoc

IMPLEMENT_DYNCREATE(CMFCApplication1toolsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication1toolsDoc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication1toolsDoc 建構/解構

CMFCApplication1toolsDoc::CMFCApplication1toolsDoc() noexcept
{
	// TODO: 在此加入一次建構程式碼

}

CMFCApplication1toolsDoc::~CMFCApplication1toolsDoc()
{
}

BOOL CMFCApplication1toolsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CMFCApplication1toolsDoc 序列化

void CMFCApplication1toolsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此加入儲存程式碼
	}
	else
	{
		// TODO: 在此加入載入程式碼
	}
}

#ifdef SHARED_HANDLERS

// 縮圖的支援
void CMFCApplication1toolsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改這段程式碼以繪製文件的資料
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜尋處理常式的支援
void CMFCApplication1toolsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 設定來自文件資料的搜尋內容。
	// 內容部分應該以 ";" 隔開

	// 範例:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication1toolsDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication1toolsDoc 診斷

#ifdef _DEBUG
void CMFCApplication1toolsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication1toolsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication1toolsDoc 命令
