#pragma once

#include <iostream>
#include <chrono>

#include "../../../engine/component/Component.hh"
#include "../../System/Graphic/TextureHandler.h"
#include "../../Component/Transform/Transform.hh"
#include "../../../engine/src/Vector2.hh"

enum Layout
{
	UI = 0,
	FRONT,
	MIDDLE,
	BACKGROUND
};

struct __declspec(dllexport)  DrawableComponent : public StrawberryMilk::Component::Component
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	DrawableComponent();
	~DrawableComponent();

	void init(std::string const &);
	void destroy();
	void update() {};

	bool Init(ID3D10Device*, int, int, char*, int, int, int, Layout);
	bool Render(ID3D10Device*);

	int GetIndexCount();
	ID3D10ShaderResourceView* GetTexture();
	Layout GetLayout();

private:
	bool InitBuffers(ID3D10Device*);
	void DestroyBuffers();
	bool UpdateBuffers();
	void RenderBuffers(ID3D10Device*);

	bool LoadTexture(ID3D10Device*, char*);
	void ReleaseTexture();
	void MovingExample();
	void ScaleExample();

private:
	Layout mLayout;
	int mTextureId;
	ID3D10Buffer *mVertexBuffer, *mIndexBuffer;
	int mVertexCount, mIndexCount;
	TextureHandler* mTexture;
	int mScreenWidth, mScreenHeight;
	int mBitmapWidth, mBitmapHeight;
	int mPreviousPosX, mPreviousPosY;
	int mPositionX, mPositionY; //va virer pour le transform
	float mScaleFactor; //lui aussi
	//ajout pour un test
	bool mIsGoingLeft;
	bool mIsScaling;
};
