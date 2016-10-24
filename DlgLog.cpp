// DlgLog.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgLog.h"


// CDlgLog 对话框

IMPLEMENT_DYNAMIC(CDlgLog, CDialog)

CDlgLog::CDlgLog(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLog::IDD, pParent)
	, m_dC(0)
{

}

CDlgLog::~CDlgLog()
{
}

void CDlgLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dC);
	DDV_MinMaxDouble(pDX, m_dC, 0, 255);
}


BEGIN_MESSAGE_MAP(CDlgLog, CDialog)
END_MESSAGE_MAP()


// CDlgLog 消息处理程序
