/**
 * This class handle the gif frames.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#ifndef GIF_FRAMES_HANDLER_H
#define GIF_FRAMES_HANDLER_H

#include "./types.hh"
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class GifFramesHandler {

    public:

        static vector<string> getFramePathsFromDir(string imagesDir);

        static void orderFramesByWriteTime(Frames& frames, const string order);
        
};

#endif