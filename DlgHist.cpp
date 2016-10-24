// DlgHist.cpp : 实现文件
//

#include "stdafx.h"
#include "DIPDemo.h"
#include "DlgHist.h"


// CDlgHist 对话框

IMPLEMENT_DYNAMIC(CDlgHist, CDialog)

CDlgHist::CDlgHist(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHist::IDD, pParent)
	, m_pdHist(NULL)
{

}

CDlgHist::~CDlgHist()
{
	
}

void CDlgHist::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHist, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgHist 消息处理程序

void CDlgHist::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	// 字符串
	CString str;

	// 获取绘制坐标的控件
	CWnd* pWnd = GetDlgItem(IDC_HIST);

	// 指针
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	
	pDC->Rectangle(0,0,320,250);
	
	// 创建画笔对象
	CPen* pPenRed = new CPen;
	
	// 红色画笔
	pPenRed->CreatePen(PS_SOLID,1,RGB(255,0,0));
	
	// 创建画笔对象
	CPen* pPenBlue = new CPen;
	
	// 蓝色画笔
	pPenBlue->CreatePen(PS_SOLID,1,RGB(0,0, 255));
	
	// 创建画笔对象
	CPen* pPenGreen = new CPen;
	
	// 绿色画笔
	pPenGreen->CreatePen(PS_DOT,1,RGB(0,255,0));
	
	// 选中当前红色画笔，并保存以前的画笔
	CGdiObject* pOldPen = pDC->SelectObject(pPenRed);
	
	// 绘制坐标轴
	pDC->MoveTo(10,10);
	
	// 垂直轴
	pDC->LineTo(10,240);
	
	// 水平轴
	pDC->LineTo(310,240);
	
	// 写X轴刻度值
	str.Format("0");
	pDC->TextOut(10, 243, str);
	str.Format("50");
	pDC->TextOut(60, 243, str);
	str.Format("100");
	pDC->TextOut(110, 243, str);
	str.Format("150");
	pDC->TextOut(160, 243, str);
	str.Format("200");
	pDC->TextOut(210, 243, str);
	str.Format("255");
	pDC->TextOut(260, 243, str);
	
	int i;

	// 绘制X轴刻度
	for (i = 0; i < 256; i += 5)
	{
		if ((i & 1) == 0)
		{
			// 10的倍数
			pDC->MoveTo(i + 10, 240);
			pDC->LineTo(i + 10, 234);
		}
		else
		{
			// 5的倍数
			pDC->MoveTo(i + 10, 240);
			pDC->LineTo(i + 10, 236);
		}
	}
	
	// 绘制X轴箭头
	pDC->MoveTo(305,235);
	pDC->LineTo(310,240);
	pDC->LineTo(305,245);
	
	// 绘制X轴箭头
	pDC->MoveTo(10,10);
	pDC->LineTo(5,15);
	pDC->MoveTo(10,10);
	pDC->LineTo(15,15);

	double maxHist = 0;

	for (i = 0; i < 256; i++)
	{
		maxHist = max(maxHist, m_pdHist[i]);
	}

	pDC->SelectObject(pPenBlue);

	for (i = 0; i < 256; i++)
	{
		pDC->MoveTo(i + 10, 240);
		pDC->LineTo(i + 10, int(240 - m_pdHist[i] / maxHist * 240));
	};
	
	// 恢复以前的画笔
	pDC->SelectObject(pOldPen);	
	
	// 删除新的画笔
	delete pPenRed;
	delete pPenBlue;
	delete pPenGreen;
}
