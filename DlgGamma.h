#pragma once


// CDlgGamma 对话框

class CDlgGamma : public CDialog
{
	DECLARE_DYNAMIC(CDlgGamma)

public:
	CDlgGamma(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgGamma();

// 对话框数据
	enum { IDD = IDD_DLG_GAMMA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 补偿系数
	double m_dEsp;
	// 伽马系数
	double m_dGamma;
};
