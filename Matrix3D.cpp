#include "Matrix3D.h"
#include <stdexcept>

Matrix3D::Matrix3D() = default;
Matrix3D::Matrix3D(float n00, float n01, float n02,
	float n10, float n11, float n12,
	float n20, float n21, float n22)
{
	n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
	n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
	n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
}

Matrix3D::Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c) 
{
	n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
	n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
	n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
}

//Column major order
float& Matrix3D::operator()(int i, int j)
{
	return n[j][i];
}

//Column major order
const float& Matrix3D::operator()(int i, int j) const
{
	return n[j][i];
}

Vector3D& Matrix3D::operator[](int j)
{
	return *reinterpret_cast<Vector3D*>(n[j]);
}

const Vector3D& Matrix3D::operator[](int j) const
{
	return *reinterpret_cast<const Vector3D*>(n[j]);
}

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
	return (Matrix3D(
		A(0, 0) * B(0, 0) + A(1, 0) * B(0, 1) + A(2, 0) * B(0, 2),
		A(0, 0) * B(1, 0) + A(1, 0) * B(1, 1) + A(2, 0) * B(1, 2),
		A(0, 0) * B(2, 0) + A(1, 0) * B(2, 1) + A(2, 0) * B(2, 2),

		A(0, 1) * B(0, 0) + A(1, 1) * B(0, 1) + A(2, 1) * B(0, 2),
		A(0, 1) * B(1, 0) + A(1, 1) * B(1, 1) + A(2, 1) * B(1, 2),
		A(0, 1) * B(2, 0) + A(1, 1) * B(2, 1) + A(2, 1) * B(2, 2),

		A(0, 2) * B(0, 0) + A(1, 2) * B(0, 1) + A(2, 2) * B(0, 2),
		A(0, 2) * B(1, 0) + A(1, 2) * B(1, 1) + A(2, 2) * B(1, 2),
		A(0, 2) * B(2, 0) + A(1, 2) * B(2, 1) + A(2, 2) * B(2, 2)
	));
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v)
{
	return Vector3D(
		M(0, 0) * v.x + M(1, 0) * v.y + M(2, 0) * v.z,
		M(0, 1) * v.x + M(1, 1) * v.y + M(2, 1) * v.z,
		M(0, 2) * v.x + M(1, 2) * v.y + M(2, 2) * v.z
	);
}

float Determinant(const Matrix3D& M)
{
	return (M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1))
		+ M(0, 1) * (M(1, 2) * M(2, 0) - M(1, 0) * M(2, 2))
		+ M(0, 2) * (M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0)));
}

//Matrix3D Inverse(const Matrix3D& M)
//{
//	float det = Determinant(M);
//	if (det == 0.0f)
//	{
//		throw std::runtime_error("Matrix is singular and cannot be inverted.");
//	}
//	float invDet = 1 / det;
//	return Matrix3D(
//		invDet * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1)),
//		invDet * (M(0, 2) * M(2, 1) - M(0, 1) * M(2, 2)),
//		invDet * (M(0, 1) * M(1, 2) - M(0, 2) * M(1, 1)),
//
//		invDet * (M(1, 2) * M(2, 0) - M(1, 0) * M(2, 2)),
//		invDet * (M(0, 0) * M(2, 2) - M(0, 2) * M(2, 0)),
//		invDet * (M(0, 2) * M(1, 0) - M(0, 0) * M(1, 2)),
//
//		invDet * (M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0)),
//		invDet * (M(0, 1) * M(2, 0) - M(0, 0) * M(2, 1)),
//		invDet * (M(0, 0) * M(1, 1) - M(0, 1) * M(1, 0))
//	);
//}

Matrix3D Inverse(const Matrix3D& M)
{
	const Vector3D& a = M[0];
	const Vector3D& b = M[1];
	const Vector3D& c = M[2];

	Vector3D r0 = Cross(b, c);
	Vector3D r1 = Cross(c, a);
	Vector3D r2 = Cross(a, b);

	if(Dot(r2,c) == 0.0f)
	{
		throw std::runtime_error("Matrix is singular and cannot be inverted.");
	}

	float invDet = 1.0f / Dot(r2, c);

	return Matrix3D(
		r0.x * invDet, r0.y * invDet, r0.z * invDet,
		r1.x * invDet, r1.y * invDet, r1.z * invDet,
		r2.x * invDet, r2.y * invDet, r2.z * invDet
	);
}


//Print the matrix in row major order
void PrintMatrix3D(const Matrix3D& m, const std::string& title)
{
	std::cout << title << ":\n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "| ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout << m(j, i) << " ";
		}
		std::cout << "|\n";
	}
}
