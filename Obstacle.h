/*rajouter les ronces : le perso avance moins vite*/

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Point.h"
#include <string>

class Obstacle {
private:
    int diametre, hauteur, PV;
    Point* centre; // utilisation de la classe Point ecrite en td
    string nom;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & diametre & hauteur & centre & PV & nom;
    }
public:
    Obstacle();
    Obstacle(int, int, int, int, int, string);
    ~Obstacle();
    virtual void print();
    virtual int getDiametre();
    virtual int getHauteur();
    virtual Point* getCentre();
    virtual int getPV();
    virtual string getNom();
};
#endif
