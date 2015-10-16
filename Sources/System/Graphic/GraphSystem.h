#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <chrono>

#include "../../../engine/System/System.hh"
#include "GraphicsCore.h"

#define SCREEN_WIDTH = 800
#define SCREEN_HEIGHT = 600

namespace HeroesSoul
{
	//va s'occuper de la window
	struct __declspec(dllexport) GraphSystem : public StrawberryMilk::System
	{
	public:
		GraphSystem();
		~GraphSystem();

		void init(StrawberryMilk::Engine *);
		void destroy(StrawberryMilk::Engine *);
		void Run();
		void update(StrawberryMilk::Engine *, double);

		bool registerEntity(StrawberryMilk::Entity::ID);

		LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

		ID3D10Device* GetDevice() { return mGraphics->GetDevice(); }

		void AddDrawableComponentForGraphCore(DrawableComponent *obj) { mGraphics->AddDrawableObject(obj); }

	private:
		bool Update();
		void InitWindows(int&, int&);
		void DestroyWindows();

	private:
		LPCSTR mApplicationName;
		HINSTANCE mHinstance;
		HWND mHwnd;

		ID3D10Device* mDevice;

		GraphicsCore* mGraphics;
	};

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	static GraphSystem* ApplicationHandle = 0;

};