#include <iostream>
#include "Foret.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

//Trouver une image libre de droit ou supprimer le tag
//Créer les menus pour chaque bouton
//Découper le code (pas mon travail)
//Créer l'interface de jeu juste après les menus

void Nouvelle_Partie(RenderWindow& window) {
    window.clear();
    window.create(VideoMode(TAILLE_FORET,TAILLE_FORET), "Nouvelle Partie");
    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.display();
    }
}

void Disclaimer_Edition(){
    RenderWindow window(VideoMode(TAILLE_FORET,200),
     "Edition Foret");
     double taille_bouton_x = 60;
     double taille_bouton_y = 20;
     Font police;
     police.loadFromFile("arial.ttf");
     Text text1;
     text1.setFont(police);
     text1.setString("Charger une foret existante ?");
     FloatRect bound = text1.getLocalBounds();
     text1.setOrigin(Vector2f(bound.width/2 + bound.left, bound.height/2 + bound.top));
     text1.setPosition(TAILLE_FORET/2, bound.height);
     text1.setCharacterSize(35);

     RectangleShape shapeO(Vector2f(taille_bouton_x,taille_bouton_y));
     shapeO.setOrigin(taille_bouton_x/2.f,taille_bouton_y/2.f);
     shapeO.setPosition(TAILLE_FORET/4.f,2*200/3.f);
     Texture texture1;
     texture1.loadFromFile("boutons/NouvellePartie.png");
     shapeO.setTexture(&texture1);
     texture1.setSmooth(true);

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.draw(shapeO);
        window.display();
}
}

void Edition_Foret_Existante(){



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
        //Ecrire les regles
        rules.draw(text1);
        rules.draw(regles1);
        rules.draw(regles2);
        rules.draw(regles3);
        rules.draw(regles4);
        rules.display();
    }
}

int main() {
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
                Nouvelle_Partie(window);
                //montrer les niveaux déja crées
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
                Edition_Foret_Existante();
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
