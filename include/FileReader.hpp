#pragma once

#include <vector>
#include <string>

/**
 * @brief Namespace for file reading utilities.
 * 
 * Provides helper functions to read files as text or binary,
 * which are used by different processing modes in the application.
 */
namespace filereader {

/**
 * @brief Reads the contents of a text file.
 * 
 * Opens the file at the specified path in text mode and reads its entire
 * contents into a single string.
 * 
 * @param path Path to the text file.
 * @return A string containing the full contents of the file.
 * @throws std::runtime_error if the file cannot be opened.
 */
std::string readTextFile(const std::string& path);

/**
 * @brief Reads the contents of a binary file.
 * 
 * Opens the file at the specified path in binary mode and reads all bytes
 * into a vector of unsigned 8-bit integers.
 * 
 * @param path Path to the binary file.
 * @return A vector containing the raw binary contents of the file.
 * @throws std::runtime_error if the file cannot be opened.
 */
std::vector<uint8_t> readBinaryFile(const std::string& path);

} // namespace filereader
