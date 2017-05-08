/*
 * Image.h
 *
 *  Created on: Mar 22, 2017
 *      Author: dan
 */

#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <cmath>
#include <string>
#include <fstream>
#include "rgb.h"
using namespace std;


class Image
{
public:
	Image();
	Image(int width, int height);
	Image(int width, int height, rgb background);

	bool set(int x, int y, const rgb & color);
	void gammaCorrect(float gamma);
	void writePPM(ostream& out);
	void readPPM(string file_name);

private:
	rgb** raster;
	int nx;  // raster width
	int ny;  // raster height
};

#endif /* SRC_IMAGE_H_ */
