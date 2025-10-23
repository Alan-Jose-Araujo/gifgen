/**
 * This class will provide methods to handle filesystem paths.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#ifndef PATH_UTILS_H
#define PATH_UTILS_H

#include <string>

using namespace std;

class PathUtils {

    public:

        /**
         * This method separates the directories and create it if not exists.
         * Having file name with extension (eg: .gif), creates it, case not,
         * set the current timestamp as file name.
         */
        static string prepareOutputPath(const string& rawPath);

};

#endif