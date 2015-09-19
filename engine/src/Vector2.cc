#include "Vector2.hh"
#include <stdexcept>

using namespace StrawberryMilk;

//constructors & destructors
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2 & _v)
{
	x = _v.x;
	y = _v.y;
}

Vector2::Vector2(Vector2 && _v)
{
	x = _v.x;
	y = _v.y;
	_v.update(0.0f, 0.0f);
}

void Vector2::operator=(const Vector2 & _v)
{
	x = _v.x;
	y = _v.y;
}

Vector2::~Vector2()
{
}

//getters & setters

void	Vector2::setX(float _x)
{
	x = _x;
}

void	Vector2::setY(float _y)
{
	y = _y;
}

void	Vector2::update(float _x, float _y)
{
	x = _x;
	y = _y;
}

void	Vector2::translate(float _x, float _y)
{
	x = x + _x;
	y = y + _y;
}

//operator overload
void Vector2::operator-(const Vector2 & _v)
{
	x = x - _v.x;
	y = y - _v.y;
}

void Vector2::operator+(const Vector2 & _v)
{
	x = x + _v.x;
	y = y + _v.y;
}

void Vector2::operator*(float _value)
{
	x = x * _value;
	y = y * _value;
}

void Vector2::operator/(float _value)
{
	if (_value == 0.0f)
		throw std::invalid_argument("Vector2: Operator/: Zero divisor given as parameter");
	x = x / _value;
	y = y / _value;
}
