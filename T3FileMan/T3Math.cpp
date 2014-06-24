#include"T3Math.h"

//һ��Ϊ��ŽǶ��������ҵĲ��ұ�
float64 CosLook[361];
float64 SinLook[361];

//�����ʼ��
void T3MatInit2X2(T3Mat2X2Ptr ma, float64 m00, float64 m01, float64 m10, float64 m11)
{
	//ʹ�ø���������ʼ������
	ma->M00 = m00;	ma->M01 = m01;
	ma->M10 = m10;	ma->M11 = m11;
}


void T3MatInit3X3(T3Mat3X3Ptr ma, 
				  float64 m00, float64 m01, float64 m02,
				  float64 m10, float64 m11, float64 m12,
				  float64 m20, float64 m21, float64 m22)
{
	//ʹ�ø���������ʼ������
	ma->M00 = m00; ma->M01 = m01; ma->M02 = m02;
	ma->M10 = m10; ma->M11 = m11; ma->M12 = m12;
	ma->M20 = m20; ma->M21 = m21; ma->M22 = m22;
}

void T3MatInit4X4(T3Mat4X4Ptr ma, 
				  float64 m00, float64 m01, float64 m02, float64 m03,
				  float64 m10, float64 m11, float64 m12, float64 m13,
				  float64 m20, float64 m21, float64 m22, float64 m23,
				  float64 m30, float64 m31, float64 m32, float64 m33)
{
	//ʹ�ø���������ʼ������
	ma->M00 = m00; ma->M01 = m01; ma->M02 = m02; ma->M03 = m03;
	ma->M10 = m10; ma->M11 = m11; ma->M12 = m12; ma->M13 = m13;
	ma->M20 = m20; ma->M21 = m21; ma->M22 = m22; ma->M23 = m23;
	ma->M30 = m30; ma->M31 = m31; ma->M32 = m32; ma->M33 = m33;
}

//��������
//���ж�A�Ƿ�Ϊ������� ��Ϊֻ�з��������Ŵ��������(|�������| = 0)
//����� = 1/|A|��A*(����Ĵ�������ʽ)
int32 T3MatInverse2X2(T3Mat2X2Ptr m, T3Mat2X2Ptr mi)
{
	//���׷���Ĵ�������ʽ 
	//|m11 m10|
	//|m01 m00|

	//�����ж��Ƿ�Ϊ�������
	float64 det = m->M00 * m->M11 - m->M01 * m->M10;

	//���ȵ͵�������е��ж���0�Ĺ�ϵ
	if(T3Abs(det) < EPSILON5)
		return 0;

	float64 detInverse = 1/det;
	//Ϊ���������
	mi->M00 = detInverse * m->M11;
	mi->M01 = detInverse * m->M10;
	mi->M10 = detInverse * m->M01;
	mi->M11 = detInverse * m->M00;

	//����ɹ�
	return 1;
}

int32 T3MatInverse3X3(T3Mat3X3Ptr m, T3Mat3X3Ptr mi)
{
	//���׷���Ĵ�������ʽ 
	//|+|m11 m12|-|m01 m02|+|m01 m02| |
	//|	|m21 m22| |m21 m22| |m11 m12| |

	//|-|m10 m12|+|m00 m02|-|m00 m02| |
	//|	|m20 m22| |m20 m22| |m10 m12| |
	
	//|+|m10 m11|-|m00 m01|+|m00 m01| |
	//|	|m20 m21| |m20 m21| |m10 m11| |

	//�����ж��Ƿ�Ϊ�������
	float64 det = (m->M00 * m->M11 * m->M22 + m->M01 * m->M12 * m->M20 + m->M10 * m->M21 *m->M02)
		- (m->M20 * m->M11 * m->M02 + m->M10 * m->M01 * m->M22 + m->M21 * m->M12 * m->M00);

	//���ȵ͵�������е��ж���0�Ĺ�ϵ
	if(T3Abs(det) < EPSILON5)
		return 0;

	float64 detInverse = 1/det;

	//Ϊ���������
	mi->M00 =  detInverse*(m->M11*m->M22 - m->M21*m->M12);
	mi->M01 = -detInverse*(m->M01*m->M22 - m->M21*m->M02);
	mi->M02 =  detInverse*(m->M01*m->M12 - m->M11*m->M02);

	mi->M10 = -detInverse*(m->M10*m->M22 - m->M20*m->M12);
	mi->M11 =  detInverse*(m->M00*m->M22 - m->M20*m->M02);
	mi->M12 = -detInverse*(m->M00*m->M12 - m->M10*m->M02);

	mi->M20 =  detInverse*(m->M10*m->M21 - m->M20*m->M11);
	mi->M21 = -detInverse*(m->M00*m->M21 - m->M20*m->M01);
	mi->M22 =  detInverse*(m->M00*m->M11 - m->M10*m->M01);

	//����ɹ�
	return 1;
}
int32 T3MatInverse4X4(T3Mat4X4Ptr m, T3Mat4X4Ptr mi)
{
	//�Ľ׷�������һ��ʼ��Ĭ��Ϊ[0, 0, 0, 1]t
	//���������ʽ̫�鷳�������Ȳ�����

	//�����ж��Ƿ�Ϊ�������
	//�������һ�е�1���մ�������ʽչ��
	//(-1)4 = 1���Ϊ����
	float64 det = (m->M00 * m->M11 * m->M22 + m->M01 * m->M12 * m->M20 + m->M10 * m->M21 *m->M02)
		- (m->M20 * m->M11 * m->M02 + m->M10 * m->M01 * m->M22 + m->M21 * m->M12 * m->M00);

	//���ȵ͵�������е��ж���0�Ĺ�ϵ
	if(T3Abs(det) < EPSILON5)
		return 0;

	float64 detInverse = 1/det;

	//Ϊ���������
	mi->M00 =  detInverse * ( m->M11 * m->M22 - m->M12 * m->M21 );
	mi->M01 = -detInverse * ( m->M01 * m->M22 - m->M02 * m->M21 );
	mi->M02 =  detInverse * ( m->M01 * m->M12 - m->M02 * m->M11 );
	mi->M03 = 0.0f;

	mi->M10 = -detInverse * ( m->M10 * m->M22 - m->M12 * m->M20 );
	mi->M11 =  detInverse * ( m->M00 * m->M22 - m->M02 * m->M20 );
	mi->M12 = -detInverse * ( m->M00 * m->M12 - m->M02 * m->M10 );
	mi->M13 = 0.0f; 

	mi->M20 =  detInverse * ( m->M10 * m->M21 - m->M11 * m->M20 );
	mi->M21 = -detInverse * ( m->M00 * m->M21 - m->M01 * m->M20 );
	mi->M22 =  detInverse * ( m->M00 * m->M11 - m->M01 * m->M10 );
	mi->M23 = 0.0f; 

	mi->M30 = -((m->M00*m->M21*m->M32 + m->M01*m->M22*m->M32 + m->M20*m->M31*m->M02)-
		((m->M30*m->M21*m->M02 + m->M20*m->M01*m->M32 + m->M31*m->M22*m->M00)));
	mi->M31 =  (m->M00*m->M21*m->M02 + m->M01*m->M22*m->M30 + m->M20*m->M31*m->M02)-
		(m->M30*m->M21*m->M02 + m->M20*m->M01*m->M32 + m->M31*m->M22*m->M00);
	mi->M32 = -((m->M00*mi->M32*m->M11 + m->M10*mi->M31*m->M02 + m->M01*mi->M12*m->M30)-
		(m->M30*m->M11*m->M02 + m->M10*m->M01*m->M32 + m->M31*m->M12*m->M00));
	mi->M33 = 1.0f;

	//����ɹ�
	return 1;
}

//�����������
//�ӷ�
void T3MatAdd2X2(T3Mat2X2Ptr ma, T3Mat2X2Ptr mb, T3Mat2X2Ptr msum)
{
	//��ӦԪ�����
	msum->M00 = ma->M00+mb->M00;
	msum->M01 = ma->M01+mb->M01;
	msum->M10 = ma->M10+mb->M10;
	msum->M11 = ma->M11+mb->M11;
}

void T3MatAdd3X3(T3Mat3X3Ptr ma, T3Mat3X3Ptr mb, T3Mat3X3Ptr msum)
{
	//ʹ���ֹ�Ч�ʸ��� ���ǽ�����Ҫ��ʱ�����ֹ���д����
	for(int32 row=0; row<3; row++)
		for(int32 column=0; column<3; column++)
			ma->M[row][column] = ma->M[row][column] + mb->M[row][column];
}

void T3MatAdd4X4(T3Mat4X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr msum)
{
	for(int32 row=0; row<4; row++)
		for(int32 column=0; column<4; column++)
			ma->M[row][column] = ma->M[row][column] + mb->M[row][column];
}

//����˷�
void T3MatMul2X2(T3Mat2X2Ptr ma, T3Mat2X2Ptr mb, T3Mat2X2Ptr mprod)
{
	//��˵Ľ����û�иı�ab��������Ǵ洢����production������
	mprod->M00 = ma->M00*mb->M00 + ma->M01*mb->M10;
	mprod->M01 = ma->M00*mb->M01 + ma->M01*mb->M11;

	mprod->M10 = ma->M10*mb->M00 + ma->M11*mb->M10;
	mprod->M11 = ma->M10*mb->M01 + ma->M11*mb->M11;
}

void T3MatMulVECTOR3D_3X3(T3Vector3DPtr  va, T3Mat3X3Ptr mb, T3Vector3DPtr  vprod)
{
	int32 sum;
	for(int32 column =0; column <3; column ++)
	{
		//�����ÿ�
		sum = 0;
		for(int32 row=0; row<3; row++)
			sum+= va->M[row] * mb->M[row][column];

		//�����������production��
		vprod->M[column] = sum;
	}
}

void T3MatMul4X4(T3Mat4X4Ptr ma, T3Mat4X4Ptr mb, T3Mat4X4Ptr mprod)
{
	int32 sum;
	for(int32 row=0; row<4; row++)
	{
		sum = 0;
		for(int32 column=0; column<4; column++)
		{
			for(int32 index=0; index<4; index++)
			{
				sum+= ma->M[row][index] + mb->M[index][row];
			}

			//������
			mprod->M[row][column] = sum;
		}
	}
}

void T3MatMul1X4_4X4(T3Mat1X4Ptr ma, T3Mat4X4Ptr mb, T3Mat1X4Ptr mprod)
{
	int32 sum;
	for(int32 row=0; row<4; row++)
	{
		sum=0;
		for(int32 column=0; column<4; column++)
		{
			sum+= ma->M[column] * mb->M[row][column];
		}

		mprod->M[row] = sum;
	}
}

void T3Mat_T3Vector3D_Mul_4X4(T3Vector4DPtr  va, T3Mat4X4Ptr mb, T3Vector4DPtr  vprod)
{
	int32 sum;
	//�˴��ٶ�3D����Ϊ4D Ҳ�������һ�е�������1 [a, b, c, 1]
	for(int32 column=0; column<3; column++)
	{
		sum=0;
		for(int32 row=0; row<3; row++)
		{
			sum+= va->M[column] * mb->M[row][column];
		}
		//3D�����ļٶ����һԪΪ1��4X4��ĳһ�����֮�󼴵����е�ĳ�е�ֵ����
		sum+= mb->M[4][column];

		vprod->M[column] = sum;
	}
}

void T3Mat_T3Vector3D_Mul_4X3(T3Vector4DPtr  va, T3Mat4X4Ptr mb, T3Vector4DPtr  vprod)
{
	//�ҹ�������ʱ�ò��������̬�����뺯���ɡ���
}

void T3Mat_T3Vector4D_Mul_4X4(T3Vector4DPtr  va, 
							  T3Mat4X4Ptr mb,
							  T3Vector4DPtr  vprod)
{
	int32 sum;
	for(int32 row=0; row<4; row++)
	{
		sum=0;
		for(int32 column=0; column<4; column++)
		{
			sum+= va->M[column] * mb->M[row][column];
		}

		vprod->M[row] = sum;
	}
}

//����������ʽ
float64 T3MatDet2X2(T3Mat2X2Ptr m)
{
	return(m->M00*m->M11 - m->M01*m->M10);
}

float64 T3MatDet3X3(T3Mat3X3Ptr m)
{
	return (m->M00 * m->M11 * m->M22 + m->M01 * m->M12 * m->M20 + m->M10 * m->M21 *m->M02)
		- (m->M20 * m->M11 * m->M02 + m->M10 * m->M01 * m->M22 + m->M21 * m->M12 * m->M00);
}

//�������
void T3Vector2DAdd(T3Vector2DPtr va, T3Vector2DPtr vb, T3Vector2DPtr vsum)
{
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
}

T3Vector2D T3Vector2DAdd(T3Vector2DPtr va, T3Vector2DPtr vb)
{
	T3Vector2D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;

	return(vsum);
}

void T3Vector3DAdd(T3Vector3DPtr va, T3Vector3DPtr vb, T3Vector3DPtr vsum)
{
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
	vsum->z = va->z + vb->z;
}

T3Vector3D T3Vector3DAdd(T3Vector3DPtr va, T3Vector3DPtr vb)
{
	T3Vector3D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;
	vsum.z = va->z + vb->z;

	return(vsum);
}

void T3Vector4DAdd(T3Vector4DPtr va, T3Vector4DPtr vb, T3Vector4DPtr vsum)
{
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
	vsum->z = va->z + vb->z;
	//4D������������һλĬ��Ϊ1 �����Ӻ���Ȼ��1
	vsum->w = 1;
}

T3Vector4D T3Vector4DAdd(T3Vector4DPtr va, T3Vector4DPtr vb)
{
	T3Vector4D vsum;

	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;
	vsum.z = va->z + vb->z;
	vsum.w = 1;

	return(vsum);
}

//�������
void T3Vector2DSub(T3Vector2DPtr va, T3Vector2DPtr vb, T3Vector2DPtr vdiff)
{
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
}

T3Vector2D T3Vector2DSub(T3Vector2DPtr va, T3Vector2DPtr vb)
{
	T3Vector2D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;

	// return result
	return(vdiff);   
}

void T3Vector3DSub(T3Vector3DPtr va, T3Vector3DPtr vb, T3Vector3DPtr vdiff)
{
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
	vdiff->z = va->z - vb->z;
}

T3Vector3D T3Vector3DSub(T3Vector3DPtr va, T3Vector3DPtr vb)
{
	T3Vector3D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;
	vdiff.z = va->z - vb->z;

	return(vdiff);         
}

void T3Vector4DSub(T3Vector4DPtr va, T3Vector4DPtr vb, T3Vector4DPtr vdiff)
{
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;
	vdiff->z = va->z - vb->z;
	vdiff->w = 1;
}

T3Vector4D T3Vector4DSub(T3Vector4DPtr va, T3Vector4DPtr vb)
{
	T3Vector4D vdiff;

	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;
	vdiff.z = va->z - vb->z;
	vdiff.w = 1;

	// return result
	return(vdiff);    
}

//����(����) �����������˻�
void T3Vector2DScale(float64 k, T3Vector2DPtr va)
{
	va->x*=k;
	va->y*=k;
}

void T3Vector2DScale(float64 k, T3Vector2DPtr va, T3Vector2DPtr vscaled)
{
	vscaled->x = k*va->x;
	vscaled->y = k*va->y;
}

void T3Vector3DScale(float64 k, T3Vector3DPtr va)
{
	va->x*=k;
	va->y*=k;
	va->z*=k;
}

void T3Vector3DScale(float64 k, T3Vector3DPtr va, T3Vector3DPtr vscaled)
{
	vscaled->x = k*va->x;
	vscaled->y = k*va->y;
	vscaled->z = k*va->z;
}

void T3Vector4DScale(float64 k, T3Vector4DPtr va)
{	
	va->x*=k;
	va->y*=k;
	va->z*=k;
	//���һλֻ��Ϊ�����
	va->w = 1;
}

void T3Vector4DScale(float64 k, T3Vector4DPtr va, T3Vector4DPtr vscaled)
{
	vscaled->x = k*va->x;
	vscaled->y = k*va->y;
	vscaled->z = k*va->z;
	vscaled->w = 1;
}

//������������
float64 T3Vector2DLength(T3Vector2DPtr va)
{
	return(sqrtf(va->x*va->x + va->y*va->y));
}

float64 T3Vector2DLengthFast(T3Vector2DPtr va)
{
	return( (float)FastSqrt2D(va->x, va->y) );
}

float64 T3Vector3DLength(T3Vector3DPtr va)
{
	return( (float)sqrtf(va->x*va->x + va->y*va->y + va->z*va->z) );
}

float64 T3Vector3DLengthFast(T3Vector3DPtr va)
{
	return( FastSqrt3D(va->x, va->y, va->z) );
}

float64 T3Vector4DLength(T3Vector4DPtr va)
{
	return(sqrtf(va->x*va->x + va->y*va->y + va->z*va->z) );
}

float64 T3Vector4DLengthFast(T3Vector4DPtr va)
{
	//���������1���Ժ��� ���Ϊ���
	return( FastSqrt3D(va->x, va->y, va->z) );
}

//������׼��(��λ��)
//���βα������ת��
void T3Vector2DNormalize(T3Vector2DPtr va)
{
	float length = sqrtf(va->x*va->x + va->y*va->y );

	//���㳤���ж���0��ϵ
	if (length < EPSILON5) 
		return;

	float length_inv = 1/length;

	//��׼��
	va->x = va->x*length_inv;
	va->y = va->y*length_inv;
}

//����׼���Ľ����������һ��������
void T3Vector2DNormalize(T3Vector2DPtr va, T3Vector2DPtr vn)
{
	T3Vector2DZero(vn);

	//���㳤��
	float length = (float)sqrtf(va->x*va->x + va->y*va->y );

	if (length < EPSILON5) 
		return;

	float length_inv = 1/length;

	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
}

void T3Vector3DNormalize(T3Vector3DPtr va)
{
	float length = sqrtf(va->x*va->x + va->y*va->y + va->z*va->z);

	if (length < EPSILON5) 
		return;

	float length_inv = 1/length;

	va->x*=length_inv;
	va->y*=length_inv;
	va->z*=length_inv;
}

void T3Vector3DNormalize(T3Vector3DPtr va, T3Vector3DPtr vn)
{
	T3Vector3DZero(vn);

	float length = T3Vector3DLength(va);

	if (length < EPSILON5) 
		return;

	float length_inv = 1.0/length;

	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
	vn->z = va->z*length_inv;
}

void T3Vector4DNormalize(T3Vector4DPtr va)
{
	float length = sqrtf(va->x*va->x + va->y*va->y + va->z*va->z);

	if (length < EPSILON5) 
		return;

	float length_inv = 1.0/length;

	va->x*=length_inv;
	va->y*=length_inv;
	va->z*=length_inv;
	va->w = 1;
}

void T3Vector4DNormalize(T3Vector4DPtr va, T3Vector4DPtr vn)
{
	T3Vector4DZero(vn);

	float length = sqrt(va->x*va->x + va->y*va->y + va->z*va->z);

	if (length < EPSILON5) 
		return;

	float length_inv = 1.0/length;

	vn->x = va->x*length_inv;
	vn->y = va->y*length_inv;
	vn->z = va->z*length_inv;
	vn->w = 1;
}

//�������
float64 T3Vector2DDot(T3Vector2DPtr va, T3Vector2DPtr vb)
{
	return( (va->x * vb->x) + (va->y * vb->y) );
}

float64 T3Vector3DDot(T3Vector3DPtr va, T3Vector3DPtr vb)
{
	return( (va->x * vb->x) + (va->y * vb->y) + (va->z * vb->z) );
}

float64 T3Vector4DDot(T3Vector4DPtr va, T3Vector4DPtr vb)
{
	//����������겻�������
	return( (va->x * vb->x) + (va->y * vb->y) + (va->z * vb->z) );
}

//�������
//2D����û��ʵ���������ϵĲ��
//����Ľ����������ͼ����
//|i j k|
//|a b c|
//|x y z|
void T3Vector3DCross(T3Vector3DPtr va,T3Vector3DPtr vb,T3Vector3DPtr vn)
{
	vn->x = va->y*vb->z - va->z*vb->y;
	vn->y = va->z*vb->x - va->x*vb->z;
	vn->z = va->x*vb->y - va->y*vb->x;
}

T3Vector3D T3Vector3DCross(T3Vector3DPtr va, T3Vector3DPtr vb)
{
	T3Vector3D vn;

	vn.x = va->y*vb->z - va->z*vb->y;
	vn.y = va->z*vb->x - va->x*vb->z;
	vn.z = va->x*vb->y - va->y*vb->x;

	return vn;
}

void T3Vector4DCross(T3Vector4DPtr va,T3Vector4DPtr vb,T3Vector4DPtr vn)
{
	//��3D�Ĳ��Ψһ��ͬ�ľ��Ǳ��������
	vn->x = va->y*vb->z - va->z*vb->y;
	vn->y = va->z*vb->x - va->x*vb->z;
	vn->z = va->x*vb->y - va->y*vb->x;
	vn->w = 1;
}

T3Vector4D T3Vector4DCross(T3Vector4DPtr va, T3Vector4DPtr vb)
{
	T3Vector4D vn;

	vn.x = va->y*vb->z - va->z*vb->y;
	vn.y = va->z*vb->x - va->x*vb->z;
	vn.z = va->x*vb->y - va->y*vb->x;
	vn.w = 1;

	return vn;
}

//�����������н�
//���ﷵ�ص��Ǽнǵ����� ��Ϊ������Ҫ������������ǶȵĴ�С ����Ч�ʹ���
float64 T3Vector2DCosTheta(T3Vector2DPtr va, T3Vector2DPtr vb)
{
	return (T3Vector2DDot(va, vb)/(T3Vector2DLength(va)*T3Vector2DLength(vb)));
}

float64 T3Vector3DCosTheta(T3Vector3DPtr va, T3Vector3DPtr vb)
{
	return (T3Vector3DDot(va, vb)/(T3Vector3DLength(va)*T3Vector3DLength(vb)));
}

float64 T3Vector4DCosTheta(T3Vector4DPtr va, T3Vector4DPtr vb)
{
	return (T3Vector4DDot(va, vb)/(T3Vector4DLength(va)*T3Vector4DLength(vb)));
}

//ʹ����������������һ������
void T3Vector2DBuild(T3Vector2DPtr init, T3Vector2DPtr term, T3Vector2DPtr result)
{
	//�����Ĳ�
	result->x = term->x - init->x;
	result->y = term->y - init->y;
}

void T3Vector3DBuild(T3Vector3DPtr init, T3Vector3DPtr term, T3Vector3DPtr result)
{
	result->x = term->x - init->x;
	result->y = term->y - init->y;
	result->z = term->z - init->z;
}

void T3Vector4DBuild(T3Vector4DPtr init, T3Vector4DPtr term, T3Vector4DPtr result)
{
	result->x = term->x - init->x;
	result->y = term->y - init->y;
	result->z = term->z - init->z;
	result->w = 1;
}

//���ټ�����������
float64 FastSin(float64 theta)
{
	//���Ƕ�ת����0-360��
	theta = fmodf(theta,360);

	//�����Ƕ�ת��
	if (theta < 0) theta+=360.0;

	//�Ƕ���������
	int thetaInt    = (int)theta;
	//�Ƕ�С������
	float thetaFrac = theta - thetaInt;

	//һ��֮�����Ҳ�ֵ*С�����ֽ������С�����ֶ�Ӧ����ֵ
	return(SinLook[thetaInt] + 
		thetaFrac*(SinLook[thetaInt+1] - SinLook[thetaInt]));
}

float64 FastCos(float64 theta)
{
	//���Ƕ�ת����0-360��
	theta = fmodf(theta,360);

	//�����Ƕ�ת��
	if (theta < 0) theta+=360.0;

	//�Ƕ���������
	int thetaInt    = (int)theta;
	//�Ƕ�С������
	float thetaFrac = theta - thetaInt;

	//һ��֮�����Ҳ�ֵ*С�����ֽ������С�����ֶ�Ӧ����ֵ
	return(CosLook[thetaInt] + 
		thetaFrac*(CosLook[thetaInt+1] - CosLook[thetaInt]));

}

//���ټ���ƽ����
//---���---
int FastSqrt2D(int x, int y)
{
	x = abs(x);
	y = abs(y);

	// compute the minimum of x,y
	int mn = T3Min(x,y);

	// return the distance
	return(x+y-(mn>>1)-(mn>>2)+(mn>>4));
}

float FastSqrt3D(float fx, float fy, float fz)
{
	int temp;  // used for swaping
	int x,y,z; // used for algorithm

	// make sure values are all positive
	x = fabs(fx) * 1024;
	y = fabs(fy) * 1024;
	z = fabs(fz) * 1024;

	// sort values
	if (y < x) T3Swap(x,y,temp)

		if (z < y) T3Swap(y,z,temp)

			if (y < x) T3Swap(x,y,temp)

				int dist = (z + 11 * (y >> 5) + (x >> 2) );

	// compute distance with 8% error
	return((float)(dist >> 10));
}

