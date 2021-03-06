#pragma once

#include <d3d10.h>
#include <d3dx10.h>

class TextureHandler
{
public:
	TextureHandler();
	~TextureHandler();

	bool Init(ID3D10Device*, char*);
	void Destroy();

	ID3D10ShaderResourceView* GetTexture();

private:
	ID3D10ShaderResourceView* mTexture;
};
