#include "Vector4.h"
#include <math.h>


Vector4::Vector4()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}


Vector4::~Vector4()
{
}

Vector4 Vector4::operator=(const Vector4 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	m_z = vecA.m_z;
	m_w = vecA.m_w;
	return *this;
}

const bool Vector4::operator==(const Vector4 & vecA)
{
	return ((m_x == vecA.m_x) && (m_y == vecA.m_y) && (m_z == vecA.m_z) && (m_w == vecA.m_w));
}

Vector4 Vector4::operator*(const float f)
{
	//Scalar Multiplication
	return Vector4((m_x * f), (m_y * f), (m_z * f), (m_w * f));
}

Vector4 Vector4::operator/(const float f)
{
	return Vector4((m_x / f), (m_y / f), (m_z / f), (m_w / f));
}

Vector4 Vector4::operator+(const Vector4 & rhs)
{
	return Vector4((m_x + rhs.m_x), (m_y + rhs.m_y), (m_z + rhs.m_z), (m_w + rhs.m_w));
}

Vector4 Vector4::operator-(const Vector4 & rhs)
{
	return Vector4((m_x - rhs.m_x), (m_y - rhs.m_y), (m_z - rhs.m_z), (m_w - rhs.m_w));
}

Vector4 Vector4::operator*(const Matrix2 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[2] = { m_x, m_y };
	float tempVecResult[2] = { 0, 0 };
	unsigned int vecRows = 2, vecColumns = 2;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (rhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	return result;
}

Vector4 Vector4::operator*(const Matrix3 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[3] = { m_x, m_y, m_z };
	float tempVecResult[3] = { 0, 0, 0 };
	unsigned int vecRows = 3, vecColumns = 3;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (rhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	result.m_z = tempVecResult[2];
	return result;
}

Vector4 Vector4::operator*(const Matrix4 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[4] = { m_x, m_y, m_z, m_w };
	float tempVecResult[4] = { 0, 0, 0, 0 };
	unsigned int vecRows = 4, vecColumns = 4;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (rhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	result.m_z = tempVecResult[2];
	result.m_w = tempVecResult[3];
	return result;
}

float Vector4::dot(const Vector4 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y) + (m_z * vecA.m_z) + (m_w * vecA.m_w));
}

Vector4 Vector4::cross(const Vector4 & vecA)
{
	return Vector4((m_y * vecA.m_z) - (m_z * vecA.m_y), (m_z * vecA.m_x) - (m_x * vecA.m_z), (m_x * vecA.m_y) - (m_y * vecA.m_x), 0);
}

float Vector4::magnitude()
{
	/*Either of these formulas should work?*/
	//return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
	return float(sqrt(dot(*this)));
}

void Vector4::normalise()
{
	if (magnitude() != 0) {
		*this = *this / magnitude();
	}
}

Vector4::operator float*()
{
	return (float*)this;
	//float temp = magnitude();
	//return &temp;
}

Vector4 operator*(const float& lhs, Vector4 & rhs)
{
	return Vector4((rhs.m_x * lhs), (rhs.m_y * lhs), (rhs.m_z * lhs), (rhs.m_w * lhs));
}

Vector4 operator*(const Matrix2 & lhs, const Vector4 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[2] = { rhs.m_x, rhs.m_y };
	float tempVecResult[2] = { 0, 0 };
	unsigned int vecRows = 2, vecColumns = 2;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (lhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	return result;
}

Vector4 operator*(const Matrix3 & lhs, const Vector4 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[3] = { rhs.m_x, rhs.m_y, rhs.m_z };
	float tempVecResult[3] = { 0, 0, 0 };
	unsigned int vecRows = 3, vecColumns = 3;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (lhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	result.m_z = tempVecResult[2];
	return result;
}

Vector4 operator*(const Matrix4 & lhs, const Vector4 & rhs)
{
	Vector4 result;
	float tempVecToMatrix[4] = { rhs.m_x, rhs.m_y, rhs.m_z, rhs.m_w };
	float tempVecResult[4] = { 0, 0, 0, 0 };
	unsigned int vecRows = 4, vecColumns = 4;
	for (unsigned int i = 0; i < vecColumns; i++) {
		for (unsigned int j = 0; j < vecRows; j++) {
			tempVecResult[j] += (lhs.m_matrix[i][j] * tempVecToMatrix[i]);
		}
	}
	result.m_x = tempVecResult[0];
	result.m_y = tempVecResult[1];
	result.m_z = tempVecResult[2];
	result.m_w = tempVecResult[3];
	return result;
}
