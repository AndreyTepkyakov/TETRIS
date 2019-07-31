#pragma once

#ifndef Figure
#include "Figure.h"
#endif

/* The class FigureTwoMasks contains the implementation of the rotation for the figures rotating 180 degrees
 (complete a full circle in two turns).
 Stores values and dimensions for masks of figures 0 and 180 degrees.
 */

class FigureTwoMasks : public Figure {
public:
	FigureTwoMasks();
	~FigureTwoMasks();

	//implementation of the rotation for the figures rotating 180 degrees
	void turnFigure(int turnNumber);

protected:

	int numberOfTurns = 2;

	int heightTurn0;
	int widthTurn0;
	std::vector<Point> Turn0;

	int heightTurn180;
	int widthTurn180;
	std::vector<Point> Turn180;
};

