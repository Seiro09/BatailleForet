using namespace std;
#include <iostream>
#include "Foret.h"

int main() {
    string fichier;
    Foret f;
    f.editerNiveau();
    cout << endl;
    f.afficher();
    cout << "Donner un fichier a ouvrir : ";
    cin >> fichier;
    f.lecture(fichier);
    cout << endl;
    f.afficher();
    f.editerNiveau();
    cout << "Nouveau niveau :" << endl << endl;
    f.afficher();
}
