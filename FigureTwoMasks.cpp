#include "FigureTwoMasks.h"



FigureTwoMasks::FigureTwoMasks() {
}


FigureTwoMasks::~FigureTwoMasks() {
}


//implementation of the rotation for the figures rotating 180 degrees
void FigureTwoMasks::turnFigure(int turnNumber) {

	//save the starting coordinates
	COORD coordStart = mask[0].cord;
	mask.clear();

	//calculate rotation index using modulo division, and write the mask 180 degrees 
	if ((turnNumber % numberOfTurns) == 1) {
		height = heightTurn180;
		width = widthTurn180;
		mask = std::vector<Point>(height * width);
		mask = Turn180;
	}

	//calculate rotation index using modulo division, and write the mask 0 degrees
	if ((turnNumber%numberOfTurns) == 0) {
		height = heightTurn0;
		width = widthTurn0;
		mask = std::vector<Point>(height * width);
		mask = Turn0;
	}

	//fill in the figure coordinates
	fillCoordFigure(coordStart);
}
