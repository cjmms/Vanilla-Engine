#include "Transformation.h"

////////////////////////////////////////////////////////////////////////
// A small library of 4x4 matrix operations needed for graphics
// transformations.  Matrix4 is a 4x4 float matrix class with indexing
// and printing methods.  A small list or procedures are supplied to
// create Rotate, Scale, Translate, and Perspective matrices and to
// return the product of any two such.


#include "math.h"

// TODO: OpenGL does not allow passing 2D array as uniform
// 2D array has to be flattened first
// Stupid OpenGL, no wonder people use D3D and Vulkan
float* Transformation::Pntr(Matrix4& M)
{
    return &(M.table[0][0]);
}

//@@ The following procedures should calculate and return 4x4
//transformation matrices instead of the identity.

// Return a rotation matrix around an axis (0:X, 1:Y, 2:Z) by an angle
// measured in degrees.  NOTE: Make sure to convert degrees to radians
// before using sin and cos.  HINT: radians = degrees*PI/180
// i: rotate around which axis
const float pi = 3.14159f;
Matrix4 Transformation::Rotate(const int i, const float theta)
{
    Matrix4 R(1.0f);  // identity matrix

    float radian = theta * pi / 180.0f;

    switch (i)
    {
    case 0:     // rotate around X
        R.table[1][1] = cosf(radian);
        R.table[2][1] = -sinf(radian);
        R.table[1][2] = sinf(radian);
        R.table[2][2] = cosf(radian);
        break;

    case 1:     // rotate around Y
        R.table[0][0] = cosf(radian);
        R.table[2][0] = sinf(radian);
        R.table[0][2] = -sinf(radian);
        R.table[2][2] = cosf(radian);
        break;
    case 2:     // rotate around Z
        R.table[0][0] = cosf(radian);
        R.table[1][0] = -sinf(radian);
        R.table[0][1] = sinf(radian);
        R.table[1][1] = cosf(radian);
        break;

    default:
        break;
    }

    return R;
}

// Return a scale matrix
Matrix4 Transformation::Scale(const float x, const float y, const float z)
{
    Matrix4 S(1.0f);
    S.table[0][0] = x;
    S.table[1][1] = y;
    S.table[2][2] = z;


    return S;
}

// Return a translation matrix
Matrix4 Transformation::Translate(const float x, const float y, const float z)
{
    Matrix4 T(1.0f);
    T.table[3][0] = x;
    T.table[3][1] = y;
    T.table[3][2] = z;

    return T;
}

// Returns a perspective projection matrix
Matrix4 Transformation::Perspective(const float rx, const float ry,
    const float front, const float back)
{
    Matrix4 P(0.0f);

    P.table[0][0] = 1.0f / rx;
    P.table[1][1] = 1.0f / ry;
    P.table[2][2] = -(back + front) / (back - front);
    P.table[3][2] = -1.0f;
    P.table[2][3] = -2.0f * front * back / (back - front);

    return P;
}




Matrix4 Transformation::LookAt(const Vector3D& Eye, const Vector3D& Center, const Vector3D& Up)
{
    Vector3D V = ( Center - Eye ).normalize();
    Vector3D A = ( V.cross(Up) ).normalize();
    Vector3D B = A.cross(V);
    
    Matrix4 lookat(1.0f);
    lookat.table[0][0] = A.x;
    lookat.table[0][1] = A.y;
    lookat.table[0][2] = A.z;
    lookat.table[0][3] = -(A * Eye);

    lookat.table[1][0] = B.x;
    lookat.table[1][1] = B.y;
    lookat.table[1][2] = B.z;
    lookat.table[1][3] = -(B * Eye);

    lookat.table[2][0] = -(V.x);
    lookat.table[2][1] = -(V.y);
    lookat.table[2][2] = -(V.z);
    lookat.table[2][3] = V * Eye;   // look at -z axis

    return lookat;
}