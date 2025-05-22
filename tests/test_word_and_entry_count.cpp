
#include "WordCountMode.hpp"
#include "FileReader.hpp"
#include "CreateTempFile.hpp"

#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>

TEST_F(TempFileTest, CountWords) {
    createTempFile("mother mothermother\nFather mother\n");
    WordCountMode mode(testFile, {"mother"}, SearchMode::WORD);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("2"), std::string::npos);
}

TEST_F(TempFileTest, CountWords1) {
    createTempFile("mothermother\nFather mo mother\nmoty momamom");
    WordCountMode mode(testFile, {"mo"}, SearchMode::WORD);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("1"), std::string::npos);
}

TEST_F(TempFileTest, CountEntries) {
    createTempFile("mother mothermother\nFather mother\n");
    WordCountMode mode(testFile, {"mother"}, SearchMode::ENTRY);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("4"), std::string::npos);
}

TEST_F(TempFileTest, CountEntries1) {
    createTempFile("mothermother\nFather mo mother\nmoty momamom");
    WordCountMode mode(testFile, {"mo"}, SearchMode::ENTRY);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("7"), std::string::npos);
}

