/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Parent.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Modéliser la classe des parents.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_PARENT_H
#define LABO3_PARENT_H

#include <string> // string

#include "Behaviors/IFamilyMember.h" // isFamilyMember
#include "Behaviors/ICanDrive.h"     // canDrive
#include "Person.h"                  // Person

/**
 * @brief Classe modélisant les parents.
 * @authors Forestier Quentin & Herzig Melvyn.
 * @date 14/04/2021
 */
class Parent : public IFamilyMember, public ICanDrive
{

public:
   /**
    * Constructeur.
    * @param name Nom de la personne.
    */
   Parent(const std::string& name);
};


#endif //LABO3_PARENT_H
