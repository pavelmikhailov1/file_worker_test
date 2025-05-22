

#include "CheckSumMode.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <cstdint>

ChecksumMode::ChecksumMode(const std::string& filename)
    : _filename(filename) {}

void ChecksumMode::exec() {
    std::vector<uint8_t> buffer;
    try {
        buffer = filereader::readBinaryFile(_filename);
    } catch (const std::exception& e) { throw e; }
    
    uint32_t checksum = 0;
    size_t i = 0;
    while (i + 3 < buffer.size()) {
        uint32_t word = static_cast<uint32_t>(buffer[i]) |
                        (static_cast<uint32_t>(buffer[i+1]) << 8) |
                        (static_cast<uint32_t>(buffer[i+2]) << 16) |
                        (static_cast<uint32_t>(buffer[i+3]) << 24);
        checksum += word;
        i += 4;
    }

    // remains
    if (i < buffer.size()) {
        uint32_t word = 0;
        for (size_t j = 0; j < buffer.size() - i; ++j) {
            word |= static_cast<uint32_t>(buffer[i + j]) << (8 * j);
        }
        checksum += word;
    }

    std::cout << "Checksum " << _filename << ": " << checksum << std::endl;
}
