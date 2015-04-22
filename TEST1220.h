// TEST1220.h : main header file for the TEST1220 application
//

#if !defined(AFX_TEST1220_H__45FF2B16_9A07_4AB4_94CC_788AB9AAE1AD__INCLUDED_)
#define AFX_TEST1220_H__45FF2B16_9A07_4AB4_94CC_788AB9AAE1AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTEST1220App:
// See TEST1220.cpp for the implementation of this class
//

class CTEST1220App : public CWinApp
{
public:
	CTEST1220App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTEST1220App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTEST1220App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1220_H__45FF2B16_9A07_4AB4_94CC_788AB9AAE1AD__INCLUDED_)
