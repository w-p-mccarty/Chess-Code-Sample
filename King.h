/***********************************************************************
Author: William McCarty
King.h SubClass of Piece.h
 ***********************************************************************/

#ifndef King_h
#define King_h

#include "Piece.h"

class King:public Piece
{
public:

	King();//Creates King
	virtual ~King();//Destroys King
	bool isChecking(Player *,Player *, int, int);//Checks If King Is Checking *Polymorphic*
	char getSymbol();//Gets King Symbol *Polymorphic*
	bool isValidMove(Player *,Player *,int &,int &);//Checks If Move Is Valid *Polymorphic*

};
#endif