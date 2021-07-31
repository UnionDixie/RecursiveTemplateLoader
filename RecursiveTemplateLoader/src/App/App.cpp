#include "App.h"

void App::run()
{
	testLoadWithLoader();
}

void App::testLoadWithLoader()
{

	{
		RecursiveDataLoader<sf::Texture> loader;
		loader.setSupportedFormats(".png.jpg.bmp", "[|.:,]");
		Timer timer;
		loader.loadAssets("data", [](auto& item, auto path) {
			item.loadFromFile(path.string());			
		});
		//auto size = loader["background"]->getSize();
	}
	{
		RecursiveDataLoader<sf::Music> loader;
		loader.setSupportedFormats("wav,ogg", "[|.:,]");
		Timer timer;
		loader.loadAssets("data1", [](auto& item, auto path) {
			item.openFromFile(path.string());
		});
		loader["meow"]->play();
	}
	{
		RecursiveDataLoader<sf::Shader> loader;
		loader.setSupportedFormats("fs|vs|gs", "[|.:,]");
		Timer timer;
		loader.loadAssets("data1", [](auto& item, auto path) {
			if (path.extension().string() == ".fs")
				item.loadFromFile(path.string(), sf::Shader::Type::Fragment);
		});
		loader["physics"]->setUniform("gravity", 9.8f);
	}
}

