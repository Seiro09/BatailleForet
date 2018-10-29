all: main
	./main

main: Main.o Foret.o Rocher.o Arbre.o Obstacle.o Point.o
	g++ Main.o Foret.o Rocher.o Arbre.o Obstacle.o Point.o -o main

Main.o: Main.cc Foret.cc Foret.h
	g++ Main.cc -c

Foret.o: Foret.cc Foret.h Rocher.h Arbre.h
	g++ Foret.cc -c

Rocher.o: Rocher.cc Rocher.h Obstacle.h
	g++ Rocher.cc -c

Arbre.o: Arbre.cc Arbre.h Obstacle.h
	g++ Arbre.cc -c

Obstacle.o: Obstacle.cc Point.h
	g++ Obstacle.cc -c

Point.o: Point.cc
	g++ Point.cc -c

clean:
	rm -f *.o
	rm -f main
