#pragma once
#include "Matrix2.h"
class Vector2
{
public:
	float m_x, m_y;

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator=(const Vector2& vecA);
	const bool operator==(const Vector2& vecA);
	Vector2 operator*(const float f);
	Vector2 operator/(const float f);
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	//ADD MATRIX FUNCTIONS HERE
	Vector2 operator*(const Matrix2& rhs);
	
	float dot(const Vector2& vecA);
	float magnitude();
	void normalise();
	operator float*();
};

Vector2 operator*(const float& lhs, Vector2& rhs);
Vector2 operator*(const Matrix2& lhs, const Vector2& rhs);