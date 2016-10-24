#if !defined(AFX_DLGMORPH_H__83FE3CDB_75BB_4990_BBAE_7AEE9471FAEB__INCLUDED_)
#define AFX_DLGMORPH_H__83FE3CDB_75BB_4990_BBAE_7AEE9471FAEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMorph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMorph dialog

class CDlgMorph : public CDialog
{
// Construction
public:
	CDlgMorph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMorph)
	enum { IDD = IDD_DLG_MORPH };
	int		m_se00;
	int		m_se01;
	int		m_se02;
	int		m_se10;
	int		m_se11;
	int		m_se12;
	int		m_se20;
	int		m_se21;
	int		m_se22;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMorph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMorph)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMORPH_H__83FE3CDB_75BB_4990_BBAE_7AEE9471FAEB__INCLUDED_)
