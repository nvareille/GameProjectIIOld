#pragma once
#ifndef STRAWBERRYMILKVECTOR3_HH_
#define STRAWBERRYMILKVECTOR3_HH_

#include <stdexcept>
#include "json/json.h"
#include "IJsonSerializable.hh"

namespace StrawberryMilk
{
	namespace Math
	{
		class Vector3 : public IJsonSerializable
		{
		public:
			float x;
			float y;
			float z;
		public:
			/*	constructors & destructors */
			Vector3();
			Vector3(float, float, float);
			virtual ~Vector3();
			Vector3(const Vector3 &);
			Vector3(Vector3 &&);
			void operator=(const Vector3 &);

			/*	getters & setters */
			void update(float, float, float);
			void translate(float, float, float);

			/*	operator overload */
			void operator-=(const Vector3 &);
			void operator+=(const Vector3 &);
			void operator*=(float);
			void operator/=(float); /* Throw a standard exception(invalid argument) */


			/* Serialization*/
			virtual void Serialize(Json::Value& root)
			{
				root["Vector3"]["vector3X"] = x;
				root["Vector3"]["vector3Y"] = y;
				root["Vector3"]["vector3Z"] = z;
			}

			virtual void Deserialize(Json::Value& root)
			{
				x = root["Vector3"].get("vector3X", 0.0f).asFloat();
				y = root["Vector3"].get("vector3Y", 0.0f).asFloat();
				z = root["Vector3"].get("vector3Z", 0.0f).asFloat();
			}
		};

		/* operator overload for epression v3 * v3*/
		static const Vector3 operator+(const Vector3 & _v1, const Vector3 & _v2) { return (Vector3(_v1.x + _v2.x, _v1.y + _v2.y, _v1.z + _v2.z)); }
		static const Vector3 operator-(const Vector3 & _v1, const Vector3 & _v2) { return (Vector3(_v1.x - _v2.x, _v1.y - _v2.y, _v1.z - _v2.z)); }

		/* operator overload for epression v3 * float*/
		static const Vector3  operator+(const Vector3 & _v, const float _value) { return (Vector3(_v.x + _value, _v.y + _value, _v.z + _value)); }
		static const Vector3  operator-(const Vector3 & _v, const float _value) { return (Vector3(_v.x - _value, _v.y - _value, _v.z - _value)); }
		static const Vector3  operator*(const Vector3 & _v, const float _value) { return (Vector3(_v.x * _value, _v.y * _value, _v.z * _value)); }
		static const Vector3  operator/(const Vector3 & _v, const float _value)
		{
			if (_value == 0.0f)
				throw std::invalid_argument("Operator/: Zero divisor given as parameter");
			return ( Vector3(_v.x / _value, _v.y / _value, _v.z / _value));
		}
	};
};
#endif