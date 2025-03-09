#include "Line.h"

Line::Line() = default;
Line::Line(float vx, float vy, float vz, float mx, float my, float mz) : direction(vx, vy, vz), moment(mx, my, mz) {}

Line::Line(Vector3D& v, Vector3D& m)
{
	direction = v;
	moment = m;
}

