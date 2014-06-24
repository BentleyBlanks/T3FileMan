#ifndef T3PRIMITIVE_H
#define T3PRIMITIVE_H

#include"T3Math.h"

//物体存储顶点最大个数
#define T3OBJECT_MAX_VERTICES 100
//物体存储多边形最大数量
#define T3OBJECT_MAX_POLYS 100

typedef struct T3PolyType
{
	//顶点列表
	T3Point4DPtr vertexList;
	//当前多边形所包含的顶点的索引
	//当前引擎采用三角形
	int32 vertex[3];

}T3Poly, *T3PolyPtr;

typedef struct T3ObejcteType
{
	//物体的名字
	char name[10];
	//物体在世界坐标中的位置
	T3Point4D worldPosition;
	//局部坐标轴 用于存储物体的朝向
	//因此在物体被旋转时局部坐标系也会时时更新
	T3Vector4D ux, uy, uz;

	//物体包含顶点个数
	int32 numVertices;
	//存储物体局部/模型坐标的数组
	T3Point4D vertexList_Local[T3OBJECT_MAX_VERTICES];
	//存储模型变换后的坐标
	T3Point4D vertexList_Trans[T3OBJECT_MAX_VERTICES];

	//物体包含多边形的个数
	int32 numPolygons;
	//存放所有多边形的多边形数组
	T3Poly polyList[T3OBJECT_MAX_POLYS];

	//平均半径
	float64 avgRadius;
	//最大半径
	float64 maxRadius;

}T3Object, *T3ObjectPtr;

#endif