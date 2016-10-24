// DlgFreqIdealLPF.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgFreqIdealLPF.h"


// CDlgFreqIdealLPF 对话框

IMPLEMENT_DYNAMIC(CDlgFreqIdealLPF, CDialog)

CDlgFreqIdealLPF::CDlgFreqIdealLPF(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFreqIdealLPF::IDD, pParent)
	, m_nFreq(0)
{

}

CDlgFreqIdealLPF::~CDlgFreqIdealLPF()
{
}

void CDlgFreqIdealLPF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nFreq);
	DDV_MinMaxInt(pDX, m_nFreq, 0, 65535);
}


BEGIN_MESSAGE_MAP(CDlgFreqIdealLPF, CDialog)
END_MESSAGE_MAP()


// CDlgFreqIdealLPF 消息处理程序
