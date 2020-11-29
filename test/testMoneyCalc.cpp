#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Dollar.hpp"

using namespace testing;

TEST(moneyTests, testMultiplication)
{
  Dollar five(5);
  five.times(2);
  ASSERT_THAT(five.amount, Eq(10));
}

