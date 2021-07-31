#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string_view>
#include <iostream>
#include <set>
#include <filesystem>
#include <functional>

template<typename T> 
class RecursiveDataLoader
{
public:
	RecursiveDataLoader() = default;
	RecursiveDataLoader(std::string_view folderPath);

	void loadAssets(std::string_view folderPath,
		 std::function<void(T&,std::string ext, std::string path)> loader = nullptr);

	T* getPtr(std::string_view name);
	T& getRef(std::string_view name);

	~RecursiveDataLoader() = default;
private:
	std::map<std::string, T> storage;
};


#include "RecursiveDataLoader.inl" //implementation



