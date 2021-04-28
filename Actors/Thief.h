#ifndef LABO3_THIEF_H
#define LABO3_THIEF_H

#include <string> // string

#include "DependentPerson.h"

/**
 * @brief Classe modélisant le voleur.
 * @date 28/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Thief : public DependentPerson
{
private:

   /**
    * @brief Message d'erreur en cas d'incompatibilité.
    */
   static const std::string errorMessage;

public:

   /**
    * @brief Constructeur.
    * @param name Nom du voleur.
    */
   explicit Thief(const std::string& name);

   /**
    * @brief Accède au message d'erreur à retourner lors d'une incompatibilité.
    * @return Retourne le message explicatif de l'incompatibilité.
    */
   std::string getErrorMessage() const override;
};


#endif //LABO3_THIEF_H
