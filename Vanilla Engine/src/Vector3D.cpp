#include "Vector3D.h"


Vector3D::Vector3D(void)
	: x(0.0f), y(0.0f), z(0.0f)
{}

Vector3D::Vector3D(float value)
	: x(value), y(value), z(value)
{}

Vector3D::Vector3D(float x, float y, float z)
	: x(x), y(y), z(z)
{}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}


const Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
	return Vector3D(rhs.x + this->x, rhs.y + this->y, rhs.z + this->z);
}


Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}


const Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
	return Vector3D(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}


Vector3D& Vector3D::operator*=(float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;

	return *this;
}


float Vector3D::operator*(const Vector3D& rhs) const	// dot product
{
	return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}


const Vector3D Vector3D::operator*(float rhs) const
{
	return Vector3D(this->x * rhs, this->y * rhs, this->z * rhs);
}


float Vector3D::magnitude(void) const
{
	return sqrtf(x * x + y * y + z * z);
}


Vector3D Vector3D::normalize(void) const
{
	return Vector3D(this->x / magnitude(), this->y / magnitude(), this->z / magnitude());
}


Vector3D Vector3D::cross(const Vector3D& rhs) const
{
	return Vector3D( this->y * rhs.z - this->z * rhs.y,
					 this->z * rhs.x - this->x * rhs.z,
					 this->x * rhs.y - this->y * rhs.x );

}



