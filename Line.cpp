#include "Line.h"

Line::Line() = default;
Line::Line(float vx, float vy, float vz, float mx, float my, float mz) : direction(vx, vy, vz), moment(mx, my, mz) {}

Line::Line(Vector3D& v, Vector3D& m)
{
	direction = v;
	moment = m;
}

Line Transform(const Line& line, const Transform4D& H)
{
	Matrix3D adj(Cross(H[1], H[2]), Cross(H[2], H[0]), Cross(H[0], H[1]));
	const Point3D& t = H.GetTranslation();

	Vector3D v = H * line.direction;
	Vector3D m = adj * line.moment + Cross(t, v);

	return Line(v, m);
}

