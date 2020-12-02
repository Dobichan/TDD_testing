#pragma once

#include "Money.hpp"

class Money;

class Expression
{
  public:
    virtual ~Expression() {};

   virtual Money reduce(std::string const & toCurrency) = 0;
};

