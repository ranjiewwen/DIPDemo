#if !defined(AFX_DLGPROJRESTORE_H__7EAC24A8_9E17_4913_89F1_B879BBF87AF8__INCLUDED_)
#define AFX_DLGPROJRESTORE_H__7EAC24A8_9E17_4913_89F1_B879BBF87AF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgProjRestore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgProjRestore dialog

class CDlgProjRestore : public CDialog
{
// Construction
public:
	CDlgProjRestore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgProjRestore)
	enum { IDD = IDD_DLG_PROJRESTORE };
	UINT	m_xPt1;
	UINT	m_xPt2;
	UINT	m_xPt3;
	UINT	m_xPt4;
	UINT	m_xBPt1;
	UINT	m_xBPt2;
	UINT	m_xBPt3;
	UINT	m_xBPt4;
	UINT	m_yBPt1;
	UINT	m_yBPt2;
	UINT	m_yBPt3;
	UINT	m_yBPt4;
	UINT	m_yPt1;
	UINT	m_yPt2;
	UINT	m_yPt3;
	UINT	m_yPt4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgProjRestore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgProjRestore)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROJRESTORE_H__7EAC24A8_9E17_4913_89F1_B879BBF87AF8__INCLUDED_)
