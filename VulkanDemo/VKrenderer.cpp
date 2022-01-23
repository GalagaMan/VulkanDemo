#include "VKrenderer.h"
#include <vulkan/vulkan.h>
#include <glfw3.h>
#include <iostream>

VkInstance instance;

void VKrenderer::CreateInstance()
{
	struct VkApplicationInfo ApplicationInfo {};
	ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	ApplicationInfo.pApplicationName = "Vulkan 2.1 Demo";
	ApplicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	ApplicationInfo.pEngineName = "No Engine";
	ApplicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	ApplicationInfo.apiVersion = VK_API_VERSION_1_2;

	struct VkInstanceCreateInfo InstanceInfo {};
	InstanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceInfo.pApplicationInfo = &ApplicationInfo;

	uint32_t glfwExtensionCount{ 0 };
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	InstanceInfo.enabledExtensionCount = glfwExtensionCount;
	InstanceInfo.ppEnabledExtensionNames = glfwExtensions;

	if (vkCreateInstance(&InstanceInfo, nullptr, &instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create a Vulkan instance\n");
	}
}