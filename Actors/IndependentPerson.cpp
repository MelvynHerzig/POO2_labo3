#include "IndependentPerson.h"

#include <string> // string

using namespace std;

IndependentPerson::IndependentPerson (const std::string& name) : Person(name)
{}

bool IndependentPerson::canDrive () const
{
   return true;
}

bool IndependentPerson::checkState (const std::list<const Person *> &persons) const
{
   return true;
}

std::string IndependentPerson::getErrorMessage () const
{
   return string{};
}
