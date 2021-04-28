#include "Thief.h"

#include <sstream> // stringstream

using namespace std;

Thief::Thief (const std::string &name) : DependentPerson(name)
{}

std::string Thief::getErrorMessage () const
{
   if(tutor == nullptr || cannotStayAloneWith.empty())
   {
      throw invalid_argument("Les relations sociales de " + getName() + " ne sont pas complètes");
   }

   stringstream result;
   result << "Le voleur ne peut rester avec la famille sans le" << tutor->getName();

   return result.str();
}
