/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: RenderingCommon.hpp
Timestamp: 4/14/2019 11:59:32 AM

*/

#ifndef RenderingCommon_HPP
#define RenderingCommon_HPP

#include "Core/SizeDefinitions.hpp"
#include <string>

namespace LinaEngine::Graphics
{
	enum BufferUsage
	{
		USAGE_STATIC_DRAW = LINA_GRAPHICS_USAGE_STATIC_DRAW,
		USAGE_STREAM_DRAW = LINA_GRAPHICS_USAGE_STREAM_DRAW,
		USAGE_DYNAMIC_DRAW = LINA_GRAPHICS_USAGE_DYNAMIC_DRAW,
		USAGE_STATIC_COPY = LINA_GRAPHICS_USAGE_STATIC_COPY,
		USAGE_STREAM_COPY = LINA_GRAPHICS_USAGE_STREAM_COPY,
		USAGE_DYNAMIC_COPY = LINA_GRAPHICS_USAGE_DYNAMIC_COPY,
		USAGE_STATIC_READ = LINA_GRAPHICS_USAGE_STATIC_READ,
		USAGE_STREAM_READ = LINA_GRAPHICS_USAGE_STREAM_READ,
		USAGE_DYNAMIC_READ = LINA_GRAPHICS_USAGE_DYNAMIC_READ,
	};

	enum BufferBit
	{
		BIT_COLOR = LINA_GRAPHICS_BUFFERBIT_COLOR,
		BIT_DEPTH = LINA_GRAPHICS_BUFFERBIT_DEPTH,
		BIT_STENCIL = LINA_GRAPHICS_BUFFERBIT_STENCIL
	};

	enum SamplerFilter
	{
		FILTER_NEAREST = LINA_GRAPHICS_SAMPLER_FILTER_NEAREST,
		FILTER_LINEAR = LINA_GRAPHICS_SAMPLER_FILTER_LINEAR,
		FILTER_NEAREST_MIPMAP_NEAREST = LINA_GRAPHICS_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST,
		FILTER_LINEAR_MIPMAP_NEAREST = LINA_GRAPHICS_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST,
		FILTER_NEAREST_MIPMAP_LINEAR = LINA_GRAPHICS_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR,
		FILTER_LINEAR_MIPMAP_LINEAR = LINA_GRAPHICS_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR,
	};

	enum SamplerWrapMode
	{
		WRAP_CLAMP_EDGE = LINA_GRAPHICS_SAMPLER_WRAP_CLAMP,
		WRAP_CLAMP_MIRROR = LINA_GRAPHICS_SAMPLER_WRAP_CLAMP_MIRROR,
		WRAP_CLAMP_BORDER = LINA_GRAPHICS_SAMPLER_WRAP_CLAMP_BORDER,
		WRAP_REPEAT = LINA_GRAPHICS_SAMPLER_WRAP_REPEAT,
		WRAP_REPEAT_MIRROR = LINA_GRAPHICS_SAMPLER_WRAP_REPEAT_MIRROR
	};

	enum TextureBindMode
	{
		BINDTEXTURE_NONE,
		BINDTEXTURE_TEXTURE,
		BINDTEXTURE_TEXTURE2D = LINA_GRAPHICS_BINDTEXTURE_TEXTURE2D,
		BINDTEXTURE_CUBEMAP = LINA_GRAPHICS_BINDTEXTURE_CUBEMAP,
		BINDTEXTURE_CUBEMAP_POSITIVE_X = LINA_GRAPHICS_BINDTEXTURE_CUBEMAP_POSITIVE_X,
		BINDTEXTURE_TEXTURE2D_MULTISAMPLE = LINA_GRAPHICS_BINDTEXTURE_TEXTURE2D_MULTISAMPLE
	};

	enum PixelFormat
	{
		FORMAT_R = 0,
		FORMAT_RG = 1,
		FORMAT_RGB = 2,
		FORMAT_RGBA = 3,
		FORMAT_RGB16F = 4,
		FORMAT_RGBA16F = 5,
		FORMAT_DEPTH = 6,
		FORMAT_DEPTH_AND_STENCIL = 7,
		FORMAT_SRGB = 8,
		FORMAT_SRGBA = 9
	};



	enum PrimitiveType
	{
		PRIMITIVE_TRIANGLES = LINA_GRAPHICS_PRIMITIVE_TRIANGLES,
		PRIMITIVE_POINTS = LINA_GRAPHICS_PRIMITIVE_POINTS,
		PRIMITIVE_LINE_STRIP = LINA_GRAPHICS_PRIMITIVE_LINE_STRIP,
		PRIMITIVE_LINE_LOOP = LINA_GRAPHICS_PRIMITIVE_LINE_LOOP,
		PRIMITIVE_LINES = LINA_GRAPHICS_PRIMITIVE_LINES,
		PRIMITIVE_LINE_STRIP_ADJACENCY = LINA_GRAPHICS_PRIMITIVE_LINE_STRIP_ADJACENCY,
		PRIMITIVE_LINES_ADJACENCY = LINA_GRAPHICS_PRIMITIVE_LINES_ADJACENCY,
		PRIMITIVE_TRIANGLE_STRIP = LINA_GRAPHICS_PRIMITIVE_TRIANGLE_STRIP,
		PRIMITIVE_TRIANGLE_FAN = LINA_GRAPHICS_PRIMITIVE_TRIANGLE_FAN,
		PRIMITIVE_TRAINGLE_STRIP_ADJACENCY = LINA_GRAPHICS_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY,
		PRIMITIVE_TRIANGLES_ADJACENCY = LINA_GRAPHICS_PRIMITIVE_TRIANGLES_ADJACENCY,
		PRIMITIVE_PATCHES = LINA_GRAPHICS_PRIMITIVE_PATCHES,
	};

	enum FaceCulling
	{
		FACE_CULL_NONE,
		FACE_CULL_BACK = LINA_GRAPHICS_FACE_CULL_BACK,
		FACE_CULL_FRONT = LINA_GRAPHICS_FACE_CULL_FRONT,
		FACE_CULL_FRONT_AND_BACK = LINA_GRAPHICS_FACE_CULL_FRONT_AND_BACK,
	};

	enum DrawFunc
	{
		DRAW_FUNC_NEVER = LINA_GRAPHICS_DRAW_FUNC_NEVER,
		DRAW_FUNC_ALWAYS = LINA_GRAPHICS_DRAW_FUNC_ALWAYS,
		DRAW_FUNC_LESS = LINA_GRAPHICS_DRAW_FUNC_LESS,
		DRAW_FUNC_GREATER = LINA_GRAPHICS_DRAW_FUNC_GREATER,
		DRAW_FUNC_LEQUAL = LINA_GRAPHICS_DRAW_FUNC_LEQUAL,
		DRAW_FUNC_GEQUAL = LINA_GRAPHICS_DRAW_FUNC_GEQUAL,
		DRAW_FUNC_EQUAL = LINA_GRAPHICS_DRAW_FUNC_EQUAL,
		DRAW_FUNC_NOT_EQUAL = LINA_GRAPHICS_DRAW_FUNC_NOT_EQUAL,
	};

	enum FrameBufferAttachment
	{
		ATTACHMENT_COLOR = LINA_GRAPHICS_ATTACHMENT_COLOR,
		ATTACHMENT_DEPTH = LINA_GRAPHICS_ATTACHMENT_DEPTH,
		ATTACHMENT_STENCIL = LINA_GRAPHICS_ATTACHMENT_STENCIL,
		ATTACHMENT_DEPTH_AND_STENCIL = LINA_GRAPHICS_ATTACHMENT_DEPTHANDSTENCIL,
	};


	enum RenderBufferStorage
	{
		STORAGE_DEPTH = LINA_GRAPHICS_STORAGE_D,
		STORAGE_DEPTH_COMP16 = LINA_GRAPHICS_STORAGE_DC16,
		STORAGE_DEPTH_COMP24 = LINA_GRAPHICS_sTORAGE_DC24,
		STORAGE_DEPTH_COMP32F = LINA_GRAPHICS_STORAGE_DC32F,
		STORAGE_DEPTH24_STENCIL8 = LINA_GRAPHICS_STORAGE_D24S8,
		STORAGE_DEPTH32F_STENCIL8 = LINA_GRAPHICS_STORAGE_D32FS8,
		STORAGE_STENCIL_INDEX8 = LINA_GRAPHICS_STORAGE_SI8
	};

	enum BlendFunc
	{
		BLEND_FUNC_NONE,
		BLEND_FUNC_ONE = LINA_GRAPHICS_BLEND_FUNC_ONE,
		BLEND_FUNC_SRC_ALPHA = LINA_GRAPHICS_BLEND_FUNC_SRC_ALPHA,
		BLEND_FUNC_ONE_MINUS_SRC_ALPHA = LINA_GRAPHICS_BLEND_FUNC_ONE_MINUS_SRC_ALPHA,
		BLEND_FUNC_ONE_MINUS_DST_ALPHA = LINA_GRAPHICS_BLEND_FUNC_ONE_MINUS_DST_ALPHA,
		BLEND_FUNC_DST_ALPHA = LINA_GRAPHICS_BLEND_FUNC_DST_ALPHA,
	};

	enum StencilOp
	{
		STENCIL_KEEP = LINA_GRAPHICS_STENCIL_KEEP,
		STENCIL_ZERO = LINA_GRAPHICS_STENCIL_ZERO,
		STENCIL_REPLACE = LINA_GRAPHICS_STENCIL_REPLACE,
		STENICL_INCR = LINA_GRAPHICS_STENCIL_INCR,
		STENCIL_INCR_WRAP = LINA_GRAPHICS_STENCIL_INCR_WRAP,
		STENCIL_DECR_WRAP = LINA_GRAPHICS_STENCIL_DECR_WRAP,
		STENCIL_DECR = LINA_GRAPHICS_STENCIL_DECR,
		STENCIL_INVERT = LINA_GRAPHICS_STENCIL_INVERT,
	};

	enum UniformType
	{
		UT_Matrix4,
		UT_Vector3,
		UT_Vector4,
		UT_Vector2,
		UT_Float,
		UT_Int
	};

	struct SamplerData
	{
		SamplerFilter minFilter = SamplerFilter::FILTER_NEAREST_MIPMAP_LINEAR;
		SamplerFilter maxFilter = SamplerFilter::FILTER_LINEAR;
		SamplerWrapMode wrapS = SamplerWrapMode::WRAP_CLAMP_EDGE;
		SamplerWrapMode wrapT = SamplerWrapMode::WRAP_CLAMP_EDGE;
		float anisotropy = 0.0f;
	};

	struct DrawParams
	{
		PrimitiveType primitiveType = PRIMITIVE_TRIANGLES;
		FaceCulling faceCulling = FACE_CULL_NONE;
		DrawFunc depthFunc = DRAW_FUNC_ALWAYS;
		DrawFunc stencilFunc = DRAW_FUNC_ALWAYS;
		StencilOp stencilFail = STENCIL_KEEP;
		StencilOp stencilPassButDepthFail = STENCIL_KEEP;
		StencilOp stencilPass = STENCIL_REPLACE;
		BlendFunc sourceBlend = BLEND_FUNC_NONE;
		BlendFunc destBlend = BLEND_FUNC_NONE;
		bool shouldWriteDepth = true;
		bool useDepthTest = true;
		bool useStencilTest = false;
		bool useScissorTest = false;
		uint32 scissorStartX = 0;
		uint32 scissorStartY = 0;
		uint32 scissorWidth = 0;
		uint32 scissorHeight = 0;
		uint32 stencilTestMask = 0;
		uint32 stencilWriteMask = 0;
		int32 stencilComparisonVal = 0;
	};

	enum Shaders
	{
		STANDARD_UNLIT = 11,
		SKYBOX_SINGLECOLOR = 20,
		SKYBOX_GRADIENT = 21,
		SKYBOX_CUBEMAP = 22,
		SKYBOX_PROCEDURAL = 23,
		SKYBOX_HDRI = 24,
		PBR_LIT = 90,
		EQUIRECTANGULAR_HDRI = 100,
		IRRADIANCE_HDRI = 101,
		PREFILTER_HDRI = 102,
		BRDF_HDRI = 103,
		SCREEN_QUAD_FINAL = 110,
		SCREEN_QUAD_BLUR = 111,
		SCREEN_QUAD_OUTLINE = 112
	};

	struct RenderingDebugData
	{
		bool visualizeDepth;
	};


	enum MaterialSurfaceType
	{
		Opaque = 0,
		Transparent = 1
	};

	enum Primitives
	{
		PLANE = 0,
		CUBE = 1,
		SPHERE = 2,
		ICOSPHERE = 3,
		CONE = 4,
		CYLINDER = 5
	};

	struct MeshParameters
	{
		bool triangulate = true;
		bool smoothNormals = true;
		bool calculateTangentSpace = true;
	};

	struct TextureParameters
	{
		PixelFormat pixelFormat = PixelFormat::FORMAT_RGBA;
		PixelFormat internalPixelFormat = PixelFormat::FORMAT_RGBA;
		SamplerFilter minFilter = SamplerFilter::FILTER_LINEAR_MIPMAP_LINEAR;
		SamplerFilter magFilter = SamplerFilter::FILTER_LINEAR;
		SamplerWrapMode wrapS = SamplerWrapMode::WRAP_CLAMP_EDGE;
		SamplerWrapMode wrapT = SamplerWrapMode::WRAP_CLAMP_EDGE;
		SamplerWrapMode wrapR = SamplerWrapMode::WRAP_CLAMP_EDGE;
		bool generateMipMaps = false;
	};

	struct SamplerParameters
	{
		TextureParameters textureParams;
		int anisotropy = 0.0f;
	};

	/* Struct containing basic data about window properties. */
	struct WindowProperties
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;
		bool vSyncEnabled;

		WindowProperties()
		{
			m_Title = "Lina Engine";
			m_Width = 1440;
			m_Height = 900;
		}

		WindowProperties(const std::string& title, unsigned int width, unsigned int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
		}
	};


}


#endif