#include "InformationField.h"


InformationField::InformationField()
{
}


//fill Information Field data in the constructor with parameters startCoordField and endCoordField
InformationField::InformationField(COORD startCoordField, COORD endCoordField) {

	// Control characters
	symbolQuit = 'q';
	symbolEndGame = 'e';
	symbolStartGame = 'r';
	symbolMoveDown = 's';
	symbolMoveLeft = 'a';
	symbolMoveRight = 'd';
	symbolTurn = 'w';

	// Color
	colorInformation = 0x0F;
	colorResult = 0x0b;

	// Starting message,
	startTitle = " _S_T_A_R_T_ ";
	startTitleCoord.X = startCoordField.X + 4;
	startTitleCoord.Y = startCoordField.Y + 7;

	startTitlePress = "   press ";
	startTitlePress += symbolStartGame;
	startTitlePress += "   ";
	startTitlePressCoord.X = startTitleCoord.X;
	startTitlePressCoord.Y = startTitleCoord.Y + 1;

	// Closing message,
	endTitle = " _GAME_OVER_ ";
	endTitleCoord.X = startTitleCoord.X;
	endTitleCoord.Y = startTitleCoord.Y + 5;
	
	// Time
	timeTitle = "Time: ";
	timeTitleCoord.X = endCoordField.X + 5;
	timeTitleCoord.Y = startCoordField.Y + 2;
	time[0] = 0;
	time[1] = 0;
	timeCoord.X = timeTitleCoord.X + timeTitle.length();
	timeCoord.Y = timeTitleCoord.Y;

	// Score
	scoreTitle = "Score: ";
	scoreTitleCoord.X = timeTitleCoord.X;
	scoreTitleCoord.Y = timeTitleCoord.Y + 3;
	score = 0;
	scoreCoord.X = scoreTitleCoord.X + scoreTitle.length();
	scoreCoord.Y = scoreTitleCoord.Y;
	
	// Next Figure coordinates
	nextFigureTitle = "Next Figure:";
	nextFigureTitleCoord.X = timeTitleCoord.X;
	nextFigureTitleCoord.Y = scoreTitleCoord.Y + 3;

	nextFigureCoord.X = timeTitleCoord.X + 2;
	nextFigureCoord.Y = nextFigureTitleCoord.Y + 2;

	// Usage instructions
	instructionTitle = "Press - ";
	instructionTitle += symbolStartGame; 
	instructionTitle += " to START game.\n";
	
	instructionTitle += "Press - ";
	instructionTitle += symbolMoveLeft;
	instructionTitle += " to move the figure to the LEFT.\n";

	instructionTitle += "Press - ";
	instructionTitle += symbolMoveDown;
	instructionTitle += " to move the figure DOWN.\n";

	instructionTitle += "Press - ";
	instructionTitle += symbolMoveRight;
	instructionTitle += " to move the figure to the RIGHT.\n";

	instructionTitle += "Press - ";
	instructionTitle += symbolTurn;
	instructionTitle += " to TURN the figure.\n";

	instructionTitle += "Press - ";
	instructionTitle += symbolEndGame;
	instructionTitle += " to END game.\n";

	instructionTitle += "Press - ";
	instructionTitle += symbolQuit;
	instructionTitle += " to QUIT game.\n\n\t";
	instructionTitle += ((char)169);
	instructionTitle += " Tepkyakov Andrey 2019.\n";

	instructionCoord.X = startCoordField.X;
	instructionCoord.Y = endCoordField.Y + 1;
}


InformationField::~InformationField() {
}


std::string InformationField::getStartTitle() {
	return startTitle;
}


COORD InformationField::getStartTitleCoord() {
	return startTitleCoord;
}


std::string InformationField::getStartTitlePress() {
	return startTitlePress;
}


COORD InformationField::getStartTitlePressCoord() {
	return startTitlePressCoord;
}


std::string InformationField::getEndTitle() {
	return endTitle;
}


COORD InformationField::getEndTitleCoord() {
	return endTitleCoord;
}


COORD InformationField::getTimeCoord() {
	return timeCoord;
}


std::string InformationField::getTimeTitle() {
	return timeTitle;
}


int InformationField::getTimeMin() {
	return time[0];
}


int InformationField::getTimeSec() {
	return time[1];
}


COORD InformationField::getTimeTitleCoord(){
	return timeTitleCoord;
}


COORD InformationField::getScoreCoord() {
	return scoreCoord;
}


std::string InformationField::getScoreTitle() {
	return scoreTitle;
}


int InformationField::getScore() {
	return score;
}


COORD InformationField::getScoreTitleCoord() {
	return scoreTitleCoord;
}


std::string InformationField::getNextFigureTitle() {
	return nextFigureTitle;
}


COORD InformationField::getNextFigureTitleCoord() {
	return nextFigureTitleCoord;
}


COORD InformationField::getNextFigureCoord() {
	return nextFigureCoord;
}


int InformationField::getColorInformation() {
	return colorInformation;
}


int InformationField::getColorResult() {
	return colorResult;
}


char InformationField::getSymbolStartGame() {
	return symbolStartGame;
}


char InformationField::getSymbolMoveLeft() {
	return symbolMoveLeft;
}


char InformationField::getSymbolMoveDown() {
	return symbolMoveDown;
}


char InformationField::getSymbolMoveRight() {
	return symbolMoveRight;
}


char InformationField::getSymbolTurn() {
	return symbolTurn;
}


char InformationField::getSymbolEndGame() {
	return symbolEndGame;
}


char InformationField::getSymbolQuit() {
	return symbolQuit;
}


std::string InformationField::getInstructionTitle() {
	return instructionTitle;
}


COORD InformationField::getInstructionCoord() {
	return instructionCoord;
}


// processing increase Time
void InformationField::increaseTime() {
	if (time[1] < 60) {
		++time[1];
	}
	else
	if (time[1] == 60 && time[0] < 60) {
		time[1] = 0;
		++time[0];
	}
}


// processing increase Score
void InformationField::increaseScore() {
	score += 10;
}


