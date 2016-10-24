#pragma once


// CDlgFreqIdealLPF 对话框

class CDlgFreqIdealLPF : public CDialog
{
	DECLARE_DYNAMIC(CDlgFreqIdealLPF)

public:
	CDlgFreqIdealLPF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFreqIdealLPF();

// 对话框数据
	enum { IDD = IDD_DLG_FREQ_IDEALLPF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 截止频率
	int m_nFreq;
};
