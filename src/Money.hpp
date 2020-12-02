#pragma once

#include <string>

#include "Expression.hpp"

class Bank;

class Money : public Expression
{
  public:
    int amount;
    std::string currency;

  public:
    Money(int amount, std::string const & cureny);
    Money times(int multiplier);
    Expression * plus(Money const & addend);
    Money reduce(Bank * bank, std::string const & toCurrency) override;

    static Money dollar(int amount);
    static Money franc(int amount);

    bool operator==(Money & other) const;
    bool operator==(Money const & other) const;
    bool operator!=(Money & other) const;
    bool operator!=(Money const & other) const;

    friend std::ostream & operator<<(std::ostream & os, Money const & money);
};
