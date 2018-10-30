using namespace std;
#include <iostream>
#include "Foret.h"
#include <fstream>

int main() {
    Foret f1;
    Arbre a1(1, 2, 3, 4, 5);
    f1.ajoute(a1);
    Rocher r1(6, 7, 8, 9, 10);
    f1.ajoute(r1);
    Arbre a2(1, 2, 3, 4, 5);
    f1.ajoute(a2);
    f1.afficher();
    cout << endl;
    f1.sauvegarde("Foret");
    f1.supprime(3, 4);
    f1.afficher();
    f1.lecture("Foret");
    cout << endl;
    f1.afficher();
    //f1.creerNiveau();
}
