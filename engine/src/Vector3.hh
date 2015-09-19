#pragma once

namespace StrawberryMilk
{
	class Vector3
	{
	public:
		float x;
		float y;
		float z;
	private:
		Vector3(Vector3 &&);
	public:
		/*	constructors & destructors */
		Vector3();
		Vector3(float, float, float);
		virtual ~Vector3();
		Vector3(const Vector3 &);
		void operator=(const Vector3 &);

		/*	getters & setters */
		void	setX(float);
		void	setY(float);
		void	setZ(float);
		void	update(float, float, float);
		void	translate(float, float, float);

		/*	operator overload */
		void operator-(const Vector3 &);
		void operator+(const Vector3 &);
		void operator*(float);
		void operator/(float); /* Throw a standard exception(invalid argument) */
	};
};