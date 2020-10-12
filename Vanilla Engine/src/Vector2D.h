#pragma once

#include <math.h>

// 2d float vector

class Vector2D
{
public:
	float x, y;		// position

	Vector2D(void);
	Vector2D(float value);	//	init to (value, value)
	Vector2D(float x, float y);

	// arithmetics
	Vector2D& operator+=(const Vector2D& rhs);
	const Vector2D operator+(const Vector2D& rhs) const;
	Vector2D& operator-=(const Vector2D& rhs);
	const Vector2D operator-(const Vector2D& rhs) const;
	Vector2D& operator*=(float rhs);
	float operator*(const Vector2D& rhs) const;	// dot product
	const Vector2D operator*(float rhs) const;

	// operation
	float magnitude(void) const;
	const Vector2D normalize(void) const;
	




};

