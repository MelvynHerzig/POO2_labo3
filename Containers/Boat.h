#ifndef LABO3_BOAT_H
#define LABO3_BOAT_H

#include "Container.h"
#include "Bank.h"

#include <cstdlib> // size_t

/**
 * @brief Modélise le bateau permettant de traverser entre les deux rives.
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Boat : public Container
{
private:
   /**
    * @brief Capacité maximale du bateau.
    */
   const std::size_t BOAT_CAPACITY;

   /**
    * @brief Nombre de personnes dans le bateau.
    */
   size_t nbOnBoard = 0;

   /**
    * @brief Rive gauche.
    */
   const Bank* const LEFT_BANK;

   /**
    * @brief Rive droite.
    */
   const Bank* const RIGHT_BANK;

   /**
    * @brief Rive accostée.
    */
   const Bank* currentBank;

public:

   /**
    * @brief Constructeur.
    * @param capacity Capacité du bateau
    * @param leftBank Rive gauche (rive de départ).
    * @param rightBank Rive droite.
    */
    Boat (size_t capacity, const Bank* leftBank, const Bank* rightBank);

   /**
   * @brief Ajoute une personne au conteneur.
   * @param person Personne à ajouter.
   * @return Retourne vrai si la personne a été ajoutée sinon faux.
   * @details Si la personne est déjà dans le conteneur ou que le pointeur
   *          est null, ou bateau plein la fonction est sans effet return false sinon true.
   */
   bool addPerson (const Person* person) override;

   /**
    * @brief Enlève une personne au conteneur.
    * @param person Personne à enlever.
    * @return Retourne vrai si la personne a été retirée sinon faux.
    * @details Si la personne n'est pas dans le conteneur ou que le pointeur
    *          est null, la fonction est sans effet return false sinon true.
    */
   bool removePerson (const Person* person) override;

   /**
    * @brief Insère un conteneur dans un flux.
    * @param os Flux recevant le conteneur
    * @return Retourne le flux avec le conteneur inséré.
    */
   std::ostream& toStream (std::ostream& os) const override;

   /**
    * @brief Vérifie si il y a un conducteur de bateau à bord.
    * @return Vrai si il y a un conducteur à bord.
    */
   bool isDriverOnBoard() const;

   /**
    * @brief Le bateau change de rive.
    */
   void navigate();

   /**
    * @brief Accesseur à la rive sur laquelle le bateau est accosté.
    * @return Retourne la rive sur laquelle le bateau est accosté.
    */
   const Bank* getCurrentBank () const;
};


#endif //LABO3_BOAT_H
