#ifndef LABO3_CONTROLLER_H
#define LABO3_CONTROLLER_H


#include <cstdlib> // size_t
#include "Actors/Driver.h"
#include "Actors/NonDriver.h"
#include "Containers/Bank.h"
#include "Containers/Boat.h"

/**
 * @brief Classe qui contrôle l'exécution de l'énigme de la rivière
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Controller
{
private:

   /**
    * @brief Caractère qui affiche l'état du jeu quand lu.
    */
   static const char PRINT_STATE;

   /**
    * @brief Caractère qui déplace un personnage dans le bateau quand lu.
    */
   static const char IN_BOAT;

   /**
    * @brief Caractère qui déplace un personnage depuis bateau quand lu.
    */
   static const char OUT_BOAT;

   /**
    * @brief Caractère qui déplace le bateau quand lu.
    */
   static const char MOVE_BOAT;

   /**
    * @brief Caractère qui réinitialise la partie quand lu.
    */
   static const char RESET;

   /**
    * @brief Caractère qui termine le programme quand lu.
    */
   static const char QUIT;

   /**
    * @brief Caractère qui affiche le menu quand lu.
    */
   static const char PRINT_MENU;

   /**
    * @brief Numéro du tour
    */
   std::size_t turn;

   /**
    * @brief Rive gauche.
    */
   Bank leftBank;

   /**
    * @brief Rive droite.
    */
   Bank rightBank;

   /**
    * @brief Bateau.
    */
   Boat boat;

   /**
    * Liste des personnes.
    */
   std::list<const Person*> persons;

public:

   /**
    * Constucteur
    */
   Controller();

   /**
    * @brief Destructeur
    */
   ~Controller();

   /**
    * @brief Lance la partie.
    */
   void play();


private:
   /**
    * @brief Affiche l'état de la partie.
    */
   void display() const;

   /**
    * @brief Réinitialise l'état des conteneurs
    */
   void resetContainers();

   /**
    * @brief Tente de déplacer le bateau.
    */
   void tryMoveBoat();

   /**
    * @brief Tente de déplacer la personne du nom name de from à to.
    * @param from Rive de départ.
    * @param to Rive d'arrivée.
    * @param name Nom de la personne.
    */
    void tryMovePerson(Container& from, Container& to, const std::string& name);

   /**
    * @brief Affiche le menu, c-à-d les contrôle pour jouer.
    */
   static void showMenu();
};


#endif //LABO3_CONTROLLER_H
