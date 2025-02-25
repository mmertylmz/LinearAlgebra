#include "Vector3D.h"

struct Point3D : Vector3D
{
	Point3D() = default;
	Point3D(float a, float b, float c) : Vector3D(a, b, c) {}
};

Point3D operator +(const Point3D& a, const Vector3D& b);
Point3D operator -(const Point3D& a, const Vector3D& b);

float DistPointLine(const Point3D& p, const Point3D& q, const Vector3D& v);
float DistLineLine(const Point3D& p, const Vector3D& u, const Point3D& q, const Vector3D& v);
