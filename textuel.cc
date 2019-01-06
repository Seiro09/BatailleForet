#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void configurer_tir(int &orientation, int &angle, int &force, int &portee){
	//~ int orientation = -1;
	while(orientation < 0 || orientation > 360)
	{printf("Choisisez un nombre entre 0 et 360 : ");
	scanf("%d", &orientation);}
	//~ printf("l'orientation est configuré à : %d \n",orientation);
	
	//~ int angle = -1;
	while(angle < 0 || angle > 90)
	{printf("Choisisez un nombre entre 0 et 90 : ");
	scanf("%d", &angle);}
	//~ printf("l'angle est configuré à : %d \n",orientation);
	
	//~ int force = -1;
	while(force < 1 || force > 5)
	{printf("Choisisez un nombre entre 1 et 5 : ");
	scanf("%d", &force);}
	//~ printf("la force de frape est configuré à : %d \n",force);
	
	//~ int portee = -1;
	while(portee < 1 || portee > 5)
	{printf("Choisisez un nombre entre 1 et 5 : ");
	scanf("%d", &portee);}
	//~ printf("la portee de frape est configuré à : %d \n",portee);
}

int main() {
	int orientation = -1;
	int angle = -1;
	int force = -1;
	int portee = -1;
	configurer_tir(orientation,angle,force,portee);
		printf("l'orientation est configuré à : %d \n",orientation);
		printf("l'angle est configuré à : %d \n",angle);
		printf("la force de frape est configuré à : %d \n",force);
		printf("la portee de frape est configuré à : %d \n",portee);
}
