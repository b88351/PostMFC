// TEST1220View.cpp : implementation of the CTEST1220View class
//

#include "stdafx.h"
#include "TEST1220.h"

#include "TEST1220Doc.h"
#include "TEST1220View.h"

#include ".\NewCellTypes\GridCellCheck.h"

#include "CDialogPost.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define USEDFONT

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View
CDialogPost		CDlg;
CGridCtrl*		m_pGridCtrl = NULL;
extern			Compalan_Data	dCom;

IMPLEMENT_DYNCREATE(CTEST1220View, CView)

BEGIN_MESSAGE_MAP(CTEST1220View, CView)
	//{{AFX_MSG_MAP(CTEST1220View)
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_DIALOG, OnFileDialog)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View construction/destruction

CTEST1220View::CTEST1220View()
{
	m_pGridCtrl = NULL;
}

CTEST1220View::~CTEST1220View()
{
	if (m_pGridCtrl)
		delete m_pGridCtrl;
}

BOOL CTEST1220View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View drawing

void CTEST1220View::OnDraw(CDC* pDC)
{
	CTEST1220Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View printing

BOOL CTEST1220View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTEST1220View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	if (m_pGridCtrl)
		m_pGridCtrl->OnBeginPrinting(pDC, pInfo);
}

void CTEST1220View::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
//	CDialogPost	CDlg;
	//	pInfo->m_nNumPreviewPages = 10;
	pInfo->SetMaxPage(1);
//-----------Load Printer Setting
	PRINTDLG printDlg;
	HDC hDc = NULL;
	AfxGetApp()->GetPrinterDeviceDefaults(&printDlg);
//	CreateDC(
//	GetPrinterDeviceDefults();
//-----------Load Picture------------
//	if (m_pGridCtrl)
//		PrintBmp(pDC, 0 + 945, 0 -450, 2876, 5970, IDB_BITMAP1);
	
//-----------Begin Printing-------------------	
	CString tmpstr;
	int nstrlen;
	int i;

	CRect rt;
	CGridCellCheck * pCellCheck;

//-----------Font------------
//	LOGFONT lf, lf2, lf3;
	LOGFONT *lf = new LOGFONT;
	LOGFONT *lf2 = new LOGFONT;
	LOGFONT *lf3 = new LOGFONT;

	CFont *fnt, *oldfnt/* = new CFont*/;
	CFont *tmpfnt = new CFont;
/*	, tmpfnt, *oldfnt/*, *ptrfn*/;

	int	row = 0;
	int	col = 0;
	row = 1;

//	pInfo->SetMaxPage(10);
	for	(row=1; row <= COM_NUM; row++)
	{
/*
//	load dialog data
		CDlg.m_Edit_Sian_Shih_X = ;
		CDlg.m_Edit_Sian_Shih_Y;
		CDlg.m_Edit_Shou_Jian_Ren_X;
		CDlg.m_Edit_Shou_Jian_Ren_Y;
		CDlg.m_Edit_You_Di_X;
		CDlg.m_Edit_You_Di_Y;
		CDlg.m_Edit_You_Di_DisBetween;
		CDlg.m_Edit_Siang_Jhen_X;
		CDlg.m_Edit_Siang_Jhen_Y;
		CDlg.m_Edit_Lu_Jie_X;
		CDlg.m_Edit_Lu_Jie_Y;
		CDlg.m_Edit_Duan_X;
		CDlg.m_Edit_Duan_Y;
		CDlg.m_Edit_Siang_X;
		CDlg.m_Edit_Siang_Y;
		CDlg.m_Edit_Nong_X;
		CDlg.m_Edit_Nong_Y;
		CDlg.m_Edit_Hao_X;
		CDlg.m_Edit_Hao_Y;
		CDlg.m_Edit_Lou_X;
		CDlg.m_Edit_Lou_Y;
		CDlg.m_Edit_Room_X;
		CDlg.m_Edit_Room_Y;
		CDlg.m_Edit_Man_fSize;
		CDlg.m_Edit_Num_fSize;
		CDlg.m_Edit_Addrs_DisBetween;
		CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
*/

//-----------Check Print_Cell------------
//		if ((((CGridCellCheck*) m_pGridCtrl->GetCell(row,2))->GetCheck()))
		if (	!(	((CGridCellCheck*)m_pGridCtrl->GetCell(row,2))	->GetCheck()	)	)
			continue;

//-----------Load Picture------------
//	pCellCheck = (CGridCellCheck*) m_pGridCtrl->GetCell(row,1);	
		if (((CGridCellCheck*) m_pGridCtrl->GetCell(row,1))->GetCheck())
			PrintBmp(pDC, 0 + 945, 0 -450, 2876, 5970, IDB_BITMAP1);
	


//-----------Load Font------------
		oldfnt = pDC->GetCurrentFont();

#ifdef USEDFONT
		fnt = pDC->GetCurrentFont();
		fnt->CreateFont(
			CDlg.m_Edit_Num_fSize,                        // nHeight
			0,                         // nWidth
			0,                         // nEscapement
			0,                         // nOrientation
			FW_NORMAL,                 // nWeight
			FALSE,                     // bItalic
			FALSE,                     // bUnderline
			0,                         // cStrikeOut
			ANSI_CHARSET,              // nCharSet
			OUT_DEFAULT_PRECIS,        // nOutPrecision
			CLIP_DEFAULT_PRECIS,       // nClipPrecision
			DEFAULT_QUALITY,           // nQuality
			DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
			L"標楷體"
			);

//		fnt->GetLogFont(lf);

/*		lf->lfHeight = 150;
		lf->lfWidth = 0;
		WCHAR fnstr[31] = L"標楷體";
		memcpy(lf->lfFaceName, fnstr, sizeof(fnstr));
		tmpfnt->CreateFontIndirect(lf);
//			MessageBox(L"lf error", L"lf");
*/
		pDC->SelectObject(fnt);/* == NULL)*/
//			MessageBox(L"SelectObject error", L"lf");
#endif

//---------縣---------//
		rt.left = 3351 + CDlg.m_Edit_Sian_Shih_X;
		rt.top = 1000 + CDlg.m_Edit_Sian_Shih_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nSian);
 		nstrlen = m_pGridCtrl->GetItemText(row, nSian).GetLength();
		for (i = 0; i < nstrlen; i++)
		{
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top + 200;
			rt.bottom = rt.top + 200;
		}

//---------市---------//
		rt.left = 3351 + CDlg.m_Edit_Sian_Shih_X;
		rt.top = 1000 + CDlg.m_Edit_Sian_Shih_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nShih);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nShih).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------市2---------//
		rt.left = 3531 + CDlg.m_Edit_Siang_Jhen_X;
		rt.top = 2000 + CDlg.m_Edit_Siang_Jhen_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nShih2);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nShih2).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------鄉---------//
		rt.left = 3531 + CDlg.m_Edit_Siang_Jhen_X;
		rt.top = 2000 + CDlg.m_Edit_Siang_Jhen_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nSiang);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nSiang).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------鎮---------//
		rt.left = 3531 + CDlg.m_Edit_Siang_Jhen_X;
		rt.top = 2000 + CDlg.m_Edit_Siang_Jhen_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nJhen);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nJhen).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------區---------//	
		rt.left = 3531 + CDlg.m_Edit_Siang_Jhen_X;
		rt.top = 2000 + CDlg.m_Edit_Siang_Jhen_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nCyu);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nCyu).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------路---------//
		rt.left = 3050 + CDlg.m_Edit_Lu_Jie_X;
		rt.top = 1340 + CDlg.m_Edit_Lu_Jie_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nLu);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nLu).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------街---------//
		rt.left = 3050 + CDlg.m_Edit_Lu_Jie_X;
		rt.top = 1340 + CDlg.m_Edit_Lu_Jie_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nJie);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nJie).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------段---------//
		rt.left = 3050 + CDlg.m_Edit_Duan_X;
		rt.top =2360+ CDlg.m_Edit_Duan_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nDuan);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nDuan).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top  + 200/*CDlg.m_Edit_D*/;
			rt.bottom = rt.top + 200;
		}

//---------巷---------//
		rt.left = 3050 + CDlg.m_Edit_Siang_X;
		rt.top = 2800 + CDlg.m_Edit_Siang_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nLane);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nLane).GetLength();
		pDC->DrawText(tmpstr, &rt, DT_LEFT | DT_TOP);

//---------弄---------//
		rt.left = 3050 + CDlg.m_Edit_Nong_X;
		rt.top = 3240 + CDlg.m_Edit_Nong_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nNong);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nNong).GetLength();
		pDC->DrawText(tmpstr, &rt, DT_LEFT | DT_TOP);

//---------號---------//
		rt.left = 3050 + CDlg.m_Edit_Hao_X;
		rt.top = 3660 + CDlg.m_Edit_Hao_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nHao);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nHao).GetLength();
		pDC->DrawText(tmpstr, &rt, DT_LEFT | DT_TOP);

//---------樓---------//
		rt.left = 3050 + CDlg.m_Edit_Lou_X;
		rt.top = 4100 + CDlg.m_Edit_Lou_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nLou);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nLou).GetLength();
		pDC->DrawText(tmpstr, &rt, DT_LEFT | DT_TOP);
		
//---------室---------//
		rt.left = 3050 + CDlg.m_Edit_Room_X;
		rt.top = 4545 + CDlg.m_Edit_Room_Y;
		rt.right = rt.left + 300 + CDlg.m_Edit_Num_fSize;
		rt.bottom = rt.top + 300 + CDlg.m_Edit_Num_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row, nRoom);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nRoom).GetLength();
		pDC->DrawText(tmpstr, &rt, DT_LEFT | DT_TOP);

//---------收---------//
/*
#ifdef USEDFONT
		fnt->GetLogFont(lf3);
		lf3->lfHeight = 200;
		lf3->lfWidth = 0;
//		lf3.lfFaceName = L"標楷體";
//		ptrfnt->CreateFontIndirect(&lf3);
//		pDC->SelectObject(ptrfnt);
		tmpfnt->CreateFontIndirect(lf3);
		pDC->SelectObject(fnt);
#endif
*/
		rt.left = 2359/* + CDlg.m_X17*/;
		rt.top = 4500/* + CDlg.m_Y17*/;
		rt.right = rt.left + 300;
		rt.bottom = rt.top + 300;

//		pDC->DrawText(L"收", &rt, DT_LEFT | DT_TOP);

//---------郵遞區號---------//
		rt.left = 2810 + CDlg.m_Edit_You_Di_X;
		rt.top = 281 + CDlg.m_Edit_You_Di_Y;
		rt.right = rt.left + 300;
		rt.bottom = rt.top + 300;

		tmpstr = m_pGridCtrl->GetItemText(row, nYou_Di);	
 		nstrlen = m_pGridCtrl->GetItemText(row, nYou_Di).GetLength();
		for (i = 0; i < nstrlen; i++)
		{	
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.left = rt.left + CDlg.m_Edit_You_Di_DisBetween;
			rt.right = rt.right + 200;
		}


//---------收件人---------//
#ifdef USEDFONT
/*		if (!fnt->GetLogFont(&lf2))
			MessageBox(L"GetLogFont lf2 error", L"lf2");
		lf2.lfHeight = CDlg.m_Edit_Man_fSize;//CDlg.m_Size;//400-450 + 粗
		lf2.lfWidth = 0;

		if (!tmpfnt->CreateFontIndirect(&lf2))
			MessageBox(L"Create lf2 error", L"lf2");
		if (pDC->SelectObject(tmpfnt) == NULL)
			MessageBox(L"SelectObject lf2 error", L"lf2");
*/
//		fnt->GetLogFont(&lf2);
//		tmpfnt.CreateFontIndirect(&lf2);
//		pDC->SelectObject(tmpfnt);

		fnt = pDC->GetCurrentFont();
		fnt->CreateFont(
			CDlg.m_Edit_Man_fSize,     // nHeight
			0,                         // nWidth
			0,                         // nEscapement
			0,                         // nOrientation
			FW_NORMAL,                 // nWeight
			FALSE,                     // bItalic
			FALSE,                     // bUnderline
			0,                         // cStrikeOut
			ANSI_CHARSET,              // nCharSet
			OUT_DEFAULT_PRECIS,        // nOutPrecision
			CLIP_DEFAULT_PRECIS,       // nClipPrecision
			DEFAULT_QUALITY,           // nQuality
			DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
			L"標楷體"
			);                 
		pDC->SelectObject(fnt);
#endif

		rt.left = 2293 + CDlg.m_Edit_Shou_Jian_Ren_X;
		rt.top = 1000 + CDlg.m_Edit_Shou_Jian_Ren_Y;
		rt.right = rt.left + 1000 + CDlg.m_Edit_Man_fSize;
		rt.bottom = rt.top + 1000 + CDlg.m_Edit_Man_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row,nShou_Jian_Ren);
 		nstrlen = m_pGridCtrl->GetItemText(row,nShou_Jian_Ren).GetLength();
		for (i = 0; i < nstrlen; i++)
		{
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top + 400 + CDlg.m_Edit_Man_fSize + CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
			rt.bottom = rt.top + 400 + CDlg.m_Edit_Man_fSize + CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
		}

//		test		//

		rt.left = 2293 + CDlg.m_Edit_Shou_Jian_Ren_X;
		rt.top = 1000 + 10000 + CDlg.m_Edit_Shou_Jian_Ren_Y;
		rt.right = rt.left + 1000 + CDlg.m_Edit_Man_fSize;
		rt.bottom = rt.top + 1000 + CDlg.m_Edit_Man_fSize;

		tmpstr = m_pGridCtrl->GetItemText(row,nShou_Jian_Ren);
 		nstrlen = m_pGridCtrl->GetItemText(row,nShou_Jian_Ren).GetLength();
		for (i = 0; i < nstrlen; i++)
		{
			pDC->DrawText(tmpstr.GetAt(i), &rt, DT_LEFT | DT_TOP);
			rt.top = rt.top + 400 + CDlg.m_Edit_Man_fSize + CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
			rt.bottom = rt.top + 400 + CDlg.m_Edit_Man_fSize + CDlg.m_Edit_Shou_Jian_Ren_DisBetween;
		}


	//------Next Page--------
//		int aaa = Escape(pDC->m_hDC, NEWFRAME, 0, 0L, 0L);
//		int bbb = Escape(pDC->m_hDC, ENDDOC, 0, 0L, 0L);
	//	pDC->m_hDC



	}


//-----------Font------------
//	LOGFONT lf, lf2, lf3;
	delete lf;
	delete lf2;
	delete lf3;

	delete tmpfnt;

	pInfo->m_bContinuePrinting = FALSE;

	CView::OnPrint(pDC, pInfo);
}


void CTEST1220View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	if (m_pGridCtrl)
		m_pGridCtrl->OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View diagnostics

#ifdef _DEBUG
void CTEST1220View::AssertValid() const
{
	CView::AssertValid();
}

void CTEST1220View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTEST1220Doc* CTEST1220View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTEST1220Doc)));
	return (CTEST1220Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTEST1220View message handlers

void CTEST1220View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	if (m_pGridCtrl == NULL)
	{
		// Create the Gridctrl object
		m_pGridCtrl = new CGridCtrl;
		if (!m_pGridCtrl) return;

		// Create the Gridctrl window
		CRect rect;
		GetClientRect(rect);
		m_pGridCtrl->Create(rect, this, 100);

		// fill it up with stuff
		m_pGridCtrl->SetEditable(TRUE);
		m_pGridCtrl->EnableDragAndDrop(TRUE);

		try {
			m_pGridCtrl->SetRowCount(COM_NUM + 1);
			m_pGridCtrl->SetColumnCount(20);
			m_pGridCtrl->SetFixedRowCount(1);
			m_pGridCtrl->SetFixedColumnCount(1);
		}
		catch (CMemoryException* e)
		{
			e->ReportError();
			e->Delete();
			return;
		}

		WCHAR tmpc[100];
		// fill rows/cols with text
		int row = 1;
		int col = 1;
		for	(col = 1; col < 3; col++)
			for (row = 1; row < m_pGridCtrl->GetRowCount(); row++)
			{
				_itow(row,tmpc,10);
				m_pGridCtrl->SetItemText(row,0,tmpc);
				m_pGridCtrl->SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
				m_pGridCtrl->SetItemState(row, col, m_pGridCtrl->GetItemState(row, 1) | !GVIS_READONLY);
			}

		for	(col = 1; col < m_pGridCtrl->GetColumnCount(); col++)
			for (row = 1; row < m_pGridCtrl->GetRowCount(); row++)
				m_pGridCtrl->SetColumnTextLen(col, 20);

		m_pGridCtrl->SetColumnWidth(0, 21);
		m_pGridCtrl->SetItemText(0, nMailer, L"信封");
		m_pGridCtrl->SetColumnWidth(nMailer, 32);
		m_pGridCtrl->SetItemText(0, 2, L"列印");
		m_pGridCtrl->SetColumnWidth(2, 32);
		m_pGridCtrl->SetItemText(0, nShou_Jian_Ren, L"收件人");
		m_pGridCtrl->SetColumnWidth(nShou_Jian_Ren, 70);
		m_pGridCtrl->SetItemText(0, nYou_Di, L"郵遞區號");
		m_pGridCtrl->SetColumnWidth(nYou_Di, 70);
		m_pGridCtrl->SetItemText(0, nSian, L"縣");
		m_pGridCtrl->SetColumnWidth(nSian, 70);
		m_pGridCtrl->SetItemText(0, nShih, L"市");
		m_pGridCtrl->SetColumnWidth(nShih, 70);

		m_pGridCtrl->SetItemText(0, nShih2, L"市2");
		m_pGridCtrl->SetColumnWidth(nShih2, 70);

		m_pGridCtrl->SetItemText(0, nSiang, L"鄉");
		m_pGridCtrl->SetColumnWidth(nSiang, 70);
		m_pGridCtrl->SetItemText(0, nJhen, L"鎮");
		m_pGridCtrl->SetColumnWidth(nJhen, 70);
		m_pGridCtrl->SetItemText(0, nCyu, L"區");
		m_pGridCtrl->SetColumnWidth(nCyu, 70);
		m_pGridCtrl->SetItemText(0, nLu, L"路");
		m_pGridCtrl->SetColumnWidth(nLu, 50);
		m_pGridCtrl->SetItemText(0, nJie, L"街");
		m_pGridCtrl->SetColumnWidth(nJie, 50);
		m_pGridCtrl->SetItemText(0, nDuan, L"段");
		m_pGridCtrl->SetColumnWidth(nDuan, 30);
		m_pGridCtrl->SetItemText(0, nLane, L"巷");
		m_pGridCtrl->SetColumnWidth(nLane, 30);
		m_pGridCtrl->SetItemText(0, nNong, L"弄");
		m_pGridCtrl->SetColumnWidth(nNong, 30);
		m_pGridCtrl->SetItemText(0, nHao, L"號");
		m_pGridCtrl->SetColumnWidth(nHao, 30);
		m_pGridCtrl->SetItemText(0, nLou, L"樓");
		m_pGridCtrl->SetColumnWidth(nLou, 30);
		m_pGridCtrl->SetItemText(0, nRoom, L"室");
		m_pGridCtrl->SetColumnWidth(nRoom, 30);
		m_pGridCtrl->SetItemText(0, nCoordinate, L"座標");
		m_pGridCtrl->SetColumnWidth(nCoordinate, 100);

/*		int a;
		a = m_pGridCtrl->GetColumnWidth(0);	
		m_pGridCtrl->SetColumnWidth(32
*/

//		m_pGridCtrl->AutoSize();
	}
}

void CTEST1220View::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if (m_pGridCtrl->GetSafeHwnd())
	{
		CRect rect;
		GetClientRect(rect);
		m_pGridCtrl->MoveWindow(rect);
	}
}

BOOL CTEST1220View::PrintBmp(CDC* pPrintDC, int x, int y, 
                         int nWidth, int nHeight, UINT nIDResource)
{
    if(!pPrintDC)   return FALSE;

    //:: Draw Button Bitmap  :://
    CDC       MemDC;
    CBitmap   bitmap;
    BITMAP    bm;

    MemDC.CreateCompatibleDC(GetDC());
    //MemDC.SetMapMode(MM_LOMETRIC);

    VERIFY (bitmap.Attach (::LoadImage (::AfxFindResourceHandle(
     MAKEINTRESOURCE (nIDResource), RT_BITMAP),
     MAKEINTRESOURCE (nIDResource), IMAGE_BITMAP, 0, 0,
     (LR_DEFAULTSIZE | LR_CREATEDIBSECTION))));
    
    bitmap.GetBitmap(&bm);

    MemDC.SelectObject(&bitmap);
    pPrintDC->StretchBlt(x, y, nWidth, nHeight, &MemDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

    return  TRUE;
}

void CTEST1220View::OnFileDialog() 
{
	// TODO: Add your command handler code here
	char buff[1024];
//	CDialogPost	CDlg;

	if(CDlg)
		return;

	CCellID cellID;// = pCell->GetGridObj()->GetFocusCell();
	int ncol,nrow;
	cellID = m_pGridCtrl->GetFocusCell();
	ncol=cellID.col;
	nrow=cellID.row;

//	load dialog data
//	m_pGridCtrl->GetItemText(nrow, nCoordinate);
//	int nRet = 	CDlg.DoModal();	
    if(CDlg.DoModal() == IDOK){
//		m_pGridCtrl->SetItemText(n  row, nCoordinate, buff);
	}
}

BOOL CTEST1220View::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	NM_GRIDVIEW *pDispInfo = (NM_GRIDVIEW*)lParam;
	UINT nMessage = pDispInfo->hdr.code;
	CDocument   *pDoc = GetDocument();
	POINT point;
	GetCursorPos(&point);

	CMenu menu;
	menu.LoadMenu(IDR_POPMENU);

	CMenu *PopMenu = menu.GetSubMenu(0);

	switch(nMessage)
	{
		case GVN_ENDLABELEDIT:
//			Save_Grid();
		break;
		case NM_RCLICK :
			if(pDispInfo->iRow >= 1 && pDispInfo->iColumn >=3)
				PopMenu->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, point.x, point.y, this);
		break;
		default:	break;
	}

//	m_pGridCtrl->GetColumnWidth(m_pGridCtrl->GetFocusCell().col);
	return CView::OnNotify(wParam, lParam, pResult);
}

void CTEST1220View::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	m_pGridCtrl->SetFocus();
}
