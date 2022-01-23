#include <glfw3.h>
#include <vulkan/vulkan.h>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <Windows.h>
#include <vector>
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
	GLFWwindow* window;
	VKrenderer* r = new VKrenderer();

	void InitWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan 1.2 Demo", nullptr, nullptr);
	}
	void InitVulkan() 
	{
		r -> CreateInstance();
	}
	void MainLoop()
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
			//Sleep(1);
		}
	}
	void CleanUp()
	{
		vkDestroyInstance(r -> instance, nullptr);
		delete r;
		glfwDestroyWindow(window);
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
