#pragma once

#include <d3d10.h>
#include <d3dx10math.h>
#include <fstream>

using namespace std;

class TextureShaderManager
{
public:
	TextureShaderManager();
	TextureShaderManager(const TextureShaderManager&);
	~TextureShaderManager();

	bool Init(ID3D10Device*, HWND);
	void Destroy();
	void Render(ID3D10Device*, int, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D10ShaderResourceView*);

private:
	bool InitShader(ID3D10Device*, HWND, char*);
	void DestroyShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, char*);

	void SetShaderParameters(D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D10ShaderResourceView*);
	void RenderShader(ID3D10Device*, int);

private:
	ID3D10Effect* mEffect;
	ID3D10EffectTechnique* mTechnique;
	ID3D10InputLayout* mLayout;

	ID3D10EffectMatrixVariable* mWorldMatrixPtr;
	ID3D10EffectMatrixVariable* mViewMatrixPtr;
	ID3D10EffectMatrixVariable* mProjectionMatrixPtr;
	ID3D10EffectShaderResourceVariable* mTexturePtr;
};
