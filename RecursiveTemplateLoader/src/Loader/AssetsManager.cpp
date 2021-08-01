#include "AssetsManager.h"

#include <cassert>

AssetsManager* AssetsManager::sInstance = nullptr;

AssetsManager::AssetsManager(std::string_view folder) {

    assert(sInstance == nullptr);
    sInstance = this;

    std::vector<std::filesystem::path> pathFiles;
    for (const auto& p : std::filesystem::recursive_directory_iterator(folder)) {
        pathFiles.emplace_back(p.path());
    }
    std::map<std::string, std::string> vertexShader, fragmentShader;

    for (const auto& it : pathFiles) {
        const auto& crntExtension = it.extension().string();
        auto nameFile = it.stem().string();
        if (crntExtension == ".png") {
            sInstance->textures[nameFile].loadFromFile(it.string());
        }
        else if (crntExtension == ".wav") {
            sInstance->soundBuffers[nameFile].loadFromFile(it.string());
        }
        else if (crntExtension == ".ttf") {
            sInstance->fonts[nameFile].loadFromFile(it.string());
        }
        else if (crntExtension == ".fs" || crntExtension == ".vs") {
            if (crntExtension == ".fs") {
                fragmentShader[nameFile] = it.string();
            }
            else {
                vertexShader[nameFile] = it.string();
            }
            if (!vertexShader[nameFile].empty() && !fragmentShader[nameFile].empty()) {   
                auto& shaderMap = sInstance->shaders;
                auto& shader = (shaderMap[nameFile] = std::unique_ptr<sf::Shader>(new sf::Shader()));
                shader->loadFromFile(vertexShader[nameFile], fragmentShader[nameFile]);
            } 
        }
    }
}

sf::Texture& AssetsManager::getTexture(std::string_view name)
{
    auto& texMap = sInstance->textures;
    if (auto it = texMap.find(name.data()); it != texMap.end())
        return it->second;
    return texMap[name.data()];//empty texture
}

sf::SoundBuffer& AssetsManager::getSoundBuffer(std::string_view name)
{
    auto& soundMap = sInstance->soundBuffers;
    if (auto it = soundMap.find(name.data()); it != soundMap.end())
        return it->second;
    return soundMap[name.data()];//empty
}

sf::Font& AssetsManager::getFont(std::string_view name)
{
    auto& fontsMap = sInstance->fonts;
    if (auto it = fontsMap.find(name.data()); it != fontsMap.end())
        return it->second;
    return fontsMap[name.data()];//empty
}

sf::Shader* AssetsManager::getShader(std::string_view name)
{
    auto& shadersMap = sInstance->shaders;
    if (auto it = shadersMap.find(name.data()); it != shadersMap.end())
        return it->second.get();
    return nullptr;
}
