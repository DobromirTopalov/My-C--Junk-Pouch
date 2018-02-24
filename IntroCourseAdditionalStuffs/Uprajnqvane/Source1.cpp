#include "Header.h"

Rooms::Rooms(const Rooms& other)
{
	width = other.width;
	height = other.height;
	length = other.length;

}

Rooms::Rooms(double w, double h, double l)
		:width(w),height(h),length(l){}


void Rooms::setW(double w)
{
	width = w;
}

void Rooms::setH(double h)
{
	height = h;
}

void Rooms::setL(double l)
{
	length - l;
}

double Rooms::getW()
{
	return width;
}

double Rooms::getH()
{
	return height;
}

double Rooms::getL()
{
	return length;
}

Rooms::Rooms()
{
	width = 0;
	height = 0;
	length = 0;
}

Rooms Rooms::operator+(const Rooms& other)
{
	Rooms temp;
	temp.width = width + other.width;
	temp.height = height + other.height;
	temp.length = length + other.length;
	return temp;
}

Rooms Rooms::operator/(const Rooms& other)
{
	Rooms temp;
	temp.width = width / other.width;
	temp.height = height / other.height;
	temp.length = length / other.length;
	return temp;
}

Rooms Rooms::operator*(const Rooms& other)
{
	Rooms temp;
	temp.width = width * other.width;
	temp.height = height * other.height;
	temp.length = length * other.length;
	return temp;
}

Rooms Rooms::operator-(const Rooms& other)
{
	Rooms temp;
	temp.width = width - other.width;
	temp.height = height - other.height;
	temp.length = length - other.length;
	return temp;
}

Rooms& Rooms::operator=(const Rooms& other)
{
	if (this != &other)
	{
		width = other.width;
		height = other.height;
		length = other.length;
	}
	return *this;
}

bool Rooms::operator<(const Rooms& other)
{
	if ((width + height + length) < (other.width + other.height + other.length))
		return true;
	else
		return false;
}

bool Rooms::operator==(const Rooms& other)
{
	if ((width + height + length) == (other.width + other.height + other.length))
		return true;
	else
		return false;
}

bool Rooms::operator>(const Rooms& other)
{
	if ((width + height + length) > (other.width + other.height + other.length))
		return true;
	else
		return false;
}

Rooms::~Rooms(){
	
	width = 0;
	height = 0;
	length = 0;
}

Rooms::Rooms(int f, int s, int t, int fth, int fft)
{
	floor[0] = (f);
	floor[1] = (s);
	floor[2] = (t);
	floor[3]=(fth);
	floor[4]=(fft);
}

int Rooms::operator[](int possition)
{
	return floor[possition];
}

Rooms Rooms:: operator()(double nheight, double nlenght, double nwidth)
{
	height = nheight;
	length = nlenght;
	width = nwidth;
	return *this;
}
Rooms* Rooms:: operator->()
{
	return this;
}


