#include "RecursiveDataLoader.hpp"

template<typename T>
inline void RecursiveDataLoader<T>::setSupportedFormats(std::string formats, std::string delim)
{
    std::regex regexz(delim);
    std::vector<std::string> list(std::sregex_token_iterator(formats.begin(), formats.end(), regexz, -1),
                                  std::sregex_token_iterator());
    for (auto&& it : list)
        if (!it.empty())
            supportedFormats.emplace(std::move("." + it), true);
}

template<typename T>
inline void RecursiveDataLoader<T>::loadAssets(std::string_view folderPath,
            std::function<void(T& item,const std::filesystem::path& itemPath)> loader) {
    if (loader == nullptr) {
        std::cout << "Nullptr functor\n";
        return;
    }

    std::vector<std::filesystem::path> pathFiles;
    for (const auto& p : std::filesystem::recursive_directory_iterator(folderPath)) {
        pathFiles.emplace_back(p.path());
    }
    for (const auto& it : pathFiles) {
        const auto& crntExtension = it.extension().string();
        if (supportedFormats[crntExtension]) {
            auto nameFile = it.stem().string();
            auto& ref = storage[nameFile];
            loader(ref, it);
        }
    }
}

template<typename T>
inline T* RecursiveDataLoader<T>::operator[](std::string_view name)
{
    return getPtr(name);
}

template<typename T>
inline const T* RecursiveDataLoader<T>::getPtr(const std::string_view name) const
{
    return getPtr(name);
}

template<typename T>
inline T* RecursiveDataLoader<T>::getPtr(std::string_view name) {
    if (auto it = storage.find(name.data()); it != storage.end()) {
        return &it->second;
    }
    return nullptr;
}






