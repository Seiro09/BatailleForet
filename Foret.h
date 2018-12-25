#ifndef FORET_H
#define FORET_H

#include "Arbre.h"
#include "Rocher.h"
#include "Buisson.h"
#include "Lac.h"
#include <list>
#include <boost/serialization/list.hpp>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>
#include <string.h>
#include <fstream>

#define TAILLE_FORET 750
#define TAILLE_CASE 25
#define NB_CASES TAILLE_FORET/TAILLE_CASE

class Foret {
private:
    list<Obstacle> l;
    int T[NB_CASES][NB_CASES];
    Point* Centre;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & l & T;
    }
public:
    Foret();
    ~Foret();
    bool collision(Obstacle&);
    void ajoute(Obstacle&);
    void supprime(int, int);
    void afficher();
    void editerNiveau();
    void remplirTableau();
    void sauvegarde(string);
    void lecture(string);
    void Edition_Nouvelle_Foret();
};
#endif
