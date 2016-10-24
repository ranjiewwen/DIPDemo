// ImgProcess.h: interface for the CImgProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_)
#define AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "Img.h"

#include "math.h"
#include <complex>

using namespace std;

extern float Template_Log[];
extern float Template_VSobel[];
extern float Template_HSobel[];
extern float Template_Smooth_Gauss[];
extern float Template_Smooth_Avg[];
extern float Template_Laplacian1[];
extern float Template_Laplacian2[];


#define PI 3.1415926


struct SLineInfo
{
	int nPixels;
	int nAngle;  // -180   +180
	int nDist;   // 0      +Max
	int GetLineAngle(SLineInfo *pLine)
	{
		
		int nRet = abs(pLine->GetAngle360() - GetAngle360());
		if(nRet > 180)
			nRet = 360 - nRet;

		if(nRet > 90)
			nRet = 180 - nRet;

	
		return abs(nRet);
	}

	int GetLineDist(SLineInfo *pLine)
	{
		if(nAngle * pLine->nAngle < 0)
			return abs(nDist + pLine->nDist);
	
		return abs(nDist - pLine->nDist);
	}

	void AddDistWithAngle(int nAdd, int n)
	{
		if(n < 0)
		{
			nAdd *= -1;
		}

		nDist += nAdd;
	}

	int GetDistWithAngle(int n)
	{
		int nRet = nDist;
		if(n < 0)
		{
			nRet *= -1;
		}

		return nRet;
	}

	int GetAngle360()
	{
		int nRet = nAngle;
		if(nAngle < 0)
		{
			nRet = abs(nAngle + 180) + 180;
		}
		return nRet;
	}

	int GetY(int x)
	{
		int nRet = 0;
		double fRadian = nAngle*PI/180.0;


		if(sin(fRadian) != 0)
			nRet = (nDist - x*cos(fRadian))/sin(fRadian);

		return nRet;
		
	}

	int GetX(int y)
	{
		int nRet = 0;
		double fRadian = nAngle*PI/180.0;


		if(cos(fRadian) != 0)
			nRet = (nDist - y*sin(fRadian))/cos(fRadian);

		return nRet;
	}

};



struct MYPOINT
{
	double x;
	double y;
};

// CImgProcess封装了各种图像处理的标准算法
class CImgProcess : public CImg  
{
public:
	CImgProcess();
	virtual ~CImgProcess();

	// 从基类的转换
	CImgProcess& operator = (CImg& img);




	//***************第3章 图像的点运算*****************
	BOOL GenHist(double * hist, int n = 256);// 生成灰度直方图
	BOOL ParLinTran(CImgProcess * pTo, BYTE x1, BYTE x2, BYTE y1, BYTE y2);//分段线性变换
	BOOL LinTran(CImgProcess * pTo, double dFa, double dFb);//线性变换
	BOOL LogTran(CImgProcess * pTo, double C);//对数变换
	BOOL GammaTran(CImgProcess * pTo, double gamma, double comp=0);//伽马变换
	BOOL WindowTran(CImgProcess * pTo, BYTE lowThre, BYTE highThre);//窗口变换
	BOOL Histeq(CImgProcess * pTo);//灰度均衡化
	BOOL Histst(CImgProcess * pTo, double* pdStdHist);//直方图规定化，直接匹配直方图
	BOOL Histst(CImgProcess * pTo, CImgProcess* pStd);//直方图规定化，匹配标准图像的直方图
	



	//***************第4章 图像的几何变换*****************
	void ImMove(CImgProcess* pTo, int x, int y);//图像平移
	void HorMirror(CImgProcess* pTo);//图像水平镜象
	void VerMirror(CImgProcess* pTo);//图像垂直镜象
	void Transpose(CImgProcess* pTo);//图像转置
	void Scale(CImgProcess* pTo,double times);//图像缩放
	void Rotate(CImgProcess* pTo,float ang);//图像旋转

	//**************投影变换复原***************//////////////////
	int m_nBasePt; //=4 基准点对儿的数目
	BOOL ImProjRestore(CImgProcess* pTo, CPoint *pPointBase, CPoint *pPointSampl, bool bInterp);//投影变形校正
	void GetProjPara(CPoint *pPointBase, CPoint *pPointSampl, double *pDbProjPara); //根据4对儿基准点确定变换参数
	BOOL InvMat(double** ppDbMat, int nLen); //矩阵求逆
	void ProdMat(double** ppDbMat, double* pDbSrc2, double* pDbDest, int y, int x, int z);
	struct MYPOINT ProjTrans(CPoint pt, double* pDbProjPara); //根据变换参数对点pt实施投影变换

	int InterpBilinear(double x, double y);//返回(x,y)点双线性插值后的灰度
	


	//***************第5章 图像增强*****************
	
	// 通用模板操作
	void Template(CImgProcess *pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, FLOAT *pfArray, FLOAT fCoef);
	int GetMedianValue(int * pAryGray, int nFilterLen); //取得排序统计中值
	void MedianFilter(CImgProcess *pTo, int nFilterH, int nFilterW, int nFilterMY, int nFilterMX); //中值滤波
	void AdaptiveMedianFilter(CImgProcess *pTo, int nFilterH, int nFilterW, int nFilterMY, int nFilterMX); //自适应中值滤波
	void FilterSobel(CImgProcess *pTo); //Sobel梯度锐化
	void EnhanceFilter(CImgProcess *pTo, double dProportion,
						 int nTempH, int nTempW, 
						 int nTempMY, int nTempMX, FLOAT *pfArray, FLOAT fCoef); //提升滤波


	

	//***************第6章 频率域图像增强*****************
private:
	// FFT
	void FFT(complex<double> * TD, complex<double> * FD, int r);
	// IFFT
	void IFFT(complex<double> * FD, complex<double> * TD, int r);
public:
	// FFT2
	BOOL FFT2(CImgProcess * pTo, BOOL bExpand = FALSE, complex<double> * pOutput = NULL, BYTE bFillColor = 255);
	// IFFT2
	BOOL IFFT2(CImgProcess * pTo, complex<double> * pInput, long lWidth, long lHeight, long lOutW = 0, long lOutH = 0);
	// 频域滤波
	BOOL FreqFilt(CImgProcess * pTo, double * pdFilter, BYTE bFillColor = 255);
	// 产生频域理想低通滤波器
	BOOL FreqIdealLPF(double * pdFilter, int nFreq);
	// 频域高斯低通滤波器
	BOOL FreqGaussLPF(double * pdFilter, double dSigma);
	// 高斯高通滤波器
	BOOL FreqGaussHPF(double * pdFilter, double dSigma);
	// 频域拉普拉斯滤波器
	BOOL FreqLaplace(double * pdFilter);
	// 高斯带阻滤波器
	BOOL FreqGaussBRF(double * pdFilter , int nFreq, int nWidth);

	/**************************************************
	LONG GetFreqWidth(BOOL isExtending = true)

	功能：
		返回频域滤镜或频域图像应有的宽度

	参数：
		BOOL isExtending
			指定对宽度的整定拟合采取的方法，
			true为扩展，对应用给定颜色补齐图像的右侧；
			false为压缩，对应从右侧裁剪图像。
			默认值为true。

	返回值：
		LONG类型，整定后的宽度计算结果
	***************************************************/

	inline LONG GetFreqWidth(BOOL isExtending = true)
	{
		LONG w = 1;

		while(w * 2 <= GetWidthPixel())
		{
			w *= 2;
		}

		// 如果需要扩展图像宽度，且图像宽度不恰好是2整数幂，则：
		if ( (w != GetWidthPixel()) && (isExtending) )
		{
			w *= 2;
		}

		return w;
	}

	/**************************************************
	LONG GetFreqHeight(BOOL isExtending = true)

	功能：
		返回频域滤镜或频域图像应有的高度

	参数：
		BOOL isExtending
			指定对宽度的整定拟合采取的方法，
			true为扩展，对应用给定颜色补齐图像的底部；
			false为压缩，对应从底部裁剪图像。
			默认值为true。

	返回值：
		LONG类型，整定后的高度计算结果
	***************************************************/

	inline LONG GetFreqHeight(BOOL isExtending = true)
	{
		LONG h = 1;

		while(h * 2 <= GetHeight())
		{
			h *= 2;
		}

		// 如果需要扩展图像高度，且图像高度不恰好是2整数幂，则：
		if ( (h != GetHeight()) && (isExtending) )
		{
			h *= 2;
		}

		return h;
	}

	


	//***************第7章 彩色图像处理*****************
	void CMY2RGB(CImgProcess *pTo);
	void RGB2CMY(CImgProcess *pTo);
	void RGB2HSI(CImgProcess* pTo);
	void HSI2RGB(CImgProcess *pTo);
	void Gray2RGB(CImgProcess *pTo);
	void YIQ2RGB(CImgProcess *pTo);
	void RGB2YIQ(CImgProcess *pTo);
	void YUV2RGB(CImgProcess *pTo);
	void RGB2YUV(CImgProcess *pTo);
	void HSV2RGB(CImgProcess *pTo);
	void RGB2HSV(CImgProcess *pTo);
	


	
	//**************第8章 形态学运算********************
	void FillRgn(CImgProcess *pTo, POINT ptStart); //区域填充算法
	void TraceBoundary(CImgProcess *pTo); //边界跟踪算法
	void Thining(); //细化算法
	void Erode(CImgProcess* pTo, int se[3][3]); //腐蚀算法
	void Dilate(CImgProcess* pTo, int se[3][3]); //膨胀算法
	void Convex(CImgProcess* pTo, BOOL bConstrain); //计算凸壳
	void Open(CImgProcess* pTo, int se[3][3]);//开运算
	void Close(CImgProcess* pTo, int se[3][3]);//闭运算

	void PixelImage(CImgProcess* pTo, int lowerThres, int upperThres);
	int TestConnRgn(CImgProcess* pImage,  LPBYTE lpVisited, int nWidth, int nHeight,	int x,int y, CPoint ptVisited[], int lowerThres, int upperThres, int &curLianXuShu);
	void LabelConnRgn(CImgProcess* pTo, int nConn = 8); //标注连通分量

	//灰度形态学
	void GrayDilate(CImgProcess* pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, int** se);//灰度膨胀
	void GrayErode(CImgProcess* pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, int** se);//灰度腐蚀
	void GrayOpen(CImgProcess* pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, int** se);//灰度开运算
	void GrayClose(CImgProcess* pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, int** se);//灰度闭运算
	void Tophat(CImgProcess* pTo, int nTempH, int nTempW, int nTempMY, int nTempMX, int** se);//顶帽变换




	//*********************第9章 图像分割********************
	// Roberts边缘寻找
	BOOL EdgeRoberts(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0, BOOL bThinning = true, BOOL bGOnly = false);
	// Sobel边缘寻找
	BOOL EdgeSobel(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0, BOOL bThinning = true, BOOL bGOnly = false);
	// Prewitt边缘寻找
	BOOL EdgePrewitt(CImgProcess * pTo, BYTE bThre = 0, BYTE bEdgeType = 0, BOOL bThinning = true, BOOL bGOnly = false);
	// 高斯拉普拉斯边缘寻找
	void EdgeLoG(CImgProcess * pTo);
	// Canny算法
	BOOL EdgeCanny(CImgProcess * pTo, BYTE bThreL = 0, BYTE bThreH = 0, BOOL bThinning = true);

	// Hough变换 查找直线
	BOOL Hough(SLineInfo *pInfoRet, int nLineRet);
	
	void Threshold(CImgProcess *pTo, BYTE bThre);//阈值分割
	int DetectThreshold(int nMaxIter, int &nDiffRet);// 迭代获取最优伐值
	void AutoThreshold(CImgProcess *pTo);//自动阈值分割

	// 区域生长算法
	BOOL RegionGrow(CImgProcess * pTo , int nSeedX, int nSeedY, BYTE bThre);
	// 分水岭算法




	//***************第10章 特征提取*****************
	vector< vector<int> > GetGrayMatrix(POINT ptD1, POINT ptD2); //计算灰度共现矩阵




	//***************第11章 识别初步*****************
	void TemplateMatch(CImgProcess* pTo, CImgProcess* pTemplate); //模板匹配

	

};//class CImgProcess



#endif // !defined(AFX_IMAGE_H__D566CE6A_BA81_4157_8E6A_748DA096668F__INCLUDED_)
