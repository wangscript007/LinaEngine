/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions 
and limitations under the License.

Class: ActionTest
Timestamp: 3/3/2019 1:51:34 PM

*/

#pragma once

#ifndef ActionTest_HPP
#define ActionTest_HPP

#include "Lina/Interfaces/IInputSubscriber.hpp"

namespace LinaEngine
{
	class ActionTest : public IInputSubscriber
	{
	public:

		ActionTest();
		~ActionTest() { std::cout << "Test object destructor!" << std::endl; };

		void SetAction();
		void TestParam(int i);
		void Test();
	};
}


#endif