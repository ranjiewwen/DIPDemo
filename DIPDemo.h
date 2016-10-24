// DIPDemo.h : main header file for the DIPDemo application
//

#if !defined(AFX_DIPDemo_H__DD0FB619_2B6D_4BE0_9979_B6EF4A78EC25__INCLUDED_)
#define AFX_DIPDemo_H__DD0FB619_2B6D_4BE0_9979_B6EF4A78EC25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoApp:
// See DIPDemo.cpp for the implementation of this class
//

class CDIPDemoApp : public CWinApp
{
public:
	CDIPDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIPDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDIPDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIPDemo_H__DD0FB619_2B6D_4BE0_9979_B6EF4A78EC25__INCLUDED_)
