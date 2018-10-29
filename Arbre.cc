using namespace std;
#include <iostream>
#include "Arbre.h"


Arbre::Arbre(int d, int h, int x, int y, int PV) : Obstacle(d,h,x,y,PV) {}

Arbre::~Arbre(){}

void Arbre::print(){
    cout << "Je suis un arbre et voici mes caracteristiques : " << endl;
    Obstacle::print();
}
