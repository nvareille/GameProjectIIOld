#include "GraphSystem.h"

#include <iostream>

namespace HeroesSoul
{
	GraphSystem::GraphSystem()
	{
		mGraphics = NULL;
	}

	GraphSystem::~GraphSystem()
	{
	}

	void GraphSystem::init(StrawberryMilk::Engine *engine)
	{
		int screenWidth, screenHeight;

		screenWidth = 0;
		screenHeight = 0;

		std::cout << "init graph";

		InitWindows(screenWidth, screenHeight);

		if (!(mGraphics = new GraphicsCore))
		{
			return;
		}

		if (!(mGraphics->Init(screenWidth, screenHeight, mHwnd)))
		{
			return;
		}
		return;

		mDevice = mGraphics->GetDevice();
	}

	void GraphSystem::destroy(StrawberryMilk::Engine *engine)
	{
		if (mGraphics)
		{
			mGraphics->Destroy();
			delete mGraphics;
			mGraphics = 0;
		}

		DestroyWindows();

		return;
	}

	void GraphSystem::Run()
	{
		MSG msg;
		bool done, result;

		ZeroMemory(&msg, sizeof(MSG));

		done = false;
		while (!done)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (msg.message == WM_QUIT)
			{
				done = true;
			}
			else
			{
				result = Update();
				if (!result)
				{
					done = true;
				}
			}

		}

		return;
	}

	bool GraphSystem::Update()
	{
		bool result;

//		if (!(mGraphics->Update()))
		{
			return false;
		}

		return true;
	}

	void GraphSystem::update(StrawberryMilk::Engine *engine, double deltatime)
	{
		if (!(mGraphics->Update(engine))){
			//throw exception;
			return;
		}
	}

	LRESULT CALLBACK GraphSystem::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
	{
		switch (umsg)
		{
		default:
		{
				   return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
		}
	}


	void GraphSystem::InitWindows(int& screenWidth, int& screenHeight)
	{
		WNDCLASSEX wc;
		DEVMODE dmScreenSettings;
		int posX, posY;


		ApplicationHandle = this;

		mHinstance = GetModuleHandle(NULL);

		// Give the application a name.
		mApplicationName = "HeroesSouls";

		// Setup the windows class with default settings.
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = mHinstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hIconSm = wc.hIcon;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = mApplicationName;
		wc.cbSize = sizeof(WNDCLASSEX);

		RegisterClassEx(&wc);

		screenWidth = GetSystemMetrics(SM_CXSCREEN);
		screenHeight = GetSystemMetrics(SM_CYSCREEN);

		// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
		if (FULL_SCREEN)
		{
			memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);
			dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
			dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
			dmScreenSettings.dmBitsPerPel = 32;
			dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

			posX = posY = 0;
		}
		else
		{
			// If windowed then set it to 800x600 resolution.
			screenWidth = 800;
			screenHeight = 600;

			// Place the window in the middle of the screen.
			posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
			posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
		}

		mHwnd = CreateWindowEx(WS_EX_APPWINDOW, mApplicationName, mApplicationName,
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			posX, posY, screenWidth, screenHeight, NULL, NULL, mHinstance, NULL);

		ShowWindow(mHwnd, SW_SHOW);
		SetForegroundWindow(mHwnd);
		SetFocus(mHwnd);

		ShowCursor(false);

		return;
	}

	void GraphSystem::DestroyWindows()
	{
		// Show the mouse cursor.
		ShowCursor(true);

		// Fix the display settings if leaving full screen mode.
		if (FULL_SCREEN)
		{
			ChangeDisplaySettings(NULL, 0);
		}

		// Remove the window.
		DestroyWindow(mHwnd);
		mHwnd = NULL;

		UnregisterClass(mApplicationName, mHinstance);
		mHinstance = NULL;

		// Release the pointer to this class.
		ApplicationHandle = NULL;

		return;
	}

	LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
	{
		switch (umessage)
		{
			// Check if the window is being destroyed.
		case WM_DESTROY:
		{
						   PostQuitMessage(0);
						   return 0;
		}

			// Check if the window is being closed.
		case WM_CLOSE:
		{
						 PostQuitMessage(0);
						 return 0;
		}

			// All other messages pass to the message handler in the system class.
		default:
			return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}