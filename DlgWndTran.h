#pragma once


// CDlgWndTran 对话框

class CDlgWndTran : public CDialog
{
	DECLARE_DYNAMIC(CDlgWndTran)

public:
	CDlgWndTran(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgWndTran();

// 对话框数据
	enum { IDD = IDD_DLG_WNDTRAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BYTE m_bLower;
	BYTE m_bUpper;
	afx_msg void OnPaint();
	// 直方图数组
	double* m_dHist;
};
