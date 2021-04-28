#include "Person.h"

#include <ostream>   // ostream
#include <algorithm> // find
#include <utility>

using namespace std;

ostream &operator<< (ostream& os, const Person &p)
{
   return os << p.getName();
}

Person::Person (std::string   name) : name(std::move(name))
{}


string Person::getName () const
{
   return name;
}

std::ostream &Person::toStream (ostream &os) const
{
   return os << name;
}






