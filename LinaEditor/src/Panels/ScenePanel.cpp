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

Class: ScenePanel
Timestamp: 6/5/2020 6:51:39 PM

*/


#include "Panels/ScenePanel.hpp"
#include "Core/GUILayer.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include <imgui/imguizmo/ImGuizmo.h>
#include "Input/InputMappings.hpp"
#include "Rendering/RenderEngine.hpp"
#include "ECS/Components/CameraComponent.hpp"

static ImGuizmo::OPERATION currentTransformGizmoOP = ImGuizmo::OPERATION::TRANSLATE;
static ImGuizmo::MODE currentTransformGizmoMode = ImGuizmo::MODE::WORLD;
static Matrix gridLineMatrix = Matrix::Identity();
static ImVec2 previousWindowSize;
#define GRID_SIZE 1000

namespace LinaEditor
{

	void ScenePanel::Draw()
	{
		ImGuizmo::BeginFrame();



		if (m_Show)
		{
			// Set window properties.
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImVec2 work_area_pos = viewport->GetWorkPos();
			ImVec2 panelSize = ImVec2(m_Size.x, m_Size.y);
			ImGui::SetNextWindowSize(panelSize, ImGuiCond_FirstUseEver);
			ImGui::SetNextWindowBgAlpha(1.0f);
			ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse;

			if (ImGui::Begin("Scene", &m_Show, flags))
			{
				Vector2 drawSize = m_RenderEngine->GetMainWindow().GetSize();
				float currentWindowX = ImGui::GetCurrentWindow()->Size.x;
				float currentWindowY = ImGui::GetCurrentWindow()->Size.y;
				float aspect = (float)drawSize.x / (float)drawSize.y;
				float desiredH = currentWindowX / aspect;

				ImVec2 pMin = ImVec2(ImGui::GetCursorScreenPos().x, ImGui::GetCursorScreenPos().y);
				ImVec2 pMax = ImVec2(ImGui::GetCursorScreenPos().x + currentWindowX, ImGui::GetCursorScreenPos().y + currentWindowY);
				ImVec2 size = ImGui::GetCurrentWindow()->Size;

				// Resize scene panel.
				if ((size.x != previousWindowSize.x || size.y != previousWindowSize.y))
				{
					m_RenderEngine->OnWindowResized((uint32)ImGui::GetCurrentWindow()->Size.x, (uint32)ImGui::GetCurrentWindow()->Size.y);
					previousWindowSize = size;
				}
				
				ImGui::GetWindowDrawList()->AddImage((void*)m_RenderEngine->GetFinalImage(), pMin, pMax, ImVec2(0, 1), ImVec2(1, 0));

				// Handle inputs.
				ProcessInput();

				ImGuiIO& io = ImGui::GetIO();
				ImGuizmo::Enable(true);
				ImGuizmo::SetOrthographic(false);
				ImGuizmo::SetDrawlist();
				ImGuizmo::SetRect(pMin.x, pMin.y, currentWindowX, currentWindowY);
				ImGui::PushClipRect(pMin, pMax, false);
				// Draw Gizmos
				DrawGizmos();
			}

			ImGui::End();
		}
	}

	void ScenePanel::Setup()
	{
		m_RenderEngine = m_GUILayer->GetRenderEngine();
	}

	void ScenePanel::ProcessInput()
	{

		if (ImGui::IsKeyPressed(LINA_KEY_Q))
			currentTransformGizmoOP = ImGuizmo::TRANSLATE;
		if (ImGui::IsKeyPressed(LINA_KEY_E))
			currentTransformGizmoOP = ImGuizmo::ROTATE;
		if (ImGui::IsKeyPressed(LINA_KEY_R))
			currentTransformGizmoOP = ImGuizmo::SCALE;
		if (ImGui::IsKeyPressed(LINA_KEY_T))
			currentTransformGizmoMode = currentTransformGizmoMode == ImGuizmo::MODE::WORLD ? ImGuizmo::MODE::LOCAL : ImGuizmo::MODE::WORLD;
	}

	void ScenePanel::DrawGizmos()
	{
		Matrix& view = m_RenderEngine->GetCameraSystem()->GetViewMatrix();
		Matrix& projection = m_RenderEngine->GetCameraSystem()->GetProjectionMatrix();

		if (m_SelectedTransform != nullptr)
		{
			// Get required matrices.
			Matrix object = m_SelectedTransform->transform.ToMatrix();

			// Draw transformation handle.
			ImGuizmo::Manipulate(&view[0][0], &projection[0][0], currentTransformGizmoOP, currentTransformGizmoMode, &object[0][0], NULL, NULL, NULL, NULL);
			float matrixTranslation[3], matrixRotation[3], matrixScale[3];
			ImGuizmo::DecomposeMatrixToComponents(&object[0][0], matrixTranslation, matrixRotation, matrixScale);

			// Set object transformation back.
			m_SelectedTransform->transform.location = Vector3(matrixTranslation[0], matrixTranslation[1], matrixTranslation[2]);
			m_SelectedTransform->transform.scale = Vector3(matrixScale[0], matrixScale[1], matrixScale[2]);
			m_SelectedTransform->transform.rotation = Quaternion::Euler(matrixRotation[0], matrixRotation[1], matrixRotation[2]);
		}

		// ImGuizmo::DrawGrid(&view[0][0], &projection[0][0], &gridLineMatrix[0][0], GRID_SIZE);
	}

}