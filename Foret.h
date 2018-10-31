#ifndef FORET_H
#define FORET_H

#include "Arbre.h"
#include "Rocher.h"
#include "Buisson.h"
#include "Lac.h"
#include <list>
#include <boost/serialization/list.hpp>
#include <cmath>
#include <string>
#include <string.h>
#include <fstream>

class Foret {
private:
    list<Obstacle> l;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & l;
    }
public:
    Foret();
    ~Foret();
    bool collision(Obstacle&);
    void ajoute(Obstacle&);
    void supprime(int, int);
    void afficher();
    void editerNiveau();
    void sauvegarde(string);
    void lecture(string);
};
#endif
