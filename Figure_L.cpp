#include "Figure_L.h"


//fill Figure "L" data in the default constructor
Figure_L::Figure_L() {

	//set color
	color = 0x06;//orange 

	//fill the mask 0 degrees
	heightTurn0 = 5;
	widthTurn0 = 8;

	char maskTurn0[5][8] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',219,219,' ',' ',' ',' ' },
		{ ' ',' ',219,219,' ',' ',' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ' }
		
	};

	Turn0 = std::vector<Point>(heightTurn0 * widthTurn0);

	for (int i = 0; i < heightTurn0; ++i) {
		for (int j = 0; j < widthTurn0; ++j) {
			Turn0[((i * widthTurn0) + j)].symbol = maskTurn0[i][j];
			Turn0[((i * widthTurn0) + j)].color = color;
		}
	}

	//fill the mask 90 degrees
	heightTurn90 = 5;
	widthTurn90 = 10;

	char maskTurn90[5][10] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',219,219,219,219,219,219,' ',' ' },
		{ ' ',' ',219,219,' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' }
	};

	Turn90 = std::vector<Point>(heightTurn90 * widthTurn90);

	for (int i = 0; i < heightTurn90; ++i) {
		for (int j = 0; j < widthTurn90; ++j) {
			Turn90[i * widthTurn90 + j].symbol = maskTurn90[i][j];
			Turn90[i * widthTurn90 + j].color = color;
		}
	}

	//fill the mask 180 degrees
	heightTurn180 = 5;
	widthTurn180 = 8;

	char maskTurn180[5][8] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ' },
		{ ' ',' ',' ',' ',219,219,' ',' ' },
		{ ' ',' ',' ',' ',219,219,' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ' }
	};

	Turn180 = std::vector<Point>(heightTurn180 * widthTurn180);

	for (int i = 0; i < heightTurn180; ++i) {
		for (int j = 0; j < widthTurn180; ++j) {
			Turn180[(i * widthTurn180 + j)].symbol = maskTurn180[i][j];
			Turn180[(i * widthTurn180 + j)].color = color;
		}
	}

	//fill the mask 270 degrees
	heightTurn270 = 5;
	widthTurn270 = 10;

	char maskTurn270[5][10] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',219,219,' ',' ' },
		{ ' ',' ',219,219,219,219,219,219,' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' }
	};

	Turn270 = std::vector<Point>(heightTurn270 * widthTurn270);

	for (int i = 0; i < heightTurn270; ++i) {
		for (int j = 0; j < widthTurn270; ++j) {
			Turn270[(i * widthTurn270 + j)].symbol = maskTurn270[i][j];
			Turn270[(i * widthTurn270 + j)].color = color;
		}
	}

	//assign Figure a mask of 0 degrees
	height = heightTurn0;
	width = widthTurn0;
	mask = std::vector<Point>(height * width);
	mask = Turn0;
}


Figure_L::~Figure_L()
{
}
