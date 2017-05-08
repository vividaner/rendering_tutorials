/*
 * Vector3.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: dan
 */




#include "Vector3.h"

istream & operator>>(istream &is, Vector3 &t)
{
	float temp;
	is >> temp;
	t.e[0] = temp;
	is >> temp;
	t.e[1] = temp;
	is >> temp;
	t.e[2] = temp;

	return is;
}

ostream & operator<<(ostream &os, const Vector3 &t)
{
	os << '('
	   << t.e[0] << " "
	   << t.e[1] << " "
	   << t.e[2] << ')';

	return os;
}
