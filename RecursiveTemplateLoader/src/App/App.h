#pragma once

#include "../Loader/RecursiveDataLoader.hpp"
#include "../Timer/Timer.h"

#include <SFML/Audio.hpp>

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
	RecursiveDataLoader<sf::Texture> loader;
	RecursiveDataLoader<sf::Music> loader2;
	RecursiveDataLoader<sf::Shader> loader3;
	//RecursiveDataLoader<sf::Music> loader2;
};

