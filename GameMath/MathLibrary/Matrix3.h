#pragma once
class Vector3;
class Matrix3
{
private:
public:
	float m_matrix[3][3];
	Matrix3();
	Matrix3(float aa, float ab, float ac, float ba, float bb, float bc, float ca, float cb, float cc);
	~Matrix3();
	Matrix3 operator=(const Matrix3& matA);
	const bool operator==(const Matrix3& matA);
	Matrix3 operator*(const Matrix3& matA);
	Matrix3 operator+(const Matrix3& matA);
	Matrix3 operator-(const Matrix3& matA);
	operator float*();
	void setRotateX(float f);
	void setRotateY(float f);
	void setRotateZ(float f);
	void setTranslate(float x, float y);
	static Matrix3 CreateIdentity();
	static Matrix3 CreateScale(float x, float y, float z);
	static Matrix3 CreateScale(Vector3 vec);
	static Matrix3 CreateRotationZ(float f);
	static Matrix3 CreateTranslation(float x, float y);
	static Matrix3 CreateBlank();
};

