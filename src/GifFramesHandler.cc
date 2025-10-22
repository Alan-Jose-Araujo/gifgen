/**
 * GifFramesHandler implementation.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define GIF_FRAMES_HANDLER_H_IMPLEMENTATION
#include "../include/GifFramesHandler.hh"

vector<string> GifFramesHandler::getFramePathsFromDir(string imagesDir) {
    Frames framePaths;

    for(const auto& entry : fs::directory_iterator(imagesDir)) {
        if(entry.is_regular_file()) {
            string path = entry.path().string();
            if(path.ends_with(".png") || path.ends_with(".jpg") || path.ends_with(".jpeg")) {
                framePaths.push_back(path);
            }
        }
    }

    return framePaths;
};

void GifFramesHandler::orderFramesByWriteTime(Frames& framePaths, const string order) {
    sort(
        framePaths.begin(),
        framePaths.end(),
        [order](const string& a, const string& b) {
            if(order == "asc") {
                return fs::last_write_time(a) < fs::last_write_time(b);
            } else if(order == "desc") {
                return fs::last_write_time(b) < fs::last_write_time(a);
            } else {
                return false;
            }
    });
};