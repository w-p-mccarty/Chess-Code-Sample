/***********************************************************************
Author: William McCarty
GameEngine.h
 ***********************************************************************/

#ifndef GameEngine_h
#define GameEngine_h

#include <iostream>
#include <sstream>
#include "Player.h"


using namespace std;

class Board;


class GameEngine
{

public:

	GameEngine();//Creates Chess Game Manager
	virtual ~GameEngine();//Destroys Chess Game Manager
	string getCommand();//Gets Users Command
	Player* getPlayer1();//Get The Player 1 Object
	Player* getPlayer2();//Get The Player 2 Object
	string lowerCase(string &);//Converts Command To Lowercase
	string cordConvert(string &);//Converts Command Cords to Calculation Cords
	void updateBoard();//Reprint Chess Board
	int switchPlayer(int &);//Change Players Turn
	bool isValidPiece(int &,int &,int &);//Checks If The Selected Piece Is Valid
	bool validateBoardDomain(int &);//Check If Position Is In Board

protected:

	Player* _player1;
	Player* _player2;
	Board* _board;

};
#endif