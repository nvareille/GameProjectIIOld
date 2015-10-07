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
		m_forces = StrawberryMilk::Math::Vector2(root["RigidBody"]["Forces"]["x"].asFloat(), root["RigidBody"]["Forces"]["y"].asFloat());
		m_dimensions = StrawberryMilk::Math::Vector2(root["RigidBody"]["Dimensions"]["x"].asFloat(), root["RigidBody"]["Dimensions"]["y"].asFloat());
		m_airResistance = root["RigidBody"]["AirResistance"].asFloat();
		m_isKinematic = root["RigidBody"]["IsKinematic"].asBool();
	}

public:
	float GetMass() { return (m_mass); };
	const StrawberryMilk::Math::Vector2 &GetDimensions() { return (m_dimensions); };
	const StrawberryMilk::Math::Vector2 &GetForces() { return (m_forces); };
	bool IsCircle() { return(m_isCircle); };
	float GetAirResistance() { return(m_airResistance); };
	bool IsKinematic() { return (m_isKinematic); };

	void AddForce(const StrawberryMilk::Math::Vector2 &v) { m_forces += v; };
	void SetForce(const StrawberryMilk::Math::Vector2 &v) { m_forces = v; };
	void SetKinematic(bool k) { m_isKinematic = k; };

private:
	StrawberryMilk::Math::Vector2 m_dimensions;
	StrawberryMilk::Math::Vector2 m_position;
	StrawberryMilk::Math::Vector2 m_forces;
	float m_mass;
	bool m_isCircle;
	float m_airResistance;
	bool m_isKinematic;
};