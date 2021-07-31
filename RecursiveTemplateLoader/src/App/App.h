#pragma once

#include "../Loader/RecursiveDataLoader.h"
#include "../Timer/Timer.h"

class App
{
public:
	App() = default;
	void run();
	~App() = default;
private:
	void testLoadWithLoader();
	//void testLoadAsyncLoader();
	void testForwardLoad();
private:
	RecursiveDataLoader loader;
};

