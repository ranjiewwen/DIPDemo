// DlgMorph.cpp : implementation file
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgMorph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMorph dialog


CDlgMorph::CDlgMorph(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMorph::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMorph)
	m_se00 = 1;
	m_se01 = 1;
	m_se02 = 1;
	m_se10 = 1;
	m_se11 = 1;
	m_se12 = 1;
	m_se20 = 1;
	m_se21 = 1;
	m_se22 = 1;
	//}}AFX_DATA_INIT
}


void CDlgMorph::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMorph)
	DDX_Text(pDX, IDC_EDIT1, m_se00);
	DDV_MinMaxInt(pDX, m_se00, -1, 1);
	DDX_Text(pDX, IDC_EDIT2, m_se01);
	DDV_MinMaxInt(pDX, m_se01, -1, 1);
	DDX_Text(pDX, IDC_EDIT3, m_se02);
	DDV_MinMaxInt(pDX, m_se02, -1, 1);
	DDX_Text(pDX, IDC_EDIT4, m_se10);
	DDV_MinMaxInt(pDX, m_se10, -1, 1);
	DDX_Text(pDX, IDC_EDIT5, m_se11);
	DDV_MinMaxInt(pDX, m_se11, -1, 1);
	DDX_Text(pDX, IDC_EDIT6, m_se12);
	DDV_MinMaxInt(pDX, m_se12, -1, 1);
	DDX_Text(pDX, IDC_EDIT7, m_se20);
	DDV_MinMaxInt(pDX, m_se20, -1, 1);
	DDX_Text(pDX, IDC_EDIT8, m_se21);
	DDV_MinMaxInt(pDX, m_se21, -1, 1);
	DDX_Text(pDX, IDC_EDIT9, m_se22);
	DDV_MinMaxInt(pDX, m_se22, -1, 1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMorph, CDialog)
	//{{AFX_MSG_MAP(CDlgMorph)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMorph message handlers
