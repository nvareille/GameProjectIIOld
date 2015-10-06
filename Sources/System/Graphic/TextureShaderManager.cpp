#include "TextureShaderManager.h"


TextureShaderManager::TextureShaderManager()
{
	mEffect = 0;
	mTechnique = 0;
	mLayout = 0;

	mWorldMatrixPtr = 0;
	mViewMatrixPtr = 0;
	mProjectionMatrixPtr = 0;
	mTexturePtr = 0;
}


TextureShaderManager::TextureShaderManager(const TextureShaderManager& other)
{
}


TextureShaderManager::~TextureShaderManager()
{
}


bool TextureShaderManager::Init(ID3D10Device* device, HWND hwnd)
{
	bool result;


	// Initialize the shader that will be used to draw the triangle.
	result = InitShader(device, hwnd, "../GraphEngine/texture.fx");
	if (!result)
	{
		return false;
	}

	return true;
}


void TextureShaderManager::Destroy()
{
	// Shutdown the shader effect.
	DestroyShader();

	return;
}


void TextureShaderManager::Render(ID3D10Device* device, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,
	ID3D10ShaderResourceView* texture)
{
	// Set the shader parameters that it will use for rendering.
	SetShaderParameters(worldMatrix, viewMatrix, projectionMatrix, texture);

	// Now render the prepared buffers with the shader.
	RenderShader(device, indexCount);

	return;
}


bool TextureShaderManager::InitShader(ID3D10Device* device, HWND hwnd, char* filename)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	D3D10_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D10_PASS_DESC passDesc;


	// Initialize the error message.
	errorMessage = 0;

	// Load the shader in from the file.
	result = D3DX10CreateEffectFromFile(filename, NULL, NULL, "fx_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0,
		device, NULL, NULL, &mEffect, &errorMessage, NULL);
	if (FAILED(result))
	{
		// If the shader failed to compile it should have writen something to the error message.
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, filename);
		}
		// If there was  nothing in the error message then it simply could not find the shader file itself.
		else
		{
			MessageBox(hwnd, filename, "Missing Shader File", MB_OK);
		}

		return false;
	}

	// Get a pointer to the technique inside the shader.
	mTechnique = mEffect->GetTechniqueByName("TextureTechnique");
	if (!mTechnique)
	{
		return false;
	}

	// Now setup the layout of the data that goes into the shader.
	// This setup needs to match the VertexType stucture in the ModelClass and in the shader.
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D10_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "TEXCOORD";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D10_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D10_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	// Get a count of the elements in the layout.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	// Get the description of the first pass described in the shader technique.
	mTechnique->GetPassByIndex(0)->GetDesc(&passDesc);

	// Create the input layout.
	result = device->CreateInputLayout(polygonLayout, numElements, passDesc.pIAInputSignature, passDesc.IAInputSignatureSize, &mLayout);
	if (FAILED(result))
	{
		return false;
	}

	// Get pointers to the three matrices inside the shader so we can update them from this class.
	mWorldMatrixPtr = mEffect->GetVariableByName("worldMatrix")->AsMatrix();
	mViewMatrixPtr = mEffect->GetVariableByName("viewMatrix")->AsMatrix();
	mProjectionMatrixPtr = mEffect->GetVariableByName("projectionMatrix")->AsMatrix();

	// Get pointer to the texture resource inside the shader.
	mTexturePtr = mEffect->GetVariableByName("shaderTexture")->AsShaderResource();

	return true;
}


void TextureShaderManager::DestroyShader()
{
	// Release the pointer to the texture in the shader file.
	mTexturePtr = 0;

	// Release the pointers to the matrices inside the shader.
	mWorldMatrixPtr = 0;
	mViewMatrixPtr = 0;
	mProjectionMatrixPtr = 0;

	// Release the pointer to the shader layout.
	if (mLayout)
	{
		mLayout->Release();
		mLayout = 0;
	}

	// Release the pointer to the shader technique.
	mTechnique = 0;

	// Release the pointer to the shader.
	if (mEffect)
	{
		mEffect->Release();
		mEffect = 0;
	}

	return;
}


void TextureShaderManager::OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, char* shaderFilename)
{
	char* compileErrors;
	unsigned long bufferSize, i;
	ofstream fout;


	// Get a pointer to the error message text buffer.
	compileErrors = (char*)(errorMessage->GetBufferPointer());

	// Get the length of the message.
	bufferSize = errorMessage->GetBufferSize();

	// Open a file to write the error message to.
	fout.open("shader-error.txt");

	// Write out the error message.
	for (i = 0; i<bufferSize; i++)
	{
		fout << compileErrors[i];
	}

	// Close the file.
	fout.close();

	// Release the error message.
	errorMessage->Release();
	errorMessage = 0;

	// Pop a message up on the screen to notify the user to check the text file for compile errors.
	MessageBox(hwnd, "Error compiling shader.  Check shader-error.txt for message.", shaderFilename, MB_OK);

	return;
}


void TextureShaderManager::SetShaderParameters(D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,
	ID3D10ShaderResourceView* texture)
{
	// Set the world matrix variable inside the shader.
	mWorldMatrixPtr->SetMatrix((float*)&worldMatrix);

	// Set the view matrix variable inside the shader.
	mViewMatrixPtr->SetMatrix((float*)&viewMatrix);

	// Set the projection matrix variable inside the shader.
	mProjectionMatrixPtr->SetMatrix((float*)&projectionMatrix);

	// Bind the texture.
	mTexturePtr->SetResource(texture);

	return;
}


void TextureShaderManager::RenderShader(ID3D10Device* device, int indexCount)
{
	D3D10_TECHNIQUE_DESC techniqueDesc;
	unsigned int i;


	// Set the input layout.
	device->IASetInputLayout(mLayout);

	// Get the description structure of the technique from inside the shader so it can be used for rendering.
	mTechnique->GetDesc(&techniqueDesc);

	// Go through each pass in the technique (should be just one currently) and render the triangles.
	for (i = 0; i < techniqueDesc.Passes; ++i)
	{
		mTechnique->GetPassByIndex(i)->Apply(0);
		device->DrawIndexed(indexCount, 0, 0);
	}

	return;
}