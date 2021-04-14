/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : ICanDrive.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Définit l' incapacité de conduite du bateau.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_ICANDRIVE_H
#define LABO3_ICANDRIVE_H

#include "../Person.h" // canDrive

/**
 * @brief Définit le comportement: peut conduire le bateau.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class ICanDrive : virtual public Person
{

public:

   /**
    * Définit si la personne peut conduire le bateau.
    * @return True.
    */
   bool canDrive() const override;
};


#endif //LABO3_ICANDRIVE_H
