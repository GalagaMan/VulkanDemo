#pragma once

class VKrenderer
{
private:
	struct VkApplicationInfo ApplicationInfo {};
	struct VkInstanceCreateInfo InstanceInfo {};
	bool CheckValidationSupport();
public:
	VkInstance instance;
	VkResult result = vkCreateInstance(&InstanceInfo, nullptr, &instance);
	void CreateInstance();
	void CheckExtensions();
};

