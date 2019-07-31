#include "Figure_S.h"


//fill Figure "S" data in the default constructor
Figure_S::Figure_S() {

	//set color
	color = 0x02;//green

	//fill the mask 0 degrees
	heightTurn0 = 5;
	widthTurn0 = 10;

	char maskTurn0[5][10] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',219,219,219,219,' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' }
	};

	Turn0 = std::vector<Point>(heightTurn0 * widthTurn0);

	for (int i = 0; i < heightTurn0; ++i) {
		for (int j = 0; j < widthTurn0; ++j) {
			Turn0[((i * widthTurn0) + j)].symbol = maskTurn0[i][j];
			Turn0[((i * widthTurn0) + j)].color = color;
		}
	}

	//fill the mask 180 degrees
	heightTurn180 = 5;
	widthTurn180 = 8;

	char maskTurn180[5][8] = {
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ',219,219,' ',' ',' ',' ' },
		{ ' ',' ',219,219,219,219,' ',' ' },
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

	//assign Figure a mask of 0 degrees
	height = heightTurn0;
	width = widthTurn0;
	mask = std::vector<Point>(height * width);
	mask = Turn0;
}


Figure_S::~Figure_S()
{
}
