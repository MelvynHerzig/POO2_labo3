#include "Controller.h"

#include "Actors/IndependentPerson.h"
#include "Actors/Thief.h"
#include "Actors/Child.h"

#include <iostream> // cout

using namespace std;

const char Controller::PRINT_STATE = 'p';
const char Controller::IN_BOAT     = 'e';
const char Controller::OUT_BOAT    = 'd';
const char Controller::MOVE_BOAT   = 'm';
const char Controller::RESET       = 'r';
const char Controller::QUIT        = 'q';
const char Controller::PRINT_MENU  = 'h';

Controller::Controller () : leftBank("Gauche"), rightBank("Droite"), boat(2, &leftBank, &rightBank)
{
   // Tour
   turn = 0;

   // Création des personnages
   auto thief = new Thief {"voleur"};
   persons.emplace_back(thief);

   auto policeman = new IndependentPerson {"policier"};
   persons.emplace_back(policeman);

   auto julie = new Child {"julie", false};
   persons.emplace_back(julie);

   auto jeanne = new Child {"jeanne", false};
   persons.emplace_back(jeanne);

   auto mother = new IndependentPerson{"mere"};
   persons.emplace_back(mother);

   auto paul = new Child {"paul", true};
   persons.emplace_back(paul);

   auto pierre = new Child {"pierre", true};
   persons.emplace_back(pierre);

   auto father = new IndependentPerson{"pere"};
   persons.emplace_back(father);

   // Définition des relations.
   thief->setRule(policeman, {mother, father, paul, pierre, julie, jeanne});

   paul->setRule(father, {mother});

   pierre->setRule(father, {mother});

   julie->setRule(mother, {father});

   jeanne->setRule(mother, {father});

   // Préparation des rives
   resetContainers();
}

Controller::~Controller ()
{
   for(const Person* person : persons)
   {
      delete person;
   }
}

void Controller::play ()
{
   char input;
   string personName;

   showMenu();

   while(not leftBank.isEmpty() || not boat.isEmpty())
   {
      display();

      cout << turn << ">";
      cin >> input;

      Bank& current = (boat.getCurrentBank() == &rightBank) ? rightBank : leftBank;

      switch(input)
      {
         case PRINT_STATE:
            break;

         case PRINT_MENU:
            showMenu();
            break;

         case RESET:
            resetContainers();
            turn = 0;
            break;

         case IN_BOAT:
            cin >> personName;
            tryMovePerson(current, boat, personName);
            break;

         case OUT_BOAT:
            cin >> personName;
            tryMovePerson(boat, current, personName);
            break;

         case MOVE_BOAT:
            tryMoveBoat();
            break;

         case QUIT:
            return;

         default:
            displayError( "commande inconnue.");
      }

      // Espacement entre les affichages
      cout << endl << endl;
   }

   cout << " BRAVO, tout le monde est passe. Fin de la partie." << endl;
}

void Controller::display () const
{
   // Rive gauche
   cout << "-----------------------------------------------------------" << endl
        << leftBank                                                      << endl
        << "-----------------------------------------------------------" << endl;

   // Rivage gauche
   if(boat.getCurrentBank() == &leftBank)
   {
      cout << boat << endl;
   }
   else
   {
      cout << endl;
   }

   // Rivière
   cout << "===========================================================" << endl;

   // Rivage droite
   if(boat.getCurrentBank() == &rightBank)
   {
      cout << boat << endl;
   }
   else
   {
      cout << endl;
   }

   // Rive droite
   cout << "-----------------------------------------------------------" << endl
        << rightBank                                                     << endl
        << "-----------------------------------------------------------" << endl;

}

void Controller::resetContainers ()
{
   // Vide les conteneurs
   leftBank.clear();
   rightBank.clear();
   boat.clear();

   // On repositionne le bateau
   if(boat.getCurrentBank() == &rightBank)
   {
      boat.navigate();
   }

   // On replace les personnes sur la rive de départ.
   leftBank.addPersons(persons);
}

void Controller::tryMoveBoat ()
{
   ++turn;

   if(boat.isDriverOnBoard())
   {
      boat.navigate();
   }
   else
   {
      displayError("Personne n'est capable de piloter le bateau.");
   }
}

void Controller::tryMovePerson (Container& from, Container& to, const string &name)
{
   // Modification et vérification de from.
   const Person* p = from.findByName(name);

   if(p == nullptr) return;

   ++turn;

   bool opSuccess = false;

   opSuccess = from.removePerson(p);

   const Person* personWithProblem = from.isValid();
   if(personWithProblem != nullptr || !opSuccess)
   {
      from.addPerson(p);

      if(personWithProblem != nullptr)
      {
         displayError(personWithProblem->getErrorMessage());
      }
      return;
   }

   //Modification et vérification de to.
   opSuccess = to.addPerson(p);
   personWithProblem = to.isValid();
   if(personWithProblem != nullptr || !opSuccess)
   {
      to.removePerson(p);
      from.addPerson(p);

      if(personWithProblem != nullptr)
      {
         displayError(personWithProblem->getErrorMessage());
      }
   }
}

void Controller::showMenu ()
{
   cout << PRINT_STATE << "      : afficher       " << endl
        << IN_BOAT     << " <nom>: embarquer <nom>" << endl
        << OUT_BOAT    << " <nom>: debarquer <nom>" << endl
        << MOVE_BOAT   << "      : deplacer bateau" << endl
        << RESET       << "      : reinitialiser  " << endl
        << QUIT        << "      : quitter        " << endl
        << PRINT_MENU  << "      : menu           " << endl;
}

void Controller::displayError (const string &error)
{
   cout << "### " << error << endl;
}

