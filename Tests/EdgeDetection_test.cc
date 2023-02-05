#undef ASSERT_FALSE
#undef ASSERT_ALL
#include <gtest/gtest.h>
#include <stdexcept>
#include "../Source/BoxKernel.h"



// Test for CyclicngClamp
TEST ( BoxKernelInitializeTest, BasicAssertions )
{
    EXPECT_THROW ( EdgeDetections::BoxKernel ( {{1,2,3}} ), std::runtime_error );
    EXPECT_THROW ( EdgeDetections::BoxKernel ( {{}} ), std::runtime_error );
    EXPECT_NO_THROW ( EdgeDetections::BoxKernel ( {{1,2,3}, {1,2,3}, {1,2,3}} ) );
}

TEST ( BoxKernelTotalTest, BasicAssertions )
{
    EdgeDetections::BoxKernel kernel = {{1,2,3}, {4,5,6}, {7,8,9}};
    EXPECT_TRUE(kernel.GetTotal() == 45);
}

TEST ( GetValueTest, BasicAssertions )
{
    EdgeDetections::BoxKernel kernel = {{1,2,3}, {4,5,6}, {7,8,9}};
    EXPECT_TRUE(kernel.GetValueAt(2,1) == 8);
    EXPECT_TRUE(kernel[2][1] == 8.0f);
    EXPECT_TRUE(kernel[2][5] == -1);
    
    EXPECT_THROW(kernel.GetValueAt(2,5), std::runtime_error);
    EXPECT_THROW(kernel[5][5], std::runtime_error);
}
