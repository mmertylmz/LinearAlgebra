#include "Matrix4D.h"
#include <stdexcept>

Matrix4D::Matrix4D() = default;

Matrix4D::Matrix4D(float n00, float n01, float n02, float n03,
    float n10, float n11, float n12, float n13,
    float n20, float n21, float n22, float n23,
    float n30, float n31, float n32, float n33)
{
    n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
    n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
    n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
    n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
}

Matrix4D::Matrix4D(const Vector4D& a, const Vector4D& b,
    const Vector4D& c, const Vector4D& d)
{
    n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
    n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
    n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
    n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
}

float& Matrix4D::operator()(int i, int j)
{
    if (i < 0 || i > 3 || j < 0 || j > 3) {
        throw std::out_of_range("Matrix index out of range");
    }
    return n[j][i];
}

const float& Matrix4D::operator()(int i, int j) const
{
    if (i < 0 || i > 3 || j < 0 || j > 3) {
        throw std::out_of_range("Matrix index out of range");
    }
    return n[j][i];
}

Vector4D& Matrix4D::operator[](int j)
{
    if (j < 0 || j > 3) {
        throw std::out_of_range("Matrix column index out of range");
    }
    return *reinterpret_cast<Vector4D*>(n[j]);
}

const Vector4D& Matrix4D::operator[](int j) const
{
    if (j < 0 || j > 3) {
        throw std::out_of_range("Matrix column index out of range");
    }
    return *reinterpret_cast<const Vector4D*>(n[j]);
}

Matrix4D operator*(const Matrix4D& A, const Matrix4D& B)
{
    return Matrix4D(
		// First column
        A(0, 0) * B(0, 0) + A(1, 0) * B(0, 1) + A(2, 0) * B(0, 2) + A(3, 0) * B(0, 3),
        A(0, 0) * B(1, 0) + A(1, 0) * B(1, 1) + A(2, 0) * B(1, 2) + A(3, 0) * B(1, 3),
        A(0, 0) * B(2, 0) + A(1, 0) * B(2, 1) + A(2, 0) * B(2, 2) + A(3, 0) * B(2, 3),
        A(0, 0) * B(3, 0) + A(1, 0) * B(3, 1) + A(2, 0) * B(3, 2) + A(3, 0) * B(3, 3),

		// Second column
        A(0, 1) * B(0, 0) + A(1, 1) * B(0, 1) + A(2, 1) * B(0, 2) + A(3, 1) * B(0, 3),
        A(0, 1) * B(1, 0) + A(1, 1) * B(1, 1) + A(2, 1) * B(1, 2) + A(3, 1) * B(1, 3),
        A(0, 1) * B(2, 0) + A(1, 1) * B(2, 1) + A(2, 1) * B(2, 2) + A(3, 1) * B(2, 3),
        A(0, 1) * B(3, 0) + A(1, 1) * B(3, 1) + A(2, 1) * B(3, 2) + A(3, 1) * B(3, 3),

		// Third column
        A(0, 2) * B(0, 0) + A(1, 2) * B(0, 1) + A(2, 2) * B(0, 2) + A(3, 2) * B(0, 3),
        A(0, 2) * B(1, 0) + A(1, 2) * B(1, 1) + A(2, 2) * B(1, 2) + A(3, 2) * B(1, 3),
        A(0, 2) * B(2, 0) + A(1, 2) * B(2, 1) + A(2, 2) * B(2, 2) + A(3, 2) * B(2, 3),
        A(0, 2) * B(3, 0) + A(1, 2) * B(3, 1) + A(2, 2) * B(3, 2) + A(3, 2) * B(3, 3),

        // Fourth Column
        A(0, 3) * B(0, 0) + A(1, 3) * B(0, 1) + A(2, 3) * B(0, 2) + A(3, 3) * B(0, 3),
        A(0, 3) * B(1, 0) + A(1, 3) * B(1, 1) + A(2, 3) * B(1, 2) + A(3, 3) * B(1, 3),
        A(0, 3) * B(2, 0) + A(1, 3) * B(2, 1) + A(2, 3) * B(2, 2) + A(3, 3) * B(2, 3),
        A(0, 3) * B(3, 0) + A(1, 3) * B(3, 1) + A(2, 3) * B(3, 2) + A(3, 3) * B(3, 3)
    );
}


Vector4D operator*(const Matrix4D& M, const Vector4D& v)
{
    return Vector4D(
        M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z + M(0, 3) * v.w,
        M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z + M(1, 3) * v.w,
        M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z + M(2, 3) * v.w,
        M(3, 0) * v.x + M(3, 1) * v.y + M(3, 2) * v.z + M(3, 3) * v.w
    );
}