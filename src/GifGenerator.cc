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

GifGenerator::GifGenerator(Frames& frames, string outputPath, int width, int height, int delayMs = 100)
: frames(frames), outputPath(outputPath), width(width), height(height), delayMs(delayMs) {};

void GifGenerator::generate() {
    if(!GifBegin(&writer, outputPath.c_str(), width, height, delayMs / 10)) {
        throw std::runtime_error("ERROR: Could not initialize the GIF file.");
    }

    for(const auto& framePath : frames) {
        int givenW, givenH, channels;
        unsigned char* image = stbi_load(framePath.c_str(), &givenW, &givenH, &channels, 4);
        if(!image) {
            continue;
        }

        GifWriteFrame(&writer, image, givenW, givenH, delayMs / 10);
        stbi_image_free(image);
    }

    GifEnd(&writer);
};