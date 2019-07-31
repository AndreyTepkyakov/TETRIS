#pragma once
#ifndef Figure
#include "Figure.h"
#endif

/* The class FigureFourMasks contains the implementation of the rotation for the figures rotating 90 degrees
(complete a full circle in four turns).
Stores values and dimensions for masks of figures 0, 90, 180 and 270 degrees.
*/

class FigureFourMasks : public Figure {
public:
	FigureFourMasks();
	~FigureFourMasks();

	//implementation of the rotation for the figures rotating 90 degrees
	void turnFigure(int turnNumber);

protected:

	int numberOfTurns = 4;

	int heightTurn0;
	int widthTurn0;
	std::vector<Point> Turn0;

	int heightTurn90;
	int widthTurn90;
	std::vector<Point> Turn90;

	int heightTurn180;
	int widthTurn180;
	std::vector<Point> Turn180;

	int heightTurn270;
	int widthTurn270;
	std::vector<Point> Turn270;
};

