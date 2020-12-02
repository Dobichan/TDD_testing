#pragma once

#include "Money.hpp"
#include "Expression.hpp"

class Bank;

class Sum : public Expression
{
  public:
    Sum(Money const & augend, Money const & addend);
    Money reduce(Bank * bank, std::string const & toCurrency) override;

    Money augend;
    Money addend;
};

