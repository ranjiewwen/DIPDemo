// DlgPointThre.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgPointThre.h"


// CDlgPointThre 对话框

IMPLEMENT_DYNAMIC(CDlgPointThre, CDialog)

CDlgPointThre::CDlgPointThre(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPointThre::IDD, pParent)
	, m_bThre(0)
{

}

CDlgPointThre::~CDlgPointThre()
{
}

void CDlgPointThre::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Thre, m_bThre);
	DDV_MinMaxByte(pDX, m_bThre, 0, 255);
}


BEGIN_MESSAGE_MAP(CDlgPointThre, CDialog)
END_MESSAGE_MAP()


// CDlgPointThre 消息处理程序
