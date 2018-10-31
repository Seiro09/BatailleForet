using namespace std;
#include <iostream>
#include "Foret.h"
#include <fstream>

int main() {
    Foret f;
    f.creerNiveau();
    cout << endl;
    f.afficher();
    f.sauvegarde("Foret");
    f.lecture("Foret");
    cout << endl;
    f.afficher();
}
