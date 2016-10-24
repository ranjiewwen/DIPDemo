// DlgLinTrans.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgLinTrans.h"


// CDlgLinTrans 对话框

IMPLEMENT_DYNAMIC(CDlgLinTrans, CDialog)

CDlgLinTrans::CDlgLinTrans(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLinTrans::IDD, pParent)
	, m_bS1(0)
	, m_bS2(0)
	, m_bT1(0)
	, m_bT2(0)
{

}

CDlgLinTrans::~CDlgLinTrans()
{
}

void CDlgLinTrans::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bS1);
	DDV_MinMaxByte(pDX, m_bS1, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_bS2);
	DDV_MinMaxByte(pDX, m_bS2, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, m_bT1);
	DDV_MinMaxByte(pDX, m_bT1, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, m_bT2);
	DDV_MinMaxByte(pDX, m_bT2, 0, 255);
}


BEGIN_MESSAGE_MAP(CDlgLinTrans, CDialog)
END_MESSAGE_MAP()


// CDlgLinTrans 消息处理程序
