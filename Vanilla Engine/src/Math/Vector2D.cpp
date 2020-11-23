#include "Vector2D.h"


Vector2D::Vector2D(void)
	: x(0.0f), y(0.0f)
{}

Vector2D::Vector2D(float value)
	: x(value), y(value)
{}

Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{}

Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}


const Vector2D Vector2D::operator+(const Vector2D& rhs) const
{
	return Vector2D(rhs.x + this->x, rhs.y + this->y);
}


Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}


const Vector2D Vector2D::operator-(const Vector2D& rhs) const
{
	return Vector2D(this->x - rhs.x, this->y - rhs.y);
}


Vector2D& Vector2D::operator*=(float rhs)
{
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}


float Vector2D::operator*(const Vector2D& rhs) const	// dot product
{
	return this->x * rhs.x + this->y * rhs.y;
}


const Vector2D Vector2D::operator*(float rhs) const
{
	return Vector2D(this->x * rhs, this->y * rhs);
}


float Vector2D::magnitude(void) const
{
	return sqrtf(x * x + y * y);
}


const Vector2D Vector2D::normalize(void) const
{
	return Vector2D(this->x / magnitude(), this->y / magnitude());
}




