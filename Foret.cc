using namespace std;
#include <iostream>
#include "Foret.h"
#include <cmath>
#include <string>

Foret::Foret() {}

Foret::~Foret()  {/*cout << "liste detruite" << endl;*/}

bool Foret::collision(Obstacle& O) {
    for (Obstacle o : this->l){
        double l; int dx, dy; // l = distance entre les deux obstacles
        dx = o.getCentre()->getx() - O.getCentre()->getx();
        dy = o.getCentre()->gety() - O.getCentre()->gety();
        l = sqrt(dx*dx + dy*dy);
        double l2 = (O.getDiametre()/2.0) + (o.getDiametre()/2.0);
        if (l < l2) return true;
    }
    return false;
}

void Foret::ajoute(Obstacle& O) {
    if(this->collision(O)) cout << "collision, creation de l'obstacle impossible" << endl;
    else {
        this->l.push_back(O);
    }
}

void Foret::afficher(){
    for(Obstacle o : this->l) {
        o.print();
    }
}

void Foret::supprime(int x, int y) {
    this->l.remove_if([x, y](Obstacle o){return ((o.getCentre()->getx()==x) && (o.getCentre()->gety()==y));});
}

void Foret::creerNiveau() {
    Obstacle* o[100]; // on limite le nombre d'obstacle a 100
    int i = 0;
    string s;
    cout << "Tapez c pour commencer a creer des obstacles, q sinon ";
    cin >> s;
    while(s != "q") {
        if(s == "c") { // bloc creation d'un obstacle
            int d, h, x, y, PV;
            string nom;
            cout << "Quel obstacle voulez-vous creer? {Arbre, Rocher} ";
            cin >> nom;
            cout << "Quel est son diametre? ";
            cin >> d;
            cout << "Quelle est sa hauteur? ";
            cin >> h;
            cout << "Quelles sont ses coordonnees?" << endl << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            cout << "Qel est son nombre de PV? ";
            cin >> PV;
            if(nom == "Arbre") {
                o[i] = new Arbre(d, h, x, y, PV);
                this->ajoute(*o[i]);
                i++;
            }
            else if(nom == "Rocher") {
                o[i] = new Rocher(d, h, x, y, PV);
                this->ajoute(*o[i]);
                i++;
            }
            else cout << "Cet obstacle n'existe pas" << endl;
        }
        if(s == "s") {
            this->afficher();
            int x, y;
            cout << "Donnez les coordonnees de l'obstacle a supprimer" << endl << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            this->supprime(x, y);
        }
        if(i == 100) {
            cout << "Nombre d'obstacle maximum atteint" << endl;
            break;
        }
        cout << "Tapez c pour continuer a creer des obstacles, s pour en supprimer un, q sinon ";
        cin >> s;
        cout << endl;
    }
    this->afficher();
}

void Foret::sauvegarde(string nom) {
    ofstream ofs(nom);
    boost::archive::text_oarchive oa(ofs);
    oa << *this;
}

void Foret::lecture(string nom) {
    ifstream ifs(nom);
    boost::archive::text_iarchive ia(ifs);
    ia >> *this;
}
