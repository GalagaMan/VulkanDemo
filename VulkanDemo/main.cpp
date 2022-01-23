#include <glfw3.h>
#include <vulkan/vulkan.h>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "VKrenderer.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 800;

class WinApp
{
public:
	void Run() 
	{
		InitWindow();
		InitVulkan();
		MainLoop();
		CleanUp();
	}

private:
	GLFWwindow* Window;
	VKrenderer r;

	void InitWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		Window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan 1.2 Demo", nullptr, nullptr);
	}
	void InitVulkan() 
	{
		r.CreateInstance();
	}
	void MainLoop() 
	{
		while (!glfwWindowShouldClose(Window)) 
		{
			glfwPollEvents();
		}
	}
	void CleanUp() 
	{
		glfwDestroyWindow(Window);
		glfwTerminate();
	}
};

int main()
{
	WinApp win;
	try
	{
		win.Run();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;	
}