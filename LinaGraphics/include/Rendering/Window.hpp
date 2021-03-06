/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: Window
Timestamp: 4/14/2019 7:46:12 PM

*/

#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP


#include "PackageManager/PAMWindow.hpp"
#include "Utility/Log.hpp"


namespace LinaEngine::Graphics
{
	class Window
	{
	public:

		FORCEINLINE Window()
		{
			LINA_CORE_TRACE("[Constructor] -> Window ({0})", typeid(*this).name());
		}

		virtual ~Window()
		{
			LINA_CORE_TRACE("[Destructor] -> Window ({0})", typeid(*this).name());
		};

		// Initializes the window.
		FORCEINLINE bool Initialize() { return m_Derived.Initialize(m_Properties); }

		// Enables/disables vsync.
		FORCEINLINE void SetVsync(bool enabled) { m_Properties.vSyncEnabled = enabled; m_Derived.SetVsync(enabled); }

		// Get vsync state.
		FORCEINLINE bool GetVsycnEnabled() { return m_Properties.vSyncEnabled; }

		// Get window width.
		FORCEINLINE uint32 GetWidth() { return m_Properties.m_Width; }

		// Get window height.
		FORCEINLINE uint32 GetHeight() { return m_Properties.m_Height; }

		// Get pointer to native window.
		FORCEINLINE void* GetNativeWindow() const { return m_Derived.GetNativeWindow(); }

		// Called every frame.
		FORCEINLINE void Tick() { m_Derived.Tick(); }

		// Gets size
		FORCEINLINE Vector2 GetSize() { return Vector2(m_Properties.m_Width, m_Properties.m_Height); }

		// Set event callbacks.
		FORCEINLINE void SetKeyCallback(std::function<void(int, int)>& cb) { m_Derived.SetKeyCallback(cb); }
		FORCEINLINE void SetMouseCallback(std::function<void(int, int)>& cb) { m_Derived.SetMouseCallback(cb); }
		FORCEINLINE void SetWindowResizeCallback(std::function<void(Vector2)>& cb) { m_Derived.SetWindowResizeCallback(cb); };
		FORCEINLINE void SetWindowClosedCallback(std::function<void()>& cb) { m_Derived.SetWindowClosedCallback(cb); };
	private:

		WindowProperties m_Properties;
		ContextWindow m_Derived;
	};
}

#endif