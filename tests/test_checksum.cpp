
#include "CheckSumMode.hpp"
#include "FileReader.hpp"
#include "CreateTempFile.hpp"
#include "TestUtl.hpp"

#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>

TEST_F(TempFileTest, CheckSum) {
    createTempFile("mother mothermother\nFather mother\n");
    ChecksumMode mode(testFile);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    try {
        EXPECT_EQ(getSum(output), get32BitSum(testFile));
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

TEST_F(TempFileTest, CheckSum1) {
    createTempFile("kjsadgjkgd ksjdgkjsdgkjdsgkjkjsdg;akl; askdosiahgbgan;s,cansc 12421412lj4l214n;12");
    ChecksumMode mode(testFile);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    try {
        EXPECT_EQ(getSum(output), get32BitSum(testFile));
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


TEST_F(TempFileTest, CheckSum2) {
    createTempFile("");
    ChecksumMode mode(testFile);
    testing::internal::CaptureStdout();
    mode.exec();
    std::string output = testing::internal::GetCapturedStdout();
    try {
        EXPECT_EQ(getSum(output), get32BitSum(testFile));
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}