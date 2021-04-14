/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Policeman.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Définir la classe modélisant le polciier.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_POLICEMAN_H
#define LABO3_POLICEMAN_H

#include <string> // string

#include "Behaviors/INotFamilyMember.h" // isFamilyMember
#include "Behaviors/ICanDrive.h"        // canDrive
#include "Person.h"                     // Person

/**
 * @brief Modéliser le policier.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class Policeman : public INotFamilyMember, public ICanDrive
{
public:
   /**
    * Constructeur.
    * @param name Nom du policier.
    */
   Policeman(const std::string& name);
};


#endif //LABO3_POLICEMAN_H
