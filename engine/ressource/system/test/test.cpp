
#include "test.hpp"
#include "../../../system/System.hh"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::System *create(void)
    {
        return dynamic_cast<StrawberryMilk::System *>(new Test);
    }
}
