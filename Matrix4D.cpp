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

float Determinant3x3(float a11, float a12, float a13,
    float a21, float a22, float a23,
    float a31, float a32, float a33)
{
    return a11 * (a22 * a33 - a23 * a32) -
        a12 * (a21 * a33 - a23 * a31) +
        a13 * (a21 * a32 - a22 * a31);
}

float Determinant(const Matrix4D& M)
{
    float det = M(0, 0) * Determinant3x3(M(1, 1), M(1, 2), M(1, 3),
        M(2, 1), M(2, 2), M(2, 3),
        M(3, 1), M(3, 2), M(3, 3)) -
        M(0, 1) * Determinant3x3(M(1, 0), M(1, 2), M(1, 3),
            M(2, 0), M(2, 2), M(2, 3),
            M(3, 0), M(3, 2), M(3, 3)) +
        M(0, 2) * Determinant3x3(M(1, 0), M(1, 1), M(1, 3),
            M(2, 0), M(2, 1), M(2, 3),
            M(3, 0), M(3, 1), M(3, 3)) -
        M(0, 3) * Determinant3x3(M(1, 0), M(1, 1), M(1, 2),
            M(2, 0), M(2, 1), M(2, 2),
            M(3, 0), M(3, 1), M(3, 2));
    return det;
}

Matrix4D Inverse(const Matrix4D& M)
{
    float det = Determinant(M);
    if (std::abs(det) < 1e-6f) {
        throw std::runtime_error("Matrix is not invertible");
    }

    Matrix4D result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float sign = ((i + j) % 2 == 0) ? 1.0f : -1.0f;

            float minor[9];
            int idx = 0;
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    if (r != i && c != j) {
                        minor[idx++] = M(r, c);
                    }
                }
            }

            result(j, i) = sign * Determinant3x3(minor[0], minor[1], minor[2],
                minor[3], minor[4], minor[5],
                minor[6], minor[7], minor[8]) / det;
        }
    }

    return result;
}

Matrix4D MakeTranslation4D(const Vector4D& v)
{
    return Matrix4D(
        1.0f, 0.0f, 0.0f, v.x,
        0.0f, 1.0f, 0.0f, v.y,
        0.0f, 0.0f, 1.0f, v.z,
        0.0f, 0.0f, 0.0f, 1.0f
    );
}

Matrix4D MakeScale4D(float s)
{
    return Matrix4D(
        s, 0.0f, 0.0f, 0.0f,
        0.0f, s, 0.0f, 0.0f,
        0.0f, 0.0f, s, 0.0f,
        0.0f, 0.0f, 0.0f, s
    );
}

Matrix4D MakeScale4D(float sx, float sy, float sz, float sw)
{
    return Matrix4D(
        sx, 0.0f, 0.0f, 0.0f,
        0.0f, sy, 0.0f, 0.0f,
        0.0f, 0.0f, sz, 0.0f,
        0.0f, 0.0f, 0.0f, sw
    );
}

Matrix4D MakeRotation4D(float t, int plane)
{
    float c = std::cos(t);
    float s = std::sin(t);

    Matrix4D result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = (i == j) ? 1.0f : 0.0f;
        }
    }

    switch (plane) {
    case 0:
        result(0, 0) = c; result(0, 1) = -s;
        result(1, 0) = s; result(1, 1) = c;
        break;
    case 1:
        result(0, 0) = c; result(0, 2) = -s;
        result(2, 0) = s; result(2, 2) = c;
        break;
    case 2:
        result(1, 1) = c; result(1, 2) = -s;
        result(2, 1) = s; result(2, 2) = c;
        break;
    case 3:
        result(0, 0) = c; result(0, 3) = -s;
        result(3, 0) = s; result(3, 3) = c;
        break;
    case 4:
        result(1, 1) = c; result(1, 3) = -s;
        result(3, 1) = s; result(3, 3) = c;
        break;
    case 5:
        result(2, 2) = c; result(2, 3) = -s;
        result(3, 2) = s; result(3, 3) = c;
        break;
    default:
        throw std::invalid_argument("Invalid rotation plane");
    }

    return result;
}