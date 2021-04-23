#include "Person.h"

#include <ostream>   // ostream
#include <algorithm> // find
#include <utility>

using namespace std;

ostream &operator<< (ostream& os, const Person &p)
{
   return os << p.name;
}

Person::Person (std::string   name) : name(std::move(name))
{}


const string& Person::getName () const
{
   return name;
}






