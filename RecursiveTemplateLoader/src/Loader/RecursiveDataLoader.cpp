#include "RecursiveDataLoader.h"

#include <iostream>
#include <set>
#include <filesystem>

RecursiveDataLoader::RecursiveDataLoader(std::string_view folderPath) noexcept
{
    loadAssets(folderPath);
}

void RecursiveDataLoader::loadAssets(std::string_view folderPath)
{
    std::vector<std::filesystem::path> pathFiles;
    for (const auto& p : std::filesystem::recursive_directory_iterator(folderPath)) {
        pathFiles.emplace_back(p.path());
    }
    std::set<std::string> supportedFormats = {
        {".png"},{".jpg"},{".bmp"}
    };
    for (const auto& it : pathFiles) {
        const auto& crntExtension = it.extension().string();
        if (auto found = supportedFormats.find(crntExtension);found != supportedFormats.end()) {
            auto nameFile = it.stem().string();
            textureStorage[nameFile].loadFromFile(it.string());
        }
    }
}

sf::Texture* RecursiveDataLoader::getPtr(std::string_view name)
{
    if (auto it = textureStorage.find(name.data()); it != textureStorage.end()) {
        return &it->second;
    }
    return nullptr;
}

sf::Texture& RecursiveDataLoader::getRef(std::string_view name)
{
    auto found = textureStorage.find(name.data());
    return found->second;//hmm
}


