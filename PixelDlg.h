#if !defined(AFX_PIXELDLG_H__80CDF5FA_0F41_43E3_90A6_AC40B59CEB06__INCLUDED_)
#define AFX_PIXELDLG_H__80CDF5FA_0F41_43E3_90A6_AC40B59CEB06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PixelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPixelDlg dialog

class CPixelDlg : public CDialog
{
// Construction
public:
	CPixelDlg(CView* pView);   // standard constructor
	BOOL Create();
	SCROLLINFO scrollinfo1;
	SCROLLINFO scrollinfo0;
//	int Hpage1;
// Dialog Data
	//{{AFX_DATA(CPixelDlg)
	enum { IDD = IDD_SHOWPIXEL };
	CScrollBar	m_vScroll;
	CScrollBar	m_hScroll;
	
	//}}AFX_DATA

public:
	int FirstOpen;
	void ScrollShow(int pos0,int pos1);
	CView* m_pView;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPixelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPixelDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCancelMode();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIXELDLG_H__80CDF5FA_0F41_43E3_90A6_AC40B59CEB06__INCLUDED_)
