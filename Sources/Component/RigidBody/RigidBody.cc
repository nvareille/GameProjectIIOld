#include "RigidBody.hh"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::Component::Component *create(void)
	{
		return dynamic_cast<StrawberryMilk::Component::Component *>(new RigidBody(0));
	}
}

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