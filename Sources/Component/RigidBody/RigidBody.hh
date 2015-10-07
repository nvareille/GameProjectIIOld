#pragma once

#include "../../../engine/Component/Component.hh"
#include "../../Component/Transform/Transform.hh"
#include "../../../engine/src/Vector2.hh"

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
	virtual void init(std::string const &);
	virtual void update();
	virtual void destroy();

public:
	float GetMass();
	const StrawberryMilk::Math::Vector2 &GetDimensions();
	const StrawberryMilk::Math::Vector2 &GetForces();
	bool IsCircle();

private:
	StrawberryMilk::Math::Vector2 m_dimensions;
	StrawberryMilk::Math::Vector2 m_position;
	StrawberryMilk::Math::Vector2 m_forces;
	float m_mass;

};