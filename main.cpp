/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Lancer l'énigme de la rivière.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>

#include <cstdlib>                     // EXIT_SUCCESS
#include <cstring>
#include "Controller.h"                // Controller, play
#include "Actors/Thief.h"              // Thief
#include "Actors/IndependentPerson.h"  // IndependentPerson
#include "Actors/Child.h"              // Child


using namespace std;

/**
 * @brief Test si dependantPerson peut rester avec les personnes dans cannotStayWith
 *        sans le tuteur.
 * @param dependantPerson Personne à tester.
 * @param cannotStayWith Pointeurs sur les personnes incompatibles.
 * @return vrai si les test ont réussis faux si une personne est ajoutée et que l'erreur
 *         n'est pas découverte par isCheck.
 */
bool testWithoutTutor(const Person* dependantPerson, initializer_list<const Person *> cannotStayWith)
{
   Bank leftBank {"Gauche"};
   Bank rightBank{"Droite"};
   Boat boat{2, &leftBank, &rightBank};
   Container* containers[] = {&leftBank, &rightBank, &boat};

   for (Container* container : containers)
   {
      container->addPerson(dependantPerson);
      for(const Person* person : cannotStayWith)
      {
         container->addPerson(person);

         // Si nullptr, le voleur pourrait rester avec le membre -> échec.
         if(container->isValid() == nullptr)
         {
            return false;
         }
         container->removePerson(person);
      }
   }

   return true;
}

/**
 * @brief Test si dependantPerson peut rester avec les personnes dans cannotStayWith
 *        avec le tuteur.
 * @param dependantPerson Personne à tester.
 * @param tutor Pointeur sur le tuteur.
 * @param cannotStayWith Pointeurs sur les personnes incompatibles.
 * @return vrai si les test ont réussis faux si une personne erreur est découverte par isCheck.
 */
bool testWithTutor(const Person* dependantPerson, const Person* tutor, initializer_list<const Person *> cannotStayWith)
{
   Bank leftBank {"Gauche"};
   Bank rightBank{"Droite"};
   Container* containers[] = {&leftBank, &rightBank};
   for(Container* container : containers)
   {
      container->addPerson(dependantPerson);
      container->addPerson(tutor);

      for (const Person* person : cannotStayWith)
      {
         container->addPerson(person);

         // Si différent de nullptr, une erreur qui ne devrait pas exister a été détecté.
         if(container->isValid() != nullptr)
         {
            return false;
         }

         container->removePerson(person);
      }
   }

   return true;
}

/**
 * Tente de surchager le bateau avec 3 personnes
 * @param persons Personne à ajouter au bateau.
 * @return Retourne vrai si réussi sinon false.
 */
bool testBoatOverLoad(const Person* persons[3])
{
   Boat boat{2, nullptr, nullptr};

   boat.addPerson(persons[0]);
   boat.addPerson(persons[1]);

   // Doit être faux
   bool result1 = boat.addPerson(persons[3]);

   boat.removePerson(persons[1]);

   // Doit être vrai
   bool result2 = boat.addPerson(persons[3]);

   return !result1 && result2;
}


/**
 * @brief Exécute quelques tests de fonctionnement.
 * @details Créer des DependantPerson const n'à pas de sens car on ne peut pas faire setRule.
 *          Les conteneurs sont non constant, sinon les tests ne pourraient pas être
 *          fait car impossible d'ajouter/retirer des personnes.
 */
void test()
{

   // **************** Préparation des personnages *************************
   // Création des personnages
   Thief thief {"voleur"};
   const IndependentPerson policeman {"policier"};
   const IndependentPerson mother    {"mere"};
   const IndependentPerson father    {"pere"};
   Child julie  {"julie", false};
   Child jeanne {"jeanne", false};
   Child paul   {"paul", true};
   Child pierre {"pierre", true};

   // Définition des relations.
   thief.setRule(&policeman, {&mother, &father, &paul, &pierre, &julie, &jeanne});
   paul.setRule(&father, {&mother});
   pierre.setRule(&father, {&mother});
   julie.setRule(&mother, {&father});
   jeanne.setRule(&mother, {&father});

   cout << "\n***** Test: Le voleur ne peut pas etre avec la famille sans le policier ******" << endl;
   if(!testWithoutTutor(&thief, {&mother, &father, &paul, &pierre, &julie, &jeanne}))
   {
      cout << "testThiefWithFamilyWithoutCop) ECHEC" << endl;
   }
   else
   {
      cout << "testThiefWithFamilyWithoutCop) REUSSITE" << endl;
   }

   cout << "\n***** Test: Le voleur ne peut pas etre avec la famille avec le policier ******" << endl;
   if(!testWithTutor(&thief, &policeman, {&mother, &father, &paul, &pierre, &julie, &jeanne}))
   {
      cout << "testThiefWithFamilyWithCop) ECHEC" << endl;
   }
   else
   {
      cout << "testThiefWithFamilyWithCop) REUSSITE" << endl;
   }

   cout << "\n***** Test: Les garcons ne peuvent pas rester seuls avec leur maman ******" << endl;
   if(!testWithoutTutor(&mother, {&paul, &pierre}))
   {
      cout << "testBoysWithMomWithoutDad) ECHEC" << endl;
   }
   else
   {
      cout << "testBoysWithMomWithoutDad) REUSSITE" << endl;
   }

   cout << "\n***** Test: Les garcons peuvent rester avec leur maman si papa est la ******" << endl;
   if(!testWithoutTutor(&mother, {&paul, &pierre}))
   {
      cout << "testBoysWithMomWithDad) ECHEC" << endl;
   }
   else
   {
      cout << "testBoysWithMomWithDad) REUSSITE" << endl;
   }

   cout << "\n***** Test: Les filles ne peuvent pas rester seules avec leur papa ******" << endl;
   if(!testWithoutTutor(&father, {&jeanne, &julie}))
   {
      cout << "testGirlsWithDadWithoutMom) ECHEC" << endl;
   }
   else
   {
      cout << "testGirlsWithDadWithoutMom) REUSSITE" << endl;
   }

   cout << "\n***** Test: Les filles peuvent rester avec leur papa si maman est la ******" << endl;
   if(!testWithoutTutor(&father, {&jeanne, &julie}))
   {
      cout << "testGirlsWithDadWithMom) ECHEC" << endl;
   }
   else
   {
      cout << "testGirlsWithDadWithMom) REUSSITE" << endl;
   }

   cout << "\n***** Test: Le bateau ne peut pas contenir plus de deux personnes ******" << endl;
   const Person* threePersons[] = {&father, &mother, &policeman};
   if(!testBoatOverLoad(threePersons))
   {
      cout << "testOverloadingBoat) ECHEC" << endl;
   }
   else
   {
      cout << "testOverloadingBoat) REUSSITE" << endl;
   }
}

/**
 * @brief Point d'entrée du programme, lance la partie si pas d'argument ou
 *        exécute les tests si argv[1] == "test".
 * @return EXIT_SUCCES si tout s'est bien déroulé.
 */
int main(int argc, char* argv[])
{
   if(argc == 2 && strcmp(argv[1], "test") == 0) // Test mode
   {
      test();
   }
   else // play mode
   {
      Controller controller;

      controller.play();
  }

  return EXIT_SUCCESS;
}


