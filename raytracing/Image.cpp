/*
 * Image.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: dan
 */
#include "Image.h"

Image::Image(){}

Image::Image(int width, int height)
{
	nx = width;
	ny = height;

	raster = new rgb*[nx];
	for(int i = 0; i < nx; i++)
	{
		raster[i] = new rgb[ny];
	}
}

Image::Image(int width, int height, rgb backgroud)
{
	nx = width;
	ny = height;
	raster = new rgb*[nx];
	for(int i = 0; i < nx; i++)
	{

		raster[i] = new rgb[ny];
		for(int j = 0; j < ny; j++)
			raster[i][j] = backgroud;
	}
}

bool Image::set(int x, int y, const rgb& color)
{
	if(x < 0 || x > nx)
		return false;
	if(y < 0 || y > ny)
		return false;

	raster[x][y] = color;
}

void Image::gammaCorrect(float gamma)
{
	rgb temp;
	float power = 1.0/gamma;
	for(int i = 0; i < nx; i++)
	{
		for(int j = 0; j < ny; j++)
		{
			temp = raster[i][j];
			raster[i][j] = rgb(pow(temp.r(), power),
							   pow(temp.g(), power),
							   pow(temp.b(), power));
		}
	}
}

void Image::writePPM(ostream& out)
{
	out << "P6\n";
	out << nx << ' ' << ny << '\n';
	out << "255\n";
	int i, j;
	unsigned int ired, igreen, iblue;
	unsigned char red, green, blue;

	for(i = ny-1; i >=0; i--)
	{
		for(j = 0; j < nx; j++)
		{
			ired = (unsigned int)(256*raster[j][i].r());
			igreen = (unsigned int)(256*raster[j][i].g());
			iblue = (unsigned int)(256*raster[j][i].b());

			if(ired > 255) ired = 255;
			if(igreen > 255) igreen = 255;
			if(iblue > 255) iblue = 255;
			red = (unsigned char)(ired);
			green = (unsigned char)(igreen);
			blue = (unsigned char)(iblue);
			out.put(red);
			out.put(green);
			out.put(blue);
		}
	}
}

void Image::readPPM(string file_name)
{
	ifstream in;
	in.open(file_name.c_str());
	if(!in.is_open())
	{
		cerr << "ERROR -- Couldn't open file \'" << file_name << "\'.\n";
		exit(-1);
	}

	char ch, type;
	char red, green, blue;
	int i, j, cols, rows;
	int num;
	in.get(ch);
	in.get(type);
	in >> cols >> rows >> num;

	nx = cols;
	ny = rows;

	raster = new rgb*[nx];

	for(i = 0; i < nx; i++)
		raster[i] = new rgb[ny];

	in.get(ch);
	for(i = ny-1; i>= 0; i--)
	{
		for(j = 0; j < nx; j++)
		{
			in.get(red);
			in.get(green);
			in.get(blue);
			raster[i][j] = rgb((float)((unsigned char)red)/255.0,
								(float)((unsigned char)green)/255.0,
								(float)((unsigned char)blue)/255.0);
		}
	}
}



