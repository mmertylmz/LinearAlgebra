#pragma once

#include "Point3D.h"
#include "Vector3D.h"
#include "Transform4D.h"

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

Transform4D MakeReflection(const Plane& f);
bool IntersectLinePlane(const Point3D& p, const Vector3D& v, const Plane& f, Point3D q);
bool IntersectThreePlanes(const Plane& f1, const Plane& f2, const Plane& f3, Point3D& p);
bool IntersectTwoPlanes(const Plane& f1, const Plane& f2, Point3D *p, Vector3D *v);