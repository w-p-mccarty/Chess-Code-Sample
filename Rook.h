/***********************************************************************
Author: William McCarty
Rook.h SubClass of Piece.h
 ***********************************************************************/

#ifndef Rook_h
#define Rook_h

#include "Piece.h"

class Rook:public Piece
{

public:

	Rook();//Creates A New Rook
	virtual ~Rook();//Destroys Rook
	char getSymbol();//Gets Rook Symbol *Polymorphic*
	bool isChecking(Player *,Player *, int, int);//Checks If Rook Is Checking *Polymorphic*
	bool isValidMove(Player *,Player *,int &,int &);//Checks If Move Is Valid *Polymorphic*

};
#endif