/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: Transformation
Timestamp: 4/9/2019 12:06:04 PM

*/

#include "Utility/Math/Transformation.hpp"  

namespace LinaEngine
{
	Transformation Transformation::Interpolate(Transformation& from, Transformation& to, float t)
	{
		return Transformation(Vector3::Lerp(from.location, to.location, t), Quaternion::Slerp(from.rotation, to.rotation, t), Vector3::Lerp(from.scale, to.scale, t));
	}
}

