#pragma once


// CDlgHist 对话框

class CDlgHist : public CDialog
{
	DECLARE_DYNAMIC(CDlgHist)

public:
	CDlgHist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgHist();

// 对话框数据
	enum { IDD = IDD_DLG_Hist };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	// 传入的灰度直方图数据
	double *m_pdHist;
};
