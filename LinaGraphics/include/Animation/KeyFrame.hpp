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

Class: KeyFrame
Timestamp: 6/2/2020 11:55:10 PM

*/
#pragma once

#ifndef KeyFrame_HPP
#define KeyFrame_HPP
#include "Joint.hpp"
#include "Utility/Math/Transformation.hpp"
#include <map>

namespace LinaEngine::Graphics
{
	class KeyFrame
	{
		
	public:
		
		KeyFrame() {};
		KeyFrame(float timeStamp, std::map<std::string, Transformation> jointKeyFrames) { m_TimeStamp = timeStamp; m_Pose = jointKeyFrames; }
		~KeyFrame() {};
	


		FORCEINLINE float GetTimeStamp() { return m_TimeStamp; }
		FORCEINLINE std::map<std::string, Transformation>& GetPose() { return m_Pose; }

	private:
	
		float m_TimeStamp;
		std::map<std::string, Transformation> m_Pose;
	};
}

#endif
