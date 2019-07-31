#pragma once
#include <Windows.h>

/*The "Point" structure stores the coordinates, color, and value of the symbol displayed on the screen.*/

struct Point {
	COORD cord;
	char symbol;
	int color;
	
	Point();
	~Point();
	Point(const Point &point);
	Point& operator= (const Point &point);
};

