#include "Vector4D.h"

Vector4D::Vector4D() = default;
Vector4D::Vector4D(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}

float& Vector4D::operator[](int i)
{
    return ((&x)[i]);
}

const float& Vector4D::operator[](int i) const
{
    return ((&x)[i]);
}

Vector4D& Vector4D::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

Vector4D& Vector4D::operator/=(float s)
{
    x /= s;
    y /= s;
    z /= s;
    w /= s;
    return *this;
}

Vector4D& Vector4D::operator+=(const Vector4D& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4D& Vector4D::operator-=(const Vector4D& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vector4D operator*(const Vector4D& v, float s)
{
    return Vector4D(v.x * s, v.y * s, v.z * s, v.w * s);
}

Vector4D operator/(const Vector4D& v, float s)
{
    return Vector4D(v.x / s, v.y / s, v.z / s, v.w / s);
}

Vector4D operator+(const Vector4D& a, const Vector4D& b)
{
    return Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector4D operator-(const Vector4D& a, const Vector4D& b)
{
    return Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}