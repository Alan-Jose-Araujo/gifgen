/**
 * This class will parse and handle the cli arguments.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#ifndef CLI_ARGUMENT_PARSER_HH
#define CLI_ARGUMENT_PARSER_HH

#include <getopt.h>
#include <functional>
#include <vector>
#include <string>

/**
 * CliArgumentParser
 * @param const char* shortOptions;
 * @param std::vector<option> longOptions;
 */
class CliArgumentParser {

    private:

        const char* shortOptions;

        std::vector<option> longOptions;

    public:

        CliArgumentParser(const char* shortOptions, const std::vector<option>& longOptions);

        void parse(int argc, char* argv[], const std::function<void(int, const char*)>& callback);

};

#endif