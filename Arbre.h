#ifndef ARBRE_H
#define ARBRE_H

#include "Obstacle.h"

//La classe Arbre hérite de la classe Obstacle
class Arbre : public Obstacle {
private:

public:
    Arbre(int, int, int, int, int);
    ~Arbre();
    void print();

};
#endif
