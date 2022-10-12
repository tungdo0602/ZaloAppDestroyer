#include <stdio.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int handleDestroyer() {
    std::string path = std::string(std::getenv("LOCALAPPDATA")) + "/Programs/Zalo";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::string path2{ entry.path().string() };
        if (path2.find("Zalo-") != std::string::npos) {
            try {
                std::string appPath = path2 + "/resources/app.asar";
                fs::remove(appPath);
            }
            catch (const std::filesystem::filesystem_error&) {
                std::system("taskkill /f /im zalo.exe");
                return handleDestroyer();
            }
        }
    }
    return 0;
}

int main()
{
    try {
        handleDestroyer();
    }
    catch (...) {

    }
    return 0;
}
