#include "GraphSystem.h"

extern "C"
{
	__declspec(dllexport) StrawberryMilk::System *create(void)
	{
		return dynamic_cast<StrawberryMilk::System *>(new HeroesSoul::GraphSystem);
	}
}
