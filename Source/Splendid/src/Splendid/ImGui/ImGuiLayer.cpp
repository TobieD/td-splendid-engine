#include "splendidpch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Platform/OpenGL/imgui_impl_glfw.h"

#include <GLFW/glfw3.h>
#include <Splendid/Core/Application.h>
#include <Platform/Windows/WindowsWindow.h>
#include <Splendid/Core/Input.h>

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

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		GLFWwindow* window = glfwGetCurrentContext();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

		SP_CORE_INFO("Initialized imGui");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void Splendid::ImGuiLayer::OnRenderStart()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Splendid::ImGuiLayer::OnRenderEnd()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	
	void Splendid::ImGuiLayer::OnUpdate()
	{
		auto [x, y] = Input::GetMousePosition();
		ImGuiIO& io = ImGui::GetIO();

		ImGui::Begin("Performance");
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::Text("MousePos: [%.1f, %.1f]", x,y);
		ImGui::End();
	}

	void Splendid::ImGuiLayer::OnEvent(Splendid::Event& event)
	{

	}
}