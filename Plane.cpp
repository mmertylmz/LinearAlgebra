#include "Plane.h"

Plane::Plane() = default;
Plane::Plane(float nx, float ny, float nz, float d)
{
	x = nx;
	y = ny;
	z = nz;
	w = d;
}

Plane::Plane(const Vector3D& n, float d)
{
	x = n.x;
	y = n.y;
	z = n.z;
	w = d;
}

const Vector3D& Plane::Normal() const
{
	return reinterpret_cast<const Vector3D&>(*this);
}

float Dot(const Plane& f, const Point3D& p)
{
	return f.x * p.x + f.y * p.y + f.z * p.z + f.w;
}

float Dot(const Plane& f, const Vector3D& v)
{
	return f.x * v.x + f.y * v.y + f.z * v.z;
}