#include "Buisson.h"

Buisson::Buisson(int d, int h, int x, int y, int PV) : Obstacle(d,h,x,y,PV/2, "Buisson") {}
// PV/2 pour simuler le fait qu'un rocher est 2 fois plus fragile qu'un arbre

Buisson::~Buisson(){}

void Buisson::print(){}
