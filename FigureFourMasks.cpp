#include "FigureFourMasks.h"


FigureFourMasks::FigureFourMasks() {
}


FigureFourMasks::~FigureFourMasks() {
}


//implementation of the rotation for the figures rotating 90 degrees
void FigureFourMasks::turnFigure(int turnNumber) {
	
	//save the starting coordinates
	COORD coordStart = mask[0].cord;
	mask.clear();

	// calculate rotation index using modulo division
	switch (turnNumber % numberOfTurns)
	{
	//write the mask 90 degrees
	case 1:
		height = heightTurn90;
		width = widthTurn90;
		mask = std::vector<Point>(height * width);
		mask = Turn90;
		break;
	//write the mask 180 degrees
	case 2:
		height = heightTurn180;
		width = widthTurn180;
		mask = std::vector<Point>(height * width);
		mask = Turn180;
		break;
	//write the mask 270 degrees
	case 3:
		height = heightTurn270;
		width = widthTurn270;
		mask = std::vector<Point>(height * width);
		mask = Turn270;
		break;
	//write the mask 0 degrees
	case 0:
		height = heightTurn0;
		width = widthTurn0;
		mask = std::vector<Point>(height * width);
		mask = Turn0;
		break;
	}

	//fill in the figure coordinates
	fillCoordFigure(coordStart);
}