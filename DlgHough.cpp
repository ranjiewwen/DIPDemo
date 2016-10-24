// DlgHough.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgHough.h"


// CDlgHough 对话框

IMPLEMENT_DYNAMIC(CDlgHough, CDialog)

CDlgHough::CDlgHough(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHough::IDD, pParent)
	, m_nNum(0)
{

}

CDlgHough::~CDlgHough()
{
}

void CDlgHough::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nNum);
	DDV_MinMaxInt(pDX, m_nNum, 0, 40);
}


BEGIN_MESSAGE_MAP(CDlgHough, CDialog)
END_MESSAGE_MAP()


// CDlgHough 消息处理程序
