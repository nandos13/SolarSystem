#pragma once
class Matrix2
{
private:
public:
	float m_matrix[2][2];
	Matrix2();
	Matrix2(float aa, float ab, float ba, float bb);
	~Matrix2();
	Matrix2 operator=(const Matrix2& matA);
	const bool operator==(const Matrix2& matA);
	Matrix2 operator*(const Matrix2& matA);
	Matrix2 operator+(const Matrix2& matA);
	Matrix2 operator-(const Matrix2& matA);
	operator float*();
	void setRotateZ(const float f);
};

