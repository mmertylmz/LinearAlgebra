#pragma once

#include "Point3D.h"
#include "Vector3D.h"

struct Plane 
{
	float x, y, z, w;
	Plane();
	Plane(float nx, float ny, float nz, float d);

	Plane(const Vector3D& n, float d);
	const Vector3D& Normal() const;
};

float Dot(const Plane& f, const Point3D& p);
float Dot(const Plane& f, const Vector3D& v);