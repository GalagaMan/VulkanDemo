#pragma once

class VKrenderer
{
public:
	VkInstance instance;
	void CreateInstance();
	bool CheckValidationSupport();
};

