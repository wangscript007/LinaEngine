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

Class: PropertiesPanel
Timestamp: 6/7/2020 5:13:24 PM

*/
#pragma once

#ifndef PropertiesPanel_HPP
#define PropertiesPanel_HPP

#include "Panels/EditorPanel.hpp"
#include "Utility/EditorUtility.hpp"

namespace LinaEditor
{
	class PropertiesPanel : public EditorPanel
	{
		
	public:
		
		PropertiesPanel(Vector2 position, Vector2 size) : EditorPanel(position, size) {};
		virtual ~PropertiesPanel() {};
	
		virtual void Draw() override;
		void Setup();

	private:
	


	};
}

#endif