using namespace std;
#include "Point.h"
#include <iostream>

Point::Point() {
	this->x = 0;
	this->y = 0;
};

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
};

Point::Point(Point& p) {
	this->x = p.x;
	this->y = p.y;

};

Point::~Point() {
	cout << "point detruit" << endl;
}

void Point::afficher() {
	cout << "x = " << this->x << endl;
	cout << "y = " << this->y << endl;
}

void Point::cloner(const Point& p) {
	this->x = p.x;
	this->y = p.y;
}

int Point::getx() {
	return this->x;
}

int Point::gety() {
	return this->y;
}
