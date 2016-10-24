// DIPDemoView.cpp : implementation of the CDIPDemoView class
//

#include "stdafx.h"
#include "DIPDemo.h"

#include "DIPDemoDoc.h"
#include "DIPDemoView.h"
#include "mainfrm.h"

#include "DlgLinerPara.h"
#include "DlgPointThre.h"
#include "DlgPointWin.h"
#include "DlgPointThre.h"
#include "DlgGeoTran.h"
#include "DlgGeoZoom.h"
#include "DlgGeoRota.h"
#include "DlgProjRestore.h"
#include "DlgSmooth.h"
#include "DlgMidFilter.h"
#include "DlgSharpThre.h"
#include "DlgColor.h"


#include "DlgHist.h"
#include "DlgLinTrans.h"
#include "DlgLog.h"
#include "DlgGamma.h"
#include "DlgWndTran.h"
#include "DlgGrayScaling.h"
#include "DlgFreqGaussBRF.h"
#include "DlgFreqGaussHPF.h"
#include "DlgFreqGaussLPF.h"
#include "DlgFreqIdealLPF.h"
#include "DlgEdgeSobelPrewitt.h"
#include "DlgHough.h"

#include "DlgMorph.h"
#include "cDlgMorphErosion.h"
#include "cDlgMorphDilation.h"
#include "cDlgMorphOpen.h"
#include "cDlgMorphClose.h"







#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView

IMPLEMENT_DYNCREATE(CDIPDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CDIPDemoView, CScrollView)
	//{{AFX_MSG_MAP(CDIPDemoView)
	ON_WM_ERASEBKGND()

	//点运算
	ON_COMMAND(ID_VIEW_INTENSITY, OnViewIntensity)
	ON_COMMAND(ID_POINT_EQUA, OnPointEqua)
	ON_COMMAND(ID_POINT_LINER, OnPointLiner)
	ON_COMMAND(ID_POINT_WIND, OnPointWind)
	ON_COMMAND(ID_POINT_THRE, OnPointThre)

	//几何运算
	ON_COMMAND(ID_GEOM_TRAN, OnGeomTran)
	ON_COMMAND(ID_GEOM_MIRV, OnGeomMirv)
	ON_COMMAND(ID_GEOM_MIRH, OnGeomMirh)
	ON_COMMAND(ID_GEOM_ROTA, OnGeomRota)
	ON_COMMAND(ID_GEOM_TRPO, OnGeomTrpo)
	ON_COMMAND(ID_GEOM_ZOOM, OnGeomZoom)
	ON_COMMAND(ID_GEOM_CALI, OnGeomCali)
	//图像增强
	ON_COMMAND(ID_ENHA_SMOOTH, OnEnhaSmooth)
	ON_COMMAND(ID_ENHA_MidianF, OnENHAMidianF)
	ON_COMMAND(ID_ENHA_SHARP, OnEnhaSharp)
	ON_COMMAND(ID_ENHA_GRADSHARP, OnEnhaGradsharp)
	ON_COMMAND(ID_ENHA_AdaptMidianF, OnENHAAdaptMidianF)
	ON_COMMAND(ID_ENHA_HIGHENHA, OnEnhaHighenha)
	//图像正交
	ON_COMMAND(ID_FREQ_FOUR, OnFreqFour)

	//形态学变换
	ON_COMMAND(ID_MORPH_EROSION, OnMorphErosion)
	ON_COMMAND(ID_MORPH_DILATION, OnMorphDilation)
	ON_COMMAND(ID_MORPH_OPEN, OnMorphOpen)
	ON_COMMAND(ID_MORPH_CLOSE, OnMorphClose)
	ON_COMMAND(ID_MORPH_THINING, OnMorphThining)
	ON_COMMAND(ID_MORPH_FILLRGN, OnMorphFillrgn)
	ON_COMMAND(ID_MORPH_LABELCONNRGN, OnMorphLabelconnrgn)
	ON_COMMAND(ID_MORPH_PIXEL, OnMorphPixel)
	ON_COMMAND(ID_MORPH_CONVEX, OnMorphConvex)
	ON_COMMAND(ID_MORPH_GRAYDILATE, OnMorphGraydilate)
	ON_COMMAND(ID_MORPH_GRAYERODE, OnMorphGrayerode)
	ON_COMMAND(ID_MORPH_GRAYOPEN, OnMorphGrayopen)
	ON_COMMAND(ID_MORPH_GRAYCLOSE, OnMorphGrayclose)
	ON_COMMAND(ID_MORPH_TOPHAT, OnMorphTophat)
	ON_COMMAND(ID_MORPH_TRACE, OnMorphTrace)

	ON_COMMAND(ID_FILE_CLEAN, OnFileClean)
	ON_COMMAND(ID_FILE_REVERSE, OnFileReverse)

	ON_COMMAND(ID_COLOR_CMY2RGB, OnColorCmy2rgb)
	ON_COMMAND(ID_COLOR_RGB2HSI, OnColorRgb2hsi)
	ON_COMMAND(ID_COLOR_HSI2RGB, OnColorHsi2rgb)
	ON_COMMAND(ID_COLOR_RGB2HSV, OnColorRgb2hsv)
	ON_COMMAND(ID_COLOR_HSV2RGB, OnColorHsv2rgb)
	ON_COMMAND(ID_COLOR_RGB2YUV, OnColorRgb2yuv)
	ON_COMMAND(ID_COLOR_YUV2RGB, OnColorYuv2rgb)
	ON_COMMAND(ID_COLOR_RGB2YIQ, OnColorRgb2yiq)
	ON_COMMAND(ID_COLOR_YIQ2RGB, OnColorYiq2rgb)

	ON_COMMAND(ID_REC_TEMPLATE, OnRecTemplate)
	ON_COMMAND(ID_FEA_GRAYMAT, OnFeaGraymat)
		
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands

	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)

	ON_COMMAND(ID_POINT_STDLIN, CDIPDemoView::OnPointStdlin)
	ON_COMMAND(ID_POINT_LOG, CDIPDemoView::OnPointLog)
	ON_COMMAND(ID_POINT_GAMMA, CDIPDemoView::OnPointGamma)
	ON_COMMAND(ID_POINT_HISTST, CDIPDemoView::OnPointHistst)
	ON_COMMAND(ID_FILE_ROTATE, CDIPDemoView::OnFileRotate)

	ON_COMMAND(ID_EDGE_ROBERT, CDIPDemoView::OnEdgeRobert)
	ON_COMMAND(ID_EDGE_SOBEL, CDIPDemoView::OnEdgeSobel)
	ON_COMMAND(ID_EDGE_PREWITT, CDIPDemoView::OnEdgePrewitt)
	ON_COMMAND(ID_EDGE_LOG, CDIPDemoView::OnEdgeLog)
	ON_COMMAND(ID_EDGE_AUTOTHRE, CDIPDemoView::OnEdgeAutothre)
	ON_COMMAND(ID_FREQ_IDEALLPF, CDIPDemoView::OnFreqIdeallpf)
	ON_COMMAND(ID_FREQ_GAUSSLPF, CDIPDemoView::OnFreqGausslpf)
	ON_COMMAND(ID_FREQ_GAUSSHPF, CDIPDemoView::OnFreqGausshpf)
	ON_COMMAND(ID_FREQ_LAPL, CDIPDemoView::OnFreqLapl)
	ON_COMMAND(ID_FREQ_GAUSSBR, CDIPDemoView::OnFreqGaussbr)
	ON_COMMAND(ID_EDGE_CANNY, CDIPDemoView::OnEdgeCanny)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDGE_REGION_GROW, CDIPDemoView::OnEdgeRegionGrow)
	ON_COMMAND(ID_EDGE_HOUGH, CDIPDemoView::OnEdgeHough)

	ON_COMMAND(ID_FILE_CONVERTGRAY, CDIPDemoView::OnFileConvertgray)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView construction/destruction

CDIPDemoView::CDIPDemoView()
: m_bLBtnDblClkSrv(0)
{
	// TODO: add construction code here

}

CDIPDemoView::~CDIPDemoView()
{
}

BOOL CDIPDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView drawing

void CDIPDemoView::OnDraw(CDC* pDC)
{
	
	// 显示等待光标
	BeginWaitCursor();
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(pDoc->m_Image.IsValidate())
	{
		CPalette* pOldPalette;
		CPalette* pPalette = pDoc->GetDocPalette();

		if(pPalette!=NULL)
		{
			pOldPalette = pDC->SelectPalette(pPalette, FALSE);
			pDC->RealizePalette(); //更新系统调色板
		}	


		pDoc->m_Image.Draw(pDC); //绘制图像
	
		if(pPalette!=NULL)
			pDC->SelectPalette(pOldPalette, FALSE);
	}
	// 恢复正常光标
	EndWaitCursor();
	
}

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView printing

BOOL CDIPDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 设置总页数为一
	pInfo->SetMaxPage(1);

	return DoPreparePrinting(pInfo);
}

void CDIPDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDIPDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView diagnostics

#ifdef _DEBUG
void CDIPDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDIPDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDIPDemoDoc* CDIPDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDIPDemoDoc)));
	return (CDIPDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoView message handlers


BOOL CDIPDemoView::OnEraseBkgnd(CDC* pDC) 
{
	// 主要是为了设置子窗体默认的背景色
	// 背景色由文档成员变量m_refColorBKG指定

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();

	// 创建一个Brush
	CBrush brush(pDoc->m_refColorBKG);                                              
                                                                                  
	// 保存以前的Brush
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	
	// 获取重绘区域
	CRect rectClip;
	pDC->GetClipBox(&rectClip);
	
	// 重绘
	pDC->PatBlt(rectClip.left, rectClip.top, rectClip.Width(), rectClip.Height(), PATCOPY);

	// 恢复以前的Brush
	pDC->SelectObject(pOldBrush);                                                  

	// 返回
	return TRUE;

}


void CDIPDemoView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CDIPDemoView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	CScrollView::OnInitialUpdate();
	ASSERT(GetDocument() != NULL);
	
	SetScrollSizes(MM_TEXT, GetDocument()->GetDocSize());
}

void CDIPDemoView::OnActivateView(BOOL bActivate, CView* pActivateView,
					CView* pDeactiveView)
{
	CScrollView::OnActivateView(bActivate, pActivateView, pDeactiveView);

	if (bActivate)
	{
		ASSERT(pActivateView == this);
		Invalidate(); //激活该视图时进行重绘
	}
}






void CDIPDemoView::OnViewIntensity() 
{
	// 查看当前图像灰度直方图
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 直方图数组
	double hist[256];

	// 设置忙状态
	BeginWaitCursor();

	// 求取直方图数组
	imgInput.GenHist(hist);

	CDlgHist dlg;
	dlg.m_pdHist = hist;

	if (dlg.DoModal() != IDOK)
	{
		// 返回
		return;
	}

	// 更新视图
	pDoc->UpdateAllViews(NULL);
	
	// 恢复光标
	EndWaitCursor();
	
}

//////////////////////////////////////////////////////////////////////////////////////
//  图像点运算

void CDIPDemoView::OnPointLiner() 
{
	// 线性变换
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
		
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 创建对话框
	CDlgLinerPara dlgPara;
	
	// 线性变换的斜率
	double fA;
	
	// 线性变换的截距
	double fB;
	
	// 初始化变量值
	dlgPara.m_fA = 2.0;
	dlgPara.m_fB = -128.0;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	fA = dlgPara.m_fA;
	fB = dlgPara.m_fB;
		
	// 更改光标形状
	BeginWaitCursor();
	
	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用LinTran()函数进行线性变换
	imgInput.LinTran(&imgOutput, fA, fB);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
	
}

void CDIPDemoView::OnPointThre()
{
	// 阈值变换
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 参数对话框
	CDlgPointThre  dlgPara;
	
	// 阈值
	BYTE	bThre;

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 初始化变量值
	dlgPara.m_bThre = 128;
	
	// 显示对话框，提示用户设定阈值
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的阈值
	bThre = dlgPara.m_bThre;
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 调用Threshold方法进行阈值变换
	imgInput.Threshold(&imgOutput, bThre);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnPointWind() 
{
	// TODO: 在此添加命令处理程序代码
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 直方图数组
	double dpHist[256];

	// 输出的临时对象
	
	CImgProcess imgOutput = imgInput;

	// 求取直方图数组
	imgInput.GenHist(dpHist);

	// 创建参数输入对话框
	CDlgWndTran dlg;
	dlg.m_bLower = 0;
	dlg.m_bUpper = 255;
	dlg.m_dHist = dpHist;
	
	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	// 窗口变换
	imgInput.WindowTran(&imgOutput, dlg.m_bLower, dlg.m_bUpper);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnPointEqua() 
{
	// TODO: 在此添加命令处理程序代码
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 直方图均衡化
	imgInput.Histeq(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

//////////////////////////////////////////////////////////////////////////////////////
//  图像几何变换
//
void CDIPDemoView::OnGeomTran() 
{
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	LONG lXOffset;
	LONG lYOffset;
	
	// 创建对话框
	CDlgGeoTran dlgPara;
	
	// 初始化变量值
	dlgPara.m_XOffset = 100;
	dlgPara.m_YOffset = 100;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	lXOffset = dlgPara.m_XOffset;
	lYOffset = dlgPara.m_YOffset;
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用ImMove()函数实现图像平移
	imgInput.ImMove(&imgOutput, lXOffset, lYOffset);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnGeomMirv() 
{
	// 竖直镜像

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用VerMirror()函数实现图像竖直镜像
	imgInput.VerMirror(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();

}


void CDIPDemoView::OnGeomMirh() 
{
	// 水平镜像

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用HorMirror()函数实现图像水平镜像
	imgInput.HorMirror(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();

}


void CDIPDemoView::OnGeomTrpo() 
{
	// 图像转置

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用Transpose()函数实现图像转置
	imgInput.Transpose(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnGeomZoom() 
{
	// 图像缩放

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 缩放比率
	float fZoomRatio;
		
	// 创建对话框
	CDlgGeoZoom dlgPara;
	
	// 初始化变量值
	dlgPara.m_Zoom = 0.5;

	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	fZoomRatio = dlgPara.m_Zoom;
	


	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	// 调用Scale()函数实现图像缩放
	imgInput.Scale(&imgOutput, fZoomRatio);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnGeomRota() 
{
	// 图像旋转

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 旋转角度
	int iRotateAngle;
	
	// 创建对话框
	CDlgGeoRota dlgPara;
	
	// 初始化变量值
	dlgPara.m_iRotateAngle = 30;
	
	// 显示对话框，提示用户设定旋转角度
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	iRotateAngle = dlgPara.m_iRotateAngle;

	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	// 调用Rotate()函数实现图像旋转
	imgInput.Rotate(&imgOutput, iRotateAngle);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnGeomCali() 
{
	// 投影校正

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();	

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	CPoint pBasePts[4]; //基准图像基准点数组
	CPoint pSrcPts[4]; //输入图像基准点数组

	// 创建对话框
	CDlgProjRestore dlgPara;
		
	// 初始化输入图像基准点
	dlgPara.m_xPt1 = 108;
	dlgPara.m_yPt1 = 135;

	dlgPara.m_xPt2 = 274;
	dlgPara.m_yPt2 = 51;

	dlgPara.m_xPt3 = 295;
	dlgPara.m_yPt3 = 119;

	dlgPara.m_xPt4 = 158;
	dlgPara.m_yPt4 = 248;

	// 初始化基准图像基准点
	dlgPara.m_xBPt1 = 0;
	dlgPara.m_yBPt1 = 0;

	dlgPara.m_xBPt2 = 310;
	dlgPara.m_yBPt2 = 0;

	dlgPara.m_xBPt3 = 310;
	dlgPara.m_yBPt3 = 100;

	dlgPara.m_xBPt4 = 0;
	dlgPara.m_yBPt4 = 100;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	pBasePts[0] = CPoint(dlgPara.m_xBPt1, dlgPara.m_yBPt1);
	pBasePts[1] = CPoint(dlgPara.m_xBPt2, dlgPara.m_yBPt2);
	pBasePts[2] = CPoint(dlgPara.m_xBPt3, dlgPara.m_yBPt3);
	pBasePts[3] = CPoint(dlgPara.m_xBPt4, dlgPara.m_yBPt4);
	
	pSrcPts[0] = CPoint(dlgPara.m_xPt1, dlgPara.m_yPt1);
	pSrcPts[1] = CPoint(dlgPara.m_xPt2, dlgPara.m_yPt2);
	pSrcPts[2] = CPoint(dlgPara.m_xPt3, dlgPara.m_yPt3);
	pSrcPts[3] = CPoint(dlgPara.m_xPt4, dlgPara.m_yPt4);
	
	// 更改光标形状
	BeginWaitCursor();

	// 调用ImProjRestore()函数实现图像投影校正
	imgInput.ImProjRestore(&imgOutput, pBasePts, pSrcPts, 1);//使用双线性插值的投影校正

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	
	// 恢复光标
	EndWaitCursor();
}


//////////////////////////////////////////////////////////////////////////////////////
//  图像增强
//
void CDIPDemoView::OnEnhaSmooth() 
{
	// 图像平滑

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	int	nTempH;	// 模板高度
	int	nTempW; // 模板宽度
	FLOAT fTempC;// 模板系数
	int		nTempMX;// 模板中心元素X坐标
	int		nTempMY;// 模板中心元素Y坐标
	
	// 模板元素数组赋初值（默认为平均模板）
	FLOAT	aValue[25] = {1.0, 1.0, 1.0, 0.0, 0.0, 
		1.0, 1.0, 1.0, 0.0, 0.0, 
		1.0, 1.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0,};
	
	// 创建对话框
	CDlgSmooth dlgPara;
	
	// 初始化对话框变量值
	dlgPara.m_intType = 0;
	dlgPara.m_iTempH  = 3;
	dlgPara.m_iTempW  = 3;
	dlgPara.m_iTempMX = 1;
	dlgPara.m_iTempMY = 1;
	dlgPara.m_fTempC  = (FLOAT) (1.0 / 9.0);
	dlgPara.m_fpArray = aValue;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户设定的参数
	nTempH  = dlgPara.m_iTempH;
	nTempW  = dlgPara.m_iTempW;
	nTempMX = dlgPara.m_iTempMX;
	nTempMY = dlgPara.m_iTempMY;
	fTempC  = dlgPara.m_fTempC;

	
	// 更改光标形状
	BeginWaitCursor();
	
	// 调用Template()函数实现平滑滤波
	imgInput.Template(&imgOutput, nTempH, nTempW, nTempMY, nTempMX, aValue, fTempC);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	// 恢复光标
	EndWaitCursor();	
}

void CDIPDemoView::OnENHAMidianF() 
{
	// 中值滤波
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	
	
	int nFilterH; // 滤波器的高度
	int nFilterW; // 滤波器的宽度
	int nFilterMX; // 中心元素的X坐标
	int nFilterMY; // 中心元素的Y坐标
	
	CDlgMidFilter dlgPara;// 创建对话框
	
	// 初始化变量值
	dlgPara.m_iFilterType = 0;
	dlgPara.m_iFilterH = 3;
	dlgPara.m_iFilterW = 1;
	dlgPara.m_iFilterMX = 0;
	dlgPara.m_iFilterMY = 1;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户的设定
	nFilterH = dlgPara.m_iFilterH;
	nFilterW = dlgPara.m_iFilterW;
	nFilterMX = dlgPara.m_iFilterMX;
	nFilterMY = dlgPara.m_iFilterMY;
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用MedianFilter()函数中值滤波
	imgInput.MedianFilter(&imgOutput, nFilterH, nFilterW, nFilterMY, nFilterMX);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnENHAAdaptMidianF() 
{
	// 自适应中值滤波
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	int nFilterH; // 滤波器的高度
	int nFilterW; // 滤波器的宽度
	int nFilterMX; // 中心元素的X坐标
	int nFilterMY; // 中心元素的Y坐标
	
	CDlgMidFilter dlgPara;// 创建对话框
	
	// 初始化变量值
	dlgPara.m_iFilterType = 0;
	dlgPara.m_iFilterH = 3;
	dlgPara.m_iFilterW = 1;
	dlgPara.m_iFilterMX = 0;
	dlgPara.m_iFilterMY = 1;
	
	// 显示对话框，提示用户设定参数
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	// 获取用户的设定
	nFilterH = dlgPara.m_iFilterH;
	nFilterW = dlgPara.m_iFilterW;
	nFilterMX = dlgPara.m_iFilterMX;
	nFilterMY = dlgPara.m_iFilterMY;
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	// 调用AdaptiveMedianFilter()函数自适应中值滤波
	imgInput.AdaptiveMedianFilter(&imgOutput, nFilterH, nFilterW, nFilterMY, nFilterMX);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnEnhaGradsharp() 
{
	// Sobel梯度锐化
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	// 调用FilterSobel()函数进行Sobel梯度锐化
	imgInput.FilterSobel(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
	
}

void CDIPDemoView::OnEnhaSharp() 
{
	// 拉普拉斯锐化
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	int nTempH; // 滤波器的高度
	int nTempW; // 滤波器的宽度
	int nTempMX; // 中心元素的X坐标
	int nTempMY; // 中心元素的Y坐标
	FLOAT	fCoef;	// 模板系数
	
	// 更改光标形状
	BeginWaitCursor();
	
	// 设置拉普拉斯模板参数
	nTempW = 3;
	nTempH = 3;
	fCoef = 1.0;
	nTempMX = 1;
	nTempMY = 1;

	// 调用Template()函数用拉普拉斯模板锐化
	imgInput.Template(&imgOutput, nTempH, nTempW, nTempMY, nTempMX, Template_Laplacian2, fCoef);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);

	// 更新视图
	pDoc->UpdateAllViews(NULL);
	
	
	// 恢复光标
	EndWaitCursor();
	
}

void CDIPDemoView::OnEnhaHighenha() 
{
	// 基于3*3的Laplacian模板的高提升滤波

	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;
	
	// 相关参数设定
	double dProportion = 1.8;
	int nTempH = 3;
	int nTempW = 3;
	int nTempMY = 1;
	int nTempMX = 1;
	// 调用EnhanceFilter()函数进行高提升滤波，采用3*3的Laplacian模板，混合系数为1.8
	imgInput.EnhanceFilter(&imgOutput, dProportion, nTempH, nTempW, nTempMY, nTempMX, Template_Laplacian2, 1);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	// 设置脏标记
	pDoc->SetModifiedFlag(TRUE);
	
	// 更新视图
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();	
}

//////////////////////////////////////////////////////////////////////////////////////
//  图像正交变换
//

void CDIPDemoView::OnFreqFour() 
{	//快速傅立叶变换

	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 执行FFT2
	imgInput.FFT2(&imgOutput,1);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}


//////////////////////////////////////////////////////////////////////////////////////
//  形态学变换
//
void CDIPDemoView::OnMorphErosion() 
{	//腐蚀运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int se[3][3]; //3*3结构元素

	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用Erode()实现图像腐蚀
	imgInput.Erode(&imgOutput, se);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();	
}

void CDIPDemoView::OnMorphOpen() 
{	//开运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int se[3][3]; //3*3结构元素

	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用Open()实现图像腐蚀
	imgInput.Open(&imgOutput, se);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();	
	
	
}


void CDIPDemoView::OnMorphTrace() 
{	//边界跟踪
	

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用TraceBoundary()函数实现边界跟踪
	imgInput.TraceBoundary(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnMorphFillrgn() 
{	// 区域的种子填充
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 需要根据实际情况设置种子点的坐标，这里简单地取种子点为图像的中心点
	POINT ptStart;
	ptStart.x = imgInput.GetWidthPixel() / 2;
	ptStart.y = imgInput.GetHeight() / 2;

	// 调用FillRgn()函数实现种子填充
	imgInput.FillRgn(&imgOutput, ptStart);
	//POINT型参数ptStart为种子点，可以是区域当中的任意一点
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnMorphLabelconnrgn() 
{	// 标注连通区域
		
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用LabelConnRgn()函数标注连通区域
	imgInput.LabelConnRgn(&imgOutput);
		
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnMorphThining() 
{
	//细化

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}

	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用Thining()实现图像细化
	imgOutput.Thining();
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
	
}


void CDIPDemoView::OnMorphPixel() 
{	//像素化

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	int nLowThres; //连通数低于此阈值的连通区被滤除
	int nHighThres; //连通数高于此阈值的连通区被滤除	

	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//这里设定低阈值为10，高阈值为100,连通数<10和连通数>300的连通区被滤除，之间的被像素化
	nLowThres = 10;
	nHighThres = 300;
	
	// 调用PixelImage()实现图像细化
	imgInput.PixelImage(&imgOutput, nLowThres, nHighThres);
	
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnMorphConvex() 
{	//凸壳
	
	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用Convex()函数计算凸集
	imgInput.Convex(&imgOutput, 1);
	//第2个参数为1表示需要限制凸壳的生长	

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnMorphClose() 
{
	//闭运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int se[3][3]; //3*3结构元素

	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 调用Close()实现图像闭运算
	imgInput.Close(&imgOutput, se);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
		
}

void CDIPDemoView::OnMorphDilation() 
{
	//膨胀运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int se[3][3]; //3*3结构元素

	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用Dilate()实现图像膨胀
	imgInput.Dilate(&imgOutput, se);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();	
	
}

void CDIPDemoView::OnMorphGraydilate() 
{	//灰度膨胀

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int** se; //结构元素
	//以3*3的结构元素为例
	se = new int* [3];
	for(int i=0; i<3; i++)
		se[i] = new int[3];
	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用GrayDilate()实现灰度膨胀
	imgInput.GrayDilate(&imgOutput, 3, 3, 1, 1, se);
	//这里se是一个int **指针，表示结构元素。这里采用了3*3原点位于中心的结构元素

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnMorphGrayerode() 
{	//灰度腐蚀

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int** se; //结构元素
	//以3*3的结构元素为例
	se = new int* [3];
	for(int i=0; i<3; i++)
		se[i] = new int[3];
	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用GrayErode()实现灰度腐蚀
	imgInput.GrayErode(&imgOutput, 3, 3, 1, 1, se);
	//这里se是一个int **指针，表示结构元素。这里采用了3*3原点位于中心的结构元素
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnMorphGrayopen() 
{	//灰度开运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int** se; //结构元素
	//以3*3的结构元素为例
	se = new int* [3];
	for(int i=0; i<3; i++)
		se[i] = new int[3];
	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用GrayOpen()实现灰度开
	imgInput.GrayOpen(&imgOutput, 3, 3, 1, 1, se);
	//这里se是一个int **指针，表示结构元素。这里采用了3*3原点位于中心的结构元素
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
	
}

void CDIPDemoView::OnMorphGrayclose() 
{	//灰度闭运算

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int** se; //结构元素
	//以3*3的结构元素为例
	se = new int* [3];
	for(int i=0; i<3; i++)
		se[i] = new int[3];
	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用GrayClose()实现灰度闭
	imgInput.GrayClose(&imgOutput, 3, 3, 1, 1, se);
	//这里se是一个int **指针，表示结构元素。这里采用了3*3原点位于中心的结构元素
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
	
}

void CDIPDemoView::OnMorphTophat() 
{	//顶帽变换

	// 获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	// 输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	
	// 创建对话框
	CDlgMorph dlgPara;	
	
	// 显示对话框，提示用户设定结构元素
	if (dlgPara.DoModal() != IDOK)
	{
		// 返回
		return;
	}
	
	int** se; //结构元素
	//以3*3的结构元素为例
	se = new int* [3];
	for(int i=0; i<3; i++)
		se[i] = new int[3];
	//根据用户输入设定结构元素
	se[0][0]=dlgPara.m_se00;
	se[0][1]=dlgPara.m_se01;
	se[0][2]=dlgPara.m_se02;
	se[1][0]=dlgPara.m_se10;
	se[1][1]=dlgPara.m_se11;
	se[1][2]=dlgPara.m_se12;
	se[2][0]=dlgPara.m_se20;
	se[2][1]=dlgPara.m_se21;
	se[2][2]=dlgPara.m_se22;	
	
	
	// 更改光标形状
	BeginWaitCursor();

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	//调用Tophat()实现顶帽变换
	imgInput.Tophat(&imgOutput, 3, 3, 1, 1, se);
	//这里se是一个int **指针，表示结构元素。这里采用了3*3原点位于中心的结构元素
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
	
}



void CDIPDemoView::OnPointStdlin()
{
	// TODO: 在此添加命令处理程序代码

	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}


	// 创建参数输入对话框
	CDlgLinTrans dlg;
	dlg.m_bS1 = 64;
	dlg.m_bS2 = 192;
	dlg.m_bT1 = 32;
	dlg.m_bT2 = 224;

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 分段线性变换
	imgInput.ParLinTran(&imgOutput, dlg.m_bS1, dlg.m_bS2, dlg.m_bT1, dlg.m_bT2);
	
	// 将结果返回给文档类	
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}
void CDIPDemoView::OnPointLog()
{
	// 对数变换
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}


	// 创建参数输入对话框
	CDlgLog dlg;
	dlg.m_dC = 20;
	
	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	// 输出的临时对象	
	CImgProcess imgOutput = imgInput;

	// 使用对数变换方法
	imgInput.LogTran(&imgOutput, dlg.m_dC);
	
	// 将结果返回给文档类	
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

}

void CDIPDemoView::OnPointGamma()
{
	// TODO: 在此添加命令处理程序代码
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	

	// 创建参数输入对话框
	CDlgGamma dlg;
	dlg.m_dEsp = 0;
	dlg.m_dGamma = 1;
	
	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	
	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 调用GammaTran方法执行伽玛变换
	imgInput.GammaTran(&imgOutput, dlg.m_dGamma, dlg.m_dEsp);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

}

void CDIPDemoView::OnPointHistst()
{
	// 直方图规定化
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 标准图像
	CImgProcess * pStdImage = new CImgProcess();

	// 定义标准图像和原图像的灰度直方图缓冲区
	double pdStdHist[256];

	// 通过打开对话框获取标准图像
	
	// 文件路径
	CString filePath;
	
	// 打开文件对话框，如果用户点击取消则返回
	CFileDialog openDlg(TRUE, 0, 0, 4|2, "Bitmap Files (*.bmp)||");
	if (openDlg.DoModal() == IDOK)
	{
		filePath = openDlg.GetPathName();
	}
	else
	{
		return;
	}

	// 获取标准图像
	pStdImage->AttachFromFile(filePath);

	// 检查图像是灰度图
	if (pStdImage->m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 计算并显示标准图像的直方图，如果用户点击取消则返回
	pStdImage->GenHist(pdStdHist);
	CDlgHist histDlg;
	histDlg.m_pdHist = pdStdHist;
	if (histDlg.DoModal() != IDOK)
	{
		return;
	}
	delete histDlg;

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 直方图规定化
	imgInput.Histst(&imgOutput, pdStdHist);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	delete pStdImage;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnFileRotate()
{
	// 交换前、后台图像
	CDIPDemoDoc * pdoc = GetDocument();
	
	//swap<CImgProcess>(pdoc->m_Image, pdoc->m_OImage);

	pdoc->SetModifiedFlag(true);
	pdoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnFileReverse() 
{	// 图像反色
	
	 //获取文档
	CDIPDemoDoc* pDoc = GetDocument();
	
	 //输入图像
	CImgProcess imgInput = pDoc->m_Image;
	
	 //检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
		
	 //更改光标形状
	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	imgOutput = !imgOutput;

	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
		
	// 恢复光标
	EndWaitCursor();
}


void CDIPDemoView::OnEdgeRobert()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}
	
	CDlgEdgeSobelPrewitt dlg;
	dlg.isRobert = true;

	if (dlg.DoModal()!=IDOK)
	{
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	imgInput.EdgeRoberts(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining, dlg.m_bGratOnly);

	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnEdgeSobel()
{
	// TODO: 在此添加命令处理程序代码
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	CDlgEdgeSobelPrewitt dlg;

	if (dlg.DoModal()!=IDOK)
	{
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// Sobel边缘检测
	imgInput.EdgeSobel(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining, dlg.m_bGratOnly);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

	// 恢复光标
	EndWaitCursor();
}

void CDIPDemoView::OnEdgePrewitt()
{
 	// TODO: 在此添加命令处理程序代码
 	
 	CDIPDemoDoc* pDoc = GetDocument();
 
 	// 输入对象
 	CImgProcess imgInput = pDoc->m_Image;
 
 	// 检查图像是灰度图
 	if (imgInput.m_pBMIH->biBitCount!=8)
 	{
 		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
 		return;
 	}
 	
 	CDlgEdgeSobelPrewitt dlg;
 
 	if (dlg.DoModal()!=IDOK)
 	{
 		return;
 	}
	
	BeginWaitCursor();

 	// 输出的临时对象
 	CImgProcess imgOutput = imgInput;
 
 	imgInput.EdgePrewitt(&imgOutput, dlg.m_bThre, dlg.m_nEdgeType, dlg.m_bThining, dlg.m_bGratOnly);
 
 	pDoc->m_Image = imgOutput;
 
 	pDoc->SetModifiedFlag(true);
 	
 	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();
}


void CDIPDemoView::OnEdgeLog()
{
	// TODO: 在此添加命令处理程序代码
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}


	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	imgInput.EdgeLoG(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();
}

void CDIPDemoView::OnEdgeAutothre()
{
	// 自动阈值分割
	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 自动阈值化
	imgInput.AutoThreshold(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnFreqIdeallpf()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	CDlgFreqIdealLPF dlg;
	dlg.m_nFreq = 0;

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 计算需要生成滤镜的大小
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();

	// 生成频域滤镜
	double * pdFreqFilt = new double[w*h];
	imgInput.FreqIdealLPF(pdFreqFilt, dlg.m_nFreq);
	
	//　应用滤镜
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 删除临时变量
	delete pdFreqFilt;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}

void CDIPDemoView::OnFreqGausslpf()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	CDlgFreqGaussLPF dlg;
	dlg.m_dSigma = 0;

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 计算需要生成滤镜的大小
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();

	// 生成频域滤镜
	double * pdFreqFilt = new double[w*h];
	imgInput.FreqGaussLPF(pdFreqFilt, dlg.m_dSigma);
	
	//　应用滤镜
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 删除临时变量
	delete pdFreqFilt;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}

void CDIPDemoView::OnFreqGausshpf()
{	// 高斯高通滤波

	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	CDlgFreqGaussHPF dlg;
	dlg.m_dSigma = 0;

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 计算需要生成滤镜的大小
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();

	// 生成频域滤镜
	double * pdFreqFilt = new double[w*h];
	imgInput.FreqGaussHPF(pdFreqFilt, dlg.m_dSigma);
	
	//　应用滤镜
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 删除临时变量
	delete pdFreqFilt;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}

void CDIPDemoView::OnFreqLapl()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 计算需要生成滤镜的大小
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();

	// 生成频域滤镜
	double * pdFreqFilt = new double[w*h];
	imgInput.FreqLaplace(pdFreqFilt);
	
	//　应用滤镜
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 删除临时变量
	delete pdFreqFilt;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}

void CDIPDemoView::OnFreqGaussbr()
{
	// TODO: 在此添加命令处理程序代码

	// 警告：本示例中此滤波器仅被设计为处理高宽均为2的整数次幂的具有全画面周期性噪声的图像，
	// 对其他类型图像的处理效果不能做出保证。

	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	CDlgFreqGaussBRF dlg;
	dlg.m_nFreq = 0;
	dlg.m_nWidth = 0;

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// 计算需要生成滤镜的大小
	LONG w = imgInput.GetFreqWidth();
	LONG h = imgInput.GetFreqHeight();

	// 生成频域滤镜
	double * pdFreqFilt = new double[w*h];
	imgInput.FreqGaussBRF(pdFreqFilt, dlg.m_nFreq, dlg.m_nWidth);
	
	//　应用滤镜
	imgInput.FreqFilt(&imgOutput, pdFreqFilt);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	// 删除临时变量
	delete pdFreqFilt;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	EndWaitCursor();
}

void CDIPDemoView::OnEdgeCanny()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	BeginWaitCursor();

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	imgInput.EdgeCanny(&imgOutput);

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

	EndWaitCursor();
}

void CDIPDemoView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;
	// 参数对话框
	CDlgPointThre * dlgPara;

	switch (m_bLBtnDblClkSrv)
	{
		case 0:
			break;
		case 1:
			// 阈值
			BYTE	bThre;

			// 初始化对话框和变量
			dlgPara = new CDlgPointThre();
			dlgPara->m_bThre = 16;
			
			// 显示对话框，提示用户设定阈值
			if (dlgPara->DoModal() != IDOK)
			{
				// 返回
				return;
			}
			
			// 获取用户设定的阈值
			bThre = dlgPara->m_bThre;

			// 删除对话框
			delete dlgPara;

			// 执行区域生长
			imgInput.RegionGrow(&imgOutput, point.x, point.y, bThre);
			break;

		default:
			AfxMessageBox((LPCTSTR)"错误的参数设置，检查设定的服务参数");
	}
			

	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);

	m_bLBtnDblClkSrv = 0;

	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CDIPDemoView::OnEdgeRegionGrow()
{
	// 区域生长
	AfxMessageBox((LPCTSTR)"双击图像中的区域以设定区域生长起始点。");
	m_bLBtnDblClkSrv = 1; //置1使得双击消息触发区域生长
}


void CDIPDemoView::OnEdgeHough()
{
	// TODO: 在此添加命令处理程序代码
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是二值图像
	if (!imgInput.IsBinaryImg())
	{
		AfxMessageBox("不是二值图像，无法处理！");
		return;
	}

	CDlgHough dlg;
	dlg.m_nNum = 0;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}

	// 要找到的直线数目
	int nLineCount = dlg.m_nNum;
	// 直线保存临时对象
	SLineInfo * pLines = new SLineInfo[nLineCount];

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// Hough变换
	imgInput.Hough(pLines, nLineCount);

	// 输出结果
	for (int k = 0; k<nLineCount; k++)//处理第k条直线
	{
		//扫描图像绘制直线
		for(int i = 0; i <imgInput.GetHeight(); i++)
		{
			for(int j = 0;j <imgInput.GetWidthPixel(); j++)
			{	
				int nDist;

				//根据theta计算rho
				nDist = (int) (j*cos(pLines[k].nAngle*PI/180.0) + \
							i*sin(pLines[k].nAngle*PI/180.0));
	
				if (nDist == pLines[k].nDist) //如果点（j, i）在直线上
					imgOutput.SetPixel(j, i, RGB(255,255,255));
			}//for j
		}//for i
	}//for k

	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnFileConvertgray()
{
	// 获取文档对象 	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;

	// 检查图像是256色图
	if (imgInput.m_pBMIH->biBitCount!=8)	{
		AfxMessageBox("不是256色图像，无法处理！");
		return;
	}

	// 256色索引图转灰度
	imgInput.Index2Gray();

	// 将结果返回给文档类
	pDoc->m_Image = imgInput;

	pDoc->SetModifiedFlag(true);
	pDoc->UpdateAllViews(NULL);
}




void CDIPDemoView::OnFileClean() 
{
	// 获取文档对象 	
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	
	imgInput.InitPixels(255);// 清空图像（置白）

	// 将结果返回给文档类
	pDoc->m_Image = imgInput;
	
	// 设置脏标志
	pDoc->SetModifiedFlag(true);
	
	// 设置客户区域无效，激发重绘事件
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnColorCmy2rgb() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是24位图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是24位图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// RGB2CMY
	imgInput.RGB2CMY(&imgOutput);


	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnColorRgb2hsi() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是RGB图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是RGB图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// RGB2HSI
	imgInput.RGB2HSI(&imgOutput);

	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnColorHsi2rgb() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是24位图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是24位图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// HSI2RGB
	imgInput.HSI2RGB(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnColorRgb2hsv() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是RGB图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是RGB图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// RGB2HSV
	imgInput.RGB2HSV(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
}

void CDIPDemoView::OnColorHsv2rgb() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是24位图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是24位图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// HSV2RGB
	imgInput.HSV2RGB(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnColorRgb2yuv() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是RGB图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是RGB图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// RGB2YUV
	imgInput.RGB2YUV(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
}

void CDIPDemoView::OnColorYuv2rgb() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是24位图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是24位图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// YUV2RGB
	imgInput.YUV2RGB(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
}

void CDIPDemoView::OnColorRgb2yiq() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是RGB图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是RGB图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// RGB2YIQ
	imgInput.RGB2YIQ(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
}

void CDIPDemoView::OnColorYiq2rgb() 
{
	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是24位图像
	if (imgInput.m_pBMIH->biBitCount!=24)
	{
		AfxMessageBox("不是24位图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	// YIQ2RGB
	imgInput.YIQ2RGB(&imgOutput);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;

	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
}

void CDIPDemoView::OnRecTemplate() 
{	
	//模板匹配

	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图像
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}

	// 输出的临时对象
	CImgProcess imgOutput = imgInput;

	CImgProcess TplImage; //模板图像

	//弹出对话框让用户选择模板图像
	CFileDialog dlg(TRUE,"bmp","*.bmp");
	if(dlg.DoModal() == IDOK)
	{
 
	 	CString strPathName;
 
		strPathName = dlg.GetPathName();
 
		TplImage.AttachFromFile(strPathName);
 	}
	else
		return;
	

	int nHeight = imgInput.GetHeight();
	int nWidth = imgInput.GetWidthPixel();
	int nTplHeight = TplImage.GetHeight();
	int nTplWidth = TplImage.GetWidthPixel();
	if(nTplHeight > nHeight || nTplWidth > nWidth )
	{
		// 提示用户
		MessageBox("模板尺寸大于源图像尺寸！", "系统提示" , MB_ICONINFORMATION | MB_OK);
	
		return;
	}

	// 更改光标形状
	BeginWaitCursor();

	// 进行模板匹配
	imgInput.TemplateMatch(&imgOutput, &TplImage);
	
	// 将结果返回给文档类
	pDoc->m_Image = imgOutput;
	
	pDoc->SetModifiedFlag(true);
	
	pDoc->UpdateAllViews(NULL);
	
	// 恢复光标形状
	EndWaitCursor();

}

void CDIPDemoView::OnFeaGraymat() 
{	//计算灰度共现矩阵

	// 获得文档类指针
	CDIPDemoDoc* pDoc = GetDocument();

	// 输入对象
	CImgProcess imgInput = pDoc->m_Image;
	
	// 检查图像是灰度图像
	if (imgInput.m_pBMIH->biBitCount!=8)
	{
		AfxMessageBox("不是8-bpp灰度图像，无法处理！");
		return;
	}


	//设定两个点的位置关系
	POINT ptD1, ptD2;

/*	//水平灰度共现矩阵
	ptD1.x = 1;
	ptD1.y = 0;
	ptD2.x = -1;
	ptD2.y = 0;
*/
	//+45度灰度共现矩阵
	ptD1.x = 1;
	ptD1.y = -1;
	ptD2.x = -1;
	ptD2.y = +1;

	//计算灰度共现矩阵
	vector< vector<int> > GrayMat = imgInput.GetGrayMatrix(ptD1, ptD2);
	
	CString str;

	int m = GrayMat.size();
	int n = GrayMat[0].size();

	//弹出对话框，显示灰度共现矩阵
	str.Format("{%d %d %d;%d %d %d;%d %d %d}", GrayMat[0][0], GrayMat[0][1], GrayMat[0][2], GrayMat[1][0], GrayMat[1][1], GrayMat[1][2], GrayMat[2][0], GrayMat[2][1], GrayMat[2][2]);
	AfxMessageBox(str);
}


