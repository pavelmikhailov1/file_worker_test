#pragma once

#include "IMode.hpp"

#include <vector>
#include <string>
#include <unordered_map>

/**
 * @brief Defines the mode of word search in the file.
 * 
 * - WORD: match whole words only (token-based).
 * - ENTRY: match all substring entries (e.g., "art" in "cart").
 */
enum class SearchMode {
    WORD,   ///< Search for whole word matches.
    ENTRY   ///< Search for substring occurrences.
};

/**
 * @brief Mode that counts the occurrences of specified tokens in a file.
 * 
 * Depending on the selected SearchMode, it either counts:
 * - exact word matches (SearchMode::WORD), or
 * - substring matches (SearchMode::ENTRY).
 * 
 * It implements the IMode interface and is triggered when the
 * user selects the "entry or words" mode via command-line arguments.
 */
class WordCountMode final : public IMode {
public:
    /**
     * @brief Constructs a WordCountMode.
     * 
     * @param filename Path to the input file.
     * @param tokens List of strings to search for.
     * @param mode Search mode (whole word or entry).
     */
    WordCountMode(const std::string& filename,
                  const std::vector<std::string>& tokens,
                  SearchMode mode);

    /**
     * @brief Executes the word count mode.
     * 
     * Runs the appropriate counting logic based on the selected SearchMode.
     */
    void exec() override;

private:
    /**
     * @brief Performs counting of full word matches.
     * 
     * Tokenizes the input file content and counts exact word occurrences.
     */
    void execWord();

    /**
     * @brief Performs counting of substring entries.
     * 
     * Finds all overlapping substring matches of each token.
     */
    void execEntry();

    /**
     * @brief Prints the result of counting.
     * 
     * Outputs the counts for each token to the standard output.
     */
    void print() const;
    
    std::string _content;  ///< Contents of the input file.
    std::unordered_map<std::string, std::size_t> _counters; ///< Map of token counts.
    SearchMode _mode;      ///< Selected search mode.
};
