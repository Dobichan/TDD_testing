#include "Sum.hpp"


Sum::Sum(Money const & augend, Money const & addend) :
  augend(augend),
  addend(addend)
{
}

Money Sum::reduce(Bank * bank, std::string const & toCurrency)
{
  int amount = augend.reduce(bank, toCurrency).amount + addend.reduce(bank, toCurrency).amount;
  return Money(amount, toCurrency);
}
