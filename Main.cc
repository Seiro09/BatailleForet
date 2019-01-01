#include <iostream>
#include "Foret.h"
#include "Personnage.h"
#include <random>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//Trouver une image libre de droit ou supprimer le tag
//Créer les menus pour chaque bouton
//Découper le code (pas mon travail)
//Créer l'interface de jeu juste après les menus

void Nouvelle_Partie(Foret f) {
    //window.clear();
    RenderWindow new_game(VideoMode(TAILLE_FORET, TAILLE_FORET),
    "Nouvelle Partie", Style::Close);
    new_game.setFramerateLimit(60);
    new_game.setKeyRepeatEnabled(false);
    string fichier;
    cin >> fichier;
    f.lecture(fichier);
    vector<RectangleShape> v;
    Texture arbre;
    arbre.loadFromFile("./sans_fond/arbre.png");
    arbre.setSmooth(true);
    Texture buisson;
    buisson.loadFromFile("./sans_fond/buisson.png");
    buisson.setSmooth(true);
    Texture rocher;
    rocher.loadFromFile("./sans_fond/rocher.png");
    rocher.setSmooth(true);
    Texture lac;
    lac.loadFromFile("./sans_fond/lac.png");
    lac.setSmooth(true);
    RectangleShape r2(Vector2f(TAILLE_CASE,TAILLE_CASE));
    for(int i = 0; i<NB_CASES; i++){
        for(int j = 0; j<NB_CASES; j++){
            switch (f.T[i][j]) {
                case 1:
                r2.setPosition(i*TAILLE_CASE, j*TAILLE_CASE);
                r2.setTexture(&arbre);
                v.push_back(r2);
                break;
                case 2:
                //RectangleShape r2(Vector2f(TAILLE_CASE,TAILLE_CASE));
                r2.setPosition(i*TAILLE_CASE, j*TAILLE_CASE);
                r2.setTexture(&buisson);
                v.push_back(r2);
                break;
                case 3:
                //RectangleShape r2(Vector2f(TAILLE_CASE,TAILLE_CASE));
                r2.setPosition(i*TAILLE_CASE, j*TAILLE_CASE);
                r2.setTexture(&rocher);
                v.push_back(r2);
                break;
                case 4:
                //RectangleShape r2(Vector2f(TAILLE_CASE,TAILLE_CASE));
                r2.setPosition(i*TAILLE_CASE, j*TAILLE_CASE);
                r2.setTexture(&lac);
                v.push_back(r2);
                break;
                default:
                //case vide
                break;
            }
        }
    }
    default_random_engine re(time(0));
    uniform_int_distribution<int> distrib{0,NB_CASES-1};
    int a = distrib(re);
    int b = distrib(re);
    while (f.T[a][b]!=0){
        a = distrib(re);
        b = distrib(re);
    }
    Personnage p1 (a,b);
    RectangleShape joueur(Vector2f(TAILLE_CASE,TAILLE_CASE));
    joueur.setPosition(p1.getx()*TAILLE_CASE,p1.gety()*TAILLE_CASE);
    a = distrib(re);
    b = distrib(re);
    while (f.T[a][b]!=0){
        a = distrib(re);
        b = distrib(re);
    }
    Personnage p2 (a,b);
    RectangleShape joueur2(Vector2f(TAILLE_CASE,TAILLE_CASE));
    joueur2.setPosition(p2.getx()*TAILLE_CASE,p2.gety()*TAILLE_CASE);
    RectangleShape fond(Vector2f(TAILLE_FORET,TAILLE_FORET));
    fond.setOrigin(TAILLE_FORET/2.f,TAILLE_FORET/2.f);
    fond.setPosition(TAILLE_FORET/2.f,TAILLE_FORET/2.f);
    Texture textureF;
    textureF.loadFromFile("foret4.png");
    fond.setTexture(&textureF);
    textureF.setSmooth(true);
    Texture joueurH;
    joueurH.loadFromFile("./sans_fond/mario_haut.png");
    joueur.setTexture(&joueurH);
    joueurH.setSmooth(true);
    Texture joueurD;
    joueurD.loadFromFile("./sans_fond/mario_droit.png");
    joueurD.setSmooth(true);
    Texture joueurB;
    joueurB.loadFromFile("./sans_fond/mario_bas.png");
    joueurB.setSmooth(true);
    Texture joueurG;
    joueurG.loadFromFile("./sans_fond/mario_gauche.png");
    joueurG.setSmooth(true);
    Texture joueur2H;
    joueur2H.loadFromFile("./sans_fond/sonic_haut.png");
    joueur2.setTexture(&joueur2H);
    joueur2H.setSmooth(true);
    Texture joueur2D;
    joueur2D.loadFromFile("./sans_fond/sonic_droit.png");
    joueur2D.setSmooth(true);
    Texture joueur2B;
    joueur2B.loadFromFile("./sans_fond/sonic_bas.png");
    joueur2B.setSmooth(true);
    Texture joueur2G;
    joueur2G.loadFromFile("./sans_fond/sonic_gauche.png");
    joueur2G.setSmooth(true);
    int portee=0;
    int angle=0;
    int force=0;
    bool tour_joueur_1 = true;
    CircleShape zone;
    while(new_game.isOpen()){
        Event event;
        while (new_game.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    new_game.close();
                    break;
                case Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.delta>0) portee+=1;
                    if (event.mouseWheelScroll.delta<0) portee-=1;
                    if (portee<0) portee=0;
                    if (portee>5) portee=5;
                    zone.setRadius(portee*TAILLE_CASE/2.0);
                    break;
                case Event::MouseMoved:
                    zone.setPosition(Vector2f(event.mouseMove.x,event.mouseMove.y));
                    zone.setOrigin(Vector2f(zone.getRadius(),zone.getRadius()));
                    break;
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left){
                        int posdepx = event.mouseButton.x/TAILLE_CASE*TAILLE_CASE-(portee/2)*TAILLE_CASE;
                        int posdepy = event.mouseButton.y/TAILLE_CASE*TAILLE_CASE-(portee/2)*TAILLE_CASE;
                        for (int departx=posdepx;
                            departx < posdepx+portee*TAILLE_CASE;
                            departx = departx+TAILLE_CASE){
                            for (int departy=posdepy;
                                departy < posdepy+portee*TAILLE_CASE;
                                departy = departy+TAILLE_CASE){
                                    if (tour_joueur_1){
                                        if (departx/TAILLE_CASE == p2.getx() && departy/TAILLE_CASE==p2.gety()){
                                            f.~Foret();
                                            p1.~Personnage();
                                            p2.~Personnage();
                                            new_game.close();
                                            cout << "Joueur 1 a gagné" << endl;
                                        }
                                    }
                                    else {
                                        if (departx/TAILLE_CASE == p1.getx() && departy/TAILLE_CASE==p1.gety()){
                                            f.~Foret();
                                            p1.~Personnage();
                                            p2.~Personnage();
                                            new_game.close();
                                            cout << "Joueur 2 a gagné" << endl;
                                        }
                                    }
                                    f.supprime(departx,departy);
                                    for(int i = 0; i<v.size();i++){
                                            if (v[i].getPosition()==Vector2f(departx,departy)){
                                            Vector2f pos = v[i].getPosition();
                                            f.T[(int)pos.x/TAILLE_CASE][(int)pos.y/TAILLE_CASE]=0;
                                            v.erase(v.begin()+i);
                                        }
                                    }
                                }
                            }
                        if (tour_joueur_1) tour_joueur_1 = false;
                        else tour_joueur_1 = true;
                    }
                    break;
                    case Event::KeyPressed:
                    if (event.key.code == Keyboard::Left) {
                        if (tour_joueur_1){
                            if (p1.getx()>0 && f.T[p1.getx()-1][p1.gety()]==0) p1.setx(p1.getx()-1);
                            joueur.setTexture(&joueurG);
                        }
                        else {
                            if (p2.getx()>0 && f.T[p2.getx()-1][p2.gety()]==0) p2.setx(p2.getx()-1);
                            joueur2.setTexture(&joueur2G);
                        }
                    }
                    if (event.key.code == Keyboard::Right) {
                        if (tour_joueur_1)
                        {
                            if (p1.getx()<NB_CASES-1 && f.T[p1.getx()+1][p1.gety()]==0) p1.setx(p1.getx()+1);
                            joueur.setTexture(&joueurD);
                        }
                        else{
                            if (p2.getx()<NB_CASES-1 && f.T[p2.getx()+1][p2.gety()]==0) p2.setx(p2.getx()+1);
                            joueur2.setTexture(&joueur2D);
                        }
                    }
                    if (event.key.code == Keyboard::Up) {
                        if (tour_joueur_1)
                        {
                            if (p1.gety()>0 && f.T[p1.getx()][p1.gety()-1]==0) p1.sety(p1.gety()-1);
                            joueur.setTexture(&joueurH);
                        }
                        else{
                            if (p2.gety()>0 && f.T[p2.getx()][p2.gety()-1]==0) p2.sety(p2.gety()-1);
                            joueur2.setTexture(&joueur2H);
                        }
                    }
                    if (event.key.code == Keyboard::Down) {
                        if (tour_joueur_1)
                        {
                            if (p1.gety()<NB_CASES-1 && f.T[p1.getx()][p1.gety()+1]==0) p1.sety(p1.gety()+1);
                            joueur.setTexture(&joueurB);
                        }
                        else{
                            if (p2.gety()<NB_CASES-1 && f.T[p2.getx()][p2.gety()+1]==0) p2.sety(p2.gety()+1);
                            joueur2.setTexture(&joueur2B);
                        }
                    }
                    break;
            }
        }
        joueur.setPosition(p1.getx()*TAILLE_CASE,p1.gety()*TAILLE_CASE);
        joueur2.setPosition(p2.getx()*TAILLE_CASE,p2.gety()*TAILLE_CASE);
        new_game.clear();
        new_game.draw(fond);
        for(auto o : v) new_game.draw(o);
        if (tour_joueur_1) new_game.draw(joueur);
        else new_game.draw(joueur2);
        new_game.draw(zone);
        new_game.display();
    }
}

void Regles_du_Jeu(){
    RenderWindow rules(VideoMode(TAILLE_FORET, 300),
    "Regles", Style::Close);
    Font police;
    police.loadFromFile("arial.ttf");
    Text text1;
    text1.setFont(police);
    text1.setString("Regles du Jeu");
    FloatRect bound = text1.getLocalBounds();
    text1.setOrigin(Vector2f(bound.width/2 + bound.left, bound.height/2 + bound.top));
    text1.setPosition(TAILLE_FORET/2, bound.height);
    text1.setCharacterSize(35);

    Text regles1;
    regles1.setFont(police);
    regles1.setString(L"Deux joueurs s’affrontent dans une forêt hostile remplie d’obstacles en tous genres. Chaque");
    FloatRect bound1 = regles1.getLocalBounds();
    //regles1.setOrigin(Vector2f(bound1.width/2 + bound1.left, bound1.height/2 + bound1.top));
    regles1.setPosition(0, bound1.height+100);
    regles1.setCharacterSize(18);

    Text regles2;
    regles2.setFont(police);
    regles2.setString(L"joueur dispose d’une arme d’attaque avec des caractéristiques précises et cherche à éliminer");
    FloatRect bound2 = regles2.getLocalBounds();
    //regles1.setOrigin(Vector2f(bound1.width/2 + bound1.left, bound1.height/2 + bound1.top));
    regles2.setPosition(0, bound2.height+125);
    regles2.setCharacterSize(18);

    Text regles3;
    regles3.setFont(police);
    regles3.setString(L"son adversaire en le mettant hors jeu. Le joueur peut être aussi mis hors jeu par l’épuisement");
    FloatRect bound3 = regles3.getLocalBounds();
    //regles1.setOrigin(Vector2f(bound1.width/2 + bound1.left, bound1.height/2 + bound1.top));
    regles3.setPosition(0, bound3.height+150);
    regles3.setCharacterSize(18);

    Text regles4;
    regles4.setFont(police);
    regles4.setString(L"de ses forces.");
    FloatRect bound4 = regles4.getLocalBounds();
    //regles1.setOrigin(Vector2f(bound1.width/2 + bound1.left, bound1.height/2 + bound1.top));
    regles4.setPosition(0, bound4.height+180);
    regles4.setCharacterSize(18);
    while(rules.isOpen()){
        Event event;
        while(rules.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                rules.close();
            }

        }
        rules.draw(text1);
        rules.draw(regles1);
        rules.draw(regles2);
        rules.draw(regles3);
        rules.draw(regles4);
        rules.display();
    }
}

void Menu_Principal(){
    string fichier;
    Foret f;
    double taille_bouton_x = 300;
    double taille_bouton_y = 100;
    RenderWindow window(VideoMode(TAILLE_FORET, TAILLE_FORET),
        "Bataille en Foret !", Style::Close | Style::Resize);

    RectangleShape fond(Vector2f(TAILLE_FORET,TAILLE_FORET));
    fond.setOrigin(TAILLE_FORET/2.f,TAILLE_FORET/2.f);
    fond.setPosition(TAILLE_FORET/2.f,TAILLE_FORET/2.f);
    Texture textureF;
    textureF.loadFromFile("FondBatailleForet.jpg");
    fond.setTexture(&textureF);
    textureF.setSmooth(true);

    RectangleShape shapeNP(Vector2f(taille_bouton_x,taille_bouton_y));
    shapeNP.setOrigin(taille_bouton_x/2.f,taille_bouton_y/2.f);
    shapeNP.setPosition(TAILLE_FORET/4.f,2*TAILLE_FORET/3.f);
    Texture texture1;
    texture1.loadFromFile("boutons/NouvellePartie.png");
    shapeNP.setTexture(&texture1);
    texture1.setSmooth(true);

    RectangleShape shapeEF(Vector2f(taille_bouton_x,taille_bouton_y));
    shapeEF.setOrigin(taille_bouton_x/2.f,taille_bouton_y/2.f);
    shapeEF.setPosition(TAILLE_FORET/4.f,7*TAILLE_FORET/8.f);
    Texture texture2;
    texture2.loadFromFile("boutons/EditerForet.png");
    shapeEF.setTexture(&texture2);
    texture2.setSmooth(true);

    RectangleShape shapeRDJ(Vector2f(taille_bouton_x,taille_bouton_y));
    shapeRDJ.setOrigin(taille_bouton_x/2.f,taille_bouton_y/2.f);
    shapeRDJ.setPosition(3*TAILLE_FORET/4.f,2*TAILLE_FORET/3.f);
    Texture texture3;
    texture3.loadFromFile("boutons/ReglesDuJeu.png");
    shapeRDJ.setTexture(&texture3);
    texture3.setSmooth(true);

    RectangleShape shapeQJ(Vector2f(taille_bouton_x,taille_bouton_y));
    shapeQJ.setOrigin(taille_bouton_x/2.f,taille_bouton_y/2.f);
    shapeQJ.setPosition(3*TAILLE_FORET/4.f,7*TAILLE_FORET/8.f);
    Texture texture4;
    texture4.loadFromFile("boutons/QuitterLeJeu.png");
    shapeQJ.setTexture(&texture4);
    texture4.setSmooth(true);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    cout<< event.size.width << event.size.height << endl;
                    break;
            }
        }

        // if (Keyboard::isKeyPressed(Keyboard::Key::Z)) shape.move(0.0f,-0.2f);
        // if (Keyboard::isKeyPressed(Keyboard::Key::Q)) shape.move(-0.2f,0.0f);
        // if (Keyboard::isKeyPressed(Keyboard::Key::S)) shape.move(0.0f,0.2f);
        // if (Keyboard::isKeyPressed(Keyboard::Key::D)) shape.move(0.2f,0.0f);
        //texture.update()

        Image image;
        if (shapeNP.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))){
            image.loadFromFile("boutons/NouvellePartie_souris.png");
            texture1.update(image);
            shapeNP.setTexture(&texture1);
            texture1.setSmooth(true);
            if (Mouse::isButtonPressed(Mouse::Left)){
                Nouvelle_Partie(f);
                //montrer les niveaux déja crées
                // window.close();
                // f.lecture("Test3.txt");
                // jouer(f.T);
            }
        }
        else if (shapeEF.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))){
            image.loadFromFile("boutons/EditerForet_souris.png");
            texture2.update(image);
            shapeEF.setTexture(&texture2);
            texture2.setSmooth(true);
            if (Mouse::isButtonPressed(Mouse::Left)){
                //Création nouveau niveau
                f.Edition_Nouvelle_Foret();
            }
            if (Mouse::isButtonPressed(Mouse::Right)){
                //Edition niveau existant
                f.Edition_Foret_Existante();
            }
        }
        else if (shapeRDJ.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))){
            image.loadFromFile("boutons/ReglesDuJeu_souris.png");
            texture3.update(image);
            shapeRDJ.setTexture(&texture3);
            texture3.setSmooth(true);
            if (Mouse::isButtonPressed(Mouse::Left)){
                //Afficher les règles
                Regles_du_Jeu();
            }
        }
        else if (shapeQJ.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))){
            image.loadFromFile("boutons/QuitterLeJeu_souris.png");
            texture4.update(image);
            shapeQJ.setTexture(&texture4);
            texture4.setSmooth(true);
            if (Mouse::isButtonPressed(Mouse::Left)) window.close();
        }
        else{
            image.loadFromFile("boutons/NouvellePartie.png");
            texture1.update(image);
            shapeNP.setTexture(&texture1);
            texture1.setSmooth(true);
            image.loadFromFile("boutons/EditerForet.png");
            texture2.update(image);
            shapeEF.setTexture(&texture2);
            texture2.setSmooth(true);
            image.loadFromFile("boutons/ReglesDuJeu.png");
            texture3.update(image);
            shapeRDJ.setTexture(&texture3);
            texture3.setSmooth(true);
            image.loadFromFile("boutons/QuitterLeJeu.png");
            texture4.update(image);
            shapeQJ.setTexture(&texture4);
            texture4.setSmooth(true);
        }



        window.clear();
        window.draw(fond);
        window.draw(shapeNP);
        window.draw(shapeEF);
        window.draw(shapeRDJ);
        window.draw(shapeQJ);
        window.display();
    }
}
int main() {
    Menu_Principal();
    // Foret f;
    // string fichier;
    // f.editerNiveau();
    // cout << endl;
    // f.afficher();
    // cout << "Donner un fichier a ouvrir : ";
    // cin >> fichier;
    // f.lecture(fichier);
    // cout << endl;
    // f.afficher();
    // f.editerNiveau();
    // cout << "Nouveau niveau :" << endl << endl;
    // f.afficher();

}
