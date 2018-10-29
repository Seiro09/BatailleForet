#ifndef ROCHER_H
#define ROCHER_H

#include "Obstacle.h"

//La classe Rocher hérite de la classe Obstacle
class Rocher : public Obstacle {
private:

public:
    Rocher(int, int, int, int, int);
    ~Rocher();
    void print();
};
#endif
