/*
 * RNG.h
 *
 *  Created on: Mar 23, 2017
 *      Author: dan
 */

#ifndef SRC_RNG_H_
#define SRC_RNG_H_

class RNG
{
public:
	RNG(unsigned long long _seed = 7564231ULL){
		seed = _seed;
		mult = 62089911ULL;
		llong_max = 4294967295ULL;
		float_max = 429496795.0f;
	}

	float operator()();
	unsigned long long seed;
	unsigned long long mult;
	unsigned long long llong_max;
	float float_max;
};

inline float RNG::operator()()
{
	seed = mult * seed;
	return float(seed % llong_max) / float_max;
}





#endif /* SRC_RNG_H_ */
