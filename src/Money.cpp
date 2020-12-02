#include <iostream>

#include "Bank.hpp"
#include "Money.hpp"
#include "Sum.hpp"

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

Expression * Money::plus(Money const & addend)
{
  return new Sum(*this, addend);
}

Money Money::reduce(Bank * bank, std::string const & toCurrency)
{
  int rate = bank->rate(currency, toCurrency);

  return Money(amount / rate, toCurrency);
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

std::ostream & operator<<(std::ostream & os, Money const & money)
{
  os << std::string("Money: ") << money.amount << money.currency;
  return os;
}
