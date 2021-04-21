#include "NonDriver.h"

NonDriver::NonDriver (const std::string &name) : Person(name)
{}

bool NonDriver::canDrive () const
{
   return false;
}


