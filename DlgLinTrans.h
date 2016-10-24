#pragma once


// CDlgLinTrans 对话框

class CDlgLinTrans : public CDialog
{
	DECLARE_DYNAMIC(CDlgLinTrans)

public:
	CDlgLinTrans(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLinTrans();

// 对话框数据
	enum { IDD = IDD_DLG_LINTRANS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BYTE m_bS1;
	BYTE m_bS2;
	BYTE m_bT1;
	BYTE m_bT2;
};
