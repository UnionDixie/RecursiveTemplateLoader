#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string_view>

class RecursiveDataLoader
{
public:
	RecursiveDataLoader() = default;
	RecursiveDataLoader(std::string_view folderPath) noexcept;

	void loadAssets(std::string_view folderPath);

	sf::Texture* getPtr(std::string_view name);
	sf::Texture& getRef(std::string_view name);

	~RecursiveDataLoader() = default;
private:
	std::map<std::string, sf::Texture> textureStorage;
};

