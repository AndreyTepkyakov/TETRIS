#include "Figure.h"


Figure::Figure() {
}


Figure & Figure::operator=(const Figure & figure) {
	height = figure.height;
	width = figure.width;
	mask = figure.mask;
	color = figure.color;
	return *this;
}


Figure::~Figure() {
}


int Figure::getHeight() {
	return height;
}


int Figure::getWidth() {
	return width;
}


int Figure::getColor() {
	return color;
}


// Pass the coordinates of the point, located in the vector mask at the index [i][j]
COORD Figure::getCoordforIndex(int i, int j) {
	return mask[i * width + j].cord;
}


// Pass the Symbol of the point, located in the vector mask at the index [i][j]
char Figure::getSymbolforIndex(int i, int j) {	
	return mask[i * width + j].symbol;
}


// Filling the mask with coordinates, starting from the starting coordinate
void Figure::fillCoordFigure(COORD startCoord) {

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			mask[i * width + j].cord.Y = startCoord.Y + i;
			mask[i * width + j].cord.X = startCoord.X + j;
		}
	}
}


// Shift of coordinates to the right
void Figure::moveRightFigure(){

	for (int i = 0; i < mask.size(); ++i) {
		mask[i].cord.X += 2;
	}

}


// Shift of coordinates to the left
void Figure::moveLeftFigure() {

	for (int i = 0; i < mask.size(); ++i) {
		mask[i].cord.X -= 2;
	}

}


// Shift of coordinates down
void Figure::moveDownFigure() {

	for (int i = 0; i < mask.size(); ++i) {
		mask[i].cord.Y += 1;
	}
	
}


//// Virtual method to turning figure, implementation for figures without turning
void Figure::turnFigure(int numberTurns){
	return;
}

