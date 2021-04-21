#include "Boat.h"
#include <ostream>   // ostream
#include <algorithm> // any_of

using namespace std;

Boat::Boat (size_t capacity, const Bank* leftBank, const Bank* rightBank)
           : Container("Bateau"), BOAT_CAPACITY(capacity)
{
   this->leftBank = leftBank;
   this->rightBank = rightBank;
   this->currentBank = leftBank;
}

bool Boat::addPerson (const Person *person)
{
   // Si il y a encore de la place et que la personne a pû embarquer.
   if(nbOnBoard <  BOAT_CAPACITY && Container::addPerson(person))
   {
      ++nbOnBoard;
      return true;
   }
   else // sinon
   {
      return false;
   }
}

bool Boat::removePerson (const Person *person)
{
   // Si la personne a pû débarquer.
   if(Container::removePerson(person))
   {
      --nbOnBoard;
      return true;
   }
   else
   {
      return false;
   }
}

ostream& Boat::toStream (ostream &os) const
{
   return os << name << ": < " << personsToString() << " >";
}

bool Boat::isDriverOnBoard()
{
   // Au moins un passager du bâteau est-il capable de le conduir ?
   return any_of(persons.begin(), persons.end(), [](const Person* p){return p->canDrive();});
}

void Boat::navigate ()
{
   currentBank = (currentBank == leftBank) ? rightBank : leftBank;
}

const Bank *Boat::getCurrentBank () const
{
   return currentBank;
}
