#include "TextureHandler.h"

#include <iostream>

TextureHandler::TextureHandler()
{
	mTexture = 0;
}

TextureHandler::~TextureHandler()
{
}


bool TextureHandler::Init(ID3D10Device* device, char* filename)
{
	HRESULT result;


	// Load the texture in.
	result = D3DX10CreateShaderResourceViewFromFile(device, filename, NULL, NULL, &mTexture, NULL);
	if (FAILED(result))
	{
		std::cout << result << std::endl;
		return false;
	}

	return true;
}


void TextureHandler::Destroy()
{
	// Release the texture resource.
	if (mTexture)
	{
		mTexture->Release();
		mTexture = 0;
	}

	return;
}


ID3D10ShaderResourceView* TextureHandler::GetTexture()
{
	return mTexture;
}