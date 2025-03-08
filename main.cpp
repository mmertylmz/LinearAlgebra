#include "Matrix3D.h"
#include "Transform4D.h"
#include "Plane.h"
#define M_PI   3.14159265358979323846264338327950288

void TestVectorOperations() {
    // Test 1: Vector Addition
    Vector3D v1(1.0f, 2.0f, 3.0f);
    Vector3D v2(4.0f, 5.0f, 6.0f);
    Vector3D sum = v1 + v2;

    bool additionTest = (sum.x == 5.0f && sum.y == 7.0f && sum.z == 9.0f);
    std::cout << "Vector Addition Test: " << (additionTest ? "PASSED" : "FAILED") << std::endl;

    // Test 2: Vector Subtraction
    Vector3D diff = v2 - v1;
    bool subtractionTest = (diff.x == 3.0f && diff.y == 3.0f && diff.z == 3.0f);
    std::cout << "Vector Subtraction Test: " << (subtractionTest ? "PASSED" : "FAILED") << std::endl;

    // Test 3: Scalar Multiplication
    float scalar = 2.0f;
    Vector3D scaled = v1 * scalar;
    bool scalarMultTest = (scaled.x == 2.0f && scaled.y == 4.0f && scaled.z == 6.0f);
    std::cout << "Scalar Multiplication Test: " << (scalarMultTest ? "PASSED" : "FAILED") << std::endl;

    // Test 4: Dot Product
    float dot = Dot(v1, v2);
    bool dotProductTest = (fabs(dot - 32.0f) < 0.0001f); // 1*4 + 2*5 + 3*6 = 32
    std::cout << "Dot Product Test: " << (dotProductTest ? "PASSED" : "FAILED") << std::endl;

    // Test 5: Cross Product
    Vector3D cross = Cross(v1, v2);
    bool crossProductTest = (
        fabs(cross.x - (-3.0f)) < 0.0001f &&
        fabs(cross.y - (6.0f)) < 0.0001f &&
        fabs(cross.z - (-3.0f)) < 0.0001f
        );
    std::cout << "Cross Product Test: " << (crossProductTest ? "PASSED" : "FAILED") << std::endl;

    // Test 6: Vector Magnitude
    Vector3D v3(3.0f, 4.0f, 0.0f);
    float magnitude = Magnitude(v3);
    bool magnitudeTest = (fabs(magnitude - 5.0f) < 0.0001f); // 3-4-5 triangle
    std::cout << "Magnitude Test: " << (magnitudeTest ? "PASSED" : "FAILED") << std::endl;

    // Test 7: Vector Normalization
    Vector3D normalized = Normalize(v3);
    bool normalizationTest = (
        fabs(normalized.x - 0.6f) < 0.0001f &&
        fabs(normalized.y - 0.8f) < 0.0001f &&
        fabs(normalized.z - 0.0f) < 0.0001f
        );
    std::cout << "Normalization Test: " << (normalizationTest ? "PASSED" : "FAILED") << std::endl;

    // Test 8: Zero Vector Test
    Vector3D zero(0.0f, 0.0f, 0.0f);
    bool zeroMagnitudeTest = (Magnitude(zero) == 0.0f);
    std::cout << "Zero Vector Test: " << (zeroMagnitudeTest ? "PASSED" : "FAILED") << std::endl;
}

void TestBasicMatrixOperations() {
    // Test 1: Matrix Creation and Element Access
    Matrix3D m1(
        2.0f, -1.0f, 5.0f,
        3.0f, 0.0f, -2.0f,    
        1.0f, 4.0f, 6.0f   
    );

    // Test element access using (i,j) operator
    bool accessTest = (
        m1(0, 0) == 2.0f && m1(0, 1) == 3.0f && m1(0, 2) == 1.0f &&
        m1(1, 0) == -1.0f && m1(1, 1) == 0.0f && m1(1, 2) == 4.0f &&
        m1(2, 0) == 5.0f && m1(2, 1) == -2.0f && m1(2, 2) == 6.0f
        );
    std::cout << "Matrix Element Access Test: " << (accessTest ? "PASSED" : "FAILED") << std::endl;

    // Test 2: Matrix Modification
    m1(1, 0) = 10.0f;
    bool modificationTest = (m1(1, 0) == 10.0f);
    std::cout << "Matrix Element Modification Test: " << (modificationTest ? "PASSED" : "FAILED") << std::endl;

    // Test 3: Matrix Creation from Vectors
    Vector3D a(1.0f, 4.0f, 7.0f); 
    Vector3D b(2.0f, 5.0f, 8.0f);  
    Vector3D c(3.0f, 6.0f, 9.0f);  
    Matrix3D m2(a, b, c);

    bool vectorConstructionTest = (
        m2(0, 0) == 1.0f && m2(0, 1) == 2.0f && m2(0, 2) == 3.0f &&
        m2(1, 0) == 4.0f && m2(1, 1) == 5.0f && m2(1, 2) == 6.0f &&
        m2(2, 0) == 7.0f && m2(2, 1) == 8.0f && m2(2, 2) == 9.0f
        );
    std::cout << "Matrix from Vectors Construction Test: " << (vectorConstructionTest ? "PASSED" : "FAILED") << std::endl;

    // Test 4: Matrix Multiplication
    Matrix3D product = m1 * m2;

    float expected = m1(0, 0) * m2(0, 0) + m1(0, 1) * m2(1, 0) + m1(0, 2) * m2(2, 0);
    bool multiplicationTest = (fabs(product(0, 0) - expected) < 0.0001f);
    std::cout << "Matrix Multiplication Test: " << (multiplicationTest ? "PASSED" : "FAILED") << std::endl;

    // Test 5: Identity Matrix Properties
    Matrix3D identity(
        1.0f, 0.0f, 0.0f,  
        0.0f, 1.0f, 0.0f,  
        0.0f, 0.0f, 1.0f   
    );
    Matrix3D result = m1 * identity;
    bool identityTest = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fabs(result(i, j) - m1(i, j)) > 0.0001f) {
                identityTest = false;
                break;
            }
        }
    }
    std::cout << "Identity Matrix Properties Test: " << (identityTest ? "PASSED" : "FAILED") << std::endl;

    // Test 6: Matrix Vector Multiplication
    Vector3D testVec(1.0f, 1.0f, 1.0f);
    Vector3D resultVec = m1 * testVec;
    bool matVecMultTest = (
        fabs(resultVec.x - (m1(0, 0) + m1(0, 1) + m1(0, 2))) < 0.0001f &&
        fabs(resultVec.y - (m1(1, 0) + m1(1, 1) + m1(1, 2))) < 0.0001f &&
        fabs(resultVec.z - (m1(2, 0) + m1(2, 1) + m1(2, 2))) < 0.0001f
        );
    std::cout << "Matrix-Vector Multiplication Test: " << (matVecMultTest ? "PASSED" : "FAILED") << std::endl;
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
	Vector3D rotationAxis(1.0f, 0.0f, 0.0f); // X-Axis Rotation
    float angle = M_PI / 4.0f;  // 45 degree
    Matrix3D rotationMatrix = MakeRotation(angle, rotationAxis);

    // Test 1: Determinant Test
    float det = Determinant(rotationMatrix);
    std::cout << "Rotation Matrix Determinant Test:" << std::endl;
    std::cout << "Expected: 1.0, Actual: " << det << std::endl;
    std::cout << "Test 1 " << (fabs(det - 1.0f) < 0.0001f ? "PASSED" : "FAILED") << std::endl;

    // Test 2: Inverse of the Rotation Matrix = Transpose Matrix
    Matrix3D inverse = Inverse(rotationMatrix);
    Matrix3D transpose = Transpose(rotationMatrix);
    bool isInverseEqualTranspose = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fabs(inverse(i, j) - transpose(i, j)) > 0.0001f) {
                isInverseEqualTranspose = false;
                break;
            }
        }
    }
    std::cout << "\nInverse = Transpose Test: " << (isInverseEqualTranspose ? "PASSED" : "FAILED") << std::endl;

    // Test 3: Rotation Matrix * Transpose Matrix = Identity Matrix
    Matrix3D identity = rotationMatrix * transpose;
    bool isIdentity = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float expected = (i == j) ? 1.0f : 0.0f;
            if (fabs(identity(i, j) - expected) > 0.0001f) {
                isIdentity = false;
                break;
            }
        }
    }
    std::cout << "Rotation * Transpose = Identity Test: " << (isIdentity ? "PASSED" : "FAILED") << std::endl;

    // Test 4: 360 degree rotation test
    Matrix3D full_rotation = MakeRotation(2 * M_PI, rotationAxis);
    bool isBackToStart = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float expected = (i == j) ? 1.0f : 0.0f;
            if (fabs(full_rotation(i, j) - expected) > 0.0001f) {
                isBackToStart = false;
                break;
            }
        }
    }
    std::cout << "360-degree Rotation Test: " << (isBackToStart ? "PASSED" : "FAILED") << std::endl;
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

void TestIntersectTwoPlanes() {
    std::cout << "\n--- Testing IntersectTwoPlanes ---\n";

    Plane plane1(2.0f, 3.0f, -1.0f, 5.0f);

    Plane plane2(1.0f, -1.0f, 2.0f, -1.0f);

    std::cout << "Plane 1 normal: ";
    PrintVector3D(plane1.Normal());

    std::cout << "Plane 2 normal: ";
    PrintVector3D(plane2.Normal());

    Point3D intersectionPoint;
    Vector3D intersectionDirection;

    bool intersects = IntersectTwoPlanes(plane1, plane2, &intersectionPoint, &intersectionDirection);

    if (intersects) {
        std::cout << "Planes intersect in a line!\n";
        std::cout << "Point on the intersection line: ";
        PrintVector3D(intersectionPoint);

        std::cout << "Direction of the intersection line: ";
        PrintVector3D(intersectionDirection);

        float dist1 = Dot(plane1, intersectionPoint);
        float dist2 = Dot(plane2, intersectionPoint);

        std::cout << "Distance from point to plane 1: " << dist1 << " (should be close to 0)\n";
        std::cout << "Distance from point to plane 2: " << dist2 << " (should be close to 0)\n";

        float dot1 = Dot(plane1.Normal(), intersectionDirection);
        float dot2 = Dot(plane2.Normal(), intersectionDirection);

        std::cout << "Dot product of plane 1 normal and intersection direction: " << dot1 << " (should be close to 0)\n";
        std::cout << "Dot product of plane 2 normal and intersection direction: " << dot2 << " (should be close to 0)\n";
    }
    else {
        std::cout << "Planes are parallel and do not intersect.\n";
    }
}

void TestIntersectThreePlanes() {
    std::cout << "\n--- Testing IntersectThreePlanes ---\n";

    Plane plane1(2.0f, 3.0f, -1.0f, 5.0f);   // 2x + 3y - z + 5 = 0
    Plane plane2(1.0f, -1.0f, 2.0f, -1.0f);  // x - y + 2z - 1 = 0
    Plane plane3(3.0f, 1.0f, 1.0f, 2.0f);    // 3x + y + z + 2 = 0

    Point3D intersectionPoint;

    bool intersects = IntersectThreePlanes(plane1, plane2, plane3, intersectionPoint);

    if (intersects) {
        std::cout << "Planes intersect at a point!\n";
        std::cout << "Intersection point: ";
        PrintVector3D(intersectionPoint);

        float dist1 = Dot(plane1, intersectionPoint);
        float dist2 = Dot(plane2, intersectionPoint);
        float dist3 = Dot(plane3, intersectionPoint);

        std::cout << "Distance from point to plane 1: " << dist1 << " (should be close to 0)\n";
        std::cout << "Distance from point to plane 2: " << dist2 << " (should be close to 0)\n";
        std::cout << "Distance from point to plane 3: " << dist3 << " (should be close to 0)\n";
    }
    else {
        std::cout << "Planes do not intersect at a single point.\n";
    }
}

void TestPlaneTransformation()
{
    std::cout << "\n--- Testing Plane Transformation ---\n";

    // Create a test plane: 2x + 3y - z + 5 = 0
    Plane testPlane(2.0f, 3.0f, -1.0f, 5.0f);
    std::cout << "Original Plane: Normal=(" << testPlane.x << ", " << testPlane.y << ", "
        << testPlane.z << "), d=" << testPlane.w << std::endl;

    // Create a test point on the plane
    Point3D pointOnPlane(1.0f, 0.0f, 7.0f);  // 2*1 + 3*0 - 7 + 5 = 0
    std::cout << "Point on original plane: (" << pointOnPlane.x << ", "
        << pointOnPlane.y << ", " << pointOnPlane.z << ")" << std::endl;
    std::cout << "Distance from point to plane: " << Dot(testPlane, pointOnPlane) << " (should be 0)\n";

    // Create a transformation matrix (translation + rotation)
    Transform4D transform = Transform4D(
        0.866f, -0.5f, 0.0f, 2.0f,  // cos(30°), -sin(30°), 0, x-translation
        0.5f, 0.866f, 0.0f, -1.0f,  // sin(30°), cos(30°), 0, y-translation
        0.0f, 0.0f, 1.0f, 3.0f      // 0, 0, 1, z-translation
    );

    // Calculate inverse of the transformation
    Transform4D inverseTransform = Inverse(transform);

    // Transform the plane using the inverse transformation
    Plane transformedPlane = testPlane * inverseTransform;
    std::cout << "Transformed Plane: Normal=(" << transformedPlane.x << ", " << transformedPlane.y << ", "
        << transformedPlane.z << "), d=" << transformedPlane.w << std::endl;

    // Transform the point (using the original transform, not the inverse)
    Point3D transformedPoint = transform * pointOnPlane;
    std::cout << "Transformed point: (" << transformedPoint.x << ", "
        << transformedPoint.y << ", " << transformedPoint.z << ")" << std::endl;

    // Check if the transformed point lies on the transformed plane
    float distance = Dot(transformedPlane, transformedPoint);
    std::cout << "Distance from transformed point to transformed plane: "
        << distance << " (should be close to 0)\n";
}

int main()
{
	/*std::cout << "=== Testing Vector Operations ===" << std::endl;
	TestVectorOperations();*/

	/*std::cout << "\n=== Testing Basic Matrix Operations ===" << std::endl;
	TestBasicMatrixOperations();*/

    /*std::cout << "\n=== Testing Matrix Inverse ===" << std::endl;
    TestMatrixInverse();*/

    /*std::cout << "\n=== Testing Rotation Matrix ===" << std::endl;
    TestRotationMatrix();*/

    /*std::cout << "\n=== Testing Reflection and Involution ===" << std::endl;
    TestReflectionAndInvolution();*/

    /*std::cout << "\n=== Testing Skew Matrix ===" << std::endl;
    TestSkewMatrix();*/

    /*std::cout << "\n=== Testing Vector4D ===" << std::endl;
    TestVector4D();*/

    /*std::cout << "\n=== Testing Matrix4D and Transform4D ===" << std::endl;
    TestMatrix4DAndTransform();*/

    /*std::cout << "\n=== Testing Line-Line Distance ===" << std::endl;
    TestLineLineDistance();*/

    /*std::cout << "\n=== Testing Point-Line Distance ===" << std::endl;
    TestPointLineDistance();*/

    //TestIntersectTwoPlanes();
    //TestIntersectThreePlanes();

    TestPlaneTransformation();

	return 0;
}
