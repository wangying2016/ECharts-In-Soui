#pragma once
#include "../miniblink/wkedefine.h"
namespace SOUI
{
	class SWkeLoader
	{
	public:
		SWkeLoader();
		~SWkeLoader();
	};
	class SWkeWebkit : public SWindow
	{
		SOUI_CLASS_NAME(SWkeWebkit, L"wkeWebkit")
	public:
		SWkeWebkit(void);
		~SWkeWebkit(void);
		wkeWebView	GetWebView() { return m_pWebView; }
	protected:
		LPCTSTR wkeCursor(int wekInfId);
		int OnCreate(void *);
		void OnDestroy();
		void OnPaint(IRenderTarget *pRT);
		void OnSize(UINT nType, CSize size);
		LRESULT OnMouseEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT OnImeStartComposition(UINT uMsg, WPARAM wParam, LPARAM lParam);
		void OnSetFocus(SWND wndOld);
		void OnKillFocus(SWND wndFocus);
		virtual BOOL OnSetCursor(const CPoint &pt);
		virtual UINT OnGetDlgCode() { return SC_WANTALLKEYS; }
		BOOL OnAttrUrl(SStringW strValue, BOOL bLoading);
		SOUI_ATTRS_BEGIN()
			ATTR_CUSTOM(L"url", OnAttrUrl)
			SOUI_ATTRS_END()

			SOUI_MSG_MAP_BEGIN()
			MSG_WM_PAINT_EX(OnPaint)
			MSG_WM_CREATE(OnCreate)
			MSG_WM_DESTROY(OnDestroy)
			MSG_WM_SIZE(OnSize)
			MSG_WM_SETFOCUS_EX(OnSetFocus)
			MSG_WM_KILLFOCUS_EX(OnKillFocus)
			MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST, 0x209, OnMouseEvent)
			MESSAGE_HANDLER_EX(WM_MOUSEWHEEL, OnMouseWheel)
			MESSAGE_HANDLER_EX(WM_KEYDOWN, OnKeyDown)
			MESSAGE_HANDLER_EX(WM_KEYUP, OnKeyUp)
			MESSAGE_HANDLER_EX(WM_CHAR, OnChar)
			MESSAGE_HANDLER_EX(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
			SOUI_MSG_MAP_END()
	protected:
		wkeWebView m_pWebView;
		SStringW m_strUrl;
		CSize m_szRtSize;
	};
}
