#pragma once
#include "Vector3D.h"

struct Line 
{	
	Vector3D direction;
	Vector3D moment;

	Line();
	Line(float vx, float vy, float vz, float mx, float my, float mz);
	Line(Vector3D& v, Vector3D& m);

};