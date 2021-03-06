/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions 
and limitations under the License.

Class: FreeLookSystem
Timestamp: 5/2/2019 2:21:35 AM

*/

#pragma once

#ifndef FreeLookSystem_HPP
#define FreeLookSystem_HPP

#include "ECS/ECSSystem.hpp"


namespace LinaEngine::Input
{
	class InputEngine;
}

namespace LinaEngine::ECS
{
	class FreeLookSystem : public BaseECSSystem
	{
	public:

		FORCEINLINE void Construct(ECSRegistry& registry, LinaEngine::Input::InputEngine& inputEngineIn)
		{
			BaseECSSystem::Construct(registry);
			inputEngine = &inputEngineIn;
		}

		virtual void UpdateComponents(float delta) override;

	private:

		LinaEngine::Input::InputEngine* inputEngine;
		float horizontalKeyAmount = 0.0f;
		float verticalKeyAmount = 0.0f;
	};
}


#endif