// DlgGamma.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgGamma.h"


// CDlgGamma 对话框

IMPLEMENT_DYNAMIC(CDlgGamma, CDialog)

CDlgGamma::CDlgGamma(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGamma::IDD, pParent)
	, m_dEsp(0)
	, m_dGamma(0)
{

}

CDlgGamma::~CDlgGamma()
{
}

void CDlgGamma::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_dEsp);
	DDV_MinMaxDouble(pDX, m_dEsp, 0, 255);
	DDX_Text(pDX, IDC_EDIT1, m_dGamma);
	DDV_MinMaxDouble(pDX, m_dGamma, 0, 255);
}


BEGIN_MESSAGE_MAP(CDlgGamma, CDialog)
END_MESSAGE_MAP()


// CDlgGamma 消息处理程序
