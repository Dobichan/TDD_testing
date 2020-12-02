#include "Sum.hpp"


Sum::Sum(Money const & augend, Money const & addend) :
  augend(augend),
  addend(addend)
{
}

Money Sum::reduce(std::string const & toCurrency)
{
  int amount = augend.amount + addend.amount;
  return Money(amount, toCurrency);
}
