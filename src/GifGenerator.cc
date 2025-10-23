/**
 * GifGenerator implementation.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define GIF_GENERATOR_H_IMPLEMENTATION
#define GIF_H_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "../include/GifGenerator.hh"
#include "../vendor/gif.hh"
#include "../vendor/stb_image.hh"
#include <iostream>

struct GifGenerator::Impl {

    GifWriter writer;

    Frames frames;

    string outputPath;

    int width;

    int height;

    int delayMs;

};

GifGenerator::GifGenerator(Frames& frames, string outputPath, int delayMs)
: p(make_unique<Impl>(Impl { {}, frames, outputPath, 0, 0, delayMs })) {};

GifGenerator::~GifGenerator() = default;

void GifGenerator::generate() {

    if (p->frames.empty()) {
        cerr << "ERROR: No frames to generate GIF." << endl;
        return;
    }

    bool atLeastOneFrameWritten = false;

    // Get the first frame dimensions.
    int frameW, frameH, channels;
    uint8_t* firstImage = stbi_load(p->frames[0].c_str(), &frameW, &frameH, &channels, 4);
    if (!firstImage) {
        cerr << "ERROR: Could not load the first frame: " << p->frames[0] << endl;
        return;
    }

    // Define the base dimensions automatically.
    p->width = frameW;
    p->height = frameH;

    // Initialize the GIF file.
    if (!GifBegin(&p->writer, p->outputPath.c_str(), p->width, p->height, p->delayMs / 10)) {
        stbi_image_free(firstImage);
        throw runtime_error("Could not initialize GIF file.");
    }

    // Write the first frame.
    GifWriteFrame(&p->writer, firstImage, p->width, p->height, p->delayMs / 10);
    stbi_image_free(firstImage);
    atLeastOneFrameWritten = true;

    // Iterate over frames.
    for (size_t i = 1; i < p->frames.size(); ++i) {
        const auto& framePath = p->frames[i];
        int w, h, ch;
        uint8_t* image = stbi_load(framePath.c_str(), &w, &h, &ch, 4);

        if (!image) {
            cerr << "WARNING: Could not load frame: " << framePath << endl;
            continue;
        }

        // Ignore files with diferent dimensions.
        if (w != p->width || h != p->height) {
            cerr << "WARNING: Skipping frame due to size mismatch: " << framePath
                 << " (expected " << p->width << "x" << p->height
                 << ", got " << w << "x" << h << ")" << endl;
            stbi_image_free(image);
            continue;
        }

        GifWriteFrame(&p->writer, image, p->width, p->height, p->delayMs / 10);
        stbi_image_free(image);
        atLeastOneFrameWritten = true;
    }

    // Finalize the GIF if at least one frame was written.
    if (atLeastOneFrameWritten) {
        GifEnd(&p->writer);
        cout << "INFO: GIF generated successfully at: " << p->outputPath << endl;
    } else {
        cerr << "ERROR: No valid frames written. GIF was not created." << endl;
    }
    
};