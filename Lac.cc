#include <cmath>
#include "Lac.h"

Lac::Lac(int h, int x, int y, int PV) : Obstacle(1,x,y,(pow(2,31)-1), "Lac") {}
// 2^31-1 PV pour simuler le fait qu'un lac est indestructible

Lac::~Lac(){}

void Lac::print(){}
