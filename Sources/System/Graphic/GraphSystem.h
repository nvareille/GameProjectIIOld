#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>

//#include "inputclass.h"
#include "GraphicsCore.h"

#define SCREEN_WIDTH = 800
#define SCREEN_HEIGHT = 600

class GraphSystem
{
public:
	GraphSystem();
	~GraphSystem();

	bool Init();
	void Destroy();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Update();
	void InitWindows(int&, int&);
	void DestroyWindows();

private:
	LPCSTR mApplicationName;
	HINSTANCE mHinstance;
	HWND mHwnd;

//	InputHandler* _input;
	GraphicsCore* mGraphics;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static GraphSystem* ApplicationHandle = 0;
