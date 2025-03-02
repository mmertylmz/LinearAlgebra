#pragma once

#include "Matrix4D.h"
#include "Point3D.h"

struct Transform4D : Matrix4D 
{
	Transform4D();
	Transform4D(
		float n00, float n01, float n02, float n03,
		float n10, float n11, float n12, float n13,
		float n20, float n21, float n22, float n23);

	Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);

	Vector3D& operator [](int j);
	const Vector3D& operator [](int j) const;

	const Point3D& GetTranslation(void) const;
	void SetTranslation(const Point3D& p);
};

Transform4D Inverse(const Transform4D& H);

Transform4D operator *(const Transform4D& A, const Transform4D& B);
Vector3D operator *(const Transform4D& A, const Vector3D& V);
Point3D operator *(const Transform4D& A, const Point3D& P);
Vector3D operator *(const Vector3D& n, const Transform4D& H);

