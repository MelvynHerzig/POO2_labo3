#include "Child.h"

#include <sstream>

using namespace std;

Child::Child (const std::string &name, bool isBoy) : DependentPerson(name), isBoy(isBoy)
{}

std::string Child::getErrorMessage () const
{
   stringstream result;

   result << getName() << " ne peut pas rester avec "
          << (isBoy ? "sa mere sans son pere" : "son pere sans sa mere");

   return result.str();
}
