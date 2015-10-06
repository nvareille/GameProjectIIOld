#include "Transform.hh"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::Component::Component *create(void)
	{
		return dynamic_cast<StrawberryMilk::Component::Component *>(new Transform(1));
	}
}

Transform::Transform() : Component(0)
{
}

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