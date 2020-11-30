#pragma once

#include <string>

class Money
{
  private:
    int amount;
    std::string currency;

  public:
    Money(int amount, std::string const & cureny);
    Money times(int multiplier);

    static Money dollar(int amount);
    static Money franc(int amount);

    bool operator==(Money & other) const;
    bool operator==(Money const & other) const;
    bool operator!=(Money & other) const;
    bool operator!=(Money const & other) const;
};
