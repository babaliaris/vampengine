#include <gtest/gtest.h>

TEST(Testing, googletest)
{
    GTEST_ASSERT_EQ(true, true) << "This test should never faild!";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}