// Vector2D.cpp: implementation of the CVector2D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Vector2D.h"
#include <math.h>



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVector2D::CVector2D()
{

}

CVector2D::~CVector2D()
{

}

void CVector2D::GetDiscretionalNextPos(POINT ptStart, 
				POINT ptEnd, int nTotal, int nNext, POINT& ptNext)
{
	if (!nTotal) return;
	ptNext.x = ptStart.x + (ptEnd.x - ptStart.x)*nNext/nTotal;
	ptNext.y = ptStart.y + (ptEnd.y - ptStart.y)*nNext/nTotal;
}

BOOL CVector2D::GetHorizontalNextPos(POINT ptStart, 
				POINT ptOnLine, int nLenght, POINT &ptNext)
{
	// 注意，坐标系与数学笛卡尔坐标系是相同的



	// 判断参数有效性
	if(ptOnLine.x - ptStart.x == 0)
	{	
		// 设置默认返回值
		ptNext.x = 0;
		ptNext.y = 0;
		return FALSE;
	}

	// 如果夹角太小，直接返回，提高效率
	if(abs(ptOnLine.y - ptStart.y) <= 1)
	{
		ptNext.x = ptStart.x + nLenght;
		ptNext.y = ptStart.y;
		return TRUE;
	}


	// 夹角余弦，取正
	float cosine = 
		((float)(ptOnLine.x - ptStart.x)/(float)sqrt((double)
		(ptOnLine.x - ptStart.x)*(ptOnLine.x - ptStart.x) + (ptOnLine.y - ptStart.y)*(ptOnLine.y - ptStart.y)));
	if(cosine < 0)
		cosine = (-1)*cosine;
	
	// 确定直线方程  斜率k，纵轴交点b
	float k = (float)(ptOnLine.y - ptStart.y)/(float)(ptOnLine.x - ptStart.x);
	float b = ptStart.y - k*(float)ptStart.x;

	// 得到下一点的坐标，返回
	ptNext.x = (int)(ptStart.x + cosine*nLenght); 
	ptNext.y = (int)(k*ptNext.x + b);

	return TRUE;
}

BOOL CVector2D::GetVerticalNextPos(POINT ptStart, 
				POINT ptOnLine, int nLenght, POINT &ptNext)
{

	// 注意，这里做了坐标旋转，X轴与Y轴互换


	// 判断参数有效性
	if(ptOnLine.y - ptStart.y == 0)
	{
		// 设置默认返回值
		ptNext.x = 0;
		ptNext.y = 0;
		return FALSE;
	}

	// 如果夹角太小，直接返回，提高效率
	if(abs(ptOnLine.x - ptStart.x) <= 1)
	{
		ptNext.x = ptStart.x;
		ptNext.y = ptStart.y + nLenght;
		return TRUE;
	}


	// 夹角余弦，取正
	float cosine = 
		((float)(ptOnLine.y - ptStart.y)/(float)sqrt((double)
		(ptOnLine.x - ptStart.x)*(ptOnLine.x - ptStart.x) + (ptOnLine.y - ptStart.y)*(ptOnLine.y - ptStart.y)));
	if(cosine < 0)
		cosine = (-1)*cosine;
	
	// 确定直线方程  斜率k，纵轴交点b
	float k = (float)(ptOnLine.x - ptStart.x)/(float)(ptOnLine.y - ptStart.y);
	float b = ptStart.x - k*(float)ptStart.y;

	// 得到下一点的坐标，返回
	ptNext.y = (int)(ptStart.y + cosine*nLenght); 
	ptNext.x = (int)(k*ptNext.y + b);

	return TRUE;
}

BOOL CVector2D::RemoveNeighborPointFromVector(POINT ptToRemove, int nRadius, vector<POINT>& pts, POINT& pt)
{
	vector<vector<POINT>::iterator> index;

	vector<POINT>::iterator pos;

	if(pts.size() == 0)
		return FALSE;

	// 寻找要移除的点
	for(pos = pts.begin(); pos != pts.end(); pos++)
	{
		if(abs((*pos).x - ptToRemove.x) <= nRadius && abs((*pos).y - ptToRemove.y) <= nRadius)
		{
			index.push_back(pos);
		}
	}

	if(index.empty())
		return FALSE;



	// 判断是否相邻
	BOOL bNeighbor = TRUE;
	if(index.size() > 1)
	{
		for(int i=1; i<index.size(); i++)
		{
			if(abs((*index[i]).x - (*index[0]).x) > 1 
					&& abs((*index[i]).y - (*index[0]).y) > 1) 
			{
				bNeighbor = FALSE; // because of no neighbor
			}
		}
	}

	// 设置返回结果
	if(bNeighbor)
		pt = *index[0];

	// remove it and return
	for(int j=0; j<index.size(); j++)
	{	
		try
		{
			pts.erase(index[j]);  // ????? 
		}
		catch(...)
		{
			AfxMessageBox("	pts.erase(index[j]) error ");
		}
	}
	return bNeighbor;
}