#include "Rocher.h"

Rocher::Rocher(int d, int h, int x, int y, int PV) : Obstacle(d,h,x,y, 2*PV, "Rocher") {}
// 2*PV pour simuler le fait qu'un rocher est 2 fois plus solide qu'un arbre

Rocher::~Rocher(){}

void Rocher::print(){}
