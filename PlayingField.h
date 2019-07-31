#pragma once
#include <iostream>
#include <vector>

#ifndef Point
#include "Point.h"
#endif

/*class Playing field stores the size and vector of the game field points*/
class PlayingField {
public:

	PlayingField();
	
	~PlayingField();
	
	int getHeight();

	int getWidth();

	int getColor();

	// Pass the Symbol of the point, located in the vector mask at the index [i][j]
	char getSymbolforIndex(int i, int j);

	// Pass the Color of the point, located in the vector mask at the index [i][j]
	char getColorforIndex(int i, int j);

	// Pass the coordinates of the point, located in the vector mask at the index [i][j]
	COORD getCoordforIndex(int i, int j);

	// Save Point in Field
	void savePoint(Point pointSave);

	// Check point in Field for empty
	BOOL checkForEmpty(int i, int j);

	// Check lines in field for full
	int checkFullLines(int indexLines);

	// Remove full lines in fild
	void removeFullLines(int indexLines);

	// Check field for full
	BOOL checkFullField();

private:
	int height;
	int width;
	std::vector<Point> field;
	int color;
	
};

