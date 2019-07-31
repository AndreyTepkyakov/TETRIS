#include "Point.h"


Point::Point() {
}

Point::~Point() {
}

// Constructor Copy
Point::Point(const Point &point) {
	cord.X = point.cord.X;
	cord.Y = point.cord.Y;
	symbol = point.symbol;
	color = point.color;
}

// Assignment operator
Point & Point::operator=(const Point & point) {
	cord.X = point.cord.X;
	cord.Y = point.cord.Y;
	symbol = point.symbol;
	color = point.color;
	return *this;
}

