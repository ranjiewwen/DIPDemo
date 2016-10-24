// DIPDemoView.h : interface of the CDIPDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIPDemoVIEW_H__60AAD957_ED0B_48FF_834E_78C547411B15__INCLUDED_)
#define AFX_DIPDemoVIEW_H__60AAD957_ED0B_48FF_834E_78C547411B15__INCLUDED_


#include "Img.h"
#include "ImgProcess.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDIPDemoView : public CScrollView
{
protected: // create from serialization only
	CDIPDemoView();
	DECLARE_DYNCREATE(CDIPDemoView)

// Attributes
public:
	CDIPDemoDoc* GetDocument();
	CPoint point1;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIPDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDIPDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDIPDemoView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnViewIntensity();

	//点运算
	afx_msg void OnPointLiner();
	afx_msg void OnPointThre();
	afx_msg void OnPointWind();
	afx_msg void OnPointEqua();
	//几何运算
	afx_msg void OnGeomTran();
	afx_msg void OnGeomMirv();
	afx_msg void OnGeomMirh();
	afx_msg void OnGeomRota();
	afx_msg void OnGeomTrpo();
	afx_msg void OnGeomZoom();
	afx_msg void OnGeomCali();
	// 图像增强
	afx_msg void OnEnhaSmooth();
	afx_msg void OnENHAMidianF();
	afx_msg void OnENHAAdaptMidianF();
	afx_msg void OnEnhaHighenha();
	afx_msg void OnEnhaSharp();
	afx_msg void OnEnhaGradsharp();

	//图像正交变换
	afx_msg void OnFreqFour();

	//形态学变换
	afx_msg void OnMorphErosion();
	afx_msg void OnMorphOpen();
	afx_msg void OnMorphTrace();
	afx_msg void OnMorphFillrgn();
	afx_msg void OnMorphLabelconnrgn();
	afx_msg void OnMorphThining();
	afx_msg void OnMorphPixel();
	afx_msg void OnMorphConvex();
	afx_msg void OnMorphClose();
	afx_msg void OnMorphDilation();
	afx_msg void OnMorphGraydilate();
	afx_msg void OnMorphGrayerode();
	afx_msg void OnMorphGrayopen();
	afx_msg void OnMorphGrayclose();
	afx_msg void OnMorphTophat();

	afx_msg void OnFileReverse();


	afx_msg void OnFileClean();

	afx_msg void OnColorCmy2rgb();
	afx_msg void OnColorRgb2hsi();
	afx_msg void OnColorHsi2rgb();
	afx_msg void OnColorRgb2hsv();
	afx_msg void OnColorHsv2rgb();
	afx_msg void OnColorRgb2yuv();
	afx_msg void OnColorYuv2rgb();
	afx_msg void OnColorRgb2yiq();
	afx_msg void OnColorYiq2rgb();

	afx_msg void OnRecTemplate();
	afx_msg void OnFeaGraymat();
	

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPointStdlin();
	afx_msg void OnPointLog();
	afx_msg void OnPointGamma();
	afx_msg void OnPointHistst();
	afx_msg void OnFileRotate();


	afx_msg void OnEdgeRobert();
	afx_msg void OnEdgeSobel();
	afx_msg void OnEdgePrewitt();
	afx_msg void OnEdgeLog();
	afx_msg void OnEdgeAutothre();


	afx_msg void OnFreqIdeallpf();
	afx_msg void OnFreqGausslpf();
	afx_msg void OnFreqGausshpf();
	afx_msg void OnFreqLapl();
	afx_msg void OnFreqGaussbr();
	afx_msg void OnEdgeCanny();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEdgeRegionGrow();

	afx_msg void OnEdgeHough();
	afx_msg void OnFileConvertgray();

public:
	// 左键在主窗口客户区双击对应所需服务的代码
	BYTE m_bLBtnDblClkSrv;
};

#ifndef _DEBUG  // debug version in DIPDemoView.cpp
inline CDIPDemoDoc* CDIPDemoView::GetDocument()
   { return (CDIPDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIPDemoVIEW_H__60AAD957_ED0B_48FF_834E_78C547411B15__INCLUDED_)
