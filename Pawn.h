/***********************************************************************
Author: William McCarty
Pawn.h SubClass of Piece.h
 ***********************************************************************/

#ifndef Pawn_h
#define Pawn_h

#include "Piece.h"

class Pawn:public Piece
{

public:

	Pawn();//Creates Pawn Piece
	virtual ~Pawn();//Destroys Pawn Piece
	char getSymbol();//Gets Pawn's Symbol *Polymorphic*
	bool isChecking(Player *,Player *, int, int);//Checks If Pawn Is Checking *Polymorphic*
	bool isValidMove(Player *,Player *,int &,int &);//Checks If Move Is Valid *Polymorphic*

};
#endif