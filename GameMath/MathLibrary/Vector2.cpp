#include "Vector2.h"
#include <math.h>


Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}


Vector2::~Vector2()
{
}

Vector2 Vector2::operator=(const Vector2 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	return *this;
}

const bool Vector2::operator==(const Vector2 & vecA)
{
	return ((m_x == vecA.m_x) && (m_y == vecA.m_y));
}

Vector2 Vector2::operator*(const float f)
{
	//Scalar Multiplication
	return Vector2((m_x * f), (m_y * f));
}

Vector2 Vector2::operator/(const float f)
{
	return Vector2((m_x / f), (m_y / f));
}

Vector2 Vector2::operator+(const Vector2 & rhs)
{
	return Vector2((m_x + rhs.m_x), (m_y + rhs.m_y));
}

Vector2 Vector2::operator-(const Vector2 & rhs)
{
	return Vector2((m_x - rhs.m_x), (m_y - rhs.m_y));
}

Vector2 Vector2::operator*(const Matrix2 & rhs)
{
	Vector2 result;
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

float Vector2::dot(const Vector2 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y));
}

float Vector2::magnitude()
{
	/*Either of these formulas should work?*/
	//return sqrt((m_x * m_x) + (m_y * m_y));
	return float(sqrt(dot(*this)));
}

void Vector2::normalise()
{
	if (magnitude() != 0) {
		*this = *this / magnitude();
	}
}

Vector2::operator float*()
{
	return (float*)this;
	//float temp = magnitude();
	//return &temp;
}

Vector2 operator*(const float& lhs, Vector2 & rhs)
{
	return Vector2((rhs.m_x * lhs), (rhs.m_y * lhs));
}

Vector2 operator*(const Matrix2 & lhs, const Vector2 & rhs)
{
	Vector2 result;
	float tempVecToMatrix[2] = {rhs.m_x, rhs.m_y};
	float tempVecResult[2] = {0, 0};
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
