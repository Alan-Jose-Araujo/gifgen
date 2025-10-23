/**
 * This class generate the gif file.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#ifndef GIF_GENERATOR_H
#define GIF_GENERATOR_H

#include "./types.hh"
#include <memory>

using namespace std;

class GifGenerator {

    private:

        /**
         * Since the GIFH is a header file lib, it must be included once
         * on a implementation (.cc) file, the Pimpl pattern is used here.
         * It conatains the GifWriter, frames, output path and image dimensions.
         */
        struct Impl;

        /**
         * The unique point will point to a Impl struct, hidding the struct
         * implementation details.
         */
        unique_ptr<Impl> p;

    public:

        GifGenerator(Frames& frames, string outputPath, int delayMs = 100);

        /**
         * The destructor must be declared explicitly, because at this point, the
         * compiler doesn't know the 'p' pointer allocated size neither implementation.
         * So, the destructor will 'says' to the compiler what do with the pointer at
         * the final of execution.
         */
        ~GifGenerator();

        void generate();

};

#endif