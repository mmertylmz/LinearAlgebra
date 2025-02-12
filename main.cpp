#include "Matrix3D.h"
#define M_PI   3.14159265358979323846264338327950288

int main()
{
    /*
    Vector3D v(1.0f, 2.0f, 3.0f);
    PrintVector3D(v);

    Vector3D w(4.0f, 5.0f, 6.0f);
    Vector3D result = v + w;

    PrintVector3D(result);
    */
    
	
	/*Matrix3D m1(2.0f, 3.0f, 1.0f,
		-1.0f, 0.0f, 4.0f,
		5.0f, -2.0f, 6.0f);*/
		
	//PrintMatrix3D(m1, "Matrix m1");

	//float value = m1(1, 0);
	//std::cout << value << std::endl;

	//m1(1, 0) = 10.0f;
	//PrintMatrix3D(m1, "Matrix m1");

	//m1[1].x = 20.0f;
	//PrintMatrix3D(m1, "Matrix m1");


	/*
	Vector3D a(1.0f, 2.0f, 3.0f);
	Vector3D b(4.0f, 5.0f, 6.0f);
	Vector3D c(7.0f, 8.0f, 9.0f);
	Matrix3D m2(a, b, c);

	PrintMatrix3D(m2, "Matrix m2");
	*/

	
	//Inverse Control	 
	/*std::cout << "Determinant of m1: " << Determinant(m1) << std::endl;
	 
	Matrix3D InversedMatrix = Inverse(m1);
	PrintMatrix3D(InversedMatrix, "Inversed Matrix m1");
	PrintMatrix3D(m1 * InversedMatrix, "m1 * Inversed Matrix m1");*/
	
	/*Vector3D rotationAxis(1.0f, 0.0f, 0.0f); 
	float angle = M_PI / 4.0f;
	Matrix3D rotationMatrix = MakeRotation(angle, rotationAxis);
	PrintMatrix3D(rotationMatrix, "Rotation Matrix (45° around X-axis)");

	float angle_90 = M_PI / 2.0f;      

	Matrix3D rotationMatrix2 = MakeRotation(angle_90, rotationAxis);
	PrintMatrix3D(rotationMatrix2, "Rotation Matrix (90° around X-axis)");*/


	////Reflection Matrix Control (Determinant always -1)
	//Vector3D reflectionAxis(1.0f, 0.0f, 0.0f);
	//Matrix3D reflectionMatrix = MakeReflection(reflectionAxis);
	//std::cout << "Determinant of reflectionMatrix: " << Determinant(reflectionMatrix) << std::endl;

	////Involution Matrix Control (Determinant always 1)
	//Vector3D involutionAxis(1.0f, 0.0f, 0.0f);
	//Matrix3D involutionMatrix = MakeInvolution(involutionAxis);
	//std::cout << "Determinant of involutionMatrix: " << Determinant(involutionMatrix) << std::endl;

    return 0;
}
