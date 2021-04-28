#include "Boat.h"
#include <ostream>   // ostream
#include <algorithm> // any_of

using namespace std;

Boat::Boat (size_t capacity, const Bank* leftBank, const Bank* rightBank)
           : Container("Bateau"), BOAT_CAPACITY(capacity), LEFT_BANK(leftBank), RIGHT_BANK(rightBank)
{
   this->currentBank = leftBank;
}

bool Boat::addPerson (const Person* person)
{
   bool result = false;
   // Si il y a encore de la place et que la personne a pû embarquer.
   if(nbOnBoard <  BOAT_CAPACITY && !contains(person))
   {
      result = Container::addPerson(person);
      ++nbOnBoard;
   }

   return result;
}

bool Boat::removePerson (const Person *person)
{
   bool result = false;

   // Si la personne a pû débarquer.
   if(contains(person))
   {
      result = Container::removePerson(person);
      --nbOnBoard;
   }

   return result;
}

ostream& Boat::toStream (ostream &os) const
{
   return os << name << ": < " << personsToString() << " >";
}

bool Boat::isDriverOnBoard() const
{
   // Au moins un passager du bâteau est-il capable de le conduire ?
   return any_of(persons.begin(), persons.end(), [](const Person* p){return p->canDrive();});
}

void Boat::navigate ()
{
   currentBank = (currentBank == LEFT_BANK) ? RIGHT_BANK : LEFT_BANK;
}

const Bank *Boat::getCurrentBank () const
{
   return currentBank;
}
