#include "Money.hpp"

Money::Money(int amount, std::string const & currency) :
  amount(amount),
  currency(currency)
{
}

Money Money::dollar(int amount)
{
  return Money(amount, "USD");
}

Money Money::franc(int amount)
{
  return Money(amount, "CHF");
}

Money Money::times(int multiplier)
{
  return Money(amount * multiplier, currency);
}

bool Money::operator==(Money & other) const
{
  return amount == other.amount &&
         currency == other.currency;
}

bool Money::operator==(Money const & other) const
{
  return amount == other.amount &&
        currency == other.currency;
}

bool Money::operator!=(Money & other) const
{
  return !(*this == other);
}

bool Money::operator!=(Money const & other) const
{
  return !(*this == other);
}
