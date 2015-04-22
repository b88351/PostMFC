// TEST1220Doc.cpp : implementation of the CTEST1220Doc class
//

#include "stdafx.h"
#include "TEST1220.h"

#include "TEST1220Doc.h"
#include "TEST1220View.h"

#include "CDialogPost.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTEST1220Doc

extern			CGridCtrl	*	m_pGridCtrl;
extern			CDialogPost		CDlg;

Compalan_Data	*dCom[COM_NUM + 1];

IMPLEMENT_DYNCREATE(CTEST1220Doc, CDocument)

BEGIN_MESSAGE_MAP(CTEST1220Doc, CDocument)
	//{{AFX_MSG_MAP(CTEST1220Doc)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTEST1220Doc construction/destruction

CTEST1220Doc::CTEST1220Doc()
{
    m_pGridCtrl = new CGridCtrl;
}

CTEST1220Doc::~CTEST1220Doc()
{
	if(m_pGridCtrl!=NULL)
		delete  m_pGridCtrl;
	m_pGridCtrl = NULL;
}

BOOL CTEST1220Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i=0;i <= COM_NUM;i++)
	{
		dCom[i] = new Compalan_Data;
	}
	
	int col, row;
	if (m_pGridCtrl != NULL)
	for	(col = 1; col < m_pGridCtrl->GetColumnCount(); col++)
		for (row = 1; row < m_pGridCtrl->GetRowCount(); row++)
			m_pGridCtrl->SetItemText(row, col, L"");


	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTEST1220Doc serialization
BOOL Save_Grid();
BOOL UpDate_Grid();
void SaveCoordinate(CArchive& ar, int i);
void LoadCoordinate(CArchive& ar, int i);

void SaveCompany(CArchive& ar, int i)
{
	ar << dCom[i]->m_cShou_Jian_Ren;	//	收件人
	ar << dCom[i]->m_cSian;				//	縣
	ar << dCom[i]->m_cShih;				//	市
	ar << dCom[i]->m_cSiang;				//	鄉
	ar << dCom[i]->m_cJhen;				//	鎮
	ar << dCom[i]->m_cCyu;				//	區
	ar << dCom[i]->m_cLu;				//	路
	ar << dCom[i]->m_cJie;				//	街
	ar << dCom[i]->m_cDuan;				//	段
	ar << dCom[i]->m_cRoom;				//	室
	ar << dCom[i]->m_nYou_Di;			//	郵遞區號
	ar << dCom[i]->m_nLane;				//	巷
	ar << dCom[i]->m_nNong;				//	弄
	ar << dCom[i]->m_nHao;				//	號
	ar << dCom[i]->m_nLou;				//	樓
	SaveCoordinate(ar,i);
//	ar << dCom[i].m_dCoordinate;			//	座標
}

void LoadCompany(CArchive& ar, int i)
{
	ar >> dCom[i]->m_cShou_Jian_Ren;	//	收件人
	ar >> dCom[i]->m_cSian;				//	縣
	ar >> dCom[i]->m_cShih;				//	市
	ar >> dCom[i]->m_cSiang;				//	鄉
	ar >> dCom[i]->m_cJhen;				//	鎮
	ar >> dCom[i]->m_cCyu;				//	區
	ar >> dCom[i]->m_cLu;				//	路
	ar >> dCom[i]->m_cJie;				//	街
	ar >> dCom[i]->m_cDuan;				//	段
	ar >> dCom[i]->m_cRoom;				//	室
	ar >> dCom[i]->m_nYou_Di;			//	郵遞區號
	ar >> dCom[i]->m_nLane;				//	巷
	ar >> dCom[i]->m_nNong;				//	弄
	ar >> dCom[i]->m_nHao;				//	號
	ar >> dCom[i]->m_nLou;				//	樓
	LoadCoordinate(ar,i);
	//	ar >> dCom[i].m_dCoordinate;			//	座標
}

void SaveCoordinate(CArchive& ar, int i)
{
	ar << dCom[i]->m_dCoordinate.m_Edit_Sian_Shih;
	ar << dCom[i]->m_dCoordinate.m_Edit_Sian_Shih_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Shou_Jian_Ren_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Shou_Jian_Ren_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_You_Di_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_You_Di_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_You_Di_DisBetween;
	ar << dCom[i]->m_dCoordinate.m_Edit_Siang_Jhen_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Siang_Jhen_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Lu_Jie_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Lu_Jie_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Duan_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Duan_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Siang_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Siang_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Nong_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Nong_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Hao_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Hao_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Lou_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Lou_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Room_X;
	ar << dCom[i]->m_dCoordinate.m_Edit_Room_Y;
	ar << dCom[i]->m_dCoordinate.m_Edit_Man_Size;
	ar << dCom[i]->m_dCoordinate.m_Edit_Num_Size;
}

void LoadCoordinate(CArchive& ar, int i)
{
	ar >> dCom[i]->m_dCoordinate.m_Edit_Sian_Shih;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Sian_Shih_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Shou_Jian_Ren_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Shou_Jian_Ren_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_You_Di_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_You_Di_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_You_Di_DisBetween;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Siang_Jhen_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Siang_Jhen_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Lu_Jie_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Lu_Jie_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Duan_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Duan_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Siang_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Siang_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Nong_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Nong_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Hao_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Hao_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Lou_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Lou_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Room_X;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Room_Y;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Man_Size;
	ar >> dCom[i]->m_dCoordinate.m_Edit_Num_Size;
}

void CTEST1220Doc::Serialize(CArchive& ar)
{
	int i;
	char  enter;
	if (ar.IsStoring())
	{
		Save_Grid();
		for(i=0; i < COM_NUM; i++)
        {
//			ar.Write(&(pSystemPLU->PLU_Struct[i].context), PER_PLU_SIZE);
			SaveCompany(ar, i);
//			ar.Write(&(pSystemPLU->PLU_Struct[i].context), PER_PLU_SIZE);
//			SaveCoordinate(ar, i);
			ar << '\n';
		}
//------------save dialog-----------
		{
			ar << CDlg.m_Edit_Sian_Shih_X;
			ar << CDlg.m_Edit_Sian_Shih_Y;
			ar << CDlg.m_Edit_Shou_Jian_Ren_X;
			ar << CDlg.m_Edit_Shou_Jian_Ren_Y;
			ar << CDlg.m_Edit_You_Di_X;
			ar << CDlg.m_Edit_You_Di_Y;
			ar << CDlg.m_Edit_You_Di_DisBetween;
			ar << CDlg.m_Edit_Siang_Jhen_X;
			ar << CDlg.m_Edit_Siang_Jhen_Y;
			ar << CDlg.m_Edit_Lu_Jie_X;
			ar << CDlg.m_Edit_Lu_Jie_Y;
			ar << CDlg.m_Edit_Duan_X;
			ar << CDlg.m_Edit_Duan_Y;
			ar << CDlg.m_Edit_Siang_X;
			ar << CDlg.m_Edit_Siang_Y;
			ar << CDlg.m_Edit_Nong_X;
			ar << CDlg.m_Edit_Nong_Y;
			ar << CDlg.m_Edit_Hao_X;
			ar << CDlg.m_Edit_Hao_Y;
			ar << CDlg.m_Edit_Lou_X;
			ar << CDlg.m_Edit_Lou_Y;
			ar << CDlg.m_Edit_Room_X;
			ar << CDlg.m_Edit_Room_Y;
			ar << CDlg.m_Edit_Man_fSize;
			ar << CDlg.m_Edit_Num_fSize;
			ar << CDlg.m_Edit_Addrs_DisBetween;
			ar << CDlg.m_Edit_Shou_Jian_Ren_DisBetween;

		} 
	}
	else
	{
		for(i=0; i<COM_NUM; i++)
		{
//			ar.Read(&(pSystemPLU->PLU_Struct[i].context), PER_PLU_SIZE);
			LoadCompany(ar, i);
//			ar.Write(&(pSystemPLU->PLU_Struct[i].context), PER_PLU_SIZE);
//			LoadCoordinate(ar, i);
			ar.Read(&enter, 1);     // skip RETURN
		}
//------------load dialog-----------
		{
			ar >> CDlg.m_Edit_Sian_Shih_X;
			ar >> CDlg.m_Edit_Sian_Shih_Y;
			ar >> CDlg.m_Edit_Shou_Jian_Ren_X;
			ar >> CDlg.m_Edit_Shou_Jian_Ren_Y;
			ar >> CDlg.m_Edit_You_Di_X;
			ar >> CDlg.m_Edit_You_Di_Y;
			ar >> CDlg.m_Edit_You_Di_DisBetween;
			ar >> CDlg.m_Edit_Siang_Jhen_X;
			ar >> CDlg.m_Edit_Siang_Jhen_Y;
			ar >> CDlg.m_Edit_Lu_Jie_X;
			ar >> CDlg.m_Edit_Lu_Jie_Y;
			ar >> CDlg.m_Edit_Duan_X;
			ar >> CDlg.m_Edit_Duan_Y;
			ar >> CDlg.m_Edit_Siang_X;
			ar >> CDlg.m_Edit_Siang_Y;
			ar >> CDlg.m_Edit_Nong_X;
			ar >> CDlg.m_Edit_Nong_Y;
			ar >> CDlg.m_Edit_Hao_X;
			ar >> CDlg.m_Edit_Hao_Y;
			ar >> CDlg.m_Edit_Lou_X;
			ar >> CDlg.m_Edit_Lou_Y;
			ar >> CDlg.m_Edit_Room_X;
			ar >> CDlg.m_Edit_Room_Y;
			ar >> CDlg.m_Edit_Man_fSize;
			ar >> CDlg.m_Edit_Num_fSize;
			ar >> CDlg.m_Edit_Addrs_DisBetween;
			ar >> CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
		} 

		UpDate_Grid();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTEST1220Doc diagnostics

#ifdef _DEBUG
void CTEST1220Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTEST1220Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTEST1220Doc commands

void CTEST1220Doc::OnEditCopy() 
{
    m_pGridCtrl->OnEditCopy();

}

void CTEST1220Doc::OnEditCut() 
{
	m_pGridCtrl->OnEditCut();
}

void CTEST1220Doc::OnEditPaste() 
{
	m_pGridCtrl->OnEditPaste();
}

void CTEST1220Doc::OnFileOpen() 
{
    CString   strFilter, strExt;
    GetDocTemplate()->GetDocString(strFilter, CDocTemplate::filterName);
    GetDocTemplate()->GetDocString(strExt, CDocTemplate::filterExt);

    strFilter += L"|*";
    strFilter += strExt;
    strFilter += L"|";

    CFileDialog dlgFile(TRUE, NULL, NULL, 
		       OFN_HIDEREADONLY,
		       strFilter,
		       AfxGetMainWnd());

    if(dlgFile.DoModal() == IDOK)
    {
//        if(!SaveModified())   return;

        OnOpenDocument(dlgFile.GetPathName());
		m_pGridCtrl->RedrawWindow();//GridUpdata();
    }	
}

void CTEST1220Doc::OnFileSave() 
{
	// TODO: Add your command handler code here
	
}

//	-----------Grid Funtion--------------
//	Save m_pGridCtrl Data
BOOL Save_Grid()
{
	if (m_pGridCtrl == NULL)
		return false;

	int col, row;
	for	(row = 1; row <= COM_NUM; row++)
	{
		dCom[row-1]->m_cShou_Jian_Ren	=	m_pGridCtrl->GetItemText(row, nShou_Jian_Ren);
		dCom[row-1]->m_nYou_Di			=	m_pGridCtrl->GetItemText(row, nYou_Di);
		dCom[row-1]->m_cSian			=	m_pGridCtrl->GetItemText(row, nSian);
		dCom[row-1]->m_cShih			=	m_pGridCtrl->GetItemText(row, nShih);

		dCom[row-1]->m_cShih2			=	m_pGridCtrl->GetItemText(row, nShih2);

		dCom[row-1]->m_cSiang			=	m_pGridCtrl->GetItemText(row, nSiang);
		dCom[row-1]->m_cJhen			=	m_pGridCtrl->GetItemText(row, nJhen);
		dCom[row-1]->m_cCyu				=	m_pGridCtrl->GetItemText(row, nCyu);
		dCom[row-1]->m_cLu				=	m_pGridCtrl->GetItemText(row, nLu);
		dCom[row-1]->m_cJie				=	m_pGridCtrl->GetItemText(row, nJie);
		dCom[row-1]->m_cDuan			=	m_pGridCtrl->GetItemText(row, nDuan);
		dCom[row-1]->m_nLane			=	m_pGridCtrl->GetItemText(row, nLane);
		dCom[row-1]->m_nNong			=	m_pGridCtrl->GetItemText(row, nNong);
		dCom[row-1]->m_nHao				=	m_pGridCtrl->GetItemText(row, nHao);
		dCom[row-1]->m_nLou				=	m_pGridCtrl->GetItemText(row, nLou);
		dCom[row-1]->m_cRoom			=	m_pGridCtrl->GetItemText(row, nRoom);
//		dCom[row-1]->m_dCoordinate		=	m_pGridCtrl->GetItemText(row, nCoordinate);
	}

	return true;
}


BOOL UpDate_Grid()
{
	if (m_pGridCtrl == NULL)
		return false;

	CString tmpstr;
	char cstr[11];
	WCHAR wcstr[11];
	int col, row;

	for	(row = 1; row <= COM_NUM; row++)
	{	
		m_pGridCtrl->SetItemText(row, nShou_Jian_Ren,	dCom[row-1]->m_cShou_Jian_Ren);		//	收件人
		m_pGridCtrl->SetItemText(row, nYou_Di,			dCom[row-1]->m_nYou_Di);			//	郵遞區號
		m_pGridCtrl->SetItemText(row, nSian,			dCom[row-1]->m_cSian);				//	縣
		m_pGridCtrl->SetItemText(row, nShih,			dCom[row-1]->m_cShih);				//	市

		m_pGridCtrl->SetItemText(row, nShih2,			dCom[row-1]->m_cShih2);				//	市2

		m_pGridCtrl->SetItemText(row, nSiang,			dCom[row-1]->m_cSiang);				//	鄉
		m_pGridCtrl->SetItemText(row, nJhen,			dCom[row-1]->m_cJhen);				//	鎮
		m_pGridCtrl->SetItemText(row, nCyu,				dCom[row-1]->m_cCyu);				//	區
		m_pGridCtrl->SetItemText(row, nLu,				dCom[row-1]->m_cLu);				//	路
		m_pGridCtrl->SetItemText(row, nJie,				dCom[row-1]->m_cJie);				//	街
		m_pGridCtrl->SetItemText(row, nDuan,			dCom[row-1]->m_cDuan);				//	段
		m_pGridCtrl->SetItemText(row, nLane,			dCom[row-1]->m_nLane);				//	巷
		m_pGridCtrl->SetItemText(row, nNong,			dCom[row-1]->m_nNong);				//	弄
		m_pGridCtrl->SetItemText(row, nHao,				dCom[row-1]->m_nHao);				//	號
		m_pGridCtrl->SetItemText(row, nLou,				dCom[row-1]->m_nLou);				//	樓
		m_pGridCtrl->SetItemText(row, nRoom,			dCom[row-1]->m_cRoom);				//	室
//		m_pGridCtrl->SetItemText(row, nCoordinate,		dCom[row-1]->m_dCoordinate);		//	座標
	}
		
	return true;

}
