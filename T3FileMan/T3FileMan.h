#include "T3Primitive.h"
struct T3POINT3;
struct T3REVOLVEPOINT;
struct T3PLGMODEL;
int T3Load0(T3PLGMODEL & ,char *);
int T3Load(T3Object & ,char *);
int T3LoadMap(T3Object * ,char *,int &);
int T3ErrorLog(int, char *);

struct T3POINT2
{
	double x;
	double y;
};

struct T3TIME
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
};


/*
int T3Draw(HDC,HWND,T3PLGMODEL &,COLORREF);
int T3Revolve(HDC,HWND,T3PLGMODEL &,POINT,COLORREF);
int T3Refresh(HDC,HWND);


struct T3POINT3
{
	double x;
	double y;
	double z;
};

struct T3REVOLVEPOINT
{
	double x;
	double y;
	double z;
	double r;
	double theta;
};

struct T3PLGMODEL
{
	double c[300];//���ģ�����в���
	int NumOfPoint;//��Ŷ�����
	T3POINT3 Point3[30];//��Ŷ���
	T3REVOLVEPOINT RPoint[30];//�����ת��Ķ���RevolvePoint
	T3POINT2 Point2[30];//���������Զ���Ķ�ά����
	T3POINT2 DPoint[30];//���ĳ������ζ����ά����DrawPoint
};

*/