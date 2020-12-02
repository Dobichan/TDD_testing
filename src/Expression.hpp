#pragma once

#include "Money.hpp"

class Bank;
class Money;

class Expression
{
  public:
    virtual ~Expression() {};

    virtual Money reduce(Bank * bank, std::string const & toCurrency) = 0;
};

