#pragma once

#include "../Loader/AssetsManager.h"
#include "../Timer/Timer.h"

class App
{
public:
	App() = default;
	void run();
	~App() = default;
private:
	void testLoadWithLoader();
};

