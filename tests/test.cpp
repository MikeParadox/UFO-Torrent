#include "ufo_torrent.h"
#include "decode.h"
#include "encode.h"
#include <gtest/gtest.h>
using namespace bencode;


using std::string;
using std::pair;
using std::string;

class Dr_list_test : public testing::Test
{
protected:
    Dr s{};
};

class Dec_test : public testing::Test
{
protected:
    Str d1{};
    Str d2{};
};

//TEST LIST
TEST_F(Dr_list_test, first_test)
{
    std::string input = "li1ei2ee"; 
    EXPECT_EQ(Encoder::encode(s.decodeLst(input).first), "li1ei2ee");
}

TEST_F(Dr_list_test, second_test)
{
    ASSERT_DEATH(s.decodeLst(""), "Invalid format");
}

TEST_F(Dr_list_test, third_test)
{
    ASSERT_DEATH(s.decodeLst("i161231183942184912"), "Invalid format");
}

TEST_F(Dr_list_test, fourth_test)
{
    EXPECT_EQ(Encoder::encode(s.decodeLst("lli1ei2eee2").first), "lli1ei2eee");
}

TEST_F(Dr_list_test, fifth_test)
{
    ASSERT_DEATH(s.decodeLst("le"), "Invalid format");
}

//TEST STRING
TEST_F(Dec_test, general_test)
{
    std::pair<std::string, int> res{ "ubun", 4 };
    ASSERT_EQ(d1.decodeStr("4:ubuntu").first, res.first);
}

TEST_F(Dec_test, general_test_2)
{
    ASSERT_DEATH(d1.decodeStr("i1414196789697899969898989898889:something"), "Âûõîä çà äèàïîçîí");
}

TEST_F(Dec_test, general_test_3)
{
    ASSERT_DEATH(d1.decodeStr("i0:someth"), "Íåâåðíûé ôîðìàò");
}

TEST_F(Dec_test, general_test_4)
{
    std::pair<std::string, int>res{ "abcd", 6 };
    ASSERT_EQ(d1.decodeStr("4:abcd"), res);
}

TEST_F(Dec_test, general_test_5)
{
    ASSERT_DEATH(d1.decodeStr("i4:qwerty123:key5"), "Íåâåðíûé ôîðìàò");
}

TEST_F(Dec_test, general_test_6)
{
    ASSERT_DEATH(d1.decodeStr("i:abcd"), "Íåâåðíûé ôîðìàò ââîäà");
}

TEST_F(Dec_test, general_test_7)
{
    std::pair<std::string, int>res{ "QWET", 6 };
    ASSERT_EQ(d1.decodeStr("4:QWETRT&@"), res);
}

TEST_F(Dec_test, general_test_8)
{
    ASSERT_DEATH(d1.decodeStr("4:").first, "Íåâåðíûé ôîðìàò");
}

TEST_F(Dec_test, general_test_9)
{
    std::pair<std::string, int>res{ "some", 6 };
    std::pair<std::string, int>res2{ "some", 6 };
    ASSERT_EQ(d1.decodeStr("4:something"), res);
    ASSERT_EQ(d2.decodeStr("4:some").first, res2.first);
}
TEST_F(Dec_test, general_test_10)
{
    ASSERT_DEATH(d2.decodeStr("4:som"), "Íåïðàâèëüíûé ââîä");
}

TEST_F(Dec_test, general_test_11)
{
    ASSERT_DEATH(d1.decodeStr(":abcd"), "Îòñóòñòâóåò ÷èñëî");
}
