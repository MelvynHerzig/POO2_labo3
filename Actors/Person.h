
#ifndef LABO3_PERSON_H
#define LABO3_PERSON_H

#include <string> // string
#include <list>   // list

class Person;

/**
 * @brief Affiche une personne dans un flux.
 * @param os Flux dans lequel afficher la personne.
 * @param container Personne concernée.
 * @return Retourne le flux avec la personne.
 */
std::ostream& operator<<(std::ostream& os, const Person& p);

/**
 * @brief Classe modélisant la base des personnes
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
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
   explicit Person(const std::string& name);

   /**
    * @brief Destructeur.
    */
   virtual ~Person() = default;

   /**
    * @brief Accesseur nom de la personne.
    * @return Retourne le nom de la personne.
    */
    std::string getName() const;

   /**
    * @brief Insère une personne dans un flux.
    * @param os Flux recevant la personne
    * @return Retourne le flux avec la personne insérée.
    */
    virtual std::ostream &toStream (std::ostream& os) const;

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   virtual bool canDrive() const = 0;

   /**
    * @brief Vérifie si elle peut rester avec les personnes en argument.
    * @param persons Personnes qui accompagnent la personne courante.
    * @return Retourne true si la personne courante peut rester avec les personnes.
    *         Sinon retourne false.
    */
   virtual bool checkState(const std::list<const Person*>& persons) const = 0;

   /**
    * @brief Accède au message d'erreur à retourner lors d'une incompatibilité.
    * @return Retourne le message explicatif de l'incompatibilité.
    * @throw invalid_argument En cas de problème de construction du message.
    */
   virtual std::string getErrorMessage() const = 0;
};

#endif //LABO3_PERSON_H
