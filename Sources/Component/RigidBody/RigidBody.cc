#include "RigidBody.hh"

RigidBody::RigidBody(StrawberryMilk::Component::Type::IDComponent id) : Component(id)
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::init(std::string const &)
{

}

void RigidBody::update()
{
}

void RigidBody::destroy()
{

}

float RigidBody::GetMass()
{
	return (m_mass);
}

const StrawberryMilk::Math::Vector2 &RigidBody::GetForces()
{
	return (m_forces);
}