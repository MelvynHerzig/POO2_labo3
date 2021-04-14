/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : ICannotDrive.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Définit la capacité de conduite du bateau.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_ICANNOTDRIVE_H
#define LABO3_ICANNOTDRIVE_H

#include "../Person.h" // canDrive

/**
 * @brief Définit le comportement: ne peut pas conduire le bateau.
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class ICannotDrive : virtual public Person
{

public:

   /**
    * Définit si la personne peut conduire le bateau.
    * @return False.
    */
   bool canDrive() const override;
};


#endif //LABO3_ICANNOTDRIVE_H
