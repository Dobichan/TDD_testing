#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Bank.hpp"
#include "../src/Expression.hpp"
#include "../src/Money.hpp"
#include "../src/Sum.hpp"

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

TEST(moneyTests, testSimpleAddition)
{
  Money five = Money::dollar(5);
  Expression * sum = five.plus(five);
  Bank bank;
  Money reduced = bank.reduce(sum, "USD");
  ASSERT_THAT(reduced, Eq(Money::dollar(10)));
  delete sum;
}

TEST(moneyTests, testPlusReturnsSum)
{
  Money five = Money::dollar(5);
  Expression * result = five.plus(five);
  Sum * sum = (Sum *)result;

  ASSERT_THAT(five, Eq(sum->augend));
  ASSERT_THAT(five, Eq(sum->addend));
  delete sum;
}

TEST(moneyTests, testReduceSum)
{
  Expression * sum = new Sum(Money::dollar(3), Money::dollar(4));
  Bank bank;
  Money result = bank.reduce(sum, "USD");
  ASSERT_THAT(result, Eq(Money::dollar(7)));

  delete sum;
}

TEST(moneyTests, testReduceMoney)
{
  Bank bank;
  Money one = Money::dollar(1);

  Money result = bank.reduce(&one, "USD");
  ASSERT_THAT(result, Eq(Money::dollar(1)));
}
