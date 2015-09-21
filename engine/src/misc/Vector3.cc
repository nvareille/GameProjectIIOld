#include "Vector3.hh"
#include <stdexcept>

using namespace StrawberryMilk::Math;

//constructors & destructors
Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3(const Vector3 & _v)
{
	x = _v.x;
	y = _v.y;
	z = _v.z;
}

Vector3::Vector3(Vector3 && _v)
{
	x = _v.x;
	y = _v.y;
	z = _v.z;
	_v.update(0.0f, 0.0f, 0.0f);
}

void Vector3::operator=(const Vector3 & _v)
{
	x = _v.x;
	y = _v.y;
	z = _v.z;
}

Vector3::~Vector3()
{
}

//getters & setters
void Vector3::update(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector3::translate(float _x, float _y, float _z)
{
	x = x + _x;
	y = y + _y;
	z = z + _z;
}

//operator overload
void Vector3::operator-(const Vector3 & _v)
{
	x = x - _v.x;
	y = y - _v.y;
	z = z - _v.z;
}

void Vector3::operator+(const Vector3 & _v)
{
	x = x + _v.x;
	y = y + _v.y;
	z = z + _v.z;
}

void Vector3::operator*(float _value)
{
	x = x * _value;
	y = y * _value;
	z = z * _value;
}

void Vector3::operator/(float _value)
{
	if (_value == 0.0f)
		throw std::invalid_argument("Vector3: Operator/: Zero divisor given as parameter");
	x = x / _value;
	y = y / _value;
	z = z / _value;
}
