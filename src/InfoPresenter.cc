/**
 * InfoPresenter implementation.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define INFO_PRESENTER_H_IMPLEMENTATION
#include "../include/InfoPresenter.hh"
#include <iostream>

using namespace std;

#define VERSION "1.0"
#define AUTHOR "Alan Jose <alanjsdelima@gmail.com>"

void InfoPresenter::printHelpMessage() {
    cout << "Usage: gifgen [options]" << endl;
    cout << "\t-d | --directory <frames directory>" << endl;
    cout << "\tDefine the image frames folder to generate the GIF file." << endl;
    cout << "\t-o | --output-path <output path>" << endl;
    cout << "\tDefines the GIF file output path." << endl;
    cout << "\t-m | --delay <delay in ms>" << endl;
    cout << "\tDefines the GIF frames delay in miliseconds." << endl;
    cout << "\t-h | --help" << endl;
    cout << "\tShows this help message." << endl;
    cout << "\t-v | --version" << endl;
    cout << "\tShows the program version, author information and licenses." << endl;
};

void InfoPresenter::printVersionMessage() {
    cout << "GifGen V" << VERSION << endl;
    cout << "Author: " << AUTHOR << endl;
    cout << "Feel free to use, modify and distribute the software." << endl;
    cout << "Lib: " << "STB <https://github.com/nothings/stb> (Public Domain)" << endl;
    cout << "Lib: " << "GIF-H <https://github.com/charlietangora/gif-h> (Public Domain)" << endl;
};

void InfoPresenter::printUnknowOptionMessage() {
    cout << "Unknow option." << endl;
};