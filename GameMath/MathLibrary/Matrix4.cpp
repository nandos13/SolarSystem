#include "Matrix4.h"
#include <math.h>



Matrix4::Matrix4()
{
	m_matrix[0][0] = 0;
	m_matrix[0][1] = 0;
	m_matrix[0][2] = 0;
	m_matrix[0][3] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 0;
	m_matrix[1][2] = 0;
	m_matrix[1][3] = 0;
	m_matrix[2][0] = 0;
	m_matrix[2][1] = 0;
	m_matrix[2][2] = 0;
	m_matrix[2][3] = 0;
	m_matrix[3][0] = 0;
	m_matrix[3][1] = 0;
	m_matrix[3][2] = 0;
	m_matrix[3][3] = 0;
}

Matrix4::Matrix4(float aa, float ab, float ac, float ad, float ba, float bb, float bc, float bd, float ca, float cb, float cc, float cd, float da, float db, float dc, float dd)
{
	m_matrix[0][0] = aa;
	m_matrix[0][1] = ab;
	m_matrix[0][2] = ac;
	m_matrix[0][3] = ad;
	m_matrix[1][0] = ba;
	m_matrix[1][1] = bb;
	m_matrix[1][2] = bc;
	m_matrix[1][3] = bd;
	m_matrix[2][0] = ca;
	m_matrix[2][1] = cb;
	m_matrix[2][2] = cc;
	m_matrix[2][3] = cd;
	m_matrix[3][0] = da;
	m_matrix[3][1] = db;
	m_matrix[3][2] = dc;
	m_matrix[3][3] = dd;
}

Matrix4::~Matrix4()
{
}

Matrix4 Matrix4::operator=(const Matrix4 & matA)
{
	m_matrix[0][0] = matA.m_matrix[0][0];
	m_matrix[0][1] = matA.m_matrix[0][1];
	m_matrix[0][2] = matA.m_matrix[0][2];
	m_matrix[0][3] = matA.m_matrix[0][3];
	m_matrix[1][0] = matA.m_matrix[1][0];
	m_matrix[1][1] = matA.m_matrix[1][1];
	m_matrix[1][2] = matA.m_matrix[1][2];
	m_matrix[1][3] = matA.m_matrix[1][3];
	m_matrix[2][0] = matA.m_matrix[2][0];
	m_matrix[2][1] = matA.m_matrix[2][1];
	m_matrix[2][2] = matA.m_matrix[2][2];
	m_matrix[2][3] = matA.m_matrix[2][3];
	m_matrix[3][0] = matA.m_matrix[3][0];
	m_matrix[3][1] = matA.m_matrix[3][1];
	m_matrix[3][2] = matA.m_matrix[3][2];
	m_matrix[3][3] = matA.m_matrix[3][3];
	return *this;
}

const bool Matrix4::operator==(const Matrix4 & matA)
{
	return ((m_matrix[0][0] == matA.m_matrix[0][0]) && (m_matrix[0][1] == matA.m_matrix[0][1]) && (m_matrix[0][2] == matA.m_matrix[0][2]) && (m_matrix[0][3] == matA.m_matrix[0][3]) && (m_matrix[1][0] == matA.m_matrix[1][0]) && (m_matrix[1][1] == matA.m_matrix[1][1]) && (m_matrix[1][2] == matA.m_matrix[1][2]) && (m_matrix[1][3] == matA.m_matrix[1][3]) && (m_matrix[2][0] == matA.m_matrix[2][0]) && (m_matrix[2][1] == matA.m_matrix[2][1]) && (m_matrix[2][2] == matA.m_matrix[2][2]) && (m_matrix[2][3] == matA.m_matrix[2][3]) && (m_matrix[3][0] == matA.m_matrix[3][0]) && (m_matrix[3][1] == matA.m_matrix[3][1]) && (m_matrix[3][2] == matA.m_matrix[3][2]) && (m_matrix[3][3] == matA.m_matrix[3][3]));
}

Matrix4 Matrix4::operator*(const Matrix4 & matA)
{
	Matrix4 result;
	unsigned int resultRows = 4, resultColumns = 4;
	for (unsigned int i = 0; i < resultColumns; i++) {
		for (unsigned int j = 0; j < resultRows; j++) {
			for (unsigned int k = 0; k < resultRows; k++) {
				result.m_matrix[i][j] += (m_matrix[k][j] * matA.m_matrix[i][k]);
			}
		}
	}
	return result;
}

Matrix4 Matrix4::operator+(const Matrix4 & matA)
{
	Matrix4 result;
	result.m_matrix[0][0] = m_matrix[0][0] + matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] + matA.m_matrix[0][1];
	result.m_matrix[0][2] = m_matrix[0][2] + matA.m_matrix[0][2];
	result.m_matrix[0][3] = m_matrix[0][3] + matA.m_matrix[0][3];
	result.m_matrix[1][0] = m_matrix[1][0] + matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] + matA.m_matrix[1][1];
	result.m_matrix[1][2] = m_matrix[1][2] + matA.m_matrix[1][2];
	result.m_matrix[1][3] = m_matrix[1][3] + matA.m_matrix[1][3];
	result.m_matrix[2][0] = m_matrix[2][0] + matA.m_matrix[2][0];
	result.m_matrix[2][1] = m_matrix[2][1] + matA.m_matrix[2][1];
	result.m_matrix[2][2] = m_matrix[2][2] + matA.m_matrix[2][2];
	result.m_matrix[2][3] = m_matrix[2][3] + matA.m_matrix[2][3];
	result.m_matrix[3][0] = m_matrix[3][0] + matA.m_matrix[3][0];
	result.m_matrix[3][1] = m_matrix[3][1] + matA.m_matrix[3][1];
	result.m_matrix[3][2] = m_matrix[3][2] + matA.m_matrix[3][2];
	result.m_matrix[3][3] = m_matrix[3][3] + matA.m_matrix[3][3];
	return result;
}

Matrix4 Matrix4::operator-(const Matrix4 & matA)
{
	Matrix4 result;
	result.m_matrix[0][0] = m_matrix[0][0] - matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] - matA.m_matrix[0][1];
	result.m_matrix[0][2] = m_matrix[0][2] - matA.m_matrix[0][2];
	result.m_matrix[0][3] = m_matrix[0][3] - matA.m_matrix[0][3];
	result.m_matrix[1][0] = m_matrix[1][0] - matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] - matA.m_matrix[1][1];
	result.m_matrix[1][2] = m_matrix[1][2] - matA.m_matrix[1][2];
	result.m_matrix[1][3] = m_matrix[1][3] - matA.m_matrix[1][3];
	result.m_matrix[2][0] = m_matrix[2][0] - matA.m_matrix[2][0];
	result.m_matrix[2][1] = m_matrix[2][1] - matA.m_matrix[2][1];
	result.m_matrix[2][2] = m_matrix[2][2] - matA.m_matrix[2][2];
	result.m_matrix[2][3] = m_matrix[2][3] - matA.m_matrix[2][3];
	result.m_matrix[3][0] = m_matrix[3][0] - matA.m_matrix[3][0];
	result.m_matrix[3][1] = m_matrix[3][1] - matA.m_matrix[3][1];
	result.m_matrix[3][2] = m_matrix[3][2] - matA.m_matrix[3][2];
	result.m_matrix[3][3] = m_matrix[3][3] - matA.m_matrix[3][3];
	return result;
}

Matrix4::operator float*()
{
	return (float*)this;
}

void Matrix4::setRotateX(float f)
{
	m_matrix[0][0] = 1;
	m_matrix[0][1] = 0;
	m_matrix[0][2] = 0;
	m_matrix[0][3] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = cosf(f);
	m_matrix[1][2] = sinf(f);
	m_matrix[1][3] = 0;
	m_matrix[2][0] = 0;
	m_matrix[2][1] = -(sinf(f));
	m_matrix[2][2] = cosf(f);
	m_matrix[2][3] = 0;
	m_matrix[3][0] = 0;
	m_matrix[3][1] = 0;
	m_matrix[3][2] = 0;
	m_matrix[3][3] = 1;
}

void Matrix4::setRotateY(float f)
{
	m_matrix[0][0] = cosf(f);
	m_matrix[0][1] = 0;
	m_matrix[0][2] = -(sinf(f));
	m_matrix[0][3] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 1;
	m_matrix[1][2] = 0;
	m_matrix[1][3] = 0;
	m_matrix[2][0] = sinf(f);
	m_matrix[2][1] = 0;
	m_matrix[2][2] = cosf(f);
	m_matrix[2][3] = 0;
	m_matrix[3][0] = 0;
	m_matrix[3][1] = 0;
	m_matrix[3][2] = 0;
	m_matrix[3][3] = 1;
}

void Matrix4::setRotateZ(float f)
{
	m_matrix[0][0] = cosf(f);
	m_matrix[0][1] = sinf(f);
	m_matrix[0][2] = 0;
	m_matrix[0][3] = 0;
	m_matrix[1][0] = -(sinf(f));
	m_matrix[1][1] = cosf(f);
	m_matrix[1][2] = 0;
	m_matrix[1][3] = 0;
	m_matrix[2][0] = 0;
	m_matrix[2][1] = 0;
	m_matrix[2][2] = 1;
	m_matrix[2][3] = 0;
	m_matrix[3][0] = 0;
	m_matrix[3][1] = 0;
	m_matrix[3][2] = 0;
	m_matrix[3][3] = 1;
}

