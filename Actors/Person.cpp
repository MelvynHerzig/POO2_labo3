#include "Person.h"

#include <ostream>   // ostream
#include <algorithm> // find
#include <utility>

using namespace std;

ostream &operator<< (ostream& os, const Person &p)
{
   return os << p.name;
}

Person::Person (std::string   name) : name(std::move(name)), tutor(nullptr)
{}

void Person::setTutor (const Person *tutor)
{
   this->tutor = tutor;
}

void Person::setIncopatibilityWith (std::initializer_list<const Person *> persons)
{
   for(const Person* person : persons)
   {
      if(person != nullptr)
      {
         cannotStayAloneWith.emplace_back(person);
      }
   }
}

bool Person::checkState (const std::list<const Person *>& persons) const
{
   // Est-ce que le tuteur est dans les parages
   bool isTutorHere = find(persons.begin(), persons.end(), tutor) != persons.end();

   // Pour chaque personne dans les parages, est ce que l'on peut rester avec
   for(const Person* person : persons)
   {
      if(person == this) continue;
      // Est ce que la personne "person" fait partie des incompatibilités
      bool canStayWith = find(cannotStayAloneWith.begin(), cannotStayAloneWith.end(), person) == cannotStayAloneWith.end();

      // Si elle ne sont pas compatibles et que le tuteur n'est pas là.
      if(not canStayWith && not isTutorHere)
      {
         return false;
      }
   }

   // La personne est compatibles avec toutes les personnes dans persons.
   return true;
}

const string& Person::getName () const
{
   return name;
}





