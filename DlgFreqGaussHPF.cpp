// DlgFreqGaussHPF.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgFreqGaussHPF.h"


// CDlgFreqGaussHPF 对话框

IMPLEMENT_DYNAMIC(CDlgFreqGaussHPF, CDialog)

CDlgFreqGaussHPF::CDlgFreqGaussHPF(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFreqGaussHPF::IDD, pParent)
	, m_dSigma(0)
{

}

CDlgFreqGaussHPF::~CDlgFreqGaussHPF()
{
}

void CDlgFreqGaussHPF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dSigma);
	DDV_MinMaxDouble(pDX, m_dSigma, 0, 256);
}


BEGIN_MESSAGE_MAP(CDlgFreqGaussHPF, CDialog)
END_MESSAGE_MAP()


// CDlgFreqGaussHPF 消息处理程序
