#ifndef T3PRIMITIVE_H
#define T3PRIMITIVE_H

#include"T3Math.h"

//����洢����������
#define T3OBJECT_MAX_VERTICES 100
//����洢������������
#define T3OBJECT_MAX_POLYS 100

typedef struct T3PolyType
{
	//�����б�
	T3Point4DPtr vertexList;
	//��ǰ������������Ķ��������
	//��ǰ�������������
	int32 vertex[3];

}T3Poly, *T3PolyPtr;

typedef struct T3ObejcteType
{
	//���������
	char name[10];
	//���������������е�λ��
	T3Point4D worldPosition;
	//�ֲ������� ���ڴ洢����ĳ���
	//��������屻��תʱ�ֲ�����ϵҲ��ʱʱ����
	T3Vector4D ux, uy, uz;

	//��������������
	int32 numVertices;
	//�洢����ֲ�/ģ�����������
	T3Point4D vertexList_Local[T3OBJECT_MAX_VERTICES];
	//�洢ģ�ͱ任�������
	T3Point4D vertexList_Trans[T3OBJECT_MAX_VERTICES];

	//�����������εĸ���
	int32 numPolygons;
	//������ж���εĶ��������
	T3Poly polyList[T3OBJECT_MAX_POLYS];

	//ƽ���뾶
	float64 avgRadius;
	//���뾶
	float64 maxRadius;

}T3Object, *T3ObjectPtr;

#endif