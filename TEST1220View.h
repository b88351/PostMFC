// TEST1220View.h : interface of the CTEST1220View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1220VIEW_H__011D1F8F_FE0C_4538_A6D5_264FB09C1F02__INCLUDED_)
#define AFX_TEST1220VIEW_H__011D1F8F_FE0C_4538_A6D5_264FB09C1F02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GridCtrl_src/GridCtrl.h"

#define COM_NUM			50

enum{nMailer=1,			//	信封

	 nShou_Jian_Ren=3,	//	收件人
	 nYou_Di,			//	郵遞區號
	 nSian,				//	縣
	 nShih,				//	市
	 nShih2,				//	市2
	 nSiang,			//	鄉
	 nJhen,				//	鎮
	 nCyu,				//	區
	 nLu,				//	路
	 nJie,				//	街
	 nDuan,				//	段
	 nLane,				//	巷
	 nNong,				//	弄
	 nHao,				//	號
	 nLou,				//	樓
	 nRoom,				//	室
	 nCoordinate		//	座標
};

class CTEST1220View : public CView
{
protected: // create from serialization only
	CTEST1220View();
	DECLARE_DYNCREATE(CTEST1220View)

// Attributes
public:
	CTEST1220Doc* GetDocument();
//	CGridCtrl* m_pGridCtrl;
	BOOL PrintBmp(CDC* pPrintDC, int x, int y, 
                  int nWidth, int nHeight, UINT nIDResource);
	BOOL Grid2Dlg();
	BOOL Dlg2Grid();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTEST1220View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTEST1220View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTEST1220View)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileDialog();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TEST1220View.cpp
inline CTEST1220Doc* CTEST1220View::GetDocument()
   { return (CTEST1220Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1220VIEW_H__011D1F8F_FE0C_4538_A6D5_264FB09C1F02__INCLUDED_)
