// DlgEdgeSobelPrewitt.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgEdgeSobelPrewitt.h"


// CDlgEdgeSobelPrewitt 对话框

IMPLEMENT_DYNAMIC(CDlgEdgeSobelPrewitt, CDialog)

CDlgEdgeSobelPrewitt::CDlgEdgeSobelPrewitt(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEdgeSobelPrewitt::IDD, pParent)
	, m_bThre(0)
	, m_nEdgeType(0)
	, m_bThining(1)
	, m_bGratOnly(0)
	, isRobert(false)
	, isGauss(false)
	, m_dSigma(0)
{
	
}

CDlgEdgeSobelPrewitt::~CDlgEdgeSobelPrewitt()
{
}

void CDlgEdgeSobelPrewitt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bThre);
	DDV_MinMaxByte(pDX, m_bThre, 0, 255);
	DDX_Check(pDX, IDC_CHECK2, m_bThining);
	DDX_Check(pDX, IDC_CHECK3, m_bGratOnly);
	DDX_Text(pDX, IDC_EDIT2, m_dSigma);
	DDV_MinMaxDouble(pDX, m_dSigma, 0, 5);
}


BEGIN_MESSAGE_MAP(CDlgEdgeSobelPrewitt, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, CDlgEdgeSobelPrewitt::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, CDlgEdgeSobelPrewitt::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, CDlgEdgeSobelPrewitt::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, CDlgEdgeSobelPrewitt::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, CDlgEdgeSobelPrewitt::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK1, CDlgEdgeSobelPrewitt::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, CDlgEdgeSobelPrewitt::OnBnClickedCheck2)
//	ON_WM_CREATE()
ON_WM_ACTIVATE()
ON_BN_CLICKED(IDC_CHECK3, CDlgEdgeSobelPrewitt::OnBnClickedCheck3)
END_MESSAGE_MAP()


// CDlgEdgeSobelPrewitt 消息处理程序

void CDlgEdgeSobelPrewitt::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nEdgeType = 0;
	UpdateData(true);
}

void CDlgEdgeSobelPrewitt::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nEdgeType = 1;
	UpdateData(true);
}

void CDlgEdgeSobelPrewitt::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nEdgeType = 2;
	UpdateData(true);
}

void CDlgEdgeSobelPrewitt::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nEdgeType = 3;
	UpdateData(true);
}

void CDlgEdgeSobelPrewitt::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nEdgeType = 4;
	UpdateData(true);
}

void CDlgEdgeSobelPrewitt::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (IsDlgButtonChecked(IDC_CHECK1)) {
		(CEdit *)GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		m_bThre = 0;
	}
	else
	{
		(CEdit *)GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	}
}

void CDlgEdgeSobelPrewitt::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgEdgeSobelPrewitt::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 在此处添加消息处理程序代码
	if (isRobert)
	{
		(CButton *)GetDlgItem(IDC_RADIO2)->EnableWindow(false);
		(CButton *)GetDlgItem(IDC_RADIO3)->EnableWindow(false);
	}

	if (isGauss)
	{
		(CStatic *)GetDlgItem(IDC_GROUP)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_RADIO3)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_RADIO4)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_RADIO5)->ShowWindow(SW_HIDE);
		(CButton *)GetDlgItem(IDC_CHECK3)->ShowWindow(SW_HIDE);
	}
	else
	{
		(CStatic *)GetDlgItem(IDC_GROUP1)->ShowWindow(SW_HIDE);
		(CStatic *)GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
		(CStatic *)GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
		(CEdit *)GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	}

	CheckDlgButton(IDC_RADIO1, 1);

	CheckDlgButton(IDC_CHECK1, 1);
	CheckDlgButton(IDC_CHECK2, 1);
}

void CDlgEdgeSobelPrewitt::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	static BOOL sbEdit1;
	if (IsDlgButtonChecked(IDC_CHECK3))
	{
		(CButton *)GetDlgItem(IDC_CHECK1)->EnableWindow(false);
		(CButton *)GetDlgItem(IDC_CHECK2)->EnableWindow(false);
		sbEdit1 = ((CEdit *)GetDlgItem(IDC_EDIT1))->IsWindowEnabled();
		(CEdit *)GetDlgItem(IDC_EDIT1)->EnableWindow(false);		
	}
	else
	{
		(CButton *)GetDlgItem(IDC_CHECK1)->EnableWindow(true);
		(CButton *)GetDlgItem(IDC_CHECK2)->EnableWindow(true);
		(CEdit *)GetDlgItem(IDC_EDIT1)->EnableWindow(sbEdit1);
	}
}
