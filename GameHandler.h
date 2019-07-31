#pragma once
#include<iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>
#include <string>

#ifndef Figure
	#include "Figure.h"
	#include "Figure_I.h"
	#include "Figure_O.h"
	#include "Figure_S.h"
	#include "Figure_Z.h"
	#include "Figure_T.h"
	#include "Figure_J.h"
	#include "Figure_L.h"
#endif

#ifndef PlayingField
	#include "PlayingField.h"
#endif

#ifndef InformationField
#include "InformationField.h"
#endif

/* processes the playing field, the falling figures, the information field, 
and displays them on the screen*/
class GameHandler {
public:
	GameHandler();

	~GameHandler();

	//show Fields
	void showPlayingField();

	void showMenu();

	//show Messages
	void showStart();

	void showResult();

	//show time and score increasing
	void showIncreaseTime();

	void showIncreaseScore();

	//create and show Figure and Next Figure
	void createNewFigure();

	void showNextFigure();

	void showFigureOnField();

	//processingKeyboardResponse
	int processingKeyboardResponse(char symbolResponse);

	//show move figure
	void showMoveDownFigure();

	void showMoveLeftFigure();

	void showMoveRightFigure();

	void showTurnFigure();

	//processing interactions Figure and Playing Field
	std::vector<BOOL> checkTouchFigureAndField();

	BOOL getCheckTouchDown();

	BOOL checkOverlapFigureAndField();

	void saveFigureOnField();

	//processing fillingPlaying Field
	void showRemovingFullLines();

	BOOL checkFullField();

private:
	InformationField informationField;
	PlayingField playingField;
	Figure * fallingFigure;
	Figure * nextFigure;

	COORD startCoordFallingFigure;
	COORD inputCursorCoord;

	std::vector <BOOL> stateMoveDownLeftRight;
	int turnNumber;
};

