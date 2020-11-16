#pragma once

#include <math.h>

// 3d float vector

class Vector3D
{
public:
	float x, y, z;		// position

	Vector3D(void);
	Vector3D(float value);	//	init to (value, value)
	Vector3D(float x, float y, float z);

	// arithmetics
	Vector3D& operator+=(const Vector3D& rhs);
	const Vector3D operator+(const Vector3D& rhs) const;
	Vector3D& operator-=(const Vector3D& rhs);
	const Vector3D operator-(const Vector3D& rhs) const;
	Vector3D& operator*=(float rhs);
	float operator*(const Vector3D& rhs) const;	// dot product
	const Vector3D operator*(float rhs) const;

	// operation
	float magnitude(void) const;
	const Vector3D normalize(void) const;

};

