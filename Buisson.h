#ifndef BUISSON_H
#define BUISSON_H

#include "Obstacle.h"

//La classe Buisson hérite de la classe Obstacle
class Buisson : public Obstacle {
public:
    Buisson(int, int, int, int);
    ~Buisson();
    void print();
};
#endif
