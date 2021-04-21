#ifndef LABO3_NONDRIVER_H
#define LABO3_NONDRIVER_H

#include "Person.h"

/**
 * @brief Modélise les personnes incapables de conduir le bateau (enfants et voleur)
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class NonDriver : public Person
{
public:

   /**
    * @brief Constructeur.
    * @param name Nom de la personne.
    */
   explicit NonDriver(const std::string& name);

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   bool canDrive() const override;
};

#endif //LABO3_NONDRIVER_H
