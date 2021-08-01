#include "App.h"

void App::run()
{
	testLoadWithLoader();
}

void App::testLoadWithLoader()
{

	{
		Timer timer;
		AssetsManager manager("data1");
		int a = 5;
	}
}

