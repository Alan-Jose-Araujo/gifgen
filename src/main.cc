/**
 * GifGen.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#include "../include/CliArgumentParser.hh"
#include "../include/GifFramesHandler.hh"
#include "../include/GifGenerator.hh"
#include "../include/InfoPresenter.hh"
#include "../include/types.hh"
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[]) {

    // Command line arguments options.
    const char* shortOptions = "d:o:m:hv";
    vector<option> longOptions = {
        {"directory", required_argument, nullptr, 'd'},
        {"output-path", optional_argument, nullptr, 'o'},
        {"delay", optional_argument, nullptr, 'm'},
        {"help", no_argument, nullptr, 'h'},
        {"version", no_argument, nullptr, 'v'},
    };

    CliArgumentParser parser(shortOptions, longOptions);

    // Application params defnition.
    string framesDirectory;
    string outputPath = "./";
    int delayMs = 100;
    Frames framePaths;

    // CLI arguments parsing.
    parser.parse(argc, argv, [&](int cliOption, const char* optarg) {
        switch(cliOption) {
            case 'd': {
                try {
                    if(!optarg) {
                        throw new runtime_error("Missing required param d | --directory, use -h or --help to see the usage.");
                    }
                    framesDirectory = string(optarg);
                }
                catch(const runtime_error& error) {
                    cerr << "ERROR: " << error.what() << endl;
                    abort();
                }
            } break;
            case 'o': {
                outputPath = optarg ? string(optarg) : "./";
            } break;
             case 'm': {
                delayMs = optarg ? stoi(optarg) : 100;
            } break;
            case 'h': {
                InfoPresenter::printHelpMessage();
                exit(EXIT_SUCCESS);
            } break;
            case 'v': {
                InfoPresenter::printVersionMessage();
                exit(EXIT_SUCCESS);
            } break;
            default: {
                InfoPresenter::printUnknowOptionMessage();
                exit(EXIT_FAILURE);
            } break;
        }
    });

    try {
        framePaths = GifFramesHandler::getFramePathsFromDir(framesDirectory);
        GifFramesHandler::orderFramesByWriteTime(framePaths, "asc");

        GifGenerator generator(framePaths, outputPath, delayMs);
        generator.generate();
    }
    catch(const exception& exception) {
        cerr << "ERROR: " << exception.what() << endl;
        abort();
    }

    return EXIT_SUCCESS;

};