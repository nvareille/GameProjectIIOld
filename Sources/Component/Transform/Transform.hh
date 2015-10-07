#pragma once

#include "../../../engine/Component/Component.hh"
#include "Vector2.hh"

class Transform : public StrawberryMilk::Component::Component, public IJsonSerializable
{
public:
	Transform();
	Transform(StrawberryMilk::Component::Type::IDComponent id);
	virtual ~Transform();
	Transform(Transform const &&) = delete;
	Transform(Transform const &) = delete;
	void operator=(Transform const &) = delete;

	// system loop
public:
	virtual void init(std::string const &, StrawberryMilk::Engine *);
	virtual void update(StrawberryMilk::Engine *);
	virtual void destroy(StrawberryMilk::Engine *);

public:
	virtual void Serialize(Json::Value &root)
	{
		
	}

	virtual void Deserialize(Json::Value &root)
	{
		m_position.x = root["Transform"]["Position"]["x"].asFloat();
		m_position.y = root["Transform"]["Position"]["y"].asFloat();

		printf("%f %f\n", m_position.x, m_position.y);
	}

public:
	StrawberryMilk::Math::Vector2 &Position() { return m_position; };
	StrawberryMilk::Math::Vector2 &Rotation() { return m_rotation; };
	StrawberryMilk::Math::Vector2 &Scale() { return m_scale; };

public:
	StrawberryMilk::Math::Vector2 m_position;
	StrawberryMilk::Math::Vector2 m_rotation;
	StrawberryMilk::Math::Vector2 m_scale;
};