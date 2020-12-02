#pragma once

#include <map>
#include <string>

#include "Money.hpp"
#include "Expression.hpp"

class Bank
{
  private:
    std::map<std::pair<std::string, std::string>, int> rates;

  public:
    Bank() = default;

    Money reduce(Expression * source, std::string const & toCurrency);
    void addRate(std::string const & from, std::string const & to, int rate);
    int rate(std::string const & from, std::string const & to);
};

