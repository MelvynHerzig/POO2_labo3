#include "Child.h"

#include <sstream> // stringstream

using namespace std;

Child::Child (const std::string &name, bool isBoy) : DependentPerson(name), isBoy(isBoy)
{}

std::string Child::getErrorMessage () const
{
   if(tutor == nullptr || cannotStayAloneWith.empty() || cannotStayAloneWith.front() == nullptr)
   {
      throw invalid_argument("Les relations sociales de " + getName() + " ne sont pas complètes");
   }

   stringstream result;
   result << getName() << " ne peut pas rester avec "
          << (isBoy ? "sa "  + cannotStayAloneWith.front()->getName() + " sans son " + tutor->getName()
                    : "son " + cannotStayAloneWith.front()->getName() + " sans sa "  + tutor->getName());

   return result.str();
}
