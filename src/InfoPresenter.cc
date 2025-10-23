/**
 * InfoPresenter implementation.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define INFO_PRESENTER_H_IMPLEMENTATION
#include "../include/InfoPresenter.hh"
#include <iostream>

using namespace std;

#define VERSION "0.1"
#define AUTHOR "Alan José <alanjsdelima@gmail.com>"

void InfoPresenter::printHelpMessage() {
    cout << "Usage: gifgen [options]" << endl;
    cout << "\t-d | --directory <frames directory>" << endl;
    cout << "\tDefine the image frames folder to generate the GIF file." << endl;
    cout << "\t\t-o | --output-path <output path>" << endl;
    cout << "\t\tDefines the GIF file output path." << endl;
    cout << "\t\t\t-h | --help" << endl;
    cout << "\t\t\tShows this help message." << endl;
    cout << "\t\t\t\t-v | --version" << endl;
    cout << "\t\t\t\tShows the program version, author information and licenses." << endl;
};

void InfoPresenter::printVersionMessage() {
    cout << "GifGen V" << VERSION << endl;
    cout << "Author:" << AUTHOR << endl;
    cout << "Feel free to use, modify and distribute the software." << endl;
    cout << "Lib:" << "STB <https://github.com/nothings/stb> (Public Domain)" << endl;
    cout << "Lib:" << "GIF-H <https://github.com/charlietangora/gif-h> (Public Domain)" << endl;
};

void InfoPresenter::printUnknowOptionMessage() {
    cout << "Unknow option." << endl;
};