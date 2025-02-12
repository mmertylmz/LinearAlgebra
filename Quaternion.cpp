#include "Quaternion.h"

Quaternion::Quaternion() = default;
Quaternion::Quaternion(float a, float b, float c, float s) : x(a), y(b), z(c), w(s) {}
Quaternion::Quaternion(const Vector3D& v, float s) : x(v.x), y(v.y), z(v.z), w(s) {}

const Vector3D& Quaternion::GetVectorPart(void) const 
{
	return reinterpret_cast<const Vector3D&>(x);
}

//TODO: GetRotationMatrix, SetRotationMatrix

Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z
	);
}
