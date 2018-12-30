all: main
	./main

main: Main.o Foret.o Lac.o Buisson.o Rocher.o Arbre.o Obstacle.o Point.o Personnage.o
	g++ Main.o Foret.o Lac.o Buisson.o Rocher.o Arbre.o Obstacle.o Point.o Personnage.o -o main -lboost_serialization -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cc Foret.cc Foret.h
	g++ Main.cc -c

Foret.o: Foret.cc Foret.h Rocher.h Arbre.h Buisson.h Lac.h
	g++ Foret.cc -c

Lac.o: Lac.cc Lac.h Obstacle.h
	g++ Lac.cc -c

Buisson.o: Buisson.cc Buisson.h Obstacle.h
	g++ Buisson.cc -c

Rocher.o: Rocher.cc Rocher.h Obstacle.h
	g++ Rocher.cc -c

Arbre.o: Arbre.cc Arbre.h Obstacle.h
	g++ Arbre.cc -c

Obstacle.o: Obstacle.cc Point.h
	g++ Obstacle.cc -c

Point.o: Point.cc
	g++ Point.cc -c

Personnage.o: Personnage.cc Personnage.h
	g++ Personnage.cc -c

clean:
	rm -f *.o
	rm -f main
