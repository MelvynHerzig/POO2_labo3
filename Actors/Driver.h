#ifndef LABO3_DRIVER_H
#define LABO3_DRIVER_H

#include "Person.h"

/**
 * @brief Modélise les personnes capables de conduir le bateau (policier et parents)
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Driver : public Person
{
public:

   /**
    * @brief Constructeur.
    * @param name Nom de la personne.
    */
   explicit Driver(const std::string& name);

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   bool canDrive() const override;
};


#endif //LABO3_DRIVER_H
