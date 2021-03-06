/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: Time
Timestamp: 4/28/2019 3:10:03 PM

*/

#pragma once

#ifndef Time_HPP
#define Time_HPP

#include "Core/SizeDefinitions.hpp"

namespace LinaEngine
{
	class Time
	{
		// Get elapsed time since the start of the application.
		static double GetTime();

		// Make the application thread sleep for designated amount of milliseconds.
		static void Sleep(uint32 milliSeconds);

		// Get elapesed time in nanoseconds.
		static double GetCurrentTimeNanoseconds();

		// Get elapsed time in milliseconds.
		static double GetCurrentTimeMilliseconds();
	};
}


#endif