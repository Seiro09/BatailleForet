using namespace std;
#include <iostream>
#include "Foret.h"

int main() {
    /*Arbre a(5, 10, 15, 20, 25);
    a.print();
    cout << "creation d'arbre ok!" << endl;
    Rocher r(1, 2, 3, 4, 5);
    r.print();
    cout << "creation de rocher ok!" << endl;*/

    Foret f1;
    Arbre a1(5, 10, 15, 20, 25);
    f1.ajoute(a1);
    Rocher r1(14, 2, 3, 4, 5);
    f1.ajoute(r1);
    Arbre a2(2, 4, 6, 8, 10);
    f1.ajoute(a2);
    f1.afficher();
    f1.supprime(3, 4);
    f1.afficher();
}
