#include "App.h"

void App::run()
{
	testLoadWithLoader();
	testForwardLoad();
}

void App::testLoadWithLoader()
{
	Timer timer;

	//loader.loadAssets("data");//texture

	loader2.loadAssets("data", [](sf::Music& a, std::string ext, std::string path) {
		if (ext == ".wav") {
			a.openFromFile(path); std::cout << "Ok\n";
		}
	});

	loader3.loadAssets("data", [](sf::Shader& a, std::string ext, std::string path) {
		if (ext == ".fs") {
			a.loadFromFile(path,sf::Shader::Type::Fragment); 
		}
	});

	loader3.loadAssets("data");
	
	sf::Music* test = loader2.getPtr("1");
	test->play();

	while (true)
	{

	}
}

void App::testForwardLoad()
{

}
