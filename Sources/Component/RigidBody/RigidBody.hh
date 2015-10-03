#pragma once

#include "../../../engine/Component/Component.hh"

class RigidBody : public StrawberryMilk::Component::Component
{
public:
	RigidBody(StrawberryMilk::Component::Type::IDComponent);
	~RigidBody();
	RigidBody(RigidBody const &&) = delete;
	RigidBody(RigidBody const &) = delete;
	void operator=(RigidBody const &) = delete;

	// system loop
public:
	virtual void init();
	virtual void update();
	virtual void destroy();
};