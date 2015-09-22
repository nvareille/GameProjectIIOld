#pragma once
#ifndef STRAWBERRYMILKVECTOR2_HH_
#define STRAWBERRYMILKVECTOR2_HH_

#include <stdexcept>
namespace StrawberryMilk
{
	namespace Math
	{
		class Vector2
		{
		public:
			float x;
			float y;
			
		public:
			/*	constructors & destructors */
			Vector2();
			Vector2(float, float);
			virtual ~Vector2();
			Vector2(const Vector2 &);
			Vector2(Vector2 &&);
			void operator=(const Vector2 &);

			/*	getters & setters */
			void update(float, float);
			void translate(float, float);

			/*	operator overload */
			void operator-=(const Vector2 &);
			void operator+=(const Vector2 &);
			void operator*=(float);
			void operator/=(float); /* Throw a standard exception(invalid argument) */
		};

		/* operator overload for epression v3 * v3*/
		static const Vector2  operator+(const Vector2 & _v1, const Vector2 & _v2) { return ( Vector2(_v1.x + _v2.x, _v1.y + _v2.y)); }
		static const Vector2  operator-(const Vector2 & _v1, const Vector2 & _v2) { return ( Vector2(_v1.x - _v2.x, _v1.y - _v2.y)); }

		/* operator overload for epression v3 * float*/
		static const Vector2  operator+(const Vector2 & _v, const float _value) { return ( Vector2(_v.x + _value, _v.y + _value)); }
		static const Vector2  operator-(const Vector2 & _v, const float _value) { return ( Vector2(_v.x - _value, _v.y - _value)); }
		static const Vector2  operator*(const Vector2 & _v, const float _value) { return ( Vector2(_v.x * _value, _v.y * _value)); }
		static const Vector2  operator/(const Vector2 & _v, const float _value)
		{
			if (_value == 0.0f)
				throw std::invalid_argument("Operator/: Zero divisor given as parameter");
			return ( Vector2(_v.x / _value, _v.y / _value));
		}
	};
};

#endif