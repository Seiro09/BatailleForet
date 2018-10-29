using namespace std;

#include <iostream>
#include "Obstacle.h"

Obstacle::Obstacle(int d, int h, int x, int y, int PV){
    this->diametre = d;
    this->hauteur = h;
    this->x = x;
    this->y = y;
    this->PV = PV;
}

Obstacle::~Obstacle(){
    cout << "Cet obstacle a été detruit" << endl;
}

int Obstacle::getDiametre(){return this->diametre;}
int Obstacle::getHauteur(){return this->hauteur;}
int Obstacle::getX(){return this->x;}
int Obstacle::getY(){return this->y;}
int Obstacle::getPV(){return this->PV;}

void Obstacle::print(){
    cout << "- Diametre : " << this->getDiametre() << endl;
    cout << "- Hauteur : " << this->getHauteur() << endl;
    cout << "- Position : " << "(" << this->getX() << "," << this->getY() << ")"<< endl;
    cout << "- PV : " << this->getPV() << endl;

}
