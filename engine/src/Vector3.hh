#pragma once

  class Vector3 {

  protected:
	  float vx;
	  float vy;
	  float vz;
  public:
	/*	constructors & destructors */
    Vector3();
	Vector3(float, float, float);
    virtual ~Vector3();
	Vector3(const Vector3 &);
	void operator=(const Vector3 &);

	/*	getters & setters */
	float	x() const;
	float	y() const;
	float	z() const;
	void	setX(float);
	void	setY(float);
	void	setZ(float);
	void	update(float, float, float);

	/*	operator overload */
	void operator-(const Vector3 &);
	void operator+(const Vector3 &);
	void operator*(float);
	void operator/(float); /* Throw a standard exception(invalid argument) */
  };
