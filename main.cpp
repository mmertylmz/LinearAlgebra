#include "Matrix3D.h"

int main()
{
    /*
    Vector3D v(1.0f, 2.0f, 3.0f);
    PrintVector3D(v);

    Vector3D w(4.0f, 5.0f, 6.0f);
    Vector3D result = v + w;

    PrintVector3D(result);
    */
    
	Matrix3D m1(1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);

	PrintMatrix3D(m1, "Matrix m1");

	float value = m1(1, 0);
	//std::cout << value << std::endl;

	m1(1, 0) = 10.0f;
	PrintMatrix3D(m1, "Matrix m1");

	m1[1].x = 20.0f;
	PrintMatrix3D(m1, "Matrix m1");


	/*
	Vector3D a(1.0f, 2.0f, 3.0f);
	Vector3D b(4.0f, 5.0f, 6.0f);
	Vector3D c(7.0f, 8.0f, 9.0f);
	Matrix3D m2(a, b, c);

	PrintMatrix3D(m2, "Matrix m2");
	*/


    return 0;
}
