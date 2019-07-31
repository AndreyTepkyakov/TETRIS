#include "GameHandler.h"


/*Stores the Figure GameHandler data*/

GameHandler::GameHandler() {
	
	//create Playing Field
	playingField = PlayingField();

	//create Information Field
	COORD startCoordField = playingField.getCoordforIndex(0,0);
	COORD endCOORDField;
	endCOORDField.X = playingField.getWidth();
	endCOORDField.Y = playingField.getHeight();

	informationField = InformationField(startCoordField, endCOORDField);

	//set start coordinate Falling Figure
	startCoordFallingFigure.X = 7;
	startCoordFallingFigure.Y = 0;

	//set coordinate inputCursor
	inputCursorCoord.X = 0;
	inputCursorCoord.Y = 32;

	//creating falling Figure and next Figure 
	fallingFigure = new Figure_O;
	nextFigure = new Figure_O;
	fallingFigure->fillCoordFigure(startCoordFallingFigure);
	nextFigure->fillCoordFigure(informationField.getNextFigureCoord());
	createNewFigure();

	//creating counters of moviment and turns figure
	stateMoveDownLeftRight.assign(3, TRUE);
	turnNumber = 0;
}


GameHandler::~GameHandler() {
	delete fallingFigure;
}


//show Fields

void GameHandler::showPlayingField() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, playingField.getColor());

	for (int i = 0; i < playingField.getHeight(); ++i) {
		SetConsoleCursorPosition(hout, playingField.getCoordforIndex(i, 0));
		for (int j = 0; j < playingField.getWidth(); ++j) {
			
			if (playingField.getSymbolforIndex(i, j) == 0) {
				std::cout << ' ';
			}
			else {
				std::cout << playingField.getSymbolforIndex(i, j);
			}
		}
	}
	SetConsoleCursorPosition(hout, inputCursorCoord);
}


void GameHandler::showMenu() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hout, informationField.getColorResult());
	std::cout.fill('0');

	SetConsoleCursorPosition(hout, informationField.getTimeCoord());
	std::cout << std::setw(2) << informationField.getTimeMin() << ':' << std::setw(2) << informationField.getTimeMin();

	SetConsoleCursorPosition(hout, informationField.getScoreCoord());
	std::cout << std::setw(4) << informationField.getScore();

	SetConsoleTextAttribute(hout, informationField.getColorInformation());

	SetConsoleCursorPosition(hout, informationField.getScoreTitleCoord());
	std::cout << informationField.getScoreTitle();

	SetConsoleCursorPosition(hout, informationField.getTimeTitleCoord());
	std::cout << informationField.getTimeTitle();

	SetConsoleCursorPosition(hout, informationField.getNextFigureTitleCoord());
	std::cout << informationField.getNextFigureTitle();

	SetConsoleOutputCP(1251);
	SetConsoleCursorPosition(hout, informationField.getInstructionCoord());
	std::cout << informationField.getInstructionTitle();
	SetConsoleOutputCP(866);

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


//show Messages

void GameHandler::showStart() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, informationField.getColorResult());

	SetConsoleCursorPosition(hout, informationField.getStartTitleCoord());
	std::cout << informationField.getStartTitle();

	SetConsoleCursorPosition(hout, informationField.getStartTitlePressCoord());
	std::cout << informationField.getStartTitlePress();

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


void GameHandler::showResult() {
	COORD coordScore;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, informationField.getColorResult());
	std::cout.fill('0');

	SetConsoleCursorPosition(hout, informationField.getEndTitleCoord());
	std::cout << informationField.getEndTitle();

	coordScore = informationField.getEndTitleCoord();
	coordScore.Y += 1;

	SetConsoleCursorPosition(hout, coordScore);
	std::cout << " Score  " << std::setw(4) << informationField.getScore() <<' ';

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


//show time and score increasing

void GameHandler::showIncreaseTime() {
	
	informationField.increaseTime();

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, informationField.getColorResult());
	std::cout.fill('0');

	SetConsoleCursorPosition(hout, informationField.getTimeCoord());
	std::cout << std::setw(2) << informationField.getTimeMin() << ':' << std::setw(2) << informationField.getTimeSec();

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


void GameHandler::showIncreaseScore() {
	
	informationField.increaseScore();
	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, informationField.getColorResult());
	std::cout.fill('0');
	
	SetConsoleCursorPosition(hout, informationField.getScoreCoord());
	std::cout << std::setw(4) << informationField.getScore();

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


//create and show falling Figure and Next Figure

void GameHandler::createNewFigure() {
	
	//fill in falling Figure - Next Figure
	fallingFigure = nextFigure;
	fallingFigure->fillCoordFigure(startCoordFallingFigure);
	
	//Next Figure =  random Figure
	srand(time(0));
	unsigned randomNumberFigure = rand() % 7 + 1;
	switch (randomNumberFigure){
	case 1:
		nextFigure = new Figure_I;
		break;
	case 2:
		nextFigure = new Figure_O;
		break;
	case 3:
		nextFigure = new Figure_S;
		break;
	case 4:
		nextFigure = new Figure_Z;
		break;
	case 5:
		nextFigure = new Figure_T;
		break;
	case 6:
		nextFigure = new Figure_J;
		break;
	case 7:
		nextFigure = new Figure_L;
		break;
	}

	//fill coordinats
	nextFigure->fillCoordFigure(informationField.getNextFigureCoord());

	stateMoveDownLeftRight.clear();
	stateMoveDownLeftRight.assign(3, TRUE);
	turnNumber = 0;
}


void GameHandler::showNextFigure() {
	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, nextFigure->getColor());

	for (int i = 0; i < nextFigure->getHeight(); ++i) {
		SetConsoleCursorPosition(hout, nextFigure->getCoordforIndex(i, 0));
		for (int j = 0; j < nextFigure->getWidth(); ++j) {
			if (nextFigure->getSymbolforIndex(i, j)) {
				std::cout << nextFigure->getSymbolforIndex(i, j);
			}
		}
	}

	SetConsoleCursorPosition(hout, inputCursorCoord);
}


void GameHandler::showFigureOnField() {

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, fallingFigure->getColor());
	
	COORD coordSymbol;

	//iterating over points in the figure
	for (int i = 0; i < fallingFigure->getHeight(); ++i) {
		SetConsoleCursorPosition(hout, fallingFigure->getCoordforIndex(i, 0));
		for (int j = 0; j < fallingFigure->getWidth(); ++j) {
			
			//set coordinate of point
			coordSymbol = fallingFigure->getCoordforIndex(i, j);

			//if point field not full, show point
			if (playingField.checkForEmpty(coordSymbol.Y, coordSymbol.X)) {
				std::cout << fallingFigure->getSymbolforIndex(i, j);
			}
			else {
				if ((j + 1) != fallingFigure->getWidth()) {
					SetConsoleCursorPosition(hout, fallingFigure->getCoordforIndex(i, j + 1));
				}
			}
			
		}
	}
	SetConsoleCursorPosition(hout, inputCursorCoord);
}


//processingKeyboardResponse

int GameHandler::processingKeyboardResponse(char symbolResponse) {	
	if (symbolResponse == informationField.getSymbolStartGame()) {
		return 1;
	}
	if (symbolResponse == informationField.getSymbolMoveLeft()) {
		return 2;
	}
	if (symbolResponse == informationField.getSymbolMoveDown()) {
		return 3;
	}
	if (symbolResponse == informationField.getSymbolMoveRight()) {
		return 4;
	}
	if (symbolResponse == informationField.getSymbolTurn()) {
		return 5;
	}
	if (symbolResponse == informationField.getSymbolEndGame()) {
		return 6;
	}
	if (symbolResponse == informationField.getSymbolQuit()) {
		return 7;
	}
	return 0;
}


//show move figure

void GameHandler::showMoveDownFigure() {
	if (!stateMoveDownLeftRight[0]) {
		return;
	}
	fallingFigure->moveDownFigure();
	showFigureOnField();

}


void GameHandler::showMoveLeftFigure() {
	if (!stateMoveDownLeftRight[1]) {
		return;
	}
	fallingFigure->moveLeftFigure();
	showFigureOnField();
}


void GameHandler::showMoveRightFigure() {
	if (!stateMoveDownLeftRight[2]) {
		return;
	}
	fallingFigure->moveRightFigure();
	showFigureOnField();
}


void GameHandler::showTurnFigure() {
	++turnNumber;
	fallingFigure->turnFigure(turnNumber);
	if (checkOverlapFigureAndField()) {
		--turnNumber;
		fallingFigure->turnFigure(turnNumber);
		return;
	}
	showFigureOnField();
}


//processing interactions Figure and Playing Field

std::vector<BOOL> GameHandler::checkTouchFigureAndField() {
	COORD coordSymbol;

	stateMoveDownLeftRight.assign(3, TRUE);
	for (int i = 0; i < fallingFigure->getHeight(); ++i) {
		for (int j = 0; j < fallingFigure->getWidth(); ++j) {
			
			if ((fallingFigure->getSymbolforIndex(i, j)) != ' ') {
				coordSymbol = fallingFigure->getCoordforIndex(i, j);
				
				if (stateMoveDownLeftRight[0]) {
					stateMoveDownLeftRight[0] = playingField.checkForEmpty(coordSymbol.Y + 1, coordSymbol.X);
				}
				if (stateMoveDownLeftRight[1]) {
					stateMoveDownLeftRight[1] = playingField.checkForEmpty(coordSymbol.Y, coordSymbol.X - 2);
				}
				if (stateMoveDownLeftRight[2]) {
					stateMoveDownLeftRight[2] = playingField.checkForEmpty(coordSymbol.Y, coordSymbol.X + 2);
				}
			}
		}
	}
	return stateMoveDownLeftRight;
}


BOOL GameHandler::getCheckTouchDown()
{
	return !stateMoveDownLeftRight[0];
}


BOOL GameHandler::checkOverlapFigureAndField() {
	
	BOOL overlap = FALSE;
	COORD coordSymbol;

	for (int i = 0; i < fallingFigure->getHeight(); ++i) {
		for (int j = 0; j < fallingFigure->getWidth(); ++j) {

			if (fallingFigure->getSymbolforIndex(i, j) != ' ') {
				coordSymbol = fallingFigure->getCoordforIndex(i, j);

				overlap = (!(playingField.checkForEmpty(coordSymbol.Y, coordSymbol.X)));
				if (overlap) {
					return overlap;
				}
			}
		}
	}
	return overlap;
}


void GameHandler::saveFigureOnField() {

	Point pointSave;

	for (int i = 0; i < fallingFigure->getHeight(); ++i) {
		for (int j = 0; j < fallingFigure->getWidth(); ++j) {
			
			if (fallingFigure->getSymbolforIndex(i, j) != ' ') {

				pointSave.cord = fallingFigure->getCoordforIndex(i, j);
				pointSave.symbol = fallingFigure->getSymbolforIndex(i, j);
				pointSave.color = fallingFigure->getColor();
				playingField.savePoint(pointSave);
			}
		}
	}
}


//processing filling Playing Field

void GameHandler::showRemovingFullLines() {

	int indexLine = (playingField.getHeight() - 2);

	indexLine = playingField.checkFullLines(indexLine);

	if(!indexLine){
		return;
	}

	int indexFound;
	do {
		indexFound = indexLine;
		showIncreaseScore();
		playingField.removeFullLines(indexLine);
		indexLine = playingField.checkFullLines(--indexLine);
	} while (indexLine != 0);

	indexLine = indexFound;
	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 1; i < indexLine; ++i) {
		for (int j = 1; j < playingField.getWidth(); ++j) {
			
			SetConsoleCursorPosition(hout, playingField.getCoordforIndex(i, j));

			if (playingField.checkForEmpty(i, j)) {
				std::cout << ' ';
			}
			else {
				SetConsoleTextAttribute(hout, playingField.getColorforIndex(i, j));
				std::cout << playingField.getSymbolforIndex(i, j);
			}
		}
	}
	SetConsoleCursorPosition(hout, inputCursorCoord);
}


BOOL GameHandler::checkFullField() {
	if (!playingField.checkFullField()) {
		return checkOverlapFigureAndField();
	}
	return playingField.checkFullField();
}

