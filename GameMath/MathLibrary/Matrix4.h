#pragma once
class Matrix4
{
private:
public:
	float m_matrix[4][4];
	Matrix4();
	Matrix4(float aa, float ab, float ac, float ad, float ba, float bb, float bc, float bd, float ca, float cb, float cc, float cd, float da, float db, float dc, float dd);
	~Matrix4();
	Matrix4 operator=(const Matrix4& matA);
	const bool operator==(const Matrix4& matA);
	Matrix4 operator*(const Matrix4& matA);
	Matrix4 operator+(const Matrix4& matA);
	Matrix4 operator-(const Matrix4& matA);
	operator float*();
	void setRotateX(float f);
	void setRotateY(float f);
	void setRotateZ(float f);
};

