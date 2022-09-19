# Splendid Engine - Documentation

### The Entry Point

The application needs to start somewhere, also referred to as 'Start up' code.
Ideally this is taken care of in the 'Engine' project

### Adding Preprocessors

- In property settings add the name under c++/ preprocessors

### Include DLL in a single line

- In the DLL project create a '{project}.h' file
- In the integration project go to properties and in the Include Directory add $(SolutionDir)/{Project}/src

### How to use the Entry Point

- In the Library project we define the main and execute an external method to create an application

``` c++
// In the Library
extern Splendid::Application* Splendid::CreateApplication();

int main(int argc, char** argv) //might need to be wmain for additional information
{
	auto app = Splendid::CreateApplication();
	app->Run();
	delete app;
}

//In the Application
Splendid::Application* Splendid::CreateApplication()
{
	return new Sandbox(); //This is our class which inherits from Splendid::Application
}
```

## How to add an external library

- As a submodule
```
git submodule add https://github.com/gabime/spdlog Splendid/vendor/spdlog
git submodule add https://github.com/TobieD/glfw Splendid/vendor/GLFW
```

- Update Premake to include path

## Precompiled headers

Used to improve build times (especially on minor changes to files).
Useful in the long term when lots of files are needed

include the pch file in all .cpp files!


## Window API

- GLFW: Easy to use, cross platform, does not support DirectX, easy to set it up for running quickly
- Win32: Windows ideal, allows DirectX
- Vulkan
	- https://vulkan-tutorial.com/

-> Window class per platform


## Layers

Layers define the order things are drawn, updated, processed in

- Rendering is bottom to top
- Input is top to bottom

examples:
- 3D game world: One layer, holds the scene
- Debug layer on gameworld, gizmo's, ..
- UI Layer: 2D orthographic projection
- Debug layer for 2D graphics (ImGui, Cheat menu
