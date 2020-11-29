#include "Dollar.hpp"

Dollar::Dollar(int amount) :
  amount{amount}
{
}

void Dollar::times(int multiplier)
{
  amount *= multiplier;
}
