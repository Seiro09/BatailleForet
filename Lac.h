#ifndef LAC_H
#define LAC_H

#include "Obstacle.h"

//La classe Lac hérite de la classe Obstacle
class Lac : public Obstacle {
public:
    Lac(int, int, int, int, int);
    ~Lac();
    void print();
};
#endif
