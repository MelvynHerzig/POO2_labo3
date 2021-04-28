#include "Thief.h"

const std::string Thief::errorMessage = "Le voleur ne peut rester avec la famille sans le policier";

Thief::Thief (const std::string &name) : DependentPerson(name)
{}

std::string Thief::getErrorMessage () const
{
   return errorMessage;
}
