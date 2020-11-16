#pragma once
#include "Vector3D.h"
#include "Matrix4.h"


#include <fstream>

// Factory functions to create specific transformations, multiply two, and invert one.
Matrix4 Rotate(const int i, const float theta);
Matrix4 Scale(const float x, const float y, const float z);
Matrix4 Translate(const float x, const float y, const float z);
Matrix4 Perspective(const float rx, const float ry, const float front, const float back);

// look at -z axis
Matrix4 LookAt(const Vector3D& Eye, const Vector3D& Center, const Vector3D& Up);

float* Pntr(Matrix4& m);
