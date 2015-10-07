#include "DrawableComponent.h"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::Component::Component *create(void)
	{
		return dynamic_cast<StrawberryMilk::Component::Component *>(new DrawableComponent);
	}
}
