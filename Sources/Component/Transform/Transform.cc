#include "Transform.hh"

Transform::Transform(StrawberryMilk::Component::Type::IDComponent id) : Component(id)
{
	printf("test\n");
}

Transform::~Transform()
{
}

void Transform::init(std::string const &)
{
	printf("test\n");
}

void Transform::update()
{
	printf("test\n");
}

void Transform::destroy()
{

}