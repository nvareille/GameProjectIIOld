#pragma once

#include "../../../engine/System/System.hh"

class PhysicSystem : public StrawberryMilk::System
{
	// ctor dtor
public:
	PhysicSystem();
	~PhysicSystem();
	PhysicSystem(System const &&) = delete;
	PhysicSystem(System const &) = delete;
	void operator=(System const &) = delete;

	// system loop
public:
	virtual void init();
	virtual void update();
	virtual void destroy();

	// member function entity
public:
	virtual bool registerEntity(void *);
};