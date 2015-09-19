#pragma once

namespace StrawberryMilk
{
	namespace Math
	{
		class Vector2
		{
		public:
			float x;
			float y;
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
			void	update(float, float);
			void	translate(float, float);

			/*	operator overload */
			void operator-(const Vector2 &);
			void operator+(const Vector2 &);
			void operator*(float);
			void operator/(float); /* Throw a standard exception(invalid argument) */
		};
	}
};