// Vector2D.h: interface for the CVector2D class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __VECTOR2D_H_
#define __VECTOR2D_H_

#include <vector>
using namespace std;

class CVector2D  
{
public:
	CVector2D();
	virtual ~CVector2D();

	// 获取两点间的一个坐标  获取任意方向上的下一个点的坐标
	// 效率最高
	void GetDiscretionalNextPos(POINT ptStart, 
				POINT ptEnd, int nTotal, int nNext, POINT& ptNext);


	// 获取一条直线上水平方向上的下一个点的坐标，右边为＋
	BOOL GetHorizontalNextPos(POINT ptStart, 
				POINT ptOnLine, int nLenght, POINT &ptNext);
	// 获取一条直线上竖直方向上的下一个点的坐标，下边为＋
	BOOL GetVerticalNextPos(POINT ptStart, 
				POINT ptOnLine, int nLenght, POINT &ptNext);

	
	// 从向量数组中移除符合条件的相邻的点，返回移除的个数
	BOOL RemoveNeighborPointFromVector(POINT ptToRemoe, 
					int nRadius, vector<POINT>& pts, POINT& pt);

};

#endif // __VECTOR2D_H_
