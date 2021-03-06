/*
Author: Inan Evin
www.inanevin.com
https://github.com/inanevin/LinaEngine

Copyright 2020~ Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: EditorPanel
Timestamp: 5/23/2020 4:16:05 PM

*/
#pragma once

#ifndef EditorPanel_HPP
#define EditorPanel_HPP

// Headers here.
#include "Utility/Math/Vector.hpp"

namespace LinaEditor
{
	using namespace LinaEngine;

	class EditorPanel
	{

	public:
		
		EditorPanel(Vector2 position, Vector2 size, class GUILayer& guiLayer) : m_Position(position), m_Size(size), m_GUILayer(&guiLayer) { };
		virtual ~EditorPanel() {};
	
		virtual FORCEINLINE void Open() { m_Show = true; }
		virtual FORCEINLINE void Close() { m_Show = false; }
		virtual void Draw() = 0;
		virtual void Setup() = 0;
		FORCEINLINE bool* GetShow() { return &m_Show; }

	protected:

		Vector2 m_Position;
		Vector2 m_Size;
		bool m_Show = false;
		class GUILayer* m_GUILayer;
	};
}

#endif
