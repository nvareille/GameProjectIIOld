#include "Vector2.hh"
#include <stdexcept>

using namespace StrawberryMilk;

//constructors & destructors
Vector2::Vector2()
{
	vx = 0;
	vy = 0;
}

Vector2::Vector2(float _x, float _y)
{
	vx = _x;
	vy = _y;
}

Vector2::Vector2(const Vector2 & _v)
{
	vx = _v.x();
	vy = _v.y();
}

Vector2::Vector2(const Vector2 && _v)
{
	vx = _v.x();
	vy = _v.y();
}

void Vector2::operator=(const Vector2 & _v)
{
	vx = _v.x();
	vy = _v.y();
}

Vector2::~Vector2()
{
}

//getters & setters
float	Vector2::x() const
{
	return (vx);
}

float	Vector2::y() const
{
	return(vy);
}

void	Vector2::setX(float _x)
{
	vx = _x;
}

void	Vector2::setY(float _y)
{
	vy = _y;
}

void	Vector2::update(float _x, float _y)
{
	vx = _x;
	vy = _y;
}

void	Vector2::translate(float _x, float _y)
{
	vx = vx + _x;
	vy = vy + _y;
}

//operator overload
void Vector2::operator-(const Vector2 & _v)
{
	vx = vx - _v.x();
	vy = vy - _v.y();
}

void Vector2::operator+(const Vector2 & _v)
{
	vx = vx + _v.x();
	vy = vy + _v.y();
}

void Vector2::operator*(float _value)
{
	vx = vx * _value;
	vy = vy * _value;
}

void Vector2::operator/(float _value)
{
	if (_value == 0.0f)
		throw std::invalid_argument("Vector2: Operator/: Zero divisor given as parameter");
	vx = vx / _value;
	vy = vy / _value;
}
