#include "Bank.h"

Bank::Bank (const std::string &name) : Container(name)
{}

std::ostream& Bank::toStream (std::ostream &os) const
{
   return os << name << ": " << personsToString();
}

