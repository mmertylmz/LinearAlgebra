#include "Vector3D.h"

int main()
{
    Vector3D v(1.0f, 2.0f, 3.0f);
    PrintVector3D(v);

    Vector3D w(4.0f, 5.0f, 6.0f);
    Vector3D result = v + w;

    PrintVector3D(result);

    return 0;
}
