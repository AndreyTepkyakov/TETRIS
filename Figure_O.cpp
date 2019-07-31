#include "Figure_O.h"


//fill Figure "O" data in the default constructor
Figure_O::Figure_O(){

	//set color
	color = 0x0E; //yellow

	//fill the mask
	height = 5;
	width = 8;

	char maskFigure[5][8] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
	};

	mask = std::vector<Point>(height * width);

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			mask[((i * width) + j)].symbol = maskFigure[i][j];
			mask[((i * width) + j)].color = color;
		}
	}
}

Figure_O::~Figure_O() {
}

