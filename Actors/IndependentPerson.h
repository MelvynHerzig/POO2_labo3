#ifndef LABO3_INDEPENDENTPERSON_H
#define LABO3_INDEPENDENTPERSON_H

#include "Person.h"

/**
 * @brief Modélise les personnes capables de conduir le bateau (policier et parents)
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class IndependentPerson : public Person
{
public:

   /**
    * @brief Constructeur.
    * @param name Nom de la personne.
    */
   explicit IndependentPerson(const std::string& name);

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   bool canDrive() const override;

   /**
    * @brief Vérifie si elle peut rester avec les personnes en argument.
    * @param persons Personnes qui accompagnent la personne courante.
    * @return Retourne true si la personne courante peut rester avec les personnes.
    *         Sinon retourne false.
    */
   bool checkState(const std::list<const Person*>& persons) const override;

   /**
    * @brief Accède au message d'erreur à retourner lors d'une incompatibilité.
    * @return Retourne le message explicatif de l'incompatibilité.
    */
   std::string getErrorMessage() const override;
};


#endif //LABO3_INDEPENDENTPERSON_H
