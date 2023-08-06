#pragma once

// MFCActiveXControl1toolsPropPage.h: CMFCActiveXControl1toolsPropPage 屬性頁類別的宣告。


// CMFCActiveXControl1toolsPropPage : 如需實作資訊，請參閱 MFCActiveXControl1toolsPropPage.cpp。

class CMFCActiveXControl1toolsPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1toolsPropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1toolsPropPage)

// 建構函式
public:
	CMFCActiveXControl1toolsPropPage();

// 對話方塊資料
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1TOOLS };

// 程式碼實作
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 訊息對應
protected:
	DECLARE_MESSAGE_MAP()
};

