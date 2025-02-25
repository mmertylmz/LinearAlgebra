#include "Matrix3D.h"
#include "Transform4D.h"
#define M_PI   3.14159265358979323846264338327950288

void TestVectorOperations() {
	// Vector addition test
	Vector3D v(1.0f, 2.0f, 3.0f);
	PrintVector3D(v);

	Vector3D w(4.0f, 5.0f, 6.0f);
	Vector3D result = v + w;

	PrintVector3D(result);
}

void TestBasicMatrixOperations() {
	// Basic matrix creation and access
	Matrix3D m1(2.0f, 3.0f, 1.0f,
		-1.0f, 0.0f, 4.0f,
		5.0f, -2.0f, 6.0f);

	PrintMatrix3D(m1, "Matrix m1");

	// Testing matrix element access
	float value = m1(1, 0);
	std::cout << "Value at (1,0): " << value << std::endl;

	m1(1, 0) = 10.0f;
	PrintMatrix3D(m1, "Matrix m1 after modifying (1,0)");

	m1[1].x = 20.0f;
	PrintMatrix3D(m1, "Matrix m1 after modifying [1].x");

	// Matrix creation from vectors
	Vector3D a(1.0f, 2.0f, 3.0f);
	Vector3D b(4.0f, 5.0f, 6.0f);
	Vector3D c(7.0f, 8.0f, 9.0f);
	Matrix3D m2(a, b, c);

	PrintMatrix3D(m2, "Matrix m2");
}

void TestMatrixInverse() {
    Matrix3D m1(2.0f, 3.0f, 1.0f,
        -1.0f, 0.0f, 4.0f,
        5.0f, -2.0f, 6.0f);

    std::cout << "Determinant of m1: " << Determinant(m1) << std::endl;

    Matrix3D InversedMatrix = Inverse(m1);
    PrintMatrix3D(InversedMatrix, "Inversed Matrix m1");
    PrintMatrix3D(m1 * InversedMatrix, "m1 * Inversed Matrix m1");
}

void TestRotationMatrix() {
    Vector3D rotationAxis(1.0f, 0.0f, 0.0f);

    // 45 degree rotation
    float angle = M_PI / 4.0f;
    Matrix3D rotationMatrix = MakeRotation(angle, rotationAxis);
    PrintMatrix3D(rotationMatrix, "Rotation Matrix (45° around X-axis)");

    // 90 degree rotation
    float angle_90 = M_PI / 2.0f;
    Matrix3D rotationMatrix2 = MakeRotation(angle_90, rotationAxis);
    PrintMatrix3D(rotationMatrix2, "Rotation Matrix (90° around X-axis)");
}

void TestReflectionAndInvolution() {
    // Reflection Matrix Test
    Vector3D reflectionAxis(1.0f, 0.0f, 0.0f);
    Matrix3D reflectionMatrix = MakeReflection(reflectionAxis);
    std::cout << "Determinant of reflectionMatrix: " << Determinant(reflectionMatrix) << std::endl;

    // Involution Matrix Test
    Vector3D involutionAxis(1.0f, 0.0f, 0.0f);
    Matrix3D involutionMatrix = MakeInvolution(involutionAxis);
    std::cout << "Determinant of involutionMatrix: " << Determinant(involutionMatrix) << std::endl;
}

void TestSkewMatrix() {
    Vector3D skewAxis(1.0f, 0.0f, 0.0f);
    Vector3D skewAxis2(0.0f, 1.0f, 0.0f);
    float t = M_PI / 4.0f;
    Matrix3D skewMatrix = MakeSkew(t, skewAxis, skewAxis2);
    std::cout << "Determinant of skewMatrix: " << Determinant(skewMatrix) << std::endl;
}

void TestVector4D() {
    Vector4D v(1.0f, 2.0f, 3.0f, 4.0f);
    std::cout << "Testing Vector4D:" << std::endl;
    PrintVector4D(v);
}

void TestMatrix4DAndTransform() {
    // Test Matrix4D and its inverse
    Matrix4D M(
        1.0f, 6.0f, 9.0f, 4.0f,
        7.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 15.0f, 14.0f, 16.0f,
        5.0f, 2.0f, 3.0f, 8.0f
    );

    Matrix4D M_inv = Inverse(M);
    Matrix4D M_identity = M * M_inv;
    std::cout << "Matrix4D Identity Determinant: " << Determinant(M_identity) << std::endl;

    // Test Transform4D and its inverse
    Transform4D T(
        6.0f, 7.0f, 5.0f, 8.0f,
        11.0f, 12.0f, 9.0f, 10.0f,
        1.0f, 3.0f, 4.0f, 2.0f
    );

    Transform4D T_inv = Inverse(T);
    Transform4D T_identity = T * T_inv;
    std::cout << "Transform4D Identity Determinant: " << Determinant(T_identity) << std::endl;
}

void TestLineLineDistance() {
    Point3D p1(1.0f, 2.0f, 3.0f);
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Point3D p2(4.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);

    float distance = DistLineLine(p1, v1, p2, v2);
    std::cout << "Line-Line Distance Test:" << std::endl;
    std::cout << "Calculated Distance: " << distance << std::endl;

    // Expected result: 3.0
    if (fabs(distance - 3.0) < 0.0001) {
        std::cout << "Test Passed!" << std::endl;
    }
    else {
        std::cout << "Test Failed!" << std::endl;
    }
}

void TestPointLineDistance() {
    Point3D p(1.0f, 2.0f, 3.0f);
    Vector3D v(1.0f, 0.0f, 0.0f);
    Point3D q(4.0f, 0.0f, 0.0f);
    float expectedDistance = sqrt(2 * 2 + 3 * 3);

    float calculatedDistance = DistPointLine(q, p, v);

    std::cout << "Point-Line Distance Test:" << std::endl;
    std::cout << "Calculated Distance: " << calculatedDistance << std::endl;
    std::cout << "Expected Distance: " << expectedDistance << std::endl;

    if (fabs(calculatedDistance - expectedDistance) < 0.0001) {
        std::cout << "Test Passed!" << std::endl;
    }
    else {
        std::cout << "Test Failed!" << std::endl;
    }
}


int main()
{
	std::cout << "=== Testing Vector Operations ===" << std::endl;
	TestVectorOperations();

	std::cout << "\n=== Testing Basic Matrix Operations ===" << std::endl;
	TestBasicMatrixOperations();

    std::cout << "\n=== Testing Matrix Inverse ===" << std::endl;
    TestMatrixInverse();

    std::cout << "\n=== Testing Rotation Matrix ===" << std::endl;
    TestRotationMatrix();

    std::cout << "\n=== Testing Reflection and Involution ===" << std::endl;
    TestReflectionAndInvolution();

    std::cout << "\n=== Testing Skew Matrix ===" << std::endl;
    TestSkewMatrix();

    std::cout << "\n=== Testing Vector4D ===" << std::endl;
    TestVector4D();

    std::cout << "\n=== Testing Matrix4D and Transform4D ===" << std::endl;
    TestMatrix4DAndTransform();

    std::cout << "\n=== Testing Line-Line Distance ===" << std::endl;
    TestLineLineDistance();

    std::cout << "\n=== Testing Point-Line Distance ===" << std::endl;
    TestPointLineDistance();

	return 0;
}
