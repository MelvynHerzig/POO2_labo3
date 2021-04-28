#ifndef LABO3_DEPENDENTPERSON_H
#define LABO3_DEPENDENTPERSON_H

#include <string> // string

#include "Person.h"

/**
 * @brief Modélise les personnes incapables de conduir le bateau (enfants et voleur)
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class DependentPerson : public Person
{
protected:
   /**
    * Liste des personnes avec qui elle ne peut pas rester sans son responsable.
    */
   std::list<const Person*> cannotStayAloneWith;

   /**
    * @brief Personne chargée de surveiller la personne courrante.
    *        En sa présence, elle peut rester avec les personnes dans
    *        cannotStayAloneWith sinon pas.
    */
   const Person* tutor;

public:

   /**
    * @brief Constructeur.
    * @param name Nom de la personne.
    */
   explicit DependentPerson(const std::string &name);

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
    * @brief Définit les relations de la personne.
    * @param tutor Tuteur qui protège la personne des personnes incompatibles.
    * @param persons Listes des personnes incompatibles sans le tuteur.
    */
   virtual void setRule(const Person *tutor, std::initializer_list<const Person *> persons);

};

#endif //LABO3_DEPENDENTPERSON_H
