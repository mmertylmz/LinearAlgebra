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

Transform4D MakeReflection(const Plane& f)
{

	float x = f.x * -2.0F;
	float y = f.y * -2.0F;
	float z = f.z * -2.0F;
	float nxny = x * f.y;
	float nxnz = x * f.z;
	float nynz = y * f.z;

	return Transform4D(
		x * f.x + 1.0F, nxny, nxnz, x * f.w,
		nxny, y * f.y + 1.0F, nynz, y * f.w,
		nxnz, nynz, z * f.z + 1.0F, z * f.w
	);
}