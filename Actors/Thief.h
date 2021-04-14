/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Thief.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Implémenter la classe modélisant le voleur.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef LABO3_THIEF_H
#define LABO3_THIEF_H

#include <string> // string

#include "Behaviors/INotFamilyMember.h" // isFamilyMember
#include "Behaviors/ICannotDrive.h"     // canDrive
#include "Person.h"                     // Person

/**
 * @brief Modélise le voleur.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class Thief : public ICannotDrive, public INotFamilyMember
{

public:

   /**
    * Constructeur.
    * @param name Nom du personnage.
    */
   Thief(const std::string& name);

};

#endif //LABO3_THIEF_H
