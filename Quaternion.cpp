#include "Quaternion.h"

Quaternion::Quaternion() = default;
Quaternion::Quaternion(float a, float b, float c, float s) : x(a), y(b), z(c), w(s) {}
Quaternion::Quaternion(const Vector3D& v, float s) : x(v.x), y(v.y), z(v.z), w(s) {}

const Vector3D& Quaternion::GetVectorPart(void) const 
{
	return reinterpret_cast<const Vector3D&>(x);
}

Matrix3D Quaternion::GetRotationMatrix(void)
{
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;
	float xy = x * y;
	float xz = x * z;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	return Matrix3D(
		1.0F - 2.0F * (y2 + z2), 2.0F * (xy - wz), 2.0F * (xz + wy),
		2.0F * (xy + wz), 1.0F - 2.0F * (x2 + z2), 2.0F * (yz - wx),
		2.0F * (xz - wy), 2.0F * (yz + wx), 1.0F - 2.0F * (x2 + y2)
	);	
}


//TODO: SetRotationMatrix

Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z
	);
}
