/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: GLInputDevice
Timestamp: 4/14/2019 5:15:15 PM

*/

#include "PackageManager/OpenGL/GLInputDevice.hpp"  
#include "Utility/Math/Math.hpp"
#include "GLFW/glfw3.h"
#include "Utility/Log.hpp"

namespace LinaEngine::Input
{

	static const float axisSensitivity = 0.1f;
	static const float mouseAxisSensitivity = 5.0f;
	GLFWwindow* glfwWindow;

	GLInputDevice::GLInputDevice()
	{
		LINA_CORE_TRACE("[Constructor] -> GLInputDevice ({0})", typeid(*this).name());
	}

	GLInputDevice::~GLInputDevice()
	{
		LINA_CORE_TRACE("[Destructor] -> GLInputDevice ({0})", typeid(*this).name());
	}

	void GLInputDevice::Initialize(void* contextWindowPointer)
	{
		LINA_CORE_TRACE("[Initialization] -> GLInputDevice ({0})", typeid(*this).name());
		glfwWindow = static_cast<GLFWwindow*>(contextWindowPointer);
	}

	void GLInputDevice::Tick()
	{
		glfwPollEvents();
	}

	bool GLInputDevice::GetKey(int keycode)
	{
		int state = glfwGetKey(glfwWindow, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GLInputDevice::GetKeyDown(int keyCode)
	{
		static int* oldState = new int[NUM_KEY_STATES];
		int newState = glfwGetKey(glfwWindow, keyCode);
		bool flag = (newState == GLFW_PRESS && oldState[keyCode] == GLFW_RELEASE) ? true : false;
		oldState[keyCode] = newState;
		return flag;
	}
	bool GLInputDevice::GetKeyUp(int keyCode)
	{
		static int* oldState = new int[NUM_KEY_STATES];
		int newState = glfwGetKey(glfwWindow, keyCode);
		bool flag = (newState == GLFW_RELEASE && oldState[keyCode] == GLFW_PRESS) ? true : false;
		oldState[keyCode] = newState;
		return flag;
	}
	bool GLInputDevice::GetMouseButton(int button)
	{
		int state = glfwGetMouseButton(glfwWindow, button);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool GLInputDevice::GetMouseButtonDown(int button)
	{
		static int* oldState = new int[NUM_MOUSE_STATES];
		int newState = glfwGetMouseButton(glfwWindow, button);
		bool flag = (newState == GLFW_PRESS && oldState[button] == GLFW_RELEASE) ? true : false;
		oldState[button] = newState;
		return flag;
	}
	bool GLInputDevice::GetMouseButtonUp(int button)
	{
		static int* oldState = new int[NUM_MOUSE_STATES];
		int newState = glfwGetMouseButton(glfwWindow, button);
		bool flag = (newState == GLFW_RELEASE && oldState[button] == GLFW_PRESS) ? true : false;
		oldState[button] = newState;
		return flag;
	}

	Vector2 GLInputDevice::GetRawMouseAxis()
	{
		// Storage for previous mouse position.
		static Vector2 oldMousePosition;

		// Get the cursor position.
		double posX, posY;
		glfwGetCursorPos(glfwWindow, &posX, &posY);

		// Get the delta mouse position.
		Vector2 currentMousePosition = Vector2((float)posX, (float)posY);
		Vector2 diff = currentMousePosition - oldMousePosition;
		Vector2 raw = Vector2::Zero;

		// Set raw axis values depending on the direction of the axis.
		if (diff.x > 0.0f) raw.x = 1.0f;
		else if (diff.x < 0.0f) raw.x = -1.0f;
		if (diff.y > 0) raw.y = 1.0f;
		else if (diff.y < 0) raw.y = -1.0f;

		// Set previous position.
		oldMousePosition = currentMousePosition;

		// Return raw.
		return raw;
	}

	Vector2 GLInputDevice::GetMouseAxis()
	{
		// Storage for previous mouse position.
		static Vector2 oldMousePos;

		// Get the cursor position.
		double posX, posY;
		glfwGetCursorPos(glfwWindow, &posX, &posY);

		// Get the delta mouse position.
		Vector2 diff = Vector2((float)(posX - oldMousePos.x), (float)(posY - oldMousePos.y));

	

		// Clamp and remap delta mouse position.
		diff.x = Math::Clamp(diff.x, -mouseAxisSensitivity, mouseAxisSensitivity);
		diff.y = Math::Clamp(diff.y, -mouseAxisSensitivity, mouseAxisSensitivity);
		diff.x = Math::Remap(diff.x, -mouseAxisSensitivity, mouseAxisSensitivity, -1.0f, 1.0f);
		diff.y = Math::Remap(diff.y, -mouseAxisSensitivity, mouseAxisSensitivity, -1.0f, 1.0f);
	
		// Set the previous position.
		oldMousePos = Vector2((float)posX, (float)posY);

		// Return delta.
		return diff;
	}

	Vector2 GLInputDevice::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(glfwWindow, &xpos, &ypos);
		return Vector2((float)xpos, (float)ypos);
	}


	void GLInputDevice::SetCursorMode(CursorMode mode) const
	{
		switch (mode)
		{
		case CursorMode::Visible:
			glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			break;

		case CursorMode::Hidden:
			glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			break;

		case CursorMode::Disabled:
			glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			break;
		}
	}

	void GLInputDevice::SetMousePosition(const Vector2 & v) const
	{
		glfwSetCursorPos(glfwWindow, v.x, v.y);
	}
}

