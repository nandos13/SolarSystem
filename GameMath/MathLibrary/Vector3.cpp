#include "Vector3.h"
#include <math.h>
#include "Matrix2.h"
#include "Matrix3.h"
#include "Vector2.h"


Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator=(const Vector3 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	m_z = vecA.m_z;
	return *this;
}

const bool Vector3::operator==(const Vector3 & vecA)
{
	return ((m_x == vecA.m_x) && (m_y == vecA.m_y) && (m_z == vecA.m_z));
}

Vector3 Vector3::operator*(const float f)
{
	//Scalar Multiplication
	return Vector3((m_x * f), (m_y * f), (m_z * f));
}

Vector3 Vector3::operator/(const float f)
{
	return Vector3((m_x / f), (m_y / f), (m_z / f));
}

Vector3 Vector3::operator+(const Vector3 & rhs)
{
	return Vector3((m_x + rhs.m_x), (m_y + rhs.m_y), (m_z + rhs.m_z));
}

Vector3 Vector3::operator-(const Vector3 & rhs)
{
	return Vector3((m_x - rhs.m_x), (m_y - rhs.m_y), (m_z - rhs.m_z));
}

Vector3 Vector3::operator*(const Matrix2 & rhs)
{
	Vector3 result;
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

Vector3 Vector3::operator*(const Matrix3 & rhs)
{
	Vector3 result;
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

float Vector3::dot(const Vector3 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y) + (m_z * vecA.m_z));
}

Vector3 Vector3::cross(const Vector3 & vecA)
{
	return Vector3((m_y * vecA.m_z) - (m_z * vecA.m_y), (m_z * vecA.m_x) - (m_x * vecA.m_z), (m_x * vecA.m_y) - (m_y * vecA.m_x));
}

float Vector3::magnitude()
{
	/*Either of these formulas should work?*/
	//return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
	return float(sqrt(dot(*this)));
}

void Vector3::normalise()
{
	if (magnitude() != 0) {
		*this = *this / magnitude();
	}
}

Vector3::operator float*()
{
	return (float*)this;
}

float Vector3::length()
{
	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

float Vector3::distance(const Vector3 & vecA)
{
	return sqrt(pow((vecA.m_x - m_x), 2) + pow((vecA.m_y - m_y), 2) + pow((vecA.m_z - m_z), 2));
}

float Vector3::distance(const Vector2 & vecA)
{
	return sqrt(pow((vecA.m_x - m_x), 2) + pow((vecA.m_y - m_y), 2) + pow((0 - m_z), 2));
}

Vector3 operator*(const float& lhs, Vector3 & rhs)
{
	return Vector3((rhs.m_x * lhs), (rhs.m_y * lhs), (rhs.m_z * lhs));
}

Vector3 operator*(const Matrix2 & lhs, const Vector3 & rhs)
{
	Vector3 result;
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

Vector3 operator*(const Matrix3 & lhs, const Vector3 & rhs)
{
	Vector3 result;
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
