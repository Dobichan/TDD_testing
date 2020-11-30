#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Money.hpp"

using namespace testing;

TEST(moneyTests, testMultiplication)
{
  auto five = Money::dollar(5);
  ASSERT_THAT(five.times(2), Eq(Money::dollar(10)));
  ASSERT_THAT(five.times(3), Eq(Money::dollar(15)));
}

TEST(moneyTests, testEquality)
{
  auto five = Money::dollar(5);
  auto six = Money::dollar(6);
  auto fiveFranc = Money::franc(5);

  ASSERT_THAT(five, Eq(Money::dollar(5)));
  ASSERT_THAT(five, Ne(six));
  ASSERT_THAT(five, Ne(fiveFranc)) << "Five dollars should not be equal to five francs";
}

TEST(moneyTests, testFrancMultiplication)
{
  auto five = Money::franc(5);
  ASSERT_THAT(five.times(2), Eq(Money::franc(10)));
  ASSERT_THAT(five.times(3), Eq(Money::franc(15)));
}
