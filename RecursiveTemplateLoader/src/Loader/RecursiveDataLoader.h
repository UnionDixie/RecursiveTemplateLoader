#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <set>
#include <string_view>
#include <memory>
#include <filesystem>
//#include <optional>

class RecursiveDataLoader
{
public:
	RecursiveDataLoader() = default;
	RecursiveDataLoader(std::string_view folderPath) noexcept;

	void loadAssets(std::string_view folderPath);

	sf::Texture* getPtr(std::string_view name);
	sf::Texture& getRef(std::string_view name);

	//std::unique_ptr<sf::Texture> getTexture(std::string_view name) const;
	//std::unique_ptr<sf::Font> getFont(std::string_view name) const;

	~RecursiveDataLoader() = default;
private:
	std::map<std::string, sf::Texture> textureStorage;
};

