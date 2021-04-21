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

#include <cstdlib> // EXIT_SUCCESS
#include "Controller.h"

using namespace std;

int main()
{
   Controller controller;

   controller.play();

   return EXIT_SUCCESS;
}
