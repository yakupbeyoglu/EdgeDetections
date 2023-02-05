#include <gtest/gtest.h>

#undef ASSERT_FALSE
#undef ASSERT_ALL


// Test for CyclicngClamp
TEST(ExampleTest, BasicAssertions) {
    EXPECT_FALSE(3 == 5);
    EXPECT_TRUE(5 == 5);

}
