#include "DependentPerson.h"

#include <algorithm> // find

using namespace std;

DependentPerson::DependentPerson (const string &name) : Person(name), tutor(nullptr)
{}


bool DependentPerson::canDrive () const
{
   return false;
}

bool DependentPerson::checkState (const std::list<const Person *> &persons) const
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

void DependentPerson::setRule (const Person *tutor, std::initializer_list<const Person *> persons)
{
   this->tutor = tutor;

   for(const Person* person : persons)
   {
      if(person != nullptr && person != tutor)
      {
         cannotStayAloneWith.emplace_back(person);
      }
   }
}




