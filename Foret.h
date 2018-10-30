#ifndef FORET_H
#define FORET_H

#include "Arbre.h"
#include "Rocher.h"
#include <list>

class Foret {
private:
    list<Obstacle> l;

public:
    Foret();
    ~Foret();
    bool collision(Obstacle&);
    void ajoute(Obstacle&);
    void supprime(int, int);
    void afficher();
};
#endif
