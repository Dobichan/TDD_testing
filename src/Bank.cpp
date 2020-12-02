#include "Bank.hpp"
#include "Expression.hpp"
#include "Money.hpp"
#include "Sum.hpp"

Money Bank::reduce(Expression * source, std::string const & toCurrency)
{
  return source->reduce(toCurrency);
}
