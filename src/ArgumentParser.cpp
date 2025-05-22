
#include "ArgumentParser.hpp"
#include "CommandLineOptions.hpp"

#include <iostream>
#include <getopt.h>
#include <regex.h>

ArgumentParser::ArgumentParser() : _help(false) {
}

bool ArgumentParser::isValidMode(const std::string& mode) {
    return mode == "entry" || mode == "words" || mode == "checksum";
}

const std::string& ArgumentParser::filename() const {
    return _filename;
}

const std::string& ArgumentParser::mode() const {
    return _mode;
}

const std::vector<std::string>& ArgumentParser::tokens() const {
    return _tokens;
}

bool ArgumentParser::showHelp() const {
    return _help;
}

bool ArgumentParser::parse(int argc, char* argv[]) {
    int opt;
    opterr = 0;

    while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) != -1) {
        switch (opt) {
            case OPT_FILE:
                _filename = optarg;
                break;
            case OPT_MODE:
                _mode = optarg;
                if (!isValidMode(_mode)) {
                    std::cerr << "Invalid mode: " << _mode << std::endl;
                    return false;
                }
                break;
            case OPT_VALUE:
                break;
            case OPT_HELP:
                _help = true;
                return true;
            case OPT_UNDEFINED:
                std::cerr << "Invalid flag: " << argv[optind - 1] << std::endl;
                return false;
            default:
                return false;
        }
    }

    while (optind < argc) {
        _tokens.emplace_back(argv[optind++]);
    }

    regex_t regex;
    if (regcomp(&regex, "^[[:alnum:]_./\\\\-]+$", REG_EXTENDED) != 0) {
        std::cerr << "Failed to compile regex\n";
        return false;
    }

    if (!_filename.empty() && regexec(&regex, _filename.c_str(), 0, nullptr, 0) != 0) {
        std::cerr << "Invalid filename: " << _filename << std::endl;
        regfree(&regex);
        return false;
    }

    regfree(&regex);
    return true;
}
