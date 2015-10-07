#pragma once

#include "../../Component/Transform/Transform.hh"

class RigidBody : public StrawberryMilk::Component::Component, public IJsonSerializable
{
public:
	RigidBody(StrawberryMilk::Component::Type::IDComponent);
	~RigidBody();
	RigidBody(RigidBody const &&) = delete;
	RigidBody(RigidBody const &) = delete;
	void operator=(RigidBody const &) = delete;

	// system loop
public:
	virtual void init(std::string const &, StrawberryMilk::Engine *);
	virtual void update(StrawberryMilk::Engine *);
	virtual void destroy(StrawberryMilk::Engine *);

	virtual void Serialize(Json::Value &)
	{

	}

	virtual void Deserialize(Json::Value &root)
	{
		m_isCircle = root["RigidBody"]["isCircle"].asBool();
		m_mass = root["RigidBody"]["mass"].asFloat();
	}

public:
	float GetMass() { return (m_mass); };
	const StrawberryMilk::Math::Vector2 &GetDimensions() { return (m_dimensions); };
	const StrawberryMilk::Math::Vector2 &GetForces() { return (m_forces); };
	bool IsCircle() { return(m_isCircle); };

private:
	StrawberryMilk::Math::Vector2 m_dimensions;
	StrawberryMilk::Math::Vector2 m_position;
	StrawberryMilk::Math::Vector2 m_forces;
	float m_mass;
	bool m_isCircle;
};