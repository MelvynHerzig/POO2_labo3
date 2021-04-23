#include "IndependentPerson.h"

#include <string> // string

using namespace std;

IndependentPerson::IndependentPerson (const std::string &name) : Person(name)
{}

bool IndependentPerson::canDrive () const
{
   return true;
}

const Person *IndependentPerson::checkState (const std::list<const Person *> &persons) const
{
   return nullptr;
}

std::string IndependentPerson::getErrorMessage () const
{
   return string{};
}
