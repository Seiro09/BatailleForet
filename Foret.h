#ifndef FORET_H
#define FORET_H

#include "Arbre.h"
#include "Rocher.h"
#include <list>
#include <boost/serialization/list.hpp>

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
    void creerNiveau();
    void sauvegarde(string);
    void lecture(string);
};
#endif
