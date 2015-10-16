#include "GraphSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	GraphSystem* System;
	bool result;


	// Create the system object.
	System = new GraphSystem;
	if (!System)
	{
		return 0;
	}

	// Init and run the system object.
	result = System->Init();
	if (result)
	{
		System->Run();
	}

	// Destroy and release the system object.
	System->Destroy();
	delete System;
	System = 0;

	return 0;
}