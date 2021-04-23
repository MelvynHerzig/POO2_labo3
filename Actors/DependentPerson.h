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
private:
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

   /**
    * @brief Message à afficher lors de la détection d'une incompatibilité.
    */
   std::string errorMessage;

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
    * @return Retourne nullptr si la personne courante peut restes avec les personnes.
    *         Sinon retourne le pointeur sur la personne problématique.
    */
   const Person* checkState(const std::list<const Person*>& persons) const override;

   /**
    * @brief Accède au message d'erreur à retourner lors d'une incompatibilité.
    * @return Retourne le message explicatif de l'incompatibilité.
    */
   std::string getErrorMessage() const override;

   /**
    * @brief Assigne une valeur au message d'erreur.
    * @param errorMessage Valeur du message d'erreur.
    */
   void setErrorMessage (const std::string &errorMessage);

   /**
    * @brief Définit les relations de la personne.
    * @param tutor Tuteur qui protège la personne des personnes incompatibles.
    * @param persons Listes des personnes incompatibles sans le tuteur.
    */
   void setRule(const Person *tutor, std::initializer_list<const Person *> persons);

};

#endif //LABO3_DEPENDENTPERSON_H
