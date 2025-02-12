#pragma once

#include <iostream>
#include <cmath>

struct Vector4D
{
    float x, y, z, w;

    Vector4D();
    Vector4D(float a, float b, float c, float d);

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector4D& operator +=(const Vector4D& v);
    Vector4D& operator -=(const Vector4D& v);
    Vector4D& operator *=(float s);
    Vector4D& operator /=(float s);
};

Vector4D operator +(const Vector4D& a, const Vector4D& b);
Vector4D operator -(const Vector4D& a, const Vector4D& b);
Vector4D operator *(const Vector4D& v, float s);
Vector4D operator /(const Vector4D& v, float s);

float Magnitude(const Vector4D& v);
Vector4D Normalize(const Vector4D& v);
float Dot(const Vector4D& a, const Vector4D& b);

//There are no Cross Products in 4D space

Vector4D Project(const Vector4D& a, const Vector4D& b);
Vector4D Reject(const Vector4D& a, const Vector4D& b);

void PrintVector4D(const Vector4D& v);