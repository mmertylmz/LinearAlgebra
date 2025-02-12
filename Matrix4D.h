#include "Vector4D.h"

struct Matrix4D
{
private:
    float n[4][4];
public:
    Matrix4D();
    Matrix4D(float n00, float n01, float n02, float n03,
        float n10, float n11, float n12, float n13,
        float n20, float n21, float n22, float n23,
        float n30, float n31, float n32, float n33);

    Matrix4D(const Vector4D& a, const Vector4D& b,
        const Vector4D& c, const Vector4D& d);

    float& operator ()(int i, int j);
    const float& operator ()(int i, int j) const;

    Vector4D& operator [](int j);
    const Vector4D& operator [](int j) const;
};

Matrix4D operator *(const Matrix4D& A, const Matrix4D& B);
Vector4D operator *(const Matrix4D& M, const Vector4D& v);

float Determinant(const Matrix4D& M);
Matrix4D Inverse(const Matrix4D& M);

Matrix4D MakeRotation4D(float t, int plane);
Matrix4D MakeTranslation4D(const Vector4D& v);
Matrix4D MakeScale4D(float s);
Matrix4D MakeScale4D(float sx, float sy, float sz, float sw);

void PrintMatrix4D(const Matrix4D& m, const std::string& title);