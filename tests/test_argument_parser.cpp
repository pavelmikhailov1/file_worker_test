
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ArgumentParser.hpp"

TEST(ArgumentParserTests, HelpFlag) {
    const char* argv[] = {"prog", "-h"};
    ArgumentParser parser;
    EXPECT_TRUE(parser.parse(2, const_cast<char**>(argv)));
    EXPECT_TRUE(parser.showHelp());
}

TEST(ArgumentParserTests, ValidWordMode1) {
    const char* argv[] = {"prog", "-f", "file.txt", "-m", "words", "-v", "mother"};
    ArgumentParser parser;
    EXPECT_TRUE(parser.parse(7, const_cast<char**>(argv)));
    EXPECT_EQ(parser.filename(), "file.txt");
    EXPECT_EQ(parser.mode(), "words");
    EXPECT_THAT(parser.tokens(), ::testing::ElementsAre("mother"));
}

TEST(ArgumentParserTests, ValidWordMode2) {
    const char* argv[] = {"prog", "-f", "file.txt", "-m", "words", "-v", "mother", "father", "sister", "brother"};
    ArgumentParser parser;
    EXPECT_TRUE(parser.parse(10, const_cast<char**>(argv)));
    EXPECT_EQ(parser.filename(), "file.txt");
    EXPECT_EQ(parser.mode(), "words");
    EXPECT_THAT(parser.tokens(), ::testing::ElementsAre("mother", "father", "sister", "brother"));
}

TEST(ArgumentParserTests, ValidWordMode3) {
    const char* argv[] = {"prog", "-f", "file.txt", "-m", "entry"};
    ArgumentParser parser;
    EXPECT_TRUE(parser.parse(5, const_cast<char**>(argv)));
    EXPECT_EQ(parser.filename(), "file.txt");
    EXPECT_EQ(parser.mode(), "entry");
    EXPECT_THAT(parser.tokens(), ::testing::ElementsAre());
}

TEST(ArgumentParserTests, MissingFileArg) {
    const char* argv[] = {"prog", "-m", "checksum"};
    ArgumentParser parser;
    EXPECT_TRUE(parser.parse(3, const_cast<char**>(argv)));
    EXPECT_EQ(parser.mode(), "checksum");
    EXPECT_EQ(parser.filename(), "");
}
