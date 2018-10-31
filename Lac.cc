#include <cmath>
#include "Lac.h"

Lac::Lac(int d, int h, int x, int y, int PV) : Obstacle(d,h,x,y,(pow(2,31)-1), "Lac") {}
// 2^31-1 PV pour simuler le fait qu'un lac est indestructible

Lac::~Lac(){}

void Lac::print(){}
