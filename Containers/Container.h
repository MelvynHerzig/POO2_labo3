#ifndef LABO3_CONTAINER_H
#define LABO3_CONTAINER_H

#include <string>    // string
#include <list>      // List
#include <algorithm> // find

#include "../Actors/Person.h"

class Container;

/**
 * @brief Affiche un conteneur dans un flux.
 * @param os Flux dans lequel afficher le conteneur.
 * @param container Contener concerné.
 * @return Retourne le flux avec le conteneur.
 */
std::ostream &operator<< (std::ostream &os, const Container& container);


/**
 * @brief Class abstraite servant de base aux "conteneurs" de personnes.
 *        Cela inclu la barque et les rives.
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Container
{

protected:
   /**
    * @brief Nom du conteneur.
    */
   std::string name;

   /**
    * @brief Liste des personnes dans le conteneur.
    */
   std::list<const Person*> persons;

public:

   /**
    * Constructeur
    * @param name Nom du conteneur.
    */
   explicit Container(std::string  name);

   /**
    * @brief Destructeur.
    */
   virtual ~Container() = default;


   /**
    * @brief Ajoute les personnes au conteneur.
    * @param persons Personnes à ajouter.
    * @details Si la personne est déjà dans le conteneur ou que le pointeur
    *          est null, la fonction ne fait rien.
    */
   void addPersons(std::list<const Person*> persons);

   /**
    * @brief Ajoute une personne au conteneur.
    * @param person Personne à ajouter.
    * @return Retourne vrai si la personne a été ajoutée sinon faux.
    * @details Si la personne est déjà dans le conteneur ou que le pointeur
    *          est null, la fonction est sans effet et retourne faux.
    */
   virtual bool addPerson(const Person* person);

   /**
    * @brief Enlève une personne au conteneur.
    * @param person Personne à enlever.
    * @return Retourne vrai si la personne a été retirée sinon faux.
    * @details Si la personne n'est pas dans le conteneur ou que le pointeur
    *          est null, la fonction est sans effet et retourne faux..
    */
   virtual bool removePerson(const Person* person);

   /**
    * Accède à l'état du conteneur.
    * @return Retourne vrai si il est vide sinon faux.
    */
   bool isEmpty() const;

   /**
    * @brief Vide le conteneur.
    */
   void clear();

   /**
    * @brief Retourne le pointeur de la personne en fonction de son nom.
    * @param name Nom de la personne à chercher.
    * @return Retourne le pointeur de la personne correspondante si elle existe
    *         autrement nullptr.
    */
   const Person* findByName(const std::string name) const;

   /**
    * @brief Vérifie si les personnes peuvent être ensembles.
    * @return Retourne un string vide si c'est le cas sinon un
    *         descriptif de la raison.
    */
   std::string isValid() const;

   /**
    * @brief Insère un conteneur dans un flux.
    * @param os Flux recevant le conteneur
    * @return Retourne le flux avec le conteneur inséré.
    */
   virtual std::ostream &toStream (std::ostream &os) const = 0;

protected:

   /**
    * @brief Indique si la personne est dans le conteneur.
    * @param person Personne à vérifier.
    * @return Retourne vrai si la personne est dans le contenuer sinon faux.
    */
   bool contains(const Person* person);

   /**
    * @brief Insère les personnes dans un flux.
    * @param os Flux recevant les personnes
    * @return Retourne le flux avec les personnes.
    */
   std::string personsToString () const;
};

#endif //LABO3_CONTAINER_H
