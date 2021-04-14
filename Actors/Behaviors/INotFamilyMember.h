/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : INotFamilyMember.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Définit qu'une personne ne fait pas partie de la famille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_INOTFAMILYMEMBER_H
#define LABO3_INOTFAMILYMEMBER_H

#include "../Person.h" // isFamilyMember

/**
 * @brief Définit le comportement: n'est pas membre de la famille.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class INotFamilyMember : virtual public Person
{

public:

   /**
    * Définit si la personne est un membre de la famille.
    * @return False.
    */
   bool isFamilyMember() const override;
};


#endif //LABO3_INOTFAMILYMEMBER_H
