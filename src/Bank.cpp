#include <iostream>

#include "Bank.hpp"
#include "Expression.hpp"
#include "Money.hpp"
#include "Sum.hpp"

Money Bank::reduce(Expression * source, std::string const & toCurrency)
{
  return source->reduce(this, toCurrency);
}

void Bank::addRate(std::string const & from, std::string const & to, int rate)
{
  std::pair<std::string, std::string> key(from, to);
  rates[key] = rate;
}

int Bank::rate(std::string const & from, std::string const & to)
{
  std::pair<std::string, std::string> key(from, to);

  if (from == to)
    return 1;

  int rate = -1;

  try
  {
    rate = rates.at(key);
  }
  catch (...)
  {
  }

  return rate;
}
