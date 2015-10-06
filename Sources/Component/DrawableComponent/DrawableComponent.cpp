#include "DrawableComponent.h"

DrawableComponent::DrawableComponent()
{
	mVertexBuffer = 0;
	mIndexBuffer = 0;
	mTexture = 0;
}


DrawableComponent::DrawableComponent(const DrawableComponent& other)
{
}


DrawableComponent::~DrawableComponent()
{
}


bool DrawableComponent::Init(ID3D10Device* device, int screenWidth, int screenHeight, char* textureFilename, int bitmapWidth, int bitmapHeight, int posYxple, Layout layout)
{
	bool result;


	// Store the screen size.
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;

	// Store the size in pixels that this bitmap should be rendered at.
	mBitmapWidth = bitmapWidth;
	mBitmapHeight = bitmapHeight;

	// Initialize the previous rendering position to negative one.
	mPreviousPosX = -1;
	mPreviousPosY = -1;

	mPositionX = 0;
	mPositionY = posYxple;

	mScaleFactor = 1;

	mLayout = layout;

	// Initialize the vertex and index buffer that hold the geometry for the triangle.
	result = InitBuffers(device);
	if (!result)
	{
		return false;
	}

	// Load the texture for this model.
	result = LoadTexture(device, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}


void DrawableComponent::Destroy()
{
	// Release the model texture.
	ReleaseTexture();

	// Release the vertex and index buffers.
	DestroyBuffers();

	return;
}


bool DrawableComponent::Render(ID3D10Device* device)
{
	bool result;


	// Re-build the dynamic vertex buffer for rendering to possibly a different location on the screen.
	result = UpdateBuffers();
	if (!result)
	{
		return false;
	}

	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(device);

	return true;
}


int DrawableComponent::GetIndexCount()
{
	return mIndexCount;
}


ID3D10ShaderResourceView* DrawableComponent::GetTexture()
{
	return mTexture->GetTexture();
}

Layout DrawableComponent::GetLayout()
{
	return mLayout;
}

bool DrawableComponent::InitBuffers(ID3D10Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D10_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D10_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;


	// Set the number of vertices in the vertex array.
	mVertexCount = 6;

	// Set the number of indices in the index array.
	mIndexCount = mVertexCount;

	// Create the vertex array.
	vertices = new VertexType[mVertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[mIndexCount];
	if (!indices)
	{
		return false;
	}

	// Initialize vertex array to zeros at first.
	memset(vertices, 0, (sizeof(VertexType)* mVertexCount));

	// Load the index array with data.
	for (i = 0; i < mIndexCount; i++)
	{
		indices[i] = i;
	}

	// Set up the description of the dynamic vertex buffer.
	vertexBufferDesc.Usage = D3D10_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType)* mVertexCount;
	vertexBufferDesc.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;

	// Now finally create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &mVertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the index buffer.
	indexBufferDesc.Usage = D3D10_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long)* mIndexCount;
	indexBufferDesc.BindFlags = D3D10_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &mIndexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}


void DrawableComponent::DestroyBuffers()
{
	// Release the index buffer.
	if (mIndexBuffer)
	{
		mIndexBuffer->Release();
		mIndexBuffer = 0;
	}

	// Release the vertex buffer.
	if (mVertexBuffer)
	{
		mVertexBuffer->Release();
		mVertexBuffer = 0;
	}

	return;
}


bool DrawableComponent::UpdateBuffers()
{
	float left, right, top, bottom;
	VertexType* vertices;
	void* verticesPtr;
	HRESULT result;


	/*// If the position we are rendering this bitmap to has not changed then don't update the vertex buffer since it
	// currently has the correct parameters.
	if((_positionX == m_previousPosX) && (_positionY == m_previousPosY))
	{
	return true;
	}

	// If it has changed then update the position it is being rendered to.
	m_previousPosX = _positionX;
	m_previousPosY = _positionY;*/

	//MovingExample();
	//ScaleExample();

	/*// Calculate the screen coordinates of the left side of the bitmap.
	left = (float)((m_screenWidth / 2) * -1) + (float)_positionX;

	// Calculate the screen coordinates of the right side of the bitmap.
	right = left + (float)m_bitmapWidth;

	// Calculate the screen coordinates of the top of the bitmap.
	top = (float)(m_screenHeight / 2) - (float)_positionY;

	// Calculate the screen coordinates of the bottom of the bitmap.
	bottom = top - (float)m_bitmapHeight;*/


	// Calculate the screen coordinates of the left side of the bitmap.
	left = (float)mPositionX - (float)((mBitmapWidth * mScaleFactor) / 2);

	// Calculate the screen coordinates of the right side of the bitmap.
	right = (float)mPositionX + (float)((mBitmapWidth * mScaleFactor) / 2);

	// Calculate the screen coordinates of the top of the bitmap.
	top = (float)mPositionY + (float)((mBitmapHeight * mScaleFactor) / 2);

	// Calculate the screen coordinates of the bottom of the bitmap.
	bottom = (float)mPositionY - (float)((mBitmapHeight * mScaleFactor) / 2);

	//std::cout << left << " - " << right << " - " << top << " - " << bottom;


	// Create the vertex array.
	vertices = new VertexType[mVertexCount];
	if (!vertices)
	{
		return false;
	}

	// Load the vertex array with data.
	// First triangle.
	vertices[0].position = D3DXVECTOR3(left, top, 0.0f);  // Top left.
	vertices[0].texture = D3DXVECTOR2(0.0f, 0.0f);

	vertices[1].position = D3DXVECTOR3(right, bottom, 0.0f);  // Bottom right.
	vertices[1].texture = D3DXVECTOR2(1.0f, 1.0f);

	vertices[2].position = D3DXVECTOR3(left, bottom, 0.0f);  // Bottom left.
	vertices[2].texture = D3DXVECTOR2(0.0f, 1.0f);

	// Second triangle.
	vertices[3].position = D3DXVECTOR3(left, top, 0.0f);  // Top left.
	vertices[3].texture = D3DXVECTOR2(0.0f, 0.0f);

	vertices[4].position = D3DXVECTOR3(right, top, 0.0f);  // Top right.
	vertices[4].texture = D3DXVECTOR2(1.0f, 0.0f);

	vertices[5].position = D3DXVECTOR3(right, bottom, 0.0f);  // Bottom right.
	vertices[5].texture = D3DXVECTOR2(1.0f, 1.0f);

	// Initialize the vertex buffer pointer to null first.
	verticesPtr = 0;

	// Lock the vertex buffer.
	result = mVertexBuffer->Map(D3D10_MAP_WRITE_DISCARD, 0, (void**)&verticesPtr);
	if (FAILED(result))
	{
		return false;
	}

	// Copy the data into the vertex buffer.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType)* mVertexCount));

	// Unlock the vertex buffer.
	mVertexBuffer->Unmap();

	// Release the vertex array as it is no longer needed.
	delete[] vertices;
	vertices = 0;

	return true;
}


void DrawableComponent::RenderBuffers(ID3D10Device* device)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	device->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	device->IASetIndexBuffer(mIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	device->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}


bool DrawableComponent::LoadTexture(ID3D10Device* device, char* filename)
{
	bool result;


	// Create the texture object.
	mTexture = new TextureHandler;
	if (!mTexture)
	{
		return false;
	}

	// Initialize the texture object.
	result = mTexture->Init(device, filename);
	if (!result)
	{
		return false;
	}

	return true;
}


void DrawableComponent::ReleaseTexture()
{
	// Release the texture object.
	if (mTexture)
	{
		mTexture->Destroy();
		delete mTexture;
		mTexture = 0;
	}

	return;
}

void DrawableComponent::MovingExample()
{
	if (mIsGoingLeft)
	{
		if (mPositionX > 300)
		{
			mIsGoingLeft = false;
		}
		else
			mPositionX += 2;
	}
	else if (!mIsGoingLeft)
	{
		if (mPositionX < -300)
		{
			mIsGoingLeft = true;
		}
		else
		{
			mPositionX -= 2;
		}
	}

}

void DrawableComponent::ScaleExample()
{
	if (mIsScaling)
	{
		if (mScaleFactor > 2)
		{
			mIsScaling = false;
		}
		else
			mScaleFactor += 0.02f;
	}
	else if (!mIsScaling)
	{
		if (mScaleFactor < 1)
		{
			mIsScaling = true;
		}
		else
			mScaleFactor -= 0.02f;
	}
}