#pragma once

#include "Vector3D.h"

struct Matrix3D 
{
private:
	float n[3][3];
public:
	Matrix3D();
	Matrix3D(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22);
	Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

	float& operator ()(int i, int j);
	const float& operator ()(int i, int j) const;

	Vector3D& operator [](int j);
	const Vector3D& operator [](int j) const;

};

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B);
Vector3D operator *(const Matrix3D& M, const Vector3D& v);

float Determinant(const Matrix3D& M);

Matrix3D Transpose(const Matrix3D& m);
Matrix3D Inverse(const Matrix3D& M);
Matrix3D MakeRotation(float t, const Vector3D& a);
Matrix3D MakeReflection(const Vector3D& a);
Matrix3D MakeInvolution(const Vector3D& a);
Matrix3D MakeScale(float s, const Vector3D& a);
Matrix3D MakeSkew(float t, const Vector3D& a, const Vector3D& b);



void PrintMatrix3D(const Matrix3D& m, const std::string& title);