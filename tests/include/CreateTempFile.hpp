
#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>

class TempFileTest : public ::testing::Test {
protected:
    void createTempFile(const std::string& content) {
        testFile = std::filesystem::temp_directory_path() / "file_worker_test.txt";
        std::ofstream out(testFile);
        if (!out) {
            FAIL() << "error open temp file: " << testFile;
        }
        out << content;
        out.close();
    }

    void TearDown() override {
        std::error_code ec;
        std::filesystem::remove(testFile, ec);
        if (ec) {
            FAIL() << "error delete temp file: " << testFile << ": " << ec.message();
        }
    }

    std::filesystem::path testFile;
};