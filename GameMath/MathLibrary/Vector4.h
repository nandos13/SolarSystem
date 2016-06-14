#pragma once
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
class Vector4
{
public:
	float m_x, m_y, m_z, m_w;

	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator=(const Vector4& vecA);
	const bool operator==(const Vector4& vecA);
	Vector4 operator*(const float f);
	Vector4 operator/(const float f);
	Vector4 operator+(const Vector4& rhs);
	Vector4 operator-(const Vector4& rhs);
	//ADD MATRIX FUNCTIONS HERE
	Vector4 operator*(const Matrix2& rhs);
	Vector4 operator*(const Matrix3& rhs);
	Vector4 operator*(const Matrix4& rhs);
	
	float dot(const Vector4& vecA);
	Vector4 cross(const Vector4& vecA);
	float magnitude();
	void normalise();
	operator float*();
};

Vector4 operator*(const float& lhs, Vector4& rhs);
Vector4 operator*(const Matrix2& lhs, const Vector4& rhs);
Vector4 operator*(const Matrix3& lhs, const Vector4& rhs);
Vector4 operator*(const Matrix4& lhs, const Vector4& rhs);