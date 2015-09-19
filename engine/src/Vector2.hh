#pragma once

namespace StrawberryMilk
{
	class Vector2
	{
	protected:
		float vx;
		float vy;
	private:
		Vector2(Vector2 &&);
	public:
		/*	constructors & destructors */
		Vector2();
		Vector2(float, float);
		virtual ~Vector2();
		Vector2(const Vector2 &);
		void operator=(const Vector2 &);

		/*	getters & setters */
		float	x() const;
		float	y() const;
		void	setX(float);
		void	setY(float);
		void	update(float, float);
		void	translate(float, float);

		/*	operator overload */
		void operator-(const Vector2 &);
		void operator+(const Vector2 &);
		void operator*(float);
		void operator/(float); /* Throw a standard exception(invalid argument) */
	};
};