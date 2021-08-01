#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string_view>
#include <unordered_map>
#include <filesystem>
#include <memory>

class AssetsManager
{
public:
	AssetsManager() = delete;

	AssetsManager(std::string_view folder);

	static sf::Texture& getTexture(std::string_view name);
	static sf::SoundBuffer& getSoundBuffer(std::string_view name);
	static sf::Font& getFont(std::string_view name);
	//1.vs and 1.fs -> 1
	static sf::Shader* getShader(std::string_view name);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, std::unique_ptr<sf::Shader>> shaders;
	//singleton
	static AssetsManager* sInstance;
};

