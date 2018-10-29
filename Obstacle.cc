using namespace std;

#include <iostream>
#include "Obstacle.h"

Obstacle::Obstacle(int d, int h, int x, int y, int PV){
    this->diametre=d;
    this->hauteur=h;
    this->x=x;
    this->y=y;
    this->PV=PV;
}

Obstacle::~Obstacle(){
    cout << "Cet obstacle a été detruit" << endl;
}

virtual int getDiametre(){return this->diametre;}
virtual int getHauteur(){return this->hauteur;}
virtual int getX(){return this->x;}
virtual int getY(){return this->y;}
virtual int getPV(){return this->PV;}
