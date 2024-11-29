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