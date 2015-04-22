// TEST1220Doc.h : interface of the CTEST1220Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1220DOC_H__D0BB5979_B1DC_4D5E_BDFB_3C553AC9253B__INCLUDED_)
#define AFX_TEST1220DOC_H__D0BB5979_B1DC_4D5E_BDFB_3C553AC9253B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define COORDINATE_SIZE				1024
#define COMPALAN_SIZE				1024

struct Coordinate_Data
{
	unsigned int	m_Edit_Sian_Shih;
	unsigned int	m_Edit_Sian_Shih_Y;
	unsigned int	m_Edit_Shou_Jian_Ren_X;
	unsigned int	m_Edit_Shou_Jian_Ren_Y;
	unsigned int	m_Edit_You_Di_X;
	unsigned int	m_Edit_You_Di_Y;
	unsigned int	m_Edit_You_Di_DisBetween;
	unsigned int	m_Edit_Siang_Jhen_X;
	unsigned int	m_Edit_Siang_Jhen_Y;
	unsigned int	m_Edit_Lu_Jie_X;
	unsigned int	m_Edit_Lu_Jie_Y;
	unsigned int	m_Edit_Duan_X;
	unsigned int	m_Edit_Duan_Y;
	unsigned int	m_Edit_Siang_X;
	unsigned int	m_Edit_Siang_Y;
	unsigned int	m_Edit_Nong_X;
	unsigned int	m_Edit_Nong_Y;
	unsigned int	m_Edit_Hao_X;
	unsigned int	m_Edit_Hao_Y;
	unsigned int	m_Edit_Lou_X;
	unsigned int	m_Edit_Lou_Y;
	unsigned int	m_Edit_Room_X;
	unsigned int	m_Edit_Room_Y;
	unsigned int	m_Edit_Man_Size;
	unsigned int	m_Edit_Num_Size;
};

struct Compalan_Data
{
	CString m_cShou_Jian_Ren;	//	����H
	CString m_cSian;				//	��
	CString m_cShih;				//	��

	CString m_cShih2;				//	��2

	CString m_cSiang;				//	�m
	CString m_cJhen;				//	��
	CString m_cCyu;				//	��
	CString m_cLu;				//	��
	CString m_cJie;				//	��
	CString m_cDuan;				//	�q
	CString m_cRoom;				//	��
	CString  m_nYou_Di;			//	�l���ϸ�
	CString  m_nLane;				//	��
	CString  m_nNong;				//	��
	CString  m_nHao;				//	��
	CString  m_nLou;				//	��
	Coordinate_Data m_dCoordinate;			//	�y��
};

class CTEST1220Doc : public CDocument
{
protected: // create from serialization only
	CTEST1220Doc();
	DECLARE_DYNCREATE(CTEST1220Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTEST1220Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTEST1220Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTEST1220Doc)
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1220DOC_H__D0BB5979_B1DC_4D5E_BDFB_3C553AC9253B__INCLUDED_)
