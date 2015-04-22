#if !defined(AFX_CDIALOGPOST_H__47C6FB2D_26D9_47E5_9E74_DFE08A9240FF__INCLUDED_)
#define AFX_CDIALOGPOST_H__47C6FB2D_26D9_47E5_9E74_DFE08A9240FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDialogPost.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogPost dialog

class CDialogPost : public CDialog
{
// Construction
public:
	CDialogPost(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogPost)
	enum { IDD = IDD_DIALOGPOST };
	int		m_Edit_Sian_Shih_X;
	int		m_Edit_Sian_Shih_Y;
	int		m_Edit_Shou_Jian_Ren_X;
	int		m_Edit_Shou_Jian_Ren_Y;
	int		m_Edit_You_Di_X;
	int		m_Edit_You_Di_Y;
	int		m_Edit_You_Di_DisBetween;
	int		m_Edit_Siang_Jhen_X;
	int		m_Edit_Siang_Jhen_Y;
	int		m_Edit_Lu_Jie_X;
	int		m_Edit_Lu_Jie_Y;
	int		m_Edit_Duan_X;
	int		m_Edit_Duan_Y;
	int		m_Edit_Siang_X;
	int		m_Edit_Siang_Y;
	int		m_Edit_Nong_X;
	int		m_Edit_Nong_Y;
	int		m_Edit_Hao_X;
	int		m_Edit_Hao_Y;
	int		m_Edit_Lou_X;
	int		m_Edit_Lou_Y;
	int		m_Edit_Room_X;
	int		m_Edit_Room_Y;
	int		m_Edit_Man_fSize;
	int		m_Edit_Num_fSize;
	int		m_Edit_Addrs_DisBetween;
	int		m_Edit_Shou_Jian_Ren_DisBetween;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogPost)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogPost)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDialogPost)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDIALOGPOST_H__47C6FB2D_26D9_47E5_9E74_DFE08A9240FF__INCLUDED_)
