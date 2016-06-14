#include "Matrix3.h"
#include "Vector3.h"
#include <math.h>



Matrix3::Matrix3()
{
	m_matrix[0][0] = 0;
	m_matrix[0][1] = 0;
	m_matrix[0][2] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 0;
	m_matrix[1][2] = 0;
	m_matrix[2][0] = 0;
	m_matrix[2][1] = 0;
	m_matrix[2][2] = 0;
}

Matrix3::Matrix3(float aa, float ab, float ac, float ba, float bb, float bc, float ca, float cb, float cc)
{
	m_matrix[0][0] = aa;
	m_matrix[0][1] = ab;
	m_matrix[0][2] = ac;
	m_matrix[1][0] = ba;
	m_matrix[1][1] = bb;
	m_matrix[1][2] = bc;
	m_matrix[2][0] = ca;
	m_matrix[2][1] = cb;
	m_matrix[2][2] = cc;
}

Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::operator=(const Matrix3 & matA)
{
	m_matrix[0][0] = matA.m_matrix[0][0];
	m_matrix[0][1] = matA.m_matrix[0][1];
	m_matrix[0][2] = matA.m_matrix[0][2];
	m_matrix[1][0] = matA.m_matrix[1][0];
	m_matrix[1][1] = matA.m_matrix[1][1];
	m_matrix[1][2] = matA.m_matrix[1][2];
	m_matrix[2][0] = matA.m_matrix[2][0];
	m_matrix[2][1] = matA.m_matrix[2][1];
	m_matrix[2][2] = matA.m_matrix[2][2];
	return *this;
}

const bool Matrix3::operator==(const Matrix3 & matA)
{
	return ((m_matrix[0][0] == matA.m_matrix[0][0]) && (m_matrix[0][1] == matA.m_matrix[0][1]) && (m_matrix[0][2] == matA.m_matrix[0][2]) && (m_matrix[1][0] == matA.m_matrix[1][0]) && (m_matrix[1][1] == matA.m_matrix[1][1]) && (m_matrix[1][2] == matA.m_matrix[1][2]) && (m_matrix[2][0] == matA.m_matrix[2][0]) && (m_matrix[2][1] == matA.m_matrix[2][1]) && (m_matrix[2][2] == matA.m_matrix[2][2]));
}

Matrix3 Matrix3::operator*(const Matrix3 & matA)
{
	Matrix3 result;
	unsigned int resultRows = 3, resultColumns = 3;
	for (unsigned int i = 0; i < resultColumns; i++) {
		for (unsigned int j = 0; j < resultRows; j++) {
			for (unsigned int k = 0; k < resultRows; k++) {
				result.m_matrix[i][j] += (m_matrix[k][j] * matA.m_matrix[i][k]);
			}
		}
	}
	return result;
}

Matrix3 Matrix3::operator+(const Matrix3 & matA)
{
	Matrix3 result;
	result.m_matrix[0][0] = m_matrix[0][0] + matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] + matA.m_matrix[0][1];
	result.m_matrix[0][2] = m_matrix[0][2] + matA.m_matrix[0][2];
	result.m_matrix[1][0] = m_matrix[1][0] + matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] + matA.m_matrix[1][1];
	result.m_matrix[1][2] = m_matrix[1][2] + matA.m_matrix[1][2];
	result.m_matrix[2][0] = m_matrix[2][0] + matA.m_matrix[2][0];
	result.m_matrix[2][1] = m_matrix[2][1] + matA.m_matrix[2][1];
	result.m_matrix[2][2] = m_matrix[2][2] + matA.m_matrix[2][2];
	return result;
}

Matrix3 Matrix3::operator-(const Matrix3 & matA)
{
	Matrix3 result;
	result.m_matrix[0][0] = m_matrix[0][0] - matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] - matA.m_matrix[0][1];
	result.m_matrix[0][2] = m_matrix[0][2] - matA.m_matrix[0][2];
	result.m_matrix[1][0] = m_matrix[1][0] - matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] - matA.m_matrix[1][1];
	result.m_matrix[1][2] = m_matrix[1][2] - matA.m_matrix[1][2];
	result.m_matrix[2][0] = m_matrix[2][0] - matA.m_matrix[2][0];
	result.m_matrix[2][1] = m_matrix[2][1] - matA.m_matrix[2][1];
	result.m_matrix[2][2] = m_matrix[2][2] - matA.m_matrix[2][2];
	return result;
}

Matrix3::operator float*()
{
	return (float*)this;
}

void Matrix3::setRotateX(float f)
{
	m_matrix[0][0] = 1;
	m_matrix[0][1] = 0;
	m_matrix[0][2] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = cosf(f);
	m_matrix[1][2] = sinf(f);
	m_matrix[2][0] = 0;
	m_matrix[2][1] = -(sinf(f));
	m_matrix[2][2] = cosf(f);
}

void Matrix3::setRotateY(float f)
{
	m_matrix[0][0] = cosf(f);
	m_matrix[0][1] = 0;
	m_matrix[0][2] = -(sinf(f));
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 1;
	m_matrix[1][2] = 0;
	m_matrix[2][0] = sinf(f);
	m_matrix[2][1] = 0;
	m_matrix[2][2] = cosf(f);
}

void Matrix3::setRotateZ(float f)
{
	m_matrix[0][0] = cosf(f);
	m_matrix[0][1] = sinf(f);
	m_matrix[0][2] = 0;
	m_matrix[1][0] = -(sinf(f));
	m_matrix[1][1] = cosf(f);
	m_matrix[1][2] = 0;
	m_matrix[2][0] = 0;
	m_matrix[2][1] = 0;
	m_matrix[2][2] = 1;
}

void Matrix3::setTranslate(float x, float y)
{
	m_matrix[0][0] = 1;
	m_matrix[0][1] = 0;
	m_matrix[0][2] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 1;
	m_matrix[1][2] = 0;
	m_matrix[2][0] = x;
	m_matrix[2][1] = y;
	m_matrix[2][2] = 1;
}

Matrix3 Matrix3::CreateIdentity()
{
	return Matrix3(1,0,0,0,1,0,0,0,1);
}

Matrix3 Matrix3::CreateScale(float x, float y, float z)
{
	return Matrix3(x,0,0,0,y,0,0,0,z);
}

Matrix3 Matrix3::CreateScale(Vector3 vec)
{
	return Matrix3(vec.m_x,0,0,0,vec.m_y,0,0,0,vec.m_z);
}

Matrix3 Matrix3::CreateRotationZ(float f)
{
	return Matrix3(cosf(f), sinf(f), 0, -(sinf(f)), cosf(f), 0, 0, 0, 1);
}

Matrix3 Matrix3::CreateTranslation(float x, float y)
{
	return Matrix3(1,0,0,0,1,0,x,y,1);
}

Matrix3 Matrix3::CreateBlank()
{
	return Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0);
}
