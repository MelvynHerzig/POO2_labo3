/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Child.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021
 -----------------------------------------------------------------------------------
 */

#include "Child.h"

Child::Child(const std::string& name, const Parent& father, const Parent& mother)
            : Person(name), father(father), mother(mother)
{}
