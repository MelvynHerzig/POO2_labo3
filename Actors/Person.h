
#ifndef LABO3_PERSON_H
#define LABO3_PERSON_H

#include <string> // string
#include <list>   // list

/**
 * @brief Classe modélisant la base des personnes
 * @date 21/04/2021
 * @authors Forestier Quentin & Herzig Melvyn
 * @compiler MinGW-g++ 6.3.0
 */
class Person
{
private:

   friend std::ostream& operator<<(std::ostream& os, const Person& p);

   /**
    * @brief nom du personnage.
    */
   const std::string name;

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

public:

   Person() = default;

   /**
    * @brief Constructeur.
    * @param name Nom du personnage.
    */
   explicit Person(std::string   name);

   /**
    * @brief Destructeur.
    */
   virtual ~Person() = default;

   /**
    * @brief Définit le tuteur de la personne.
    * @param tutor Tuteur.
    */
   void setTutor(const Person* tutor);

   /**
    * @brief Définit la liste des personnes qui ne peuvent pas être en présence
    *        de la personne sans son tuteur.
    * @param persons Listes des personnes incompatibles sans le tuteur.
    */
   void setIncopatibilityWith(std::initializer_list<const Person*> persons);

   /**
    * @brief Vérifie si elle peut rester avec les personnes en argument.
    * @param persons Personnes qui accompagnent la personne courante.
    * @return Retourne vrai si la personne courante peut restes avec les personnes.
    */
   bool checkState(const std::list<const Person*>& persons) const;

   /**
    * @brief Accesseur nom de la personne.
    * @return Retourne le nom de la personne.
    */
   const std::string &getName () const;

   /**
    * @brief Détermine si la personne peut conduire le bateau.
    * @return Vrai si elle le peut sinon faux.
    */
   virtual bool canDrive() const = 0;

private:

};

#endif //LABO3_PERSON_H
