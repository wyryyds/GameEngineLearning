#include "GuiHelper.hpp"

#include <imgui.h>
#include <imgui_internal.h>

namespace HAIEngine
{
	const char* GuiHelper::CameraTypeString[] = 
	{
		"Undefined",
		"OrthoCamera",
		"PerspectiveCamera"
	};

	const char* GuiHelper::LightTypeString[] =
	{
		"Undefined",
		"Direction Light",
		"Point Light",
		"Spot Light"
	};

	void GuiHelper::DrawVec3Control(const std::string& label, glm::vec3& values, float resetValue, float columnWidth)
	{
		ImGuiIO& io = ImGui::GetIO();
		auto boldFont = io.Fonts->Fonts[0];

		ImGui::PushID(label.c_str());

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, columnWidth);
		ImGui::Text(label.c_str());
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

		float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

		//draw x;
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
		ImGui::PushFont(boldFont);
		if (ImGui::Button("X", buttonSize))
			values.x = resetValue;
		ImGui::PopFont();
		ImGui::PopStyleColor(3);

		ImGui::SameLine();
		ImGui::DragFloat("##X", &values.x, 0.1f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

		//draw y;
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
		ImGui::PushFont(boldFont);
		if (ImGui::Button("Y", buttonSize))
			values.y = resetValue;
		ImGui::PopFont();
		ImGui::PopStyleColor(3);

		ImGui::SameLine();
		ImGui::DragFloat("##Y", &values.y, 0.1f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

		//draw z;
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
		ImGui::PushFont(boldFont);
		if (ImGui::Button("Z", buttonSize))
			values.z = resetValue;
		ImGui::PopFont();
		ImGui::PopStyleColor(3);

		ImGui::SameLine();
		ImGui::DragFloat("##Z", &values.z, 0.1f, 0.0f, 0.0f, "%.2f");
		ImGui::PopItemWidth();

		ImGui::PopStyleVar();

		ImGui::Columns(1);

		ImGui::PopID();
	}

	void GuiHelper::DrawFloatSlider(const char* label, float* v, float v_min, float v_max)
	{
		//ImGui::SliderFloat(label, v, v_min, v_max);
		ImGui::Text(label);
		ImGui::SameLine(); 
		ImGui::SliderFloat("", v, v_min, v_max);

	}

	void GuiHelper::DrawFloatInput(const char* label, float* v)
	{
		ImGui::Text(label);
		ImGui::SameLine();
		ImGui::InputFloat("", v);
	}

	void HAIEngine::GuiHelper::DrawEnumControl(CameraType& type)
	{
		const char* currentItem = CameraType2String(type);
		if (ImGui::BeginCombo("Camera Type", currentItem)) {
			for (int i = 0; i < static_cast<int>(CameraType::Count); ++i) {
				bool isSelected = (currentItem == CameraTypeString[i]);
				if (ImGui::Selectable(CameraTypeString[i], isSelected)) {
					type = static_cast<CameraType>(i);
				}
				if (isSelected) {
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
	}

	void GuiHelper::DrawEnumControl(LightType& type)
	{
		const char* currentItem = LightType2String(type);
		if (ImGui::BeginCombo("Camera Type", currentItem)) {
			for (int i = 0; i < static_cast<int>(LightType::Count); ++i) {
				bool isSelected = (currentItem == LightTypeString[i]);
				if (ImGui::Selectable(LightTypeString[i], isSelected)) {
					type = static_cast<LightType>(i);
				}
				if (isSelected) {
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
	}

	void GuiHelper::DrawColorEditor3(const char* label, float col[3])
	{
		ImGui::ColorEdit3(label, col);
	}

	CameraType HAIEngine::GuiHelper::String2CameraType(const char* typeString)
	{
		for (int i = 0; i < static_cast<int>(CameraType::Count); ++i) {
			if (strcmp(typeString, CameraTypeString[i]) == 0) {
				return static_cast<CameraType>(i);
			}
		}
		return CameraType::UNDEFINED;
	}

	LightType GuiHelper::String2LightType(const char* typeString)
	{
		for (int i = 0; i < static_cast<int>(LightType::Count); ++i) {
			if (strcmp(typeString, LightTypeString[i]) == 0) {
				return static_cast<LightType>(i);
			}
		}
		return LightType::UNDEFINED;
	}
}
