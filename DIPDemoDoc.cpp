// DIPDemoDoc.cpp : implementation of the CDIPDemoDoc class
//

#include "stdafx.h"
#include "DIPDemo.h"

#include "DIPDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoDoc

IMPLEMENT_DYNCREATE(CDIPDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDIPDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDIPDemoDoc)
	ON_COMMAND(ID_FILE_REOPEN, OnFileReopen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoDoc construction/destruction

CDIPDemoDoc::CDIPDemoDoc()
{
	m_sizeDoc = CSize(1,1);
	m_pPalette = NULL;
	// 默认背景色，灰色
	m_refColorBKG = 0x00808080;	
}

CDIPDemoDoc::~CDIPDemoDoc()
{
	// 判断调色板是否存在
	if (m_pPalette != NULL)
	{
		// 清除调色板
		delete m_pPalette;
	}
}

BOOL CDIPDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoDoc diagnostics

#ifdef _DEBUG
void CDIPDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDIPDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDIPDemoDoc commands

BOOL CDIPDemoDoc::CanCloseFrame(CFrameWnd* pFrame) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDocument::CanCloseFrame(pFrame);
}

void CDIPDemoDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pPalette != NULL)
		m_pPalette->DeleteObject();

	CDocument::DeleteContents();
}


void CDIPDemoDoc::Init()
{
	// 初始化

	// 如果图像无效，直接返回
	if (!m_Image.IsValidate())
	{
		return;
	}
	
	// 设置文档大小
	m_sizeDoc = CSize(m_Image.GetWidthPixel(), m_Image.GetHeight());

	// 判断调色板是否为空
	if (m_pPalette != NULL)
	{
		// 删除调色板对象
		delete m_pPalette;

		// 重置调色板为空
		m_pPalette = NULL;
	}
	
	//不是调色板显示模式，则直接返回
	CClientDC dc(NULL);
	if((dc.GetDeviceCaps(RASTERCAPS) & RC_PALETTE) == 0)
		return;
		
	
	// 创建新调色板
	m_pPalette = new CPalette;
	
	
	int nEntries = m_Image.GetColorTableEntriesNum();
	if (nEntries == 0)
		return;

	LOGPALETTE* lpPal = (LOGPALETTE*) new BYTE[sizeof(LOGPALETTE) + (sizeof(PALETTEENTRY)*(nEntries-1))];
	
	// 设置版本号
	lpPal->palVersion = 0x300;
	// 设置颜色数目
	lpPal->palNumEntries = (WORD)nEntries;

	RGBQUAD *pPal = (RGBQUAD*)(m_Image.GetColorTable());
	

	int i;
	// 创建调色板
	for (i = 0; i < nEntries; i++)
	{
		// 读取红色分量
	
		lpPal->palPalEntry[i].peRed = pPal[i].rgbRed;
				
		// 读取绿色分量
		lpPal->palPalEntry[i].peGreen = pPal[i].rgbGreen;
				
		// 读取蓝色分量
		lpPal->palPalEntry[i].peBlue = pPal[i].rgbBlue;
				
		// 保留位
		lpPal->palPalEntry[i].peFlags = 0;
	}

	// 按照逻辑调色板创建调色板，并返回指针
	m_pPalette->CreatePalette(lpPal);
	
	delete lpPal;	
}


BOOL CDIPDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	DeleteContents();
	
	// 更改光标形状
	BeginWaitCursor();
	
	// 读取图像并附加到m_Image上
	if(!m_Image.AttachFromFile(lpszPathName))
	{
		EndWaitCursor();
		AfxMessageBox("打开文件时出错!请确保正确的位图(*.bmp)文件类型。");
		return FALSE;
	}

	// 恢复光标形状
	EndWaitCursor();

	//nWidth = m_Image->->biWidth;
	//nHeight = BIH->biHeight;
	//nColorBits = BIH->biBitCount;
	//nByteWidth = (nWidth*nColorBits + 31) / 32 * 4;
	//nColor = (nColorBits > 8) ? 0 : (int)(pow(2.0, nColorBits));//
	//lpBits = lpBitmap + sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*nColor;


	// 判断读取成功否
	if (!m_Image.m_lpData)
	{
		// 失败，可能非BMP格式
		CString strMsg;
		strMsg = "读取图像时出错！可能是不支持该类型的图像文件！";
		
		// 提示出错
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
		
		// 返回FALSE
		return FALSE;
	}
	
	Init(); //对图像的尺寸和调色板信息进行初始化

	// 设置文件名称
	SetPathName(lpszPathName);

	// 拷贝当前m_Image到m_OImage
	m_OImage = m_Image;
	
	// 初始化胀标记为FALSE
	SetModifiedFlag(FALSE);
	

	// 返回TRUE
	return TRUE;
}

void CDIPDemoDoc::OnFileReopen() 
{
 	// 重新打开图像，放弃所有修改
 
	// 判断当前图像是否已经被改动
	if (IsModified())
	{
		// 提示用户该操作将丢失所有当前的修改
		if (MessageBox(NULL, "重新打开图像将丢失所有改动！是否继续？", "系统提示", MB_ICONQUESTION | MB_YESNO) == IDNO)
		{
			// 用户取消操作，直接返回
			return;
		}
	}

	CString strPathName;
  	
	// 获取当前文件路径
 	strPathName = GetPathName();
 

 	// 更改光标形状
 	BeginWaitCursor();

	if(!m_Image.AttachFromFile(strPathName))
	{
		EndWaitCursor();
		AfxMessageBox("打开文件时出错!请确保正确的位图(*.bmp)文件类型。");
		return;
	}
	
	// 判断读取成功否
	if (!m_Image.m_lpData)
	{
		// 失败，可能非BMP格式
		CString strMsg;
		strMsg = "读取图像时出错！可能是不支持该类型的图像文件！";
		
		// 提示出错
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
		
		// 返回
		return;
	}
	
	Init(); //对图像的尺寸和调色板信息进行初始化

 	// 初始化脏标记为FALSE
 	SetModifiedFlag(FALSE);
 	
 	// 刷新
 	UpdateAllViews(NULL);
  	
 	// 恢复光标形状
 	EndWaitCursor();
	

 	// 返回
 	return;
 	
}

BOOL CDIPDemoDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	if(!m_Image.SaveToFile(lpszPathName))
	{
		CString strMsg;
		strMsg = "无法保存BMP图像！";
		
		// 提示出错
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
		return FALSE;
	}
	

	// 恢复光标形状
	EndWaitCursor();
	
	// 重置胀标记为FALSE
	SetModifiedFlag(FALSE);

	return TRUE;
}






