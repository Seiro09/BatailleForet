using namespace std;
#include <iostream>

class Point {
private:
	int x, y;

public:
	Point();
	Point(int, int);
	Point(Point&);
	~Point();
    void afficher();
	void cloner(const Point&);
	int getx();
	int gety();
};
