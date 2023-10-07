#include "splendidpch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <Splendid/Core/Application.h>


namespace Splendid
{
	Splendid::ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	Splendid::ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init();
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void Splendid::ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();

		SplendidApplication& app = SplendidApplication::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f - 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void Splendid::ImGuiLayer::OnEvent(Splendid::Event& event)
	{

	}
}