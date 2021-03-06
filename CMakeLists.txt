#linaenginebuildlauncherentrypointv100

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Author: Inan Evin
# www.inanevin.com
# 
# Copyright (C) 2018 Inan Evin
# 
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions 
# and limitations under the License.
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.6)
project (Lina)


#--------------------------------------------------------------------
# Options & Definitions
#--------------------------------------------------------------------
#set(CMAKE_C_COMPILER /c/MinGW/bin/gcc.exe)
#set(CMAKE_CXX_COMPILER /c/MinGW/bin/g++.exe)

# option(LINA_BUILD_SANDBOX "Build Sandbox Application" ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_SUPPRESS_REGENERATION true)
#option(BUILD_SHARED_LIBS "Build Shared Libraries" ON)


option(LINA_SHARED_COMMON "Build Lina COMMON DLL" OFF)
option(LINA_SHARED_ECS "Build Lina ECS DLL" OFF)
option(LINA_SHARED_ACTION "Build Lina ACTION DLL" OFF)
option(LINA_SHARED_INPUT "Build Lina INPUT DLL" OFF)
option(LINA_SHARED_GRAPHICS "Build Lina GRAPHICS DLL" OFF)
option(LINA_SHARED_PHYSICS "Build Lina PHYSICS DLL" OFF)
option(LINA_SHARED_ENGINE "Build Lina ENGINE DLL" OFF)
option(x64_COMPILATION "Target Architecture x64" ON)

if(${x64_COMPILATION} MATCHES ON)
	set(TARGET_ARCHITECTURE "x64")
	
elseif(${x64_COMPILATION} MATCHES OFF)
	set(TARGET_ARCHITECTURE "Win32")
endif()


set(ASSIMP_LIB "assimp-vc142-mtd.lib")
set(ASSIMP_DLL "assimp-vc142-mtd.dll")


set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(LINA_GRAPHICS_OPENGL 1)

#--------------------------------------------------------------------
# Set source & header dirs
#--------------------------------------------------------------------
set(LINAENGINE_SOURCE_DIR LinaEngine/src)
set(LINAENGINE_HEADER_DIR LinaEngine/include)
set(LINAENGINE_VENDOR_DIR LinaEngine/vendor)
set(LINASANDBOX_SOURCE_DIR Sandbox/src)
set(LINASANDBOX_HEADER_DIR Sandbox/include)

#--------------------------------------------------------------------
# Sub directories
#--------------------------------------------------------------------



add_subdirectory(Sandbox)
add_subdirectory(LinaEditor)
add_subdirectory(LinaEngine)
add_subdirectory(LinaECS)
add_subdirectory(LinaGraphics)
add_subdirectory(LinaCommon)
add_subdirectory(LinaAction)
add_subdirectory(LinaInput)
add_subdirectory(LinaPhysics)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT LinaEditor)

