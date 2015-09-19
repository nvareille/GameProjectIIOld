#include "Vector3.hh"
#include <stdexcept>

using namespace StrawberryMilk;

//constructors & destructors
Vector3::Vector3()
{
	vx = 0;
	vy = 0;
	vz = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	vx = _x;
	vy = _y;
	vz = _z;
}

Vector3::Vector3(const Vector3 & _v)
{
	vx = _v.x();
	vy = _v.y();
	vz = _v.z();
}

void Vector3::operator=(const Vector3 & _v)
{
	vx = _v.x();
	vy = _v.y();
	vz = _v.z();
}

Vector3::~Vector3()
{
}

//getters & setters
float Vector3::x() const
{
	return (vx);
}

float Vector3::y() const
{
	return(vy);
}

float Vector3::z() const
{
	return(vz);
}

void Vector3::setX(float _x)
{
	vx = _x;
}

void Vector3::setY(float _y)
{
	vy = _y;
}

void Vector3::setZ(float _z)
{
	vz = _z;
}

void Vector3::update(float _x, float _y, float _z)
{
	vx = _x;
	vy = _y;
	vz = _z;
}

void Vector3::translate(float _x, float _y, float _z)
{
	vx = vx + _x;
	vy = vy + _y;
	vz = vz + _z;
}

//operator overload
void Vector3::operator-(const Vector3 & _v)
{
	vx = vx - _v.x();
	vy = vy - _v.y();
	vz = vz - _v.z();
}

void Vector3::operator+(const Vector3 & _v)
{
	vx = vx + _v.x();
	vy = vy + _v.y();
	vz = vz + _v.z();
}

void Vector3::operator*(float _value)
{
	vx = vx * _value;
	vy = vy * _value;
	vz = vz * _value;
}

void Vector3::operator/(float _value)
{
	if (_value == 0.0f)
		throw std::invalid_argument("Vector3: Operator/: Zero divisor given as parameter");
	vx = vx / _value;
	vy = vy / _value;
	vz = vz / _value;
}
