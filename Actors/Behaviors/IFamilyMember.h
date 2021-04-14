/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : IFamilyMember.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Définit qu'une personne fait partie de la famille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_IFAMILYMEMBER_H
#define LABO3_IFAMILYMEMBER_H

#include "../Person.h" // isFamilyMember


/**
 * @brief Définit le comportement: est membre de la famille.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class IFamilyMember : virtual public Person
{

public:

   /**
    * Définit si la personne est un membre de la famille.
    * @return True.
    */
   bool isFamilyMember() const override;
};


#endif //LABO3_IFAMILYMEMBER_H
