#pragma once


// CDlgFreqGaussLPF 对话框

class CDlgFreqGaussLPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqGaussLPF)

public:
	CDlgFreqGaussLPF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFreqGaussLPF();

// 对话框数据
	enum { IDD = IDD_DLG_FREQ_GAUSSLPF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 高斯滤波器Sigma参数
	double m_dSigma;
};
