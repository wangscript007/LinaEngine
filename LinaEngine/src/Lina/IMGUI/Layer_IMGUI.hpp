/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: Layer_IMGUI
Timestamp: 3/7/2019 1:58:49 PM

*/

#pragma once

#ifndef Layer_IMGUI_HPP
#define Layer_IMGUI_HPP

#include "Lina/Layer.hpp"

namespace LinaEngine
{
	class LINA_API Layer_IMGUI : public Layer
	{

	public:

		Layer_IMGUI();
		~Layer_IMGUI();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:

		float m_Time = 0.0f;
	};
}


#endif