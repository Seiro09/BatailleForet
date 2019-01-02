using namespace std;
#include "Personnage.h"

Personnage::Personnage(int x, int y){
    this->x=x;
    this->y=y;
    this->orientation=0;
    this->PV=100;
}

Personnage::~Personnage(){}

int Personnage::getx(){return this->x;}
int Personnage::gety(){return this->y;}
int Personnage::getorientation(){return this->orientation;}
int Personnage::getPV(){return this->PV;}

void Personnage::setx(int x){this->x=x;}
void Personnage::sety(int y){this->y=y;}
void Personnage::setorientation(int o){this->orientation=o;}
void Personnage::setPV(int PV){this->PV=PV;}
