// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	
	void OnBtnMsgBox();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);


protected: // C++ 控制图表内容变化

	// 控件响应：C++ 控制图表变化显示
	void OnBtnChangePie1();
	void OnBtnChangePie2();
	void OnBtnChangePie3();
	void OnBtnChangePie4();

	// 调用 js 函数 ChangeValue
	HRESULT _CallJsChangeValue(UINT uValue1, UINT uValue2, UINT uValue3, UINT uValue4);

	// 获取当前页面数据
	HRESULT _GetCurrentValue();

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_change_pie_1", OnBtnChangePie1)
		EVENT_NAME_COMMAND(L"btn_change_pie_2", OnBtnChangePie2)
		EVENT_NAME_COMMAND(L"btn_change_pie_3", OnBtnChangePie3)
		EVENT_NAME_COMMAND(L"btn_change_pie_4", OnBtnChangePie4)
		EVENT_MAP_END()
		
		//HostWnd真实窗口消息处理
		BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL m_bLayoutInited;
	UINT m_uValue1 = 1;
	UINT m_uValue2 = 1;
	UINT m_uValue3 = 1;
	UINT m_uValue4 = 1;
};
