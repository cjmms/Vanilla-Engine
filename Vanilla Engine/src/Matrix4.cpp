#include "Matrix4.h"

Matrix4::Matrix4(float value)
{
	table[0][0] = value;
	table[0][1] = 0.0f;
	table[0][2] = 0.0f;
	table[0][3] = 0.0f;

	table[1][0] = 0.0f;
	table[1][1] = value;
	table[1][2] = 0.0f;
	table[1][3] = 0.0f;

	table[2][0] = 0.0f;
	table[2][1] = 0.0f;
	table[2][2] = value;
	table[2][3] = 0.0f;

	table[3][0] = 0.0f;
	table[3][1] = 0.0f;
	table[3][2] = 0.0f;
	table[3][3] = value;
}


Matrix4::Matrix4() : Matrix4(0.0f)
{
}