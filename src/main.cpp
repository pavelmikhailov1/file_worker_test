
#include "ArgumentParser.hpp"
#include "IMode.hpp"
#include "WordCountMode.hpp"
#include "CheckSumMode.hpp"
#include "HelpMode.hpp"

#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    ArgumentParser parser;
    if (!parser.parse(argc, argv)) {
        std::cerr << "Invalid argument. Use -h for info." << std::endl;
        return 1;
    }

    try {
        std::unique_ptr<IMode> mode;
        const std::string& m = parser.mode();
        
        if (m == "entry") {
            mode = std::make_unique<WordCountMode>(parser.filename(), parser.tokens(), SearchMode::ENTRY);
        } else if (m == "words") {
            mode = std::make_unique<WordCountMode>(parser.filename(), parser.tokens(), SearchMode::WORD);
        } else if (m == "checksum") {
            mode = std::make_unique<ChecksumMode>(parser.filename());
        } else {
            mode = std::make_unique<HelpMode>();
        }

        mode->exec();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
