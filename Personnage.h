#ifndef PERSONNAGE_H
#define PERSONNAGE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>


class Personnage {
private:
	int x,y;
    int orientation;
    int PV;
    ///Arme
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version){
		ar & x & y;
	}
public:
	Personnage(int, int);
    ~Personnage();
	int getx();
	int gety();
	int getorientation();
	int getPV();

	void setx(int);
	void sety(int);
	void setorientation(int);
	void setPV(int);
};

#endif
