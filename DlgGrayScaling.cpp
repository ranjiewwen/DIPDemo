// DlgGrayScaling.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgGrayScaling.h"


// CDlgGrayScaling 对话框

IMPLEMENT_DYNAMIC(CDlgGrayScaling, CDialog)

CDlgGrayScaling::CDlgGrayScaling(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGrayScaling::IDD, pParent)
	, m_bX1(0)
	, m_bX2(0)
	, m_bY1(0)
	, m_bY2(0)
{

}

CDlgGrayScaling::~CDlgGrayScaling()
{
}

void CDlgGrayScaling::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bX1);
	DDV_MinMaxByte(pDX, m_bX1, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_bX2);
	DDV_MinMaxByte(pDX, m_bX2, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, m_bY1);
	DDV_MinMaxByte(pDX, m_bY1, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, m_bY2);
	DDV_MinMaxByte(pDX, m_bY2, 0, 255);
}


BEGIN_MESSAGE_MAP(CDlgGrayScaling, CDialog)
END_MESSAGE_MAP()


// CDlgGrayScaling 消息处理程序
