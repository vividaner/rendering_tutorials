/*
 * rgb.h
 *
 *  Created on: Mar 22, 2017
 *      Author: dan
 */

#ifndef RGB_H_
#define RGB_H_

#include <iostream>


class rgb {
public:
	rgb() {_r = _g = _b = 0;}
	virtual ~rgb();


	rgb(float red, float green, float blue);
	rgb(const rgb & original){*this = original;}

	void setRed(float red) {_r = red;}
	void setGreen(float green) {_g = green;}
	void setBlue(float blue) {_b = blue;}


	rgb& operator=(const rgb & right_op);
	rgb& operator+=(const rgb & right_op);
	rgb& operator*=(const rgb & right_op);
	rgb& operator/=(const rgb & right_op);
	rgb& operator*=(float right_op);
	rgb& operator/=(float right_op);

	rgb operator+()const {return *this;}
	rgb operator-()const {return rgb(-_r, -_g, -_b);}

	float r() const {return _r;}
	float g() const {return _g;}
	float b() const {return _b;}

	void clamp();

	//friend ostream& operator<<(ostream & out, const rgb & the_rgb);
	friend rgb operator*(const rgb& c, float f);
	friend rgb operator*(float f, const rgb& c);
	friend rgb operator/(const rgb& c, float f);
	friend rgb operator*(const rgb& c1, const rgb& c2);
	friend rgb operator/(const rgb& c1, const rgb& c2);
	friend rgb operator+(const rgb& c1, const rgb& c2);


	float _r;
	float _g;
	float _b;


};

inline rgb::rgb(float red, float green, float blue) : _r(red), _g(green), _b(blue) {}
inline rgb::~rgb(){}
inline rgb& rgb::operator+=(const rgb & right_op){
	*this = *this + right_op;
	return *this;
}

inline rgb& rgb::operator*=(float right_op){
	*this = *this * right_op;
	return *this;
}

inline rgb& rgb::operator/=(float right_op){
	*this = *this / right_op;
	return *this;
}

inline rgb& rgb::operator*=(const rgb & right_op){
	*this = *this * right_op;
	return *this;
}

inline rgb& rgb::operator/=(const rgb & right_op){
	*this = *this / right_op;
	return *this;
}

inline rgb& rgb::operator=(const rgb & right_op){
	_r = right_op._r;
	_g = right_op._g;
	_b = right_op._b;
	return *this;
}

inline void rgb::clamp(){
	if(_r > 1.0f) _r = 1.0f;
	if(_g > 1.0f) _g = 1.0f;
	if(_b > 1.0f) _b = 1.0f;

	if(_r < 0.0f) _r = 0.0f;
	if(_g < 0.0f) _g = 0.0f;
	if(_b < 0.0f) _b = 0.0f;
}

inline rgb operator*(const rgb& c, float f)
{
	return rgb(c._r*f, c._g*f, c._b*f);
}

inline rgb operator*(float f, const rgb& c)
{
	return rgb(c._r*f, c._g*f, c._b*f);
}

inline rgb operator/(const rgb& c, float f)
{
	return rgb(c._r/f, c._g/f, c._b/f);
}

inline rgb operator*(const rgb& c1, const rgb& c2)
{
	return rgb(c1._r*c2._r, c1._g*c2._g, c1._b*c2._b);
}

inline rgb operator/(const rgb& c1, const rgb& c2)
{
	return rgb(c1._r/c2._r, c1._g/c2._g, c1._b/c2._b);
}

inline rgb operator+(const rgb& c1, const rgb& c2)
{
	return rgb(c1._r+c2._r, c1._g+c2._g, c1._b+c2._b);
}







#endif /* RGB_H_ */
