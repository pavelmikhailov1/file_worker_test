
#include "WordCountMode.hpp"
#include "FileReader.hpp"
#include "AhoCorasick.hpp"

#include <unordered_map>
#include <iostream>
#include <sstream>

WordCountMode::WordCountMode(const std::string& filename, const std::vector<std::string>& tokens, SearchMode mode)
    : _content(filereader::readTextFile(filename)), _mode(mode) {
        for (const auto& token : tokens) {
            _counters[token] = 0;
        }
    }

void WordCountMode::exec() {
    if (_mode == SearchMode::WORD) {
        execWord();
    } else if (_mode == SearchMode::ENTRY) {
        execEntry();
    }
}

void WordCountMode::execWord() {
    std::istringstream iss(_content);
    std::string word;

    while (iss >> word) {
        if (_counters.count(word)) {
            ++_counters[word];
        }
    }
    print();
}

void WordCountMode::execEntry() {
    AhoCorasick ac;
    for (auto& [token, count] : _counters) {
        ac.addToken(token, &count);
    }

    ac.build();
    ac.search(_content);

    print();
}

void WordCountMode::print() const {
    for (const auto& [token, count] : _counters) {
        std::cout << token << " - " << count << '\n';
    }
}


