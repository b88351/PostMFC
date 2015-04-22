// CDialogPost.cpp : implementation file
//

#include "stdafx.h"
#include "TEST1220.h"
#include "CDialogPost.h"
#include "GridCtrl_src/GridCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogPost dialog
extern			CGridCtrl	*	m_pGridCtrl;

CDialogPost::CDialogPost(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogPost::IDD, pParent)
{
	EnableAutomation();
	//{{AFX_DATA_INIT(CDialogPost)
	m_Edit_You_Di_DisBetween = 180;
	m_Edit_Man_fSize = 300;
	m_Edit_Num_fSize = 150;
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogPost::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CDialogPost::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogPost)
	DDX_Text(pDX, IDC_EDIT_Sian_Shih_X, m_Edit_Sian_Shih_X);
	DDX_Text(pDX, IDC_EDIT_Sian_Shih_Y, m_Edit_Sian_Shih_Y);
	DDX_Text(pDX, IDC_EDIT_Shou_Jian_Ren_X, m_Edit_Shou_Jian_Ren_X);
	DDX_Text(pDX, IDC_EDIT_Shou_Jian_Ren_Y, m_Edit_Shou_Jian_Ren_Y);
	DDX_Text(pDX, IDC_EDIT_You_Di_X, m_Edit_You_Di_X);
	DDX_Text(pDX, IDC_EDIT_You_Di_Y, m_Edit_You_Di_Y);
	DDX_Text(pDX, IDC_EDIT_You_Di_DisBetween, m_Edit_You_Di_DisBetween);
	DDX_Text(pDX, IDC_EDIT_Siang_Jhen_X, m_Edit_Siang_Jhen_X);
	DDX_Text(pDX, IDC_EDIT_Siang_Jhen_Y, m_Edit_Siang_Jhen_Y);
	DDX_Text(pDX, IDC_EDIT_Lu_Jie_X, m_Edit_Lu_Jie_X);
	DDX_Text(pDX, IDC_EDIT_Lu_Jie_Y, m_Edit_Lu_Jie_Y);
	DDX_Text(pDX, IDC_EDIT_Duan_X, m_Edit_Duan_X);
	DDX_Text(pDX, IDC_EDIT_Duan_Y, m_Edit_Duan_Y);
	DDX_Text(pDX, IDC_EDIT_Siang_X, m_Edit_Siang_X);
	DDX_Text(pDX, IDC_EDIT_Siang_Y, m_Edit_Siang_Y);
	DDX_Text(pDX, IDC_EDIT_Nong_X, m_Edit_Nong_X);
	DDX_Text(pDX, IDC_EDIT_Nong_Y, m_Edit_Nong_Y);
	DDX_Text(pDX, IDC_EDIT_Hao_X, m_Edit_Hao_X);
	DDX_Text(pDX, IDC_EDIT_Hao_Y, m_Edit_Hao_Y);
	DDX_Text(pDX, IDC_EDIT_Lou_X, m_Edit_Lou_X);
	DDX_Text(pDX, IDC_EDIT_Lou_Y, m_Edit_Lou_Y);
	DDX_Text(pDX, IDC_EDIT_Room_X, m_Edit_Room_X);
	DDX_Text(pDX, IDC_EDIT_Room_Y, m_Edit_Room_Y);
	DDX_Text(pDX, IDC_EDIT_Man_fSize, m_Edit_Man_fSize);
	DDX_Text(pDX, IDC_EDIT_Num_fSize, m_Edit_Num_fSize);
	DDX_Text(pDX, IDC_EDIT_Addrs_DisBetween, m_Edit_Addrs_DisBetween);
	DDX_Text(pDX, IDC_EDIT_Shou_Jian_Ren_DisBetween, m_Edit_Shou_Jian_Ren_DisBetween);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogPost, CDialog)
	//{{AFX_MSG_MAP(CDialogPost)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDialogPost, CDialog)
	//{{AFX_DISPATCH_MAP(CDialogPost)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDialogPost to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {835FEBEF-3438-4D5D-A673-9F0EA84C7DFE}
static const IID IID_IDialogPost =
{ 0x835febef, 0x3438, 0x4d5d, { 0xa6, 0x73, 0x9f, 0xe, 0xa8, 0x4c, 0x7d, 0xfe } };

BEGIN_INTERFACE_MAP(CDialogPost, CDialog)
	INTERFACE_PART(CDialogPost, IID_IDialogPost, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogPost message handlers
