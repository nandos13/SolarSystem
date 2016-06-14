#include "Matrix2.h"
#include <math.h>



Matrix2::Matrix2()
{
	m_matrix[0][0] = 0;
	m_matrix[0][1] = 0;
	m_matrix[1][0] = 0;
	m_matrix[1][1] = 0;
}

Matrix2::Matrix2(float aa, float ab, float ba, float bb)
{
	m_matrix[0][0] = aa;
	m_matrix[0][1] = ab;
	m_matrix[1][0] = ba;
	m_matrix[1][1] = bb;
}

Matrix2::~Matrix2()
{
}

Matrix2 Matrix2::operator=(const Matrix2 & matA)
{
	m_matrix[0][0] = matA.m_matrix[0][0];
	m_matrix[0][1] = matA.m_matrix[0][1];
	m_matrix[1][0] = matA.m_matrix[1][0];
	m_matrix[1][1] = matA.m_matrix[1][1];
	return *this;
}

const bool Matrix2::operator==(const Matrix2 & matA)
{
	return ((m_matrix[0][0] == matA.m_matrix[0][0]) && (m_matrix[0][1] == matA.m_matrix[0][1]) && (m_matrix[1][0] == matA.m_matrix[1][0]) && (m_matrix[1][1] == matA.m_matrix[1][1]));
}

Matrix2 Matrix2::operator*(const Matrix2 & matA)
{
	Matrix2 result;
	unsigned int resultRows = 2, resultColumns = 2;
	for (unsigned int i = 0; i < resultColumns; i++) {
		for (unsigned int j = 0; j < resultRows; j++) {
			for (unsigned int k = 0; k < resultRows; k++) {
				result.m_matrix[i][j] += (m_matrix[k][j] * matA.m_matrix[i][k]);
			}
		}
	}
	return result;
}

Matrix2 Matrix2::operator+(const Matrix2 & matA)
{
	Matrix2 result;
	result.m_matrix[0][0] = m_matrix[0][0] + matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] + matA.m_matrix[0][1];
	result.m_matrix[1][0] = m_matrix[1][0] + matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] + matA.m_matrix[1][1];
	return result;
}

Matrix2 Matrix2::operator-(const Matrix2 & matA)
{
	Matrix2 result;
	result.m_matrix[0][0] = m_matrix[0][0] - matA.m_matrix[0][0];
	result.m_matrix[0][1] = m_matrix[0][1] - matA.m_matrix[0][1];
	result.m_matrix[1][0] = m_matrix[1][0] - matA.m_matrix[1][0];
	result.m_matrix[1][1] = m_matrix[1][1] - matA.m_matrix[1][1];
	return result;
}

Matrix2::operator float*()
{
	return (float*)this;
}

void Matrix2::setRotateZ(const float f)
{
	m_matrix[0][0] = cosf(f);
	m_matrix[0][1] = sinf(f);
	m_matrix[1][0] = -(sinf(f));
	m_matrix[1][1] = cosf(f);
}
