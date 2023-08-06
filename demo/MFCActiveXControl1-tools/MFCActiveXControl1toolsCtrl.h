#pragma once

// MFCActiveXControl1toolsCtrl.h: CMFCActiveXControl1toolsCtrl ActiveX 控制項類別的宣告。


// CMFCActiveXControl1toolsCtrl : 如需實作資訊，請參閱 MFCActiveXControl1toolsCtrl.cpp。

class CMFCActiveXControl1toolsCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1toolsCtrl)

// 建構函式
public:
	CMFCActiveXControl1toolsCtrl();

// 覆寫
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 程式碼實作
protected:
	~CMFCActiveXControl1toolsCtrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1toolsCtrl)    // Class Factory 和 GUID
	DECLARE_OLETYPELIB(CMFCActiveXControl1toolsCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1toolsCtrl)     // 屬性頁 ID
	DECLARE_OLECTLTYPE(CMFCActiveXControl1toolsCtrl)		// 類型名稱及其他狀態

// 訊息對應
	DECLARE_MESSAGE_MAP()

// 分派對應
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件對應
	DECLARE_EVENT_MAP()

// 分派和事件 ID
public:
	enum {
	};
};

