#pragma once
#include <iostream>
#include <vector>

#ifndef Point
#include "Point.h"
#endif

/* The class "figure" contains the height, width, color and vector mask that will be displayed on the screen.*/

class Figure {
public:
	Figure();

	Figure& operator= (const Figure & figure);

	~Figure();

	int getHeight();

	int getWidth();

	int getColor();

	// Pass the coordinates of the point, located in the vector mask at the index [i][j]
	COORD getCoordforIndex(int i, int j);

	// Pass the Symbol of the point, located in the vector mask at the index [i][j]
	char getSymbolforIndex(int i, int j);

	// Filling the mask with coordinates, starting from the starting coordinate
	void fillCoordFigure(COORD startCoord);

	// Shift of coordinates to the right
	void moveRightFigure();

	// Shift of coordinates to the left
	void moveLeftFigure();

	// Shift of coordinates down
	void moveDownFigure();

	// Virtual method to turning figure, implementation for figures without turning
	virtual void turnFigure(int numberTurns);

protected:
	int height;
	int width;
	std::vector<Point> mask;
	int color;
};

