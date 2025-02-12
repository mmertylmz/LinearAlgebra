#include "Matrix3D.h"

struct Quaternion
{
	float x, y, z, w;

	Quaternion();
	Quaternion(float a, float b, float c, float s);
	Quaternion(const Vector3D& v, float s);

	const Vector3D& GetVectorPart(void) const;

	//Matrix3D GetRotationMatrix(void);
	//void SetRotationMatrix(const Matrix3D& m);

};

Quaternion operator*(const Quaternion& q1, const Quaternion& q2);