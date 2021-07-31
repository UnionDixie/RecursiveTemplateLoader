#include "RecursiveDataLoader.hpp"

#include <type_traits>

template<typename T, typename F>
constexpr auto is_valid(F&& f) -> decltype(f(std::declval<T>()), true) { return true; }
template<typename>
constexpr bool is_valid(...) { return false; }
#define IS_VALID(T, EXPR) is_valid<T>( [](auto&& obj)->decltype(obj.EXPR){} )


template<typename T>
inline RecursiveDataLoader<T>::RecursiveDataLoader(std::string_view folderPath)
{
    loadAssets(folderPath);
}



template<typename T>
inline void RecursiveDataLoader<T>::loadAssets(std::string_view folderPath,
            std::function<void(T&, std::string ext, std::string path)> loader) {

    std::vector<std::filesystem::path> pathFiles;
    for (const auto& p : std::filesystem::recursive_directory_iterator(folderPath)) {
        pathFiles.emplace_back(p.path());
    }
    std::set<std::string> supportedFormats = {
        {".png"},{".jpg"},{".bmp"},{".wav"},{".fs"}
    };
    for (const auto& it : pathFiles) {
        const auto& crntExtension = it.extension().string();
        if (auto found = supportedFormats.find(crntExtension); found != supportedFormats.end()) {
            auto nameFile = it.stem().string();
            if constexpr (IS_VALID(T, loadFromFile(""))) {
                storage[nameFile].loadFromFile(it.string());
            }
            else if(loader != nullptr){
                 loader(storage[nameFile], crntExtension, it.string());
            }
            else {
                std::cout << "Class must have loadFromFile member,OR USES NON DEF LOADER";
            }
        }
    }
}


template<typename T>
inline T* RecursiveDataLoader<T>::getPtr(std::string_view name) {
    if (auto it = storage.find(name.data()); it != storage.end()) {
        return &it->second;
    }
    return nullptr;

}

template<typename T>
inline T& RecursiveDataLoader<T>::getRef(std::string_view name) {
    auto found = storage.find(name.data());
    return found->second;//hmm
}



