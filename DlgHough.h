#pragma once


// CDlgHough 对话框

class CDlgHough : public CDialog
{
	DECLARE_DYNAMIC(CDlgHough)

public:
	CDlgHough(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgHough();

// 对话框数据
	enum { IDD = IDD_HOUGH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nNum;
};
