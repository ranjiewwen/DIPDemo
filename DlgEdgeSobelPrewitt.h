#pragma once


// CDlgEdgeSobelPrewitt 对话框

class CDlgEdgeSobelPrewitt : public CDialog
{
	DECLARE_DYNAMIC(CDlgEdgeSobelPrewitt)

public:
	CDlgEdgeSobelPrewitt(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgEdgeSobelPrewitt();

// 对话框数据
	enum { IDD = IDD_EDGE_SOBEL_PREWITT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	// 阈值
	BYTE m_bThre;
	// 边缘类型
	int m_nEdgeType;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	int m_bThining;
	int m_bGratOnly;
	// 设定为true时去掉45度和135度边缘选项
	BOOL isRobert;
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	BOOL isGauss;
	double m_dSigma;
	afx_msg void OnBnClickedCheck3();
};
