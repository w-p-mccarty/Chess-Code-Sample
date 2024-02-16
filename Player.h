/***********************************************************************
Author: William McCarty
Player.h
 ***********************************************************************/

#ifndef Player_h
#define Player_h

#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"

class Player
{

public:

	Player(int, int);//Creates Player
	Player();//Creates Player*Default*
	virtual ~Player();//Destroys Player
	bool isInCheck();//Returns Whether Player Is In Check
	void setCheck(bool);//Modifies Player Check Status
	int getColor();//Returns Piece Color
	Piece** getPieces();//Returns All Pieces Of Player
	Piece* findPiece(int, int);//Finds A Piece In Location

private:

	int _player;
	int _color;
	Piece *_piece[16];
	bool _inCheck;

};
#endif