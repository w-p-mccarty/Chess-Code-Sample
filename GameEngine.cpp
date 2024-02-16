/***********************************************************************
Author: William McCarty
GameEngine.cpp
 ***********************************************************************/

#include "Player.h"
#include "Board.h"
#include "GameEngine.h"

#define PLAYER_1 1
#define PLAYER_2 2
#define WHITE 1
#define BLACK 0
#define COL_COMMAND 0
#define ROW_COMMAND 1
#define MAX_BOARD 8
#define MIN_BOARD 0


//Creates Chess Game Manager
GameEngine::GameEngine()
{
	cout<<"     C++ Chess"<<endl;
	cout<<"------------------"<<endl;//Game Title

	Player *player1 = new Player(PLAYER_1,WHITE);
	Player *player2 = new Player(PLAYER_2,BLACK);
	Board *board = new Board(player1,player2);//Creates Game Components

	_player1=player1;
	_player2=player2;
	_board = board;//Sets Global Variables
	
}

//Destroys Chess Game Manager
GameEngine::~GameEngine()
{
	delete _board;
	delete _player1;
	delete _player2;//Destroys Game Components And Engine
}

//Gets Users Command
string GameEngine::getCommand()
{
	string command="";

	getline(cin,command);
	command = lowerCase(command);

	return command;
}

//Get The Player 1 Object
Player* GameEngine::getPlayer1()
{

	return _player1;

}

//Get The Player 2 Object
Player* GameEngine::getPlayer2()
{

	return _player2;

}

//Converts Command To Lowercase
string GameEngine::lowerCase(string & command)
{
	string lowerCom="";

	for(int i=0;i<command.length();i++){

		lowerCom += tolower(command[i]);

	}

	return lowerCom;
}

//Converts Command Cords to Calculation Cords
string GameEngine::cordConvert(string & cord)
{
	char col = cord[COL_COMMAND];
	char row = cord[ROW_COMMAND];

	switch(col){//Column

		case 'a':

			col='1';
			break;

		case 'b':

			col='2';
			break;

		case 'c':

			col='3';
			break;

		case 'd':

			col='4';
			break;

		case 'e':

			col='5';
			break;

		case 'f':

			col='6';
			break;

		case 'g':

			col='7';
			break;

		case 'h':

			col='8';
			break;

		default:

			col='*';//Random Character

	}

	switch(row){//Row

		case '1':

			row='8';
			break;

		case '2':

			row='7';
			break;

		case '3':

			row='6';
			break;

		case '4':

			row='5';
			break;

		case '5':

			row='4';
			break;

		case '6':

			row='3';
			break;

		case '7':

			row='2';
			break;

		case '8':

			row='1';
			break;

		default:
			row='*';//Random Character
	}

	cord[COL_COMMAND] = col;
	cord[ROW_COMMAND] = row;

	return cord;
}

//Reprint Chess Board
void GameEngine::updateBoard()
{

	return _board->createBoard();

}

//Change Players Turn
int GameEngine::switchPlayer(int &curPlayer)
{
	if(curPlayer==1){//Was Player 1

		return 2;

	}else{//Was Player 2

		return 1;

	}
}

//Checks If The Selected Piece Is Valid
bool GameEngine::isValidPiece(int & player,int & fromX,int & fromY)
{
	if(player==1){

		if(_player1->findPiece(fromX,fromY)!=NULL&&_player1->findPiece(fromX,fromY)->isAlive()){//Checks If Player 1 Has Piece At Location

			return true;

		}

		return false;

	}else{

		if(_player2->findPiece(fromX,fromY)!=NULL&&_player2->findPiece(fromX,fromY)->isAlive()){//Checks If Player 2 Has Piece At Location

			return true;

		}

		return false;

	}
}

//Check If Position Is In Board
bool GameEngine::validateBoardDomain(int & loc)
{
	if(loc>MIN_BOARD&&loc<=MAX_BOARD){//Checks If On Board

		return true;

	}

	return false;

}