#include "Point3D.h"

Point3D operator +(const Point3D& a, const Vector3D& b)
{
	return Point3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point3D operator -(const Point3D& a, const Vector3D& b)
{
	return Point3D(a.x - b.x, a.y - b.y, a.z - b.z);
}

float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v)
{
	Vector3D a = Cross(q - p, v);
	return sqrt(Dot(a, a) / Dot(v, v));
}