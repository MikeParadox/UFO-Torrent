#include "ufo_torrent.h"
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <gtest/gtest.h>

TEST(TestCaseName, TestName)
{
    EXPECT_EQ(testSum(2, 2), 4);
    const auto x = boost::multiprecision::int128_t(1234123521);
    const auto y = boost::multiprecision::int128_t(1234123521);
    EXPECT_EQ(x, y);
}