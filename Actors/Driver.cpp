#include "Driver.h"

Driver::Driver (const std::string &name) : Person(name)
{}

bool Driver::canDrive () const
{
   return true;
}
