using namespace std;
#include <iostream>
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Point {
private:
	int x, y;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version){
		ar & x & y;
	}
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
