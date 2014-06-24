#ifndef T3Math_H
#define T3Math_H

#include <math.h>
#include <memory.h>

//�淶C/C++������������������ʽ
typedef signed short int16;
typedef signed int int32;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;


//�ǳ�С�ĳ��� �����ж�һ�������µ������Ƿ����0
#define EPSILON4 (float64)(1E-4)
#define EPSILON5 (float64)(1E-5)
#define EPSILON6 (float64)(1E-6)

//PI����
#define PI		   (float64)3.1415926535897932384626f
#define PI2        (float64))6.283185307f
#define PI_DIV_2   (float64)1.570796327f
#define PI_DIV_4   (float64))0.785398163f
#define PI_INV     (float64)0.318309886f

//ȡ�������Сֵ
#define T3Min(a, b)  (((a) < (b)) ? (a) : (b)) 
#define T3Max(a, b)  (((a) > (b)) ? (a) : (b)) 

//ȡ����ֵ
#define T3Abs(a) fabs(a)

//�����β�
#define T3Swap(a,b,temp) {temp=a; a=b; b=temp;}

//���ȽǶ�ת��
#define AngleToRadian(angle) ((angle)*PI/180.0)
#define RadianToAngle(radians) ((radians)*180.0/PI)

//�������Χ
#define RandRange(x,y) ((x) + (rand()%((y)-(x)+1)))

//���ȽǶȲ��ұ� ��Ҫ����ʱ����T3BulidSinCosTablel����ʼ���������Ҳ��ұ�
//���ڲ��Ҽ���sin��cosֵ
extern float64 CosLook[361];
extern float64 SinLook[361];


//���ݽṹ����
//�����͵�
//ʹ����������֧�ֶ��ַ�ʽ������������
typedef struct T3Vector2DType
{
	union
	{
		//����洢��ʽ
		float64 M[2];
		//����������ɽṹ��洢
		struct
		{
			float64 x, y;
		};
	};
}T3Vector2D, T3Point2D, *T3Vector2DPtr, *T3Point2DPtr;


typedef struct T3Vector3DType
{
	union
	{
		//����洢��ʽ
		float64 M[3];
		//����������ɽṹ��洢
		struct
		{
			float64 x, y, z;
		};
	};
}T3Vector3D, T3Point3D, *T3Vector3DPtr, *T3Point3DPtr;


typedef struct T3Vector4DType
{
	union
	{
		//����洢��ʽ
		float64 M[4];
		//����������ɽṹ��洢
		struct
		{
			//��α���w
			float64 x, y, z, w;
		};
	};
}T3Vector4D, T3Point4D, *T3Vector4DPtr, *T3Point4DPtr;

//����
//1*2����
typedef struct T3Mat1X2Type
{
	union
	{
		//����洢��ʽ
		float64 M[2];
		//����������ɽṹ��洢

		struct
		{
			float64 M00, M01;
			float64 M10, M11;
		};
	};
}T3Mat1X2, *T3Mat1X2Ptr;

//2*2����
typedef struct T3Mat2X2Type
{
	union
	{
		//����洢��ʽ
		float64 M[2][2];
		//����������ɽṹ��洢

		struct
		{
			float64 M00, M01;
			float64 M10, M11;
		};
	};
}T3Mat2X2, *T3Mat2X2Ptr;

//1*3����
typedef struct T3Mat1X3Type
{
	union
	{
		//����洢��ʽ
		float64 M[3];
		//����������ɽṹ��洢
		struct
		{
			float64 M00, M01, M02;
		};

	};
} T3Mat1X3, *T3Mat1X3Ptr;

//1*4����
typedef struct T3Mat1X4Type
{
	union
	{
		//����洢��ʽ
		float64 M[4];
		//����������ɽṹ��洢
		struct
		{
			float64 M00, M01, M02, M03;
		};

	};
} T3Mat1X4, *T3Mat1X4Ptr;

//3*3����
typedef struct T3Mat3X3Type
{
	union
	{
		//����洢��ʽ
		float64 M[3][3];
		//����������ɽṹ��洢

		struct
		{
			float64 M00, M01, M02;
			float64 M10, M11, M12;
			float64 M20, M21, M22;
		};
	};
}T3Mat3X3, *T3Mat3X3Ptr;

//4*3����
typedef struct T3Mat4X3Type
{
	union
	{
		//����洢��ʽ
		float64 M[4][3];
		//����������ɽṹ��洢
		struct
		{
			float64 M00, M01, M02;
			float64 M10, M11, M12;
			float64 M20, M21, M22;
			float64 M30, M31, M32;
		};
	};
} T3Mat4X3, *T3Mat4X3Ptr;

//4*4����
typedef struct T3Mat4X4Type
{
	union
	{
		//����洢��ʽ
		float64 M[4][4];
		//����������ɽṹ��洢
		struct
		{
			float64 M00, M01, M02, M03;
			float64 M10, M11, M12, M13;
			float64 M20, M21, M22, M23;
			float64 M30, M31, M32, M33;
		};
	};
} T3Mat4X4, *T3Mat4X4Ptr;

//��λ����
//4x4��λ����
const T3Mat4X4 T3IdentityMat4X4 = {
	1,0,0,0, 
	0,1,0,0, 
	0,0,1,0, 
	0,0,0,1};

//4x3��λ���� ��������ѧ�ϲ�����������Ĭ��������о���[0, 0, 0, 1]
const T3Mat4X3 T3IdentityMat4X3 = {
	1,0,0, 
	0,1,0, 
	0,0,1, 
	0,0,0,};


//3x3��λ����
const T3Mat3X3 T3IdentityMat3X3 = {
	1,0,0, 
	0,1,0, 
	0,0,1};

//2x2��λ����
const T3Mat2X2 T3IdentityMat2X2 = {
	1,0, 
	0,1};


//��������������
#define T3MatZero2X2(m) {memset((void *)(m), 0, sizeof(T3Mat2X2));}
#define T3MatZero3X3(m) {memset((void *)(m), 0, sizeof(T3Mat3X3));}
#define T3MatZero4X4(m) {memset((void *)(m), 0, sizeof(T3Mat4X4));}
#define T3MatZero4X3(m) {memset((void *)(m), 0, sizeof(T3Mat4X3));}

//����������λ��
#define T3MatIdentity2X2(m) {memcpy((void *)(m), (void *)&T3IdentityMat2X2, sizeof(T3Mat2X2));}
#define T3MatIdentity3X3(m) {memcpy((void *)(m), (void *)&T3IdentityMat3X3, sizeof(T3Mat3X3));}
#define T3MatIdentity4X4(m) {memcpy((void *)(m), (void *)&T3IdentityMat4X4, sizeof(T3Mat4X4));}
#define T3MatIdentity4X3(m) {memcpy((void *)(m), (void *)&T3IdentityMat4X3, sizeof(T3Mat4X3));}

//����Դ����Ŀ�������
#define T3MatCopy2X2(srcMat, destMat) {memcpy((void *)(destMat), (void *)(srcMat), sizeof(MATRIX2X2) ); }
#define T3MatCopy3X3(srcMat, destMat) {memcpy((void *)(destMat), (void *)(srcMat), sizeof(MATRIX3X3) ); }
#define T3MatCopy4X4(srcMat, destMat) {memcpy((void *)(destMat), (void *)(srcMat), sizeof(MATRIX4X4) ); }
#define T3MatCopy4X3(srcMat, destMat) {memcpy((void *)(destMat), (void *)(srcMat), sizeof(MATRIX4X3) ); }

//��������󽻻�ָ��������
inline void T3MatColunmSwap2X2(T3Mat2X2Ptr m, int32 c, T3Mat1X2Ptr v) 
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; } 

inline void T3MatColunmSwap3X3(T3Mat3X3Ptr m, int c, T3Mat1X3Ptr v) 
{ m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2]; } 

inline void T3MatColunmSwap4X4(T3Mat4X4Ptr m, int c, T3Mat1X4Ptr v) 
{m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2]; m->M[3][c]=v->M[3]; } 

inline void T3MatColunmSwap4X3(T3Mat4X3Ptr m, int c, T3Mat1X4Ptr v) 
{m->M[0][c]=v->M[0]; m->M[1][c]=v->M[1]; m->M[2][c]=v->M[2]; m->M[3][c]=v->M[3]; } 

//ת�þ���
inline void T3MatTranspos3X3(T3Mat3X3Ptr m) 
{ 
	T3Mat3X3 mt;
	mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20;
	mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21;
	mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22;
	memcpy((void *)m,(void *)&mt, sizeof(T3Mat3X3)); 
}

inline void T3MatTranspos4X4(T3Mat4X4Ptr m) 
{
	T3Mat4X4 mt;
	mt.M00 = m->M00; mt.M01 = m->M10; mt.M02 = m->M20; mt.M03 = m->M30; 
	mt.M10 = m->M01; mt.M11 = m->M11; mt.M12 = m->M21; mt.M13 = m->M31; 
	mt.M20 = m->M02; mt.M21 = m->M12; mt.M22 = m->M22; mt.M23 = m->M32; 
	mt.M30 = m->M03; mt.M31 = m->M13; mt.M32 = m->M22; mt.M33 = m->M33; 
	memcpy((void *)m,(void *)&mt, sizeof(T3Mat4X4)); 
}

inline void T3MatTranspos3X3(T3Mat3X3Ptr m, T3Mat3X3Ptr mt) 
{ 
	mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20;
	mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21;
	mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22; 
}

inline void T3MatTranspos4X4(T3Mat4X4Ptr m, T3Mat4X4Ptr mt) 
{ 
	mt->M00 = m->M00; mt->M01 = m->M10; mt->M02 = m->M20; mt->M03 = m->M30; 
	mt->M10 = m->M01; mt->M11 = m->M11; mt->M12 = m->M21; mt->M13 = m->M31; 
	mt->M20 = m->M02; mt->M21 = m->M12; mt->M22 = m->M22; mt->M23 = m->M32; 
	mt->M30 = m->M03; mt->M31 = m->M13; mt->M32 = m->M22; mt->M33 = m->M33; 
}

//�����ʼ��
void T3MatInit2X2(T3Mat2X2Ptr ma, float64 m00, float64 m01, float64 m10, float64 m11);

void T3MatInit3X3(T3Mat3X3Ptr ma, 
				  float64 m00, float64 m01, float64 m02,
				  float64 m10, float64 m11, float64 m12,
				  float64 m20, float64 m21, float64 m22);

void T3MatInit4X4(T3Mat4X4Ptr ma, 
				  float64 m00, float64 m01, float64 m02, float64 m03,
				  float64 m10, float64 m11, float64 m12, float64 m13,
				  float64 m20, float64 m21, float64 m22, float64 m23,
				  float64 m30, float64 m31, float64 m32, float64 m33);

//��������
int32 T3MatInverse2X2(T3Mat2X2Ptr m, T3Mat2X2Ptr mi);
int32 T3MatInverse3X3(T3Mat3X3Ptr m, T3Mat3X3Ptr mi);
int32 T3MatInverse4X4(T3Mat4X4Ptr m, T3Mat4X4Ptr mi);

//�����������
//�ӷ�
void T3MatAdd2X2(T3Mat2X2Ptr ma, T3Mat2X2Ptr mb, T3Mat2X2Ptr msum);
void T3MatAdd3X3(T3Mat3X3Ptr ma, T3Mat3X3Ptr mb, T3Mat3X3Ptr msum);
void T3MatAdd4X4(T3Mat4X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr msum);

//�˷�
void T3MatMul2X2(T3Mat2X2Ptr ma, T3Mat2X2Ptr mb, T3Mat2X2Ptr mprod);

void T3MatMulVECTOR3D_3X3(T3Vector3DPtr  va, T3Mat3X3Ptr mb, T3Vector3DPtr  vprod);

void T3MatMul4X4(T3Mat4X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr mprod);
void T3MatMul4X4(T3Mat4X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr mprod);
void T3MatMul1X4_4X4(T3Mat1X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr mprod);

void T3Mat_T3Vector3D_Mul_4X4(T3Vector4DPtr  va, T3Mat4X4Ptr mb, T3Vector4DPtr  vprod);
void T3Mat_T3Vector3D_Mul_4X3(T3Vector4DPtr  va, T3Mat4X4Ptr mb, T3Vector4DPtr  vprod);

void T3Mat_T3Vector4D_Mul_4X4(T3Vector4DPtr  va, 
						  T3Mat4X4Ptr mb,
						  T3Vector4DPtr  vprod);
//����������ʽ
float64 T3MatDet2X2(T3Mat2X2Ptr m);
float64 T3MatDet3X3(T3Mat3X3Ptr m);



//��������������ͬ
//���ʼ��
inline void T3Point2DInit(T3Point2DPtr vdst, T3Point2DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
}

inline void T3Point3DInit(T3Point3DPtr vdst, T3Point3DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  (vdst)->z = (vsrc)->z; 
}

inline void T3Point4DInit(T3Point4DPtr vdst, T3Point4DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
	(vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;  
}

//�㿽��
inline void T3Point2DCopy(T3Point2DPtr vdst, T3Point2DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
}

inline void T3Point3DCopy(T3Point3DPtr vdst, T3Point3DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  (vdst)->z = (vsrc)->z; 
}

inline void T3Point4DCopy(T3Point4DPtr vdst, T3Point4DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
	(vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;  
}



//������ʼ��
inline void T3Vector2DInit(T3Vector2DPtr vdst, T3Vector2DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
}

inline void T3Vector3DInit(T3Vector3DPtr vdst, T3Vector3DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  (vdst)->z = (vsrc)->z; 
}

inline void T3Vector4DInit(T3Vector4DPtr vdst, T3Vector4DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
	(vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;  
}

//��������
inline void T3Vector2DCopy(T3Vector2DPtr vdst, T3Vector2DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
}


inline void T3Vector3DCopy(T3Vector3DPtr vdst, T3Vector3DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  (vdst)->z = (vsrc)->z; 
}

inline void T3Vector4DCopy(T3Vector4DPtr vdst, T3Vector4DPtr vsrc) 
{
	(vdst)->x = (vsrc)->x; (vdst)->y = (vsrc)->y;  
	(vdst)->z = (vsrc)->z; (vdst)->w = (vsrc)->w;  
}

//4D�������ת��Ϊ3D����
inline void T3Vector4D_DIV_W(T3Vector4DPtr v) 
{(v)->x/=(v)->w; (v)->y/=(v)->w; (v)->z/=(v)->w;  }

//4D�������ת��Ϊ�����4D
inline void T3Vector4D_DIV_W_To_T3Vector3D(T3Vector4DPtr v4, T3Vector4DPtr v3) 
{(v3)->x = (v4)->x/(v4)->w; (v3)->y = (v4)->y/(v4)->w; (v3)->z = (v4)->z/(v4)->w;  }

//����
inline void T3Vector2DZero(T3Vector2DPtr v) 
{(v)->x = (v)->y = 0.0;}

inline void T3Vector3DZero(T3Vector3DPtr v) 
{(v)->x = (v)->y = (v)->z = 0.0;}

inline void T3Vector4DZero(T3Vector4DPtr v) 
{(v)->x = (v)->y = (v)->z = 0.0; (v)->w = 1.0;}

//�������
void T3Vector2DAdd(T3Vector2DPtr va, T3Vector2DPtr vb, T3Vector2DPtr vsum);
T3Vector2D T3Vector2DAdd(T3Vector2DPtr va, T3Vector2DPtr vb);

void T3Vector3DAdd(T3Vector3DPtr va, T3Vector3DPtr vb, T3Vector3DPtr vsum);
T3Vector3D T3Vector3DAdd(T3Vector3DPtr va, T3Vector3DPtr vb);

void T3Vector4DAdd(T3Vector4DPtr va, T3Vector4DPtr vb, T3Vector4DPtr vsum);
T3Vector4D T3Vector4DAdd(T3Vector4DPtr va, T3Vector4DPtr vb);

//�������
void T3Vector2DSub(T3Vector2DPtr va, T3Vector2DPtr vb, T3Vector2DPtr vdiff);
T3Vector2D T3Vector2DSub(T3Vector2DPtr va, T3Vector2DPtr vb);

void T3Vector3DSub(T3Vector3DPtr va, T3Vector3DPtr vb, T3Vector3DPtr vdiff);
T3Vector3D T3Vector3DSub(T3Vector3DPtr va, T3Vector3DPtr vb);

void T3Vector4DSub(T3Vector4DPtr va, T3Vector4DPtr vb, T3Vector4DPtr vdiff);
T3Vector4D T3Vector4DSub(T3Vector4DPtr va, T3Vector4DPtr vb);

//����(����) �����������˻�
void T3Vector2DScale(float64 k, T3Vector2DPtr va);
void T3Vector2DScale(float64 k, T3Vector2DPtr va, T3Vector2DPtr vscaled);

void T3Vector3DScale(float64 k, T3Vector3DPtr va);
void T3Vector3DScale(float64 k, T3Vector3DPtr va, T3Vector3DPtr vscaled);

void T3Vector4DScale(float64 k, T3Vector4DPtr va);
void T3Vector4DScale(float64 k, T3Vector4DPtr va, T3Vector4DPtr vscaled);

//������������
float64 T3Vector2DLength(T3Vector2DPtr va);
float64 T3Vector2DLengthFast(T3Vector2DPtr va);

float64 T3Vector3DLength(T3Vector3DPtr va);
float64 T3Vector3DLengthFast(T3Vector3DPtr va);

float64 T3Vector4DLength(T3Vector4DPtr va);
float64 T3Vector4DLengthFast(T3Vector4DPtr va);

//������׼��(��λ��)
void T3Vector2DNormalize(T3Vector2DPtr va);
void T3Vector2DNormalize(T3Vector2DPtr va, T3Vector2DPtr vn);

void T3Vector3DNormalize(T3Vector3DPtr va);
void T3Vector3DNormalize(T3Vector3DPtr va, T3Vector3DPtr vn);

void T3Vector4DNormalize(T3Vector4DPtr va);
void T3Vector4DNormalize(T3Vector4DPtr va, T3Vector4DPtr vn);

//�������
float64 T3Vector2DDot(T3Vector2DPtr va, T3Vector2DPtr vb);
float64 T3Vector3DDot(T3Vector3DPtr va, T3Vector3DPtr vb);
float64 T3Vector4DDot(T3Vector4DPtr va, T3Vector4DPtr vb);

//�������
//2D����û��ʵ���������ϵĲ��
void T3Vector3DCross(T3Vector3DPtr va,T3Vector3DPtr vb,T3Vector3DPtr vn);
T3Vector3D T3Vector3DCross(T3Vector3DPtr va, T3Vector3DPtr vb);

void T3Vector4DCross(T3Vector4DPtr va,T3Vector4DPtr vb,T3Vector4DPtr vn);
T3Vector4D T3Vector4DCross(T3Vector4DPtr va, T3Vector4DPtr vb);

//�����������н�
float64 T3Vector2DCosTheta(T3Vector2DPtr va, T3Vector2DPtr vb);
float64 T3Vector3DCosTheta(T3Vector3DPtr va, T3Vector3DPtr vb);
float64 T3Vector4DCosTheta(T3Vector4DPtr va, T3Vector4DPtr vb);

//ʹ����������������һ������
void T3Vector2DBuild(T3Vector2DPtr init, T3Vector2DPtr term, T3Vector2DPtr result);
void T3Vector3DBuild(T3Vector3DPtr init, T3Vector3DPtr term, T3Vector3DPtr result);
void T3Vector4DBuild(T3Vector4DPtr init, T3Vector4DPtr term, T3Vector4DPtr result);

//���ټ�����������
float64 FastSin(float64 theta);
float64 FastCos(float64 theta);

//���ټ���ƽ����
int FastSqrt2D(int x, int y);
float FastSqrt3D(float fx, float fy, float fz);
#endif