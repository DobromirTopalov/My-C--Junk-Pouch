#pragma once


	class Rooms
	{
		double width;
		double height;
		double length;

		int floor[5];
	public:
		void setW(double w);
		void setH(double h);
		void setL(double l);

		double getW();
		double getH();
		double getL();

		bool operator<(const Rooms& other);
		bool operator>(const Rooms& other);
		bool operator==(const Rooms& other);

		Rooms operator*(const Rooms& other);
		Rooms operator/(const Rooms& other);
		Rooms operator-(const Rooms& other);
		Rooms operator+(const Rooms& other);
		Rooms& operator=(const Rooms& other);

		int operator[](int possition);
		Rooms operator()(double nheight, double nlenght, double nwidth);
		Rooms* operator->();


		Rooms();
		Rooms(const Rooms& other);
		Rooms(double w, double h, double l);
		Rooms(int f, int s, int t, int fth, int fft);
		~Rooms();

	};
