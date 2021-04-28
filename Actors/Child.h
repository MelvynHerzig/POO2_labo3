#ifndef LABO3_CHILD_H
#define LABO3_CHILD_H

#include <string> // string

#include "DependentPerson.h"

/**
 * @brief Classe modélisant les enfants.
 * @date 28/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Child : public DependentPerson
{
private:

   /**
    * @brief L'enfant est-il un garçon.
    */
   bool isBoy;

public:

   /**
    * @brief Constructeur.
    * @param name Nom de l'enfant.
    * @param isBoy Est-ce un garcon ? si vrai oui sinon c'est une fille.
    */
   Child(const std::string& name, bool isBoy);

   /**
   * @brief Accède au message d'erreur à retourner lors d'une incompatibilité.
   * @return Retourne le message explicatif de l'incompatibilité.
   * @throw invalid_argument Si il n'a pas de tuteur ou qu'il n'a pas au moins une
   *       personne dans sa liste annotStayAloneWith.
   */
   std::string getErrorMessage() const override;
};


#endif //LABO3_CHILD_H
