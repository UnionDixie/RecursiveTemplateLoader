#include "App.h"

void App::run()
{
	testLoadWithLoader();
	testForwardLoad();
}

void App::testLoadWithLoader()
{
	Timer timer;
	loader.loadAssets("data");
}

void App::testForwardLoad()
{

}
