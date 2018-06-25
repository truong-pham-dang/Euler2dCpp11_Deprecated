#include "MyPoint.h"

MyPoint::MyPoint(double x, double y, double z, unsigned ident)
{
    this -> x     = x;
    this -> y     = y;
    this -> z     = z;
    this -> ident = ident;
}

bool MyPoint::operator==(MyPoint rhs)
{
	if (abs(this->x - rhs.x) <= 1.0e-9 && abs(this->y - rhs.y) <= 1.0e-9 && abs(this->z - rhs.z) <= 1.0e-9)
	{
		return true;
	}
	return false;
}

int MyPoint::get_ident()
{
	return this->ident;
}

double MyPoint::get_x()
{
	return this->x;
}

double MyPoint::get_y()
{
	return this->y;
}

double MyPoint::get_z()
{
	return this->z;
}

void MyPoint::print()
{
    cout << this -> x << " " << this -> y << " " << this -> z << "\n" << endl;
}

