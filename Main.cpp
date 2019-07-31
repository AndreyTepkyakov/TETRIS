#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

#ifndef GameHandler
	#include "GameHandler.h"
#endif

/*
	Program TETRIS. create by Teplyakov Andrey
*/

enum PossibleKeyboardResponse {
	unknowAction,
	start,
	moveLeft,
	moveDown,
	moveRight,
	turn,
	endGame,
	quit,
};

int main () {

	SetConsoleTitle("TETRIS");
	system("mode con cols=45 lines=34");

	PossibleKeyboardResponse keyboardResponse = unknowAction;
	int action = keyboardResponse;

	int timerCounter = 0;
	
	while (action != quit) {
		char symbolResponse = 0;

		GameHandler game;
		
		if (action != endGame) {
			game.showPlayingField();
			game.showMenu();
			game.showStart();
		}
		
		do {
			symbolResponse = _getch();
			action = game.processingKeyboardResponse(symbolResponse);
		} while (action != quit  && action != start);
		
		if (action != quit) {
			game.showPlayingField();
			game.showNextFigure();
			game.showFigureOnField();
		}

		while (action != quit && action != endGame) {
			
			Sleep((970/3));
			++timerCounter;

			if (timerCounter == 3) {
				game.showIncreaseTime(); 
				timerCounter = 0;
			}

			game.showMoveDownFigure();
			
			if (_kbhit() != 0) {
				symbolResponse = _getch();
				action = game.processingKeyboardResponse(symbolResponse);

				switch (action) {
				case(moveLeft):
					game.checkTouchFigureAndField();
					game.showMoveLeftFigure();
					break;
				case(moveDown):
					game.checkTouchFigureAndField();
					game.showMoveDownFigure();
					break;
				case(moveRight):
					game.checkTouchFigureAndField();
					game.showMoveRightFigure();
					break;
				case(turn):
					game.showTurnFigure();
					break;
				}
				symbolResponse = 0;
			}
			game.checkTouchFigureAndField();
			if (game.getCheckTouchDown()) {
				game.saveFigureOnField();
				game.showRemovingFullLines();
				game.createNewFigure();
				game.showNextFigure();
				game.showFigureOnField();
				if (game.checkFullField()) {
					action = endGame;
				}
			}
		}
		game.showResult();
		game.showStart();
	}
	return 0;
}

