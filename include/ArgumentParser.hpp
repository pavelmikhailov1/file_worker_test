#pragma once

#include <string>
#include <vector>

/**
 * @brief Class for parsing command line arguments.
 * 
 * Supports reading the input filename, mode of operation, a list of tokens, and help flag.
 */
class ArgumentParser final {
public:
    /**
     * @brief Default constructor.
     * 
     * Initializes internal members with default values.
     */
    ArgumentParser();

    /**
     * @brief Parses command line arguments.
     * 
     * @param argc Number of command line arguments.
     * @param argv Array of command line argument strings.
     * @return true if arguments are valid and parsed successfully; false otherwise.
     */
    bool parse(int argc, char* argv[]);

    /**
     * @brief Filename getter.
     * 
     * @return Path file.
     */
    const std::string& filename() const;

    /**
     * @brief Mode getter.
     * 
     * @return The operation mode (e.g., "words", "entry", "checksum").
     */
    const std::string& mode() const;

    /**
     * @brief Tokens getter.
     * 
     * @return Vector of tokens.
     */
    const std::vector<std::string>& tokens() const;

    /**
     * @brief Checks if help flag was requested.
     * 
     * @return true if help flag is set; false otherwise.
     */
    bool showHelp() const;

private:
    /**
     * @brief Checks if the provided mode string is valid.
     * 
     * @param mode The mode string to validate.
     * @return true if the mode is valid; false otherwise.
     */
    bool isValidMode(const std::string& mode);

    std::string _filename;               ///< Filename from arguments.
    std::string _mode;                   ///< Mode of operation.
    std::vector<std::string> _tokens;    ///< Tokens to search for.
    bool _help;                          ///< Help flag.
};
