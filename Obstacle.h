/*atom://teletype/portal/6fb2131e-b27a-4a17-8938-d3294b811301*/
/*rajouter les ronces : le perso avance moins vite*/

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle{
private:
    int diametre, hauteur, x, y, PV;

public:
    Obstacle();
    ~Obstacle();
    virtual int getDiametre();
    virtual int getHauteur();
    virtual int getX();
    virtual int getY();
    virtual int getPV();
};
#endif
