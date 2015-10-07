#pragma once

#include "../../../engine/Component/Component.hh"
#include "../../../engine/src/Vector2.hh"

class Transform : public StrawberryMilk::Component::Component
{
public:
	Transform(StrawberryMilk::Component::Type::IDComponent id);
	~Transform();
	Transform(Transform const &&) = delete;
	Transform(Transform const &) = delete;
	void operator=(Transform const &) = delete;

	// system loop
public:
	virtual void init(std::string const &);
	virtual void update();
	virtual void destroy();

public:
	StrawberryMilk::Math::Vector2 &Position() { return m_position; };
	StrawberryMilk::Math::Vector2 &Rotation() { return m_rotation; };
	StrawberryMilk::Math::Vector2 &Scale() { return m_scale; };

private:
	StrawberryMilk::Math::Vector2 m_position;
	StrawberryMilk::Math::Vector2 m_rotation;
	StrawberryMilk::Math::Vector2 m_scale;
};