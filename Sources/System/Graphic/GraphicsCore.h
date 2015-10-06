#pragma once

#include <list>

#include "D3DWrapper.h"
#include "Camera.h"
#include "TextureShaderManager.h"
#include "../../Component/DrawableComponent/DrawableComponent.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsCore
{
public:
	GraphicsCore();
	GraphicsCore(const GraphicsCore&);
	~GraphicsCore();

	bool Init(int, int, HWND);
	void Destroy();
	bool Update();

	bool AddDrawableObject(DrawableComponent*);
	bool RemoveDrawableObject();

private:
	bool Render(float);

private:
	D3DWrapper* mD3DWrapper;
	Camera* mCamera;
	TextureShaderManager* mTextureShader;
	std::list<DrawableComponent*> mDrawableComponents;
};
