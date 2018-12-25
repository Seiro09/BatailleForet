using namespace std;

#include <iostream>
#include "Obstacle.h"

Obstacle::Obstacle(){}

Obstacle::Obstacle(int h, int x, int y, int PV, string nom){
    this->hauteur = h;
    this->centre = new Point(x, y);
    this->PV = PV;
    this->nom = nom;
}

Obstacle::~Obstacle(){
    /*cout << "Cet obstacle a été detruit" << endl;*/
}

int Obstacle::getHauteur(){return this->hauteur;}
Point* Obstacle::getCentre(){return this->centre;}
int Obstacle::getPV(){return this->PV;}
string Obstacle::getNom() {return this->nom;}

void Obstacle::print(){
    cout << this->getNom() << " : ";
    cout << "Hauteur : " << this->getHauteur();
    cout << " | Position : " << "(" << this->getCentre()->getx() << "," << this->getCentre()->gety() << ")";
    cout << " | PV : " << this->getPV() << endl;
}
