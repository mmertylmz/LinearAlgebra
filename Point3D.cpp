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

float DistLineLine(const Point3D& p1, const Vector3D& v1, const Point3D& p2, const Vector3D& v2)
{
	Vector3D dp = p2 - p1;

	float v11 = Dot(v1, v1);
	float v22 = Dot(v2, v2);
	float v12 = Dot(v1, v2);

	float det = v12 * v12 - v11 * v22;

	if(fabs(det) > FLT_MIN)
	{
		det = 1.0F / det;

		float dpv1 = Dot(dp, v1);
		float dpv2 = Dot(dp, v2);
		float t1 = det * (v12 * dpv2 - v22 * dpv1);
		float t2 = det * (v11 * dpv2 - v12 * dpv1);

		return Magnitude(dp + v2 * t2 - v1 * t1);
	}

	//The lines are parallel
	Vector3D a = Cross(dp, v1);
	return sqrt(Dot(a, a) / v11);
}