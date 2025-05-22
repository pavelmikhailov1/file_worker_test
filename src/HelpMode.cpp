
#include "HelpMode.hpp"
#include "CommandLineOptions.hpp"

#include <iostream>
#include <iomanip>

void HelpMode::exec() {
    std::cout << "Usage:\n"
              << "  test -f <file> -m <mode> [-v token1 token2 ...]\n"
              << "  test -h\n\n"
              << "Options:\n";

    constexpr int col1 = 39;
    constexpr int col2 = 10;

    for (const auto& entry : help_text) {
        std::cout << std::left << std::setw(col1) << entry[0]
                  << std::setw(col2) << entry[1]
                  << entry[2] << std::endl;
    }

    std::cout << "\nModes:\n"
              << "  entry     The number of occurrences of tokens in file\n"
              << "  words     The number of complete matches with the tokens in file\n" 
              << "  checksum  Compute 32-bit checksum of the file contents\n";
}