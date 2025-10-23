/**
 * PathUtils implementations.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define PATH_UTILS_H_IMPLEMENTATION
#include "../include/PathUtils.hh"
#include <filesystem>
#include <chrono>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

string PathUtils::prepareOutputPath(const string& rawPath) {
    fs::path givenPath(rawPath);

    if(givenPath.has_extension()) {
        fs::create_directories(givenPath.parent_path());
        return givenPath.string();
    }

    fs::create_directories(givenPath);

    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime {};

    #ifdef _WIN32
        localtime_s(&localTime, &currentTime);
    #else
        localtime_r(&currentTime, &localTime);
    #endif

    ostringstream oss;
    oss << put_time(&localTime, "%Y_%m_%d_%H_%M_%S") << "_output_gif.gif";

    return (givenPath / oss.str()).string();
};