/**
 * CliArgumentParser implementation.
 * @author Alan José <alanjsdelima@gmail.com>
 */
#define CLI_ARGUMENT_PARSER_H_IMPLEMENTATION
#include "../include/CliArgumentParser.hh"

CliArgumentParser::CliArgumentParser(const char* shortOptions, const std::vector<option>& longOptions)
: shortOptions(shortOptions), longOptions(longOptions) {};

void CliArgumentParser::parse(int argc, char* argv[], const std::function<void(int, const char*)>& callback) {
    int cliOption;
    std::vector<option> options = longOptions;
    // 'getopt_long' function requires a C-style array, so add the terminator at the end.
    options.push_back({nullptr, 0, nullptr, 0});

    while((cliOption = getopt_long(argc, argv, shortOptions, options.data(), nullptr)) != -1) {
        callback(cliOption, optarg);
    }
}