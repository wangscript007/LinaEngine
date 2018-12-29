/*
Author: Inan Evin
www.inanevin.com

MIT License

Lina Engine, Copyright (c) 2018 Inan Evin

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

4.0.30319.42000
9/30/2018 4:59:52 PM

*/

#include "pch.h"
#include "Rendering/Lina_RenderingEngine.hpp"  
#include "Rendering/Shaders/Lina_BasicShader.hpp"
#include "Rendering/Shaders/Lina_ForwardAmbientLightShader.hpp"
#include "Rendering/Shaders/Lina_ForwardDirectionalLightShader.hpp"
#include "Rendering/Shaders/Lina_ForwardPointLightShader.hpp"
#include "Rendering/Shaders/Lina_ForwardSpotLightShader.hpp"
#include "Scene/Lina_Camera.hpp"
#include "Game/Lina_GameCore.hpp"

Lina_RenderingEngine::Lina_RenderingEngine()
{
	ambientLight = Vector3(0.4f, 0.4f, 0.4f);
}	


// Destructor.
Lina_RenderingEngine::~Lina_RenderingEngine()
{
	Lina_Console cons = Lina_Console();
	cons.AddConsoleMsg("Rendering deinitialized.", Lina_Console::MsgType::Deinitialization, "Render Engine");

	delete m_GameWindow;
	delete basicShader;
	delete forwardAmbientShader;
	// BELOW ARE CONVERTED TO SINGLETONS SO NO NEED TO DELETE NOW //
	//delete forwardDirectionalShader;
	//delete forwardPointShader;
	//delete forwardSpotShader;

}

void Lina_RenderingEngine::CreateDisplayWindow()
{
	// Initialize display.
	m_GameWindow = new Lina_Window(screenWidth, screenHeight, screenTitle);
}

// Init rendering engine.
void Lina_RenderingEngine::Initialize(Lina_GameCore* g) 
{
	// Add a console message.
	Lina_Console cons = Lina_Console();
	cons.AddConsoleMsg("Rendering engine initialized.", Lina_Console::MsgType::Initialization, "Render Engine");

	// Assign game.
	game = g;

	// Initialize event handler.
	eventHandler.Initialize();
	
	// Register window events.
	eventHandler.SubscribeToAction(ActionType::SDLQuit, [this]() { m_GameWindow->CloseWindow(); });

	// Create a window.
	CreateDisplayWindow();

	// Clear colors.
	ClearColors(0.0, 0.0, 0.0, 1.0);

	// Enable Textures
	SetTextures(true);

	// Every face in clock-wise order is front.
	glFrontFace(GL_CW);

	// Get rid of the back face.
	glCullFace(GL_BACK);

	// Enable culling faces for now to prevent extra faces.
	glEnable(GL_CULL_FACE);

	// Enable depth test -> enable Z draw-order.
	glEnable(GL_DEPTH_TEST);

	// depth clamp
	glEnable(GL_DEPTH_CLAMP);

	// Init shaders
	InitializeShaders();

}

void Lina_RenderingEngine::InitializeShaders()
{

	basicShader = new Lina_BasicShader();
	forwardAmbientShader = new Lina_ForwardAmbientLightShader();
	forwardDirectionalShader = &Lina_ForwardDirectionalLightShader::Instance();
	forwardPointShader = &Lina_ForwardPointLightShader::Instance();
	forwardSpotShader = &Lina_ForwardSpotLightShader::Instance();

	basicShader->SetRenderingEngine(this);
	forwardAmbientShader->SetRenderingEngine(this);
	forwardDirectionalShader->SetRenderingEngine(this);
	forwardPointShader->SetRenderingEngine(this);
	forwardSpotShader->SetRenderingEngine(this);

	basicShader->Init();
	forwardAmbientShader->Init();
	forwardDirectionalShader->Init();
	forwardPointShader->Init();
	forwardSpotShader->Init();

}

void Lina_RenderingEngine::ClearScreen()
{
	// Clear color & depth buffers.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// Main method to render.
void Lina_RenderingEngine::Render()
{

	// Clar screen.
	ClearScreen();

	// Render the ambient lighting first.
	game->Render(forwardAmbientShader);

	// Enable color blending.
	glEnable(GL_BLEND);

	// Existing color * 1 + new color * 1
	glBlendFunc(GL_ONE, GL_ONE);

	// Disable depth buffer while adding more color, because objects are the same and no need to write it to the buffer.
	glDepthMask(false);

	// Only try adding on new pixels if they have the exact same depth.
	// (Only do lighting for pixels that make it into the final image)
	glDepthFunc(GL_EQUAL);

	// Render in multiple passes, for every light.
	for (std::vector<const Lina_BaseLight*>::iterator it = currentLights.begin(); it != currentLights.end(); ++it)
	{
		activeLight = (*it);
		game->Render(activeLight->GetShader());
	}

	// Set depth calculations back.
	glDepthFunc(GL_LESS);

	// Enable depth buffer.
	glDepthMask(true);

	// Disable color blending.
	glDisable(GL_BLEND);
	
	// Call swap buffers on active window.
	m_GameWindow->Update();
}

void Lina_RenderingEngine::CleanUp()
{
	Lina_Console cons = Lina_Console();
	cons.AddConsoleMsg("Cleaning up rendering engine...", Lina_Console::MsgType::Deinitialization, "Render Engine");
	ClearLights();
}

void Lina_RenderingEngine::SetTextures(bool enabled)
{
	if (enabled)
		glEnable(GL_TEXTURE_2D);
	else
		glDisable(GL_TEXTURE_2D);
}

void Lina_RenderingEngine::ClearColors(float r, float g, float b, float a)
{
	// Clear color.
	glClearColor(r,g,b,a);
}

void Lina_RenderingEngine::ClearLights()
{
	// Light components will already be deallocated from the memory by the actors that hold them.

	/*for (std::vector<const Lina_BaseLight*>::iterator it = currentLights.begin(); it != currentLights.end(); ++it) 
	{
		delete *it;
	}
	*/
	currentLights.clear();
}


Lina_Vector3F& Lina_RenderingEngine::GetAmbientLight()
{
	return ambientLight;
}
