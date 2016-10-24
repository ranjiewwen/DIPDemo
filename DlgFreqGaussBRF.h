#pragma once


// CDlgFreqGaussBRF 对话框

class CDlgFreqGaussBRF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqGaussBRF)

public:
	CDlgFreqGaussBRF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFreqGaussBRF();

// 对话框数据
	enum { IDD = IDD_DLG_FREQ_GAUSSBRF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 阻带中心频率
	int m_nFreq;
	// 阻带宽度
	int m_nWidth;
};
