#pragma once

#include "../Loader/RecursiveDataLoader.hpp"
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

