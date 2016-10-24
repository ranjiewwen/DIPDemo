#pragma once


// CDlgGrayScaling 对话框

class CDlgGrayScaling : public CDialog
{
	DECLARE_DYNAMIC(CDlgGrayScaling)

public:
	CDlgGrayScaling(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgGrayScaling();

// 对话框数据
	enum { IDD = IDD_DLG_GRAYSCAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BYTE m_bX1;
	BYTE m_bX2;
	BYTE m_bY1;
	BYTE m_bY2;
};
