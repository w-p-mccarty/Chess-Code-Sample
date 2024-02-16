/***********************************************************************
Author: William McCarty
Board.h
 ***********************************************************************/

#ifndef Board_h
#define Board_h

#include "Player.h"

using namespace std;

class Board
{

public:

	Board(Player *, Player *);//Creates The Board
	virtual ~Board();//Destroys The Board
	void createBoard();//Displays the Current Board

private:

	Player *_player1;
	Player *_player2;

};
#endif