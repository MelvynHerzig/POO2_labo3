#include "Container.h"

#include <iostream> // cout
#include <sstream>  // stringstream

using namespace std;

Container::Container (std::string  name) : name(std::move(name))
{}

std::ostream &operator<<(std::ostream &os, const Container& container)
{
   return container.toStream(os);
}

void Container::addPersons (std::list<const Person *> persons)
{
   for(const Person* person : persons)
   {
      addPerson(person);
   }
}

bool Container::addPerson (const Person *person)
{
   if(person == nullptr || contains(person)) return false;

   persons.push_back(person);

   return true;
}

bool Container::removePerson (const Person *person)
{
   auto foundAt = find(persons.begin(), persons.end(), person);

   // La personne est elle dans le conteneur ?
   bool result = foundAt != persons.end();

   // Si elle l'est, on la retire.
   if(result)
   {
      persons.erase(foundAt);
   }

   return result;
}

bool Container::isEmpty () const
{
   return persons.empty();
}

void Container::clear ()
{
   persons.clear();
}

const Person *Container::findByName (const std::string name) const
{
   const list<const Person*>::const_iterator it = find_if(persons.begin(), persons.end(), [&name](const Person* p) {return p->getName() == name;});
   return it != persons.end() ? *it : nullptr;
}

bool Container::contains (const Person *person)
{
   return find(persons.begin(), persons.end(), person) != persons.end();
}

string Container::personsToString () const
{
   stringstream ss;
   bool first = true;

   for(const Person* pPerson : persons)
   {
      if(!first) // Ajout des espaces entre les personnes.
      {
         ss << " ";
      }
      else
      {
         first = false;
      }

      ss << *pPerson;
   }

   return ss.str();
}

bool Container::isValid () const
{
   for(const Person* person : persons)
   {
      if( not person->checkState(persons))
      {
         return false;
      }
   }

   return true;
}


