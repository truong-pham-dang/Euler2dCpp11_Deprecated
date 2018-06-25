#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class MyPoint{

public:
	MyPoint(){};
	MyPoint(double, double, double, unsigned);
	bool operator==(MyPoint);
	void print();
	int get_ident();
	double get_x();
	double get_y();
	double get_z();

private:
    double x;
    double y;
    double z;
    unsigned ident;
};

