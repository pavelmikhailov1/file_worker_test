
#include <string>
#include <array>
#include <memory>
#include <stdexcept>
#include <regex>
#include <cstdint>

std::string get32BitSum(const std::string& pathFile) {
    std::string command = "bash ../../tests/tools/get_32bit_sum.sh " + pathFile;
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("Failed to run script");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();  
    }

    result.erase(result.find_last_not_of("\n\r") + 1);

    return result;
}


std::string getSum(const std::string& str) {
    std::regex numberRegex(R"(\d+)");
    std::smatch match;

    if (std::regex_search(str, match, numberRegex)) {
        return match.str();
    }

    throw std::runtime_error("No number found in string");
}
