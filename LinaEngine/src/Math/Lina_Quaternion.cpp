/*
Author: Inan Evin
www.inanevin.com

MIT License

Lina Engine, Copyright (c) 2018 Inan Evin

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

4.0.30319.42000
10/17/2018 9:01:26 PM

*/

#include "pch.h"
#include "Math/Lina_Quaternion.hpp"  
#include "Math/Lina_Matrix.hpp"
#include "Math/Lina_Math.hpp"


Lina_Quaternion::Lina_Quaternion(const Vector3 & axis, float angle)
{
	angle = Lina_Math::ToRadians(angle);
	float sinHalfAngle = sinf(angle / 2);
	float cosHalfAngle = cosf(angle / 2);
	x = axis.x * sinHalfAngle;
	y = axis.y * sinHalfAngle;
	z = axis.z * sinHalfAngle;
	w = cosHalfAngle;
}

Lina_Quaternion::Lina_Quaternion(const Lina_Matrix4F & m)
{

	float trace = m[0][0] + m[1][1] + m[2][2];

	if (trace > 0)
	{
		float s = 0.5f / sqrtf(trace + 1.0f);
		w = 0.25f / s;
		x = (m[1][2] - m[2][1]) * s;
		y = (m[2][0] - m[0][2]) * s;
		z = (m[0][1] - m[1][0]) * s;
	}
	else if (m[0][0] > m[1][1] && m[0][0] > m[2][2])
	{
		float s = 2.0f * sqrtf(1.0f + m[0][0] - m[1][1] - m[2][2]);
		w = (m[1][2] - m[2][1]) / s;
		x = 0.25f * s;
		y = (m[1][0] + m[0][1]) / s;
		z = (m[2][0] + m[0][2]) / s;
	}
	else if (m[1][1] > m[2][2])
	{
		float s = 2.0f * sqrtf(1.0f + m[1][1] - m[0][0] - m[2][2]);
		w = (m[2][0] - m[0][2]) / s;
		x = (m[1][0] + m[0][1]) / s;
		y = 0.25f * s;
		z = (m[2][1] + m[1][2]) / s;
	}
	else
	{
		float s = 2.0f * sqrtf(1.0f + m[2][2] - m[1][1] - m[0][0]);
		w = (m[0][1] - m[1][0]) / s;
		x = (m[2][0] + m[0][2]) / s;
		y = (m[1][2] + m[2][1]) / s;
		z = 0.25f * s;
	}

	float length = Magnitude();
	w /= length;
	x /= length;
	y /= length;
	z /= length;
}

Lina_Quaternion Lina_Quaternion::NLerp(const Lina_Quaternion & r, float lerpFactor, bool shortestPath) const
{
	Lina_Quaternion correctedDest;

	if (shortestPath && this->Dot(r) < 0)
		correctedDest = r * -1;
	else
		correctedDest = r;
	
	return Lina_Quaternion(Lerp(correctedDest, lerpFactor).Normalized());
}

Lina_Quaternion Lina_Quaternion::SLerp(const Lina_Quaternion & r, float lerpFactor, bool shortestPath) const
{
	static const float EPSILON = 1e3;

	float cos = this->Dot(r);
	Lina_Quaternion correctedDest;

	if (shortestPath && cos < 0)
	{
		cos *= -1;
		correctedDest = r * -1;
	}
	else
		correctedDest = r;

	if (fabs(cos) > (1 - EPSILON))
		return NLerp(correctedDest, lerpFactor, false);

	float sin = (float)sqrtf(1.0f - cos * cos);
	float angle = atan2(sin, cos);
	float invSin = 1.0f / sin;

	float srcFactor = sinf((1.0f - lerpFactor) * angle) * invSin;
	float destFactor = sinf((lerpFactor)* angle) * invSin;

	return Lina_Quaternion((*this) * srcFactor + correctedDest * destFactor);
}

Lina_Matrix4F Lina_Quaternion::ToRotationMatrix() const
{
	Lina_Vector3F forward = Lina_Vector3F(2.0f * (x * z - w * y), 2.0f * (y * z + w * x), 1.0f - 2.0f * (x * x + y * y));
	Lina_Vector3F up = Lina_Vector3F(2.0f * (x*y + w*z), 1.0f - 2.0f * (x*x + z*z), 2.0f * (y*z - w*x));
	Lina_Vector3F right = Lina_Vector3F(1.0f - 2.0f * (y*y + z*z), 2.0f * (x*y - w*z), 2.0f * (x*z + w*y));

	return Lina_Matrix4F().InitRotationFromVectors(forward, up, right);
}

