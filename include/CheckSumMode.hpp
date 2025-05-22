
#pragma once

#include "IMode.hpp"
#include <string>

/**
 * @brief Mode for calculating a 32-bit checksum of a file.
 * 
 * This mode reads the contents of the specified file and computes
 * a simple 32-bit checksum by summing all 32-bit words.
 * 
 * It implements the IMode interface and is triggered when the
 * user selects the "checksum" mode via command-line arguments.
 */
class ChecksumMode final : public IMode {
public:
    /**
     * @brief Constructs the checksum mode.
     * 
     * @param filename Path to the input file whose checksum will be computed.
     */
    explicit ChecksumMode(const std::string& filename);

    /**
     * @brief Executes the checksum calculation.
     * 
     * Opens the specified file, reads it in binary mode, splits it into
     * 32-bit words, and computes the checksum as the sum of all words.
     * The result is printed to the console.
     */
    void exec() override;

private:
    std::string _filename; ///< Path to the input file.
};
