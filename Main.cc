using namespace std;
#include <iostream>
#include "Foret.h"

int main() {
    Arbre a(5, 10, 15, 20, 25);
    a.print();
    cout << "creation d'arbre ok!" << endl;
    Rocher r(1, 2, 3, 4, 5);
    r.print();
    cout << "creation de rocher ok!" << endl;
}
