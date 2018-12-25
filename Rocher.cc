#include "Rocher.h"

Rocher::Rocher(int h, int x, int y, int PV) : Obstacle(h,x,y, 2*PV, "Rocher") {}
// 2*PV pour simuler le fait qu'un rocher est 2 fois plus solide qu'un arbre

Rocher::~Rocher(){}

void Rocher::print(){}
