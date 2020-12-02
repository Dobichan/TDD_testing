#pragma once

#include <string>

#include "Money.hpp"
#include "Expression.hpp"

class Bank
{
  public:
    Bank() = default;

    Money reduce(Expression * source, std::string const & toCurrency);
};

