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

bool IntersectLinePlane(const Point3D& p, const Vector3D& v, const Plane& f, Point3D q)
{
	// Calculate the dot product of the plane normal and line direction vector
	// This tells us if the line and plane are parallel or not
	float fv = Dot(f, v);

	// If the dot product is not close to zero, the line and plane are not parallel
	// and must intersect at exactly one point
	if (fabs(fv) > FLT_MIN)
	{
		// This formula computes the parameter 't' where the line intersects the plane
		// and then substitutes it back into the line equation
		q = p - v * (Dot(f, p) / fv);

		// Intersection found
		return true;
	}

	// The line and plane are parallel (no intersection)
	return false;
}

bool IntersectThreePlanes(const Plane& f1, const Plane& f2, const Plane& f3, Point3D& p)
{
	const Vector3D& n1 = f1.Normal();
	const Vector3D& n2 = f2.Normal();
	const Vector3D& n3 = f3.Normal();

	Vector3D n1xn2 = Cross(n1, n2);

	float det = Dot(n1xn2, n3);
	if (fabs(det) > FLT_MIN)
	{
		Vector3D n2xn3 = Cross(n2, n3);
		Vector3D n3xn1 = Cross(n3, n1);

		// Compute the intersection point
		Vector3D result = (n2xn3 * (-f1.w) + n3xn1 * (-f2.w) + n1xn2 * (-f3.w)) / det;

		// Store the result in the output parameter
		p = Point3D(result.x, result.y, result.z);
		return true;
	}

	return false;
}