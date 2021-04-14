/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Person.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 14/04/2021

 But         : Implémenter la classe de "base" personne.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO3_PERSON_H
#define LABO3_PERSON_H

#include <string>

/**
 * @brief Classe modélisant la base du policier, voleur, parents et enfants
 * @authors Forestier Quentin & Herzig Melvyn
 * @date 14/04/2021
 */
class Person
{
private:

   /**
    * @brief nom du personnage.
    */
   const std::string name;

public:

   /**
    * @brief Constructeur.
    * @param name Nom du personnage.
    */
   Person(const std::string& name);

   /**
    * @brief Destructeur.
    */
   virtual ~Person() = default;

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   virtual bool canDrive() const = 0;

   /**
    * @brief Détermine si la personne est un membre de la famille.
    * @return Vrai si c'est un membre de la famille sinon faux.
    */
   virtual bool isFamilyMember() const = 0;

};

#endif //LABO3_PERSON_H
