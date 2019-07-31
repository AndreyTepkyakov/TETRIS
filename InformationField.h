#pragma once
#include <iostream>
#include <Windows.h>


/* The class "InformationField" contains such informetion - control characters, usage instructions, 
starting and closing message, time, score, Next Figure coordinates, and copyright*/
class InformationField
{
public:
	InformationField();
	InformationField(COORD startCoordField, COORD endCoordField);
	~InformationField();

	std::string getStartTitle();
	COORD getStartTitleCoord();

	std::string getStartTitlePress();
	COORD getStartTitlePressCoord();

	std::string getEndTitle();
	COORD getEndTitleCoord();

	COORD getTimeCoord();
	std::string getTimeTitle();
	int getTimeMin();
	int getTimeSec();
	COORD getTimeTitleCoord();

	COORD getScoreCoord();
	std::string getScoreTitle();
	int getScore();
	COORD getScoreTitleCoord();

	std::string getNextFigureTitle();
	COORD getNextFigureTitleCoord();
	COORD getNextFigureCoord();

	int getColorInformation();
	int getColorResult();

	char getSymbolStartGame();
	char getSymbolMoveLeft();
	char getSymbolMoveDown();
	char getSymbolMoveRight();
	char getSymbolTurn();
	char getSymbolEndGame();
	char getSymbolQuit();

	std::string getInstructionTitle();
	COORD getInstructionCoord();

	// processing increase Time
	void increaseTime();
	
	// processing increase Score
	void increaseScore();
	
private:

	char symbolQuit;
	char symbolEndGame;
	char symbolStartGame;
	char symbolMoveDown;
	char symbolMoveLeft;
	char symbolMoveRight;
	char symbolTurn;

	int colorInformation;
	int colorResult;

	std::string startTitle;
	COORD startTitleCoord;

	std::string startTitlePress;
	COORD startTitlePressCoord;

	std::string endTitle;
	COORD endTitleCoord;
	
	std::string timeTitle;
	COORD timeTitleCoord;
	int time[2];
	COORD timeCoord;

	std::string scoreTitle;
	COORD scoreTitleCoord;
	int score;
	COORD scoreCoord;

	std::string nextFigureTitle;
	COORD nextFigureTitleCoord;
	COORD nextFigureCoord;
	
	std::string instructionTitle;
	COORD instructionCoord;
};

