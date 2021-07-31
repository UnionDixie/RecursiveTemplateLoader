#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string_view>
#include <string>
#include <iostream>
#include <filesystem>
#include <functional>
#include <algorithm>
#include <regex>

template<typename T> 
class RecursiveDataLoader
{
public:
	RecursiveDataLoader() = default;

	RecursiveDataLoader(const RecursiveDataLoader&) = delete;
	RecursiveDataLoader& operator=(const RecursiveDataLoader&) = delete;
	RecursiveDataLoader(RecursiveDataLoader&&) = delete;
	RecursiveDataLoader& operator=(RecursiveDataLoader&&) = delete;

	/// <summary>
	/// set formats for correct load Assets
	/// </summary>
	/// <param name="formats">".png.jpg.bmp"</param>
	/// <param name="delim">"[.]" because regex</param>
	void setSupportedFormats(std::string formats, std::string delim);
	/// <summary>
	/// load assets with users functor
	/// </summary>
	/// <param name="folderPath">"data"</param>
	/// <param name="loader">"itetm.loadFromFile(path) u get only path with your formats"</param>
	void loadAssets(std::string_view folderPath,
		            std::function<void(T& item, const std::filesystem::path& itemPath)> loader);

	T* operator[](std::string_view name);
	T* getPtr(std::string_view name);
	const T* getPtr(const std::string_view name) const;

	~RecursiveDataLoader() = default;
private:
	std::unordered_map<std::string, bool> supportedFormats;
	std::unordered_map<std::string, T> storage;
};


#include "RecursiveDataLoader.inl" //implementation



