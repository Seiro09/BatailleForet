/*atom://teletype/portal/6fb2131e-b27a-4a17-8938-d3294b811301*/
/*rajouter les ronces : le perso avance moins vite*/

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Point.h"

class Obstacle {
private:
    int diametre, hauteur, PV;
    Point* centre; // utilisation de la classe Point ecrite en td
public:
    Obstacle(int, int, int, int, int);
    ~Obstacle();
    virtual void print();
    virtual int getDiametre();
    virtual int getHauteur();
    virtual Point* getCentre();
    virtual int getPV();
};
#endif
