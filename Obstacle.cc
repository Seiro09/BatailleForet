using namespace std;

#include <iostream>
#include "Obstacle.h"

Obstacle::Obstacle(int d, int h, int x, int y, int PV){
    this->diametre = d;
    this->hauteur = h;
    this->centre = new Point(x, y);
    this->PV = PV;
}

Obstacle::~Obstacle(){
    cout << "Cet obstacle a été detruit" << endl;
}

int Obstacle::getDiametre(){return this->diametre;}
int Obstacle::getHauteur(){return this->hauteur;}
Point* Obstacle::getCentre(){return this->centre;}
int Obstacle::getPV(){return this->PV;}

void Obstacle::print(){
    cout << "- Diametre : " << this->getDiametre() << endl;
    cout << "- Hauteur : " << this->getHauteur() << endl;
    cout << "- Position : " << "(" << this->getCentre()->getx() << "," << this->getCentre()->gety() << ")"<< endl;
    cout << "- PV : " << this->getPV() << endl;

}
