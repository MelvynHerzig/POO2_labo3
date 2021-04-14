/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Child.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Modéliser la classe des enfants de la famille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_CHILD_H
#define LABO3_CHILD_H

#include <string> // string

#include "Behaviors/IFamilyMember.h" // isFamilyMember
#include "Behaviors/ICannotDrive.h"     // canDrive
#include "Parent.h"                  // Parent
#include "Person.h"                  // Person

/**
 * @brief Classe modélisant les enfants de la famille
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class Child : public IFamilyMember, public ICannotDrive
{

private:

   /**
    * Père de l'enfant.
    */
   const Parent& father;

   /**
    * Mère de l'enfant.
    */
   const Parent& mother;

public:

   /**
    * Constructeur.
    * @param name Nom.
    * @param father Père.
    * @param mother Mère.
    */
   Child(const std::string& name, const Parent& father, const Parent& mother);

};

#endif //LABO3_CHILD_H
