#include "GraphicsCore.h"

GraphicsCore::GraphicsCore()
{
	mD3DWrapper = NULL;
	mCamera = NULL;
	mTextureShader = NULL;
	//	mDrawableComponents = NULL;
}

GraphicsCore::~GraphicsCore()
{

}

bool GraphicsCore::Init(int screenWidth, int screenHeight, HWND hwnd)
{
	// Create the Direct3D object.
	if (!(mD3DWrapper = new D3DWrapper))
	{
		return false;
	}

	// Init the Direct3D object.
	if (!(mD3DWrapper->Init(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR)))
	{
		MessageBox(hwnd, "Could not Init Direct3D.", "Error", MB_OK);
		return false;
	}

	
	// Create the camera object.
	mCamera = new Camera;
	if (!mCamera)
	{
		return false;
	}
	
	// Set the initial position of the camera.
	mCamera->SetPosition(0.0f, 0.0f, -10.0f);

	// Create the texture shader object.
	mTextureShader = new TextureShaderManager;
	if (!mTextureShader)
	{
		return false;
	}

	// Init the texture shader object.
	if (!(mTextureShader->Init(mD3DWrapper->GetDevice(), hwnd)))
	{
		MessageBox(hwnd, "Could not Init the texture shader object.", "Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsCore::Destroy()
{
	// Release the bitmap object.
	for (std::list<DrawableComponent*>::const_iterator iterator = mDrawableComponents.begin(); iterator != mDrawableComponents.end(); ++iterator)
	{
		(*iterator)->Destroy();
		//delete mDrawableComponent;
	}
	mDrawableComponents.clear();

	// Release the texture shader object.
	if (mTextureShader)
	{
		mTextureShader->Destroy();
		delete mTextureShader;
		mTextureShader = 0;
	}

	// Release the camera object.
	if (mCamera)
	{
		delete mCamera;
		mCamera = 0;
	}

	// Release the D3D object.
	if (mD3DWrapper)
	{
		mD3DWrapper->Destroy();
		delete mD3DWrapper;
		mD3DWrapper = 0;
	}

	return;
}

bool GraphicsCore::Update()
{
	bool result;
	static float rotation = 0.0f;


	// Update the rotation variable each Update.
	rotation += (float)D3DX_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsCore::Render(float rotation)
{
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;

	// Clear the buffers to begin the scene.
	mD3DWrapper->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	mCamera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	mCamera->GetViewMatrix(viewMatrix);
	mD3DWrapper->GetWorldMatrix(worldMatrix);
	mD3DWrapper->GetProjectionMatrix(projectionMatrix);
	mD3DWrapper->GetOrthoMatrix(orthoMatrix);

	// Turn off the Z buffer to begin all 2D rendering.
	mD3DWrapper->TurnZBufferOff();

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	for each (DrawableComponent* obj in mDrawableComponents)
	{
		
		if (!(obj->Render(mD3DWrapper->GetDevice())))
		{
			return false;
		}

		// Render the bitmap using the texture shader.
		mTextureShader->Render(mD3DWrapper->GetDevice(), obj->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, obj->GetTexture());
	}

	// Turn the Z buffer back on now that all 2D rendering has completed.
	mD3DWrapper->TurnZBufferOn();

	// Present the rendered scene to the screen.
	mD3DWrapper->EndScene();

	return true;
}

bool GraphicsCore::AddDrawableObject(DrawableComponent *obj)
{
	std::cout << "adding obj start" << std::endl;
	if (obj == NULL)
		return false;

	std::list<DrawableComponent*>::const_iterator iterator;
	iterator = mDrawableComponents.begin();

	while (iterator != mDrawableComponents.end() && (*iterator)->GetLayout() > obj->GetLayout())
	{
		++iterator;
	}

	if (iterator == mDrawableComponents.end())
	{
		mDrawableComponents.push_back(obj);
	}
	else
	{
		mDrawableComponents.insert(iterator, obj);
	}

	std::cout << "adding obj end" << std::endl;

	return true;
}