#pragma once

#include <getopt.h>

/**
 * @brief Identifiers for command line options.
 * 
 * The values correspond to the short option characters.
 */
enum OptionID {
    OPT_FILE = 'f',      /**< Option for input file (requires argument). */
    OPT_MODE = 'm',      /**< Option for mode selection (requires argument). */
    OPT_VALUE = 'v',     /**< Option for optional list of tokens (optional argument). */
    OPT_HELP = 'h',      /**< Option to show help (no argument). */
    OPT_UNDEFINED = '?'  /**< Returned on unrecognized option. */
};

/**
 * @brief String defining short options for getopt.
 * 
 * Format:
 * - 'f:' — option -f requires an argument
 * - 'm:' — option -m requires an argument
 * - 'v::' — option -v has an optional argument
 * - 'h' — option -h is a flag with no argument
 */
static const char* short_opts = "f:m:v::h";

/**
 * @brief Array of struct option for getopt_long describing long options.
 * 
 * Each option contains:
 * - the option name (e.g., "file")
 * - argument requirement (required_argument, optional_argument, no_argument)
 * - pointer to a flag variable (nullptr here)
 * - the value returned by getopt_long when this option is found
 */
static const option long_opts[] = {
    {"file", required_argument, nullptr, OPT_FILE},
    {"mode", required_argument, nullptr, OPT_MODE},
    {"value", optional_argument, nullptr, OPT_VALUE},
    {"help", no_argument, nullptr, OPT_HELP},
    {nullptr, 0, nullptr, 0}  /**< Marks end of array */
};

/**
 * @brief Help text descriptions for command line options.
 * 
 * An array of strings describing each option for help display.
 * Format: {option(s), requirement, description}
 */
static const char* help_text[][3] = {
    {" -f, --file <filename>",    "required", "Input file to process"},
    {" -m, --mode <entry|words|checksum>", "required", "Select mode: entry count, word count or checksum"},
    {" -v, --value <tokens...>",  "optional", "List of tokens to count (for 'entry' or 'words' mode)"},
    {" -h, --help",               "flag",     "Show this help message"},
};
