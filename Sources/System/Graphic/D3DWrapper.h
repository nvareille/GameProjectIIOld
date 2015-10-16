#pragma once

#pragma comment(lib, "d3d10.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "dxgi.lib")

#include <d3d10.h>
#include <d3dx10.h>

class D3DWrapper
{
public:
	D3DWrapper();
	D3DWrapper(const D3DWrapper&);
	~D3DWrapper();

	bool Init(int, int, bool, HWND, bool, float, float);
	void Destroy();

	void BeginScene(float, float, float, float);
	void EndScene();

	ID3D10Device* GetDevice();

	void GetProjectionMatrix(D3DXMATRIX&);
	void GetWorldMatrix(D3DXMATRIX&);
	void GetOrthoMatrix(D3DXMATRIX&);

	void GetVideoCardInfo(char*, int&);

	void TurnZBufferOn();
	void TurnZBufferOff();

private:
	bool mVsyncEnabled;
	int mVideoCardMemory;
	char mVideoCardDescription[128];
	IDXGISwapChain* mSwapChain;
	ID3D10Device* mDevice;
	ID3D10RenderTargetView* mRenderTargetView;
	ID3D10Texture2D* mDepthStencilBuffer;
	ID3D10DepthStencilState* mDepthStencilState;
	ID3D10DepthStencilView* mDepthStencilView;
	ID3D10RasterizerState* mRasterState;
	D3DXMATRIX mProjectionMatrix;
	D3DXMATRIX mWorldMatrix;
	D3DXMATRIX mOrthoMatrix;
	ID3D10DepthStencilState* mDepthDisabledStencilState;
};
