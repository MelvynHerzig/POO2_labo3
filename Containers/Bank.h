#ifndef LABO3_BANK_H
#define LABO3_BANK_H

#include "Container.h"

#include <ostream> // ostream

/**
 * @brief Modélise les rives.
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Bank : public Container
{
private:

public:

   /**
    * @brief Constructeur.
    * @param name Nom du rivage.
    */
   explicit Bank(const std::string& name);

   /**
    * @brief Insère un conteneur dans un flux.
    * @param os Flux recevant le conteneur
    * @return Retourne le flux avec le conteneur inséré.
    */
   std::ostream &toStream (std::ostream &os) const override;
};


#endif //LABO3_BANK_H
