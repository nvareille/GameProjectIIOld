
#include "test.hpp"
#include "../../../component/Component.hh"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::Component::Component *create(void)
    {
        return dynamic_cast<StrawberryMilk::Component::Component *>(new Test);
    }
}
