#include <vulkan/vulkan.h>
#include <glfw3.h>
#include <iostream>
#include <vector>
#include "VKrenderer.h"


const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
#ifdef NDEBUG
const bool enableValidationLayers{ false };
#else
const bool enableValidationLayers{ true };
#endif


//VkInstance VKrenderer::instance;

bool VKrenderer::CheckValidationSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<struct VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers)
	{
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
			return false;
	}

	return true;
}

void VKrenderer::CreateInstance()
{
	if (enableValidationLayers && !CheckValidationSupport())
	{
		throw std::runtime_error("unnable to get validation layers because unsupported\n");
	}

	struct VkApplicationInfo ApplicationInfo {};
	ApplicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	ApplicationInfo.pApplicationName = "Vulkan 1.2 Demo";
	ApplicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	ApplicationInfo.pEngineName = "No Engine";
	ApplicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	ApplicationInfo.apiVersion = VK_API_VERSION_1_2;

	struct VkInstanceCreateInfo InstanceInfo {};
	InstanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceInfo.pApplicationInfo = &ApplicationInfo;

	if (enableValidationLayers)
	{
		InstanceInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		InstanceInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else
	{
		InstanceInfo.enabledLayerCount = 0;
	}

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