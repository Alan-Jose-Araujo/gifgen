/**
 * This class generate the gif file.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#ifndef GIF_GENERATOR_H
#define GIF_GENERATOR_H

#include "./types.hh"
#include "../vendor/gif.hh"

using namespace std;

class GifGenerator {

    private:

        GifWriter writer;

        Frames frames;

        string outputPath;

        int width;

        int height;

        int delayMs;

    public:

        GifGenerator(Frames& frames, string outputPath, int width, int height, int delayMs = 100);

        void generate();

};

#endif