#include "PlayingField.h"


//fill Field data in the default constructor
PlayingField::PlayingField() {

	height = 22;
	width = 22;

	color = 0x0b;

	field = std::vector<Point>(height*width);

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			field[((i * width) + j)].cord.Y = i;
			field[((i * width) + j)].cord.X = j;
			field[((i * width) + j)].color = color;
			
			if (i == 0 && j == 0) {
				field[((i * width) + j)].symbol = 201;
			} else
			if (i == 0 && j == (width - 1)) {
				field[((i * width) + j)].symbol = 187;
			} else
			if (i == (height - 1) && j == 0) {
				field[((i * width) + j)].symbol = 200;
			} else
			if (i == (height - 1) && j == (width - 1)) {
				field[((i * width) + j)].symbol = 188;
			} else
			if (i == 0 || i == (height - 1)) {
				field[((i * width) + j)].symbol = 205;
			} else
			if (j == 0 || j == (width - 1)) {
					field[((i * width) + j)].symbol = 186;
			} else {
				field[((i * width) + j)].symbol = 0;
			}
		}
	}
}


PlayingField::~PlayingField() {
}


int PlayingField::getHeight() {
	return height;
}


int PlayingField::getWidth() {
	return width;
}


int PlayingField::getColor() {
	return color;
}


// Pass the Symbol of the point, located in the vector mask at the index [i][j]
char PlayingField::getSymbolforIndex(int i, int j) {
	return field[i * width + j].symbol;
}


// Pass the Color of the point, located in the vector mask at the index [i][j]
char PlayingField::getColorforIndex(int i, int j) {
	return field[i * width + j].color;
}


// Pass the coordinates of the point, located in the vector mask at the index [i][j]
COORD PlayingField::getCoordforIndex(int i, int j) {
	return field[i * width + j].cord;
}


// Save Point in Field
void PlayingField::savePoint(Point pointSave) {
	field[pointSave.cord.Y * width + pointSave.cord.X] = pointSave;
}


// Check point in Field for empty
BOOL PlayingField::checkForEmpty(int  y, int x) {	
	if (x >= width || y >= height) {
		return FALSE;
	}
	int index = (y * width) + x;
	return !field[index].symbol;
}


// Check lines in field for full
int PlayingField::checkFullLines(int indexLines) {
	
	int countFullSymbols = 0;

	//find full lines
	for (int i = indexLines; i > 0; --i) {
		for (int j = (width - 2); j > 0; --j) {
			if (field[i * width + j].symbol != 0) {
				++countFullSymbols;	
			}
		}
		if(countFullSymbols == (width - 2)){
			indexLines = ++i;
			return  indexLines;
		}
		countFullSymbols = 0;
	}
	return 0;
}


// Remove full lines in field
void PlayingField::removeFullLines(int indexLines) {
	// fill line in the previous line 
	for (int i = indexLines; i > 1; --i) {
		for (int j = (width - 2); j > 0; --j) {
			if (field[(i - 1)* width + j].symbol == 0) {
				field[i * width + j].symbol = field[(i - 1)* width + j].symbol;
				field[i * width + j].color = field[(i - 1)* width + j].color;
			}
		}
	}
}


// Check field for full
BOOL PlayingField::checkFullField() {
	//Check first line field for full
	for (int j = 1; j < width - 1; ++j) {
		if (field[1 * width + j].symbol != 0) {
			return TRUE;
		}
	}
	return 0;
}


