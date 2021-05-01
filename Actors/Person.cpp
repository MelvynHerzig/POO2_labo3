#include "Person.h"

#include <ostream> // ostream

using namespace std;

ostream& operator<< (ostream& os, const Person &p)
{
   return p.toStream(os);
}

Person::Person (const std::string& name) : name(name)
{}

string Person::getName () const
{
   return name;
}

std::ostream &Person::toStream (ostream &os) const
{
   return os << name;
}






