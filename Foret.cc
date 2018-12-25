using namespace std;
#include <iostream>
#include "Foret.h"
using namespace sf;

Foret::Foret() {
    this->Centre=new Point(TAILLE_FORET/2,TAILLE_FORET/2);
    for (int i = 0; i<NB_CASES; i++){
        for (int j = 0; j<NB_CASES; j++){
            T[i][j]=0;
        }
    }
}

Foret::~Foret()  {/*cout << "liste detruite" << endl;*/}

bool Foret::collision(Obstacle& O) {
    for (Obstacle o : this->l){
        // double l; int dx, dy; // l = distance entre les deux obstacles
        // dx = o.getCentre()->getx() - O.getCentre()->getx();
        // dy = o.getCentre()->gety() - O.getCentre()->gety();
        // l = sqrt(dx*dx + dy*dy);
        // double l2 = (O.getDiametre()/2.0) + (o.getDiametre()/2.0);
        // if (l < l2) return true;
        if ((o.getCentre()->getx()==O.getCentre()->getx())&&(o.getCentre()->gety()==O.getCentre()->gety())) return true;
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

void Foret::editerNiveau() {
    int i = 0;
    string s;
    cout << "Tapez c pour creer (ou s pour supprimer) des obstacles, q sinon ";
    cin >> s;
    while(s != "q") {
        if(s == "c") { // bloc creation d'un obstacle
        Obstacle* o;
            int h, x, y, PV;
            string nom;
            cout << "Quel obstacle voulez-vous creer? {Arbre, Rocher, Buisson, Lac} ";
            cin >> nom;
            cout << "Quelle est sa hauteur? ";
            cin >> h;
            cout << "Quelles sont ses coordonnees?" << endl << "x = ";
            cin >> x;
            x=(x/TAILLE_CASE)*TAILLE_CASE;
            cout << "y = ";
            cin >> y;
            y=(y/TAILLE_CASE)*TAILLE_CASE;
            cout << "Quel est son nombre de PV? ";
            cin >> PV;
            if(nom == "Arbre") {
                o = new Arbre(h, x, y, PV);
                this->ajoute(*o);
            }
            else if(nom == "Rocher") {
                o = new Rocher(h, x, y, PV);
                this->ajoute(*o);
            }
            else if(nom == "Buisson") {
                o = new Buisson(h, x, y, PV);
                this->ajoute(*o);
            }
            else if(nom == "Lac") {
                o = new Lac(h, x, y, PV);
                this->ajoute(*o);
            }
            else cout << "Cet obstacle n'existe pas" << endl;
        }
        if(s == "s") { // bloc de suppression d'un obstacle
            this->afficher();
            int x, y;
            cout << "Donnez les coordonnees de l'obstacle a supprimer" << endl << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            this->supprime(x, y);
        }
        cout << "Tapez c pour continuer a creer des obstacles, s pour en supprimer un, q sinon ";
        cin >> s;
        cout << endl;
    }
    this->afficher();
    string fichier;
    cout << "Donner un nom pour le fichier de sauvegarde (finir par .txt) : ";
    cin >> fichier;
    this->sauvegarde(fichier);
    this->remplirTableau();
}

void Foret::remplirTableau(){
    for(Obstacle o : this->l) {
        if (o.getNom()=="Arbre"){
            T[o.getCentre()->getx()/TAILLE_CASE][o.getCentre()->gety()/TAILLE_CASE]=1;
        }
        else if (o.getNom()=="Buisson"){
            T[o.getCentre()->getx()/TAILLE_CASE][o.getCentre()->gety()/TAILLE_CASE]=2;
        }
        else if (o.getNom()=="Rocher"){
            T[o.getCentre()->getx()/TAILLE_CASE][o.getCentre()->gety()/TAILLE_CASE]=3;
        }
        else if (o.getNom()=="Lac"){
            T[o.getCentre()->getx()/TAILLE_CASE][o.getCentre()->gety()/TAILLE_CASE]=4;
        }

    }
    for (int i = 0; i<NB_CASES; i++){
        for (int j = 0; j<NB_CASES; j++){
            cout << T[i][j];
        }
        cout << endl;
    }


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

void Foret::Edition_Nouvelle_Foret(){
    RenderWindow window(VideoMode(TAILLE_FORET,TAILLE_FORET),
     "Edition Foret");
    int type=0;
    //RectangleShape r(Vector2f(TAILLE_CASE,TAILLE_CASE));
    vector<RectangleShape> v;
    VertexArray lines(Lines,4*NB_CASES);
    for (int i = 0; i<NB_CASES; i++){
        lines[2*i].position = sf::Vector2f(i*TAILLE_CASE, 0);
        lines[2*i+1].position = sf::Vector2f(i*TAILLE_CASE, TAILLE_FORET);
        lines[2*i].color = sf::Color::White;
        lines[2*i+1].color = sf::Color::White;
    }
    for (int i = 0; i <NB_CASES; i++){
        lines[2*NB_CASES+2*i].position = sf::Vector2f(0,i*TAILLE_CASE);
        lines[2*NB_CASES+2*i+1].position = sf::Vector2f(TAILLE_FORET,i*TAILLE_CASE);
        lines[2*NB_CASES+2*i].color = sf::Color::White;
        lines[2*NB_CASES+2*i+1].color = sf::Color::White;
    }
    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
            if (Mouse::isButtonPressed(Mouse::Left) && window.hasFocus()) {
                bool existe = false;
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                //cout << localPosition.x << " "<< localPosition.y << endl;
                if (localPosition.x < TAILLE_FORET && localPosition.x > 0 &&
                    localPosition.y < TAILLE_FORET && localPosition.y > 0) {
                        for(int i = 0; i<v.size();i++){
                            if (v[i].getPosition()==
                            Vector2f(localPosition.x/TAILLE_CASE*TAILLE_CASE,
                                localPosition.y/TAILLE_CASE*TAILLE_CASE)){
                                    Vector2f pos = v[i].getPosition();
                                    this->T[(int)pos.y/TAILLE_CASE][(int)pos.x/TAILLE_CASE]++;
                                    switch (T[(int)pos.y/TAILLE_CASE][(int)pos.x/TAILLE_CASE]) {
                                        case 1:
                                            v[i].setFillColor(Color::Green);
                                            break;
                                        case 2:
                                            v[i].setFillColor(Color::Yellow);
                                            break;
                                        case 3:
                                            v[i].setFillColor(Color::Red);
                                            break;
                                        case 4:
                                            v[i].setFillColor(Color::Blue);
                                            break;
                                        default:
                                            T[(int)pos.y/TAILLE_CASE][(int)pos.x/TAILLE_CASE]=1;
                                            v[i].setFillColor(Color::Green);
                                            break;
                                    }
                                    //v[i].setFillColor(Color::Blue);
                                    existe=true;
                                }
                            }
                if (!existe){
                    RectangleShape r2(Vector2f(TAILLE_CASE,TAILLE_CASE));
                    r2.setPosition((localPosition.x/TAILLE_CASE)*TAILLE_CASE,(localPosition.y/TAILLE_CASE)*TAILLE_CASE);
                    r2.setFillColor(Color::Green);
                    v.push_back(r2);
                    this->T[localPosition.y/TAILLE_CASE][localPosition.x/TAILLE_CASE]=1;
                }
            }
            }
            if (Mouse::isButtonPressed(Mouse::Middle) && window.hasFocus()){
                v.clear();
                for (int i = 0; i<NB_CASES; i++){
                    for (int j = 0; j<NB_CASES; j++){
                        T[i][j]=0;
                    }
                }
                // sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                // this->T[localPosition.x/TAILLE_CASE][localPosition.y/TAILLE_CASE]=0;
            }
            if (Mouse::isButtonPressed(Mouse::Right)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if (localPosition.x < TAILLE_FORET && localPosition.x > 0 &&
                    localPosition.y < TAILLE_FORET && localPosition.y > 0) {
                        for(int i = 0; i<v.size();i++){
                            if (v[i].getPosition()==
                            Vector2f(localPosition.x/TAILLE_CASE*TAILLE_CASE,
                                localPosition.y/TAILLE_CASE*TAILLE_CASE)){
                                    Vector2f pos = v[i].getPosition();
                                    this->T[(int)pos.y/TAILLE_CASE][(int)pos.x/TAILLE_CASE]=0;
                                    v.erase(v.begin()+i);
                                }
                            }
                        }
            }
        }
        for (int i = 0; i<NB_CASES; i++){
            for (int j = 0; j<NB_CASES; j++){
                cout << T[i][j];
            }
            cout << endl;
        }
        // for(int i = 0; i<NB_CASES; i++){
        //     for(int j = 0; j<NB_CASES; j++){
        //         r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //         r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //         r.setFillColor(Color::Green);
        //         v.push_back(r);
        //         switch (this->T[i][j]) {
        //             case 1:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::Green);
        //             v.push_back(r);
        //             break;
        //             case 2:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::Red);
        //             v.push_back(r);
        //             break;
        //             case 3:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::Yellow);
        //             v.push_back(r);
        //             break;
        //             case 4:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::Blue);
        //             v.push_back(r);
        //             break;
        //             case 5:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::White);
        //             v.push_back(r);
        //             break;
        //             default:
        //             r.setOrigin(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setPosition(i*TAILLE_CASE,j*TAILLE_CASE);
        //             r.setFillColor(Color::Black);
        //             v.push_back(r);
        //             break;
        //         }
        //     }
        // }

        for(auto o : v) window.draw(o);
        //cout << v.size() << endl;
        window.draw(lines);
        window.display();
        window.clear();
    }
}
