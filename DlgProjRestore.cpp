// DlgProjRestore.cpp : implementation file
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgProjRestore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgProjRestore dialog


CDlgProjRestore::CDlgProjRestore(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgProjRestore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgProjRestore)
	m_xPt1 = 0;
	m_xPt2 = 0;
	m_xPt3 = 0;
	m_xPt4 = 0;
	m_xBPt1 = 0;
	m_xBPt2 = 0;
	m_xBPt3 = 0;
	m_xBPt4 = 0;
	m_yBPt1 = 0;
	m_yBPt2 = 0;
	m_yBPt3 = 0;
	m_yBPt4 = 0;
	m_yPt1 = 0;
	m_yPt2 = 0;
	m_yPt3 = 0;
	m_yPt4 = 0;
	//}}AFX_DATA_INIT
}


void CDlgProjRestore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgProjRestore)
	DDX_Text(pDX, IDC_EDIT_XPT1, m_xPt1);
	DDX_Text(pDX, IDC_EDIT_XPT2, m_xPt2);
	DDX_Text(pDX, IDC_EDIT_XPT3, m_xPt3);
	DDX_Text(pDX, IDC_EDIT_XPT4, m_xPt4);
	DDX_Text(pDX, IDC_EDIT_XBPT1, m_xBPt1);
	DDX_Text(pDX, IDC_EDIT_XBPT2, m_xBPt2);
	DDX_Text(pDX, IDC_EDIT_XBPT3, m_xBPt3);
	DDX_Text(pDX, IDC_EDIT_XBPT4, m_xBPt4);
	DDX_Text(pDX, IDC_EDIT_YBPT1, m_yBPt1);
	DDX_Text(pDX, IDC_EDIT_YBPT2, m_yBPt2);
	DDX_Text(pDX, IDC_EDIT_YBPT3, m_yBPt3);
	DDX_Text(pDX, IDC_EDIT_YBPT4, m_yBPt4);
	DDX_Text(pDX, IDC_EDIT_YPT1, m_yPt1);
	DDX_Text(pDX, IDC_EDIT_YPT2, m_yPt2);
	DDX_Text(pDX, IDC_EDIT_YPT3, m_yPt3);
	DDX_Text(pDX, IDC_EDIT_YPT4, m_yPt4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgProjRestore, CDialog)
	//{{AFX_MSG_MAP(CDlgProjRestore)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgProjRestore message handlers
