#include "Transform.hh"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::Component::Component *create(void)
	{
		return dynamic_cast<StrawberryMilk::Component::Component *>(new Transform(0));
	}
}

Transform::Transform() : Component(0)
{
}

Transform::Transform(StrawberryMilk::Component::Type::IDComponent id) : Component(id)
{
}

Transform::~Transform()
{
}

void Transform::init(std::string const &str)
{
	JsonLoader jl(str);

	jl.LoadFile();
	jl.showContent();
	jl.loadObject(this);
}

void Transform::update()
{
}

void Transform::destroy()
{

}

/*void Transform::Serialize(Json::Value& root)
{
}

void Transform::Deserialize(Json::Value& root)
{
}*/