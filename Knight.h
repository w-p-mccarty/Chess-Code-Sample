/***********************************************************************
Author: William McCarty
Knight.h SubClass of Piece.h
 ***********************************************************************/

#ifndef Knight_h
#define Knight_h

#include "Piece.h"

class Knight:public Piece
{

public:

	Knight();//Creates New Knight
	virtual ~Knight();//Destroys Knight
	bool isChecking(Player *,Player *, int, int);//Checks If Checking *Polymorphic*
	char getSymbol();//Gets Queen Symbol  *Polymorphic*
	bool isValidMove(Player *,Player *,int &,int &);//Checks If A Valid Move *Polymorphic*

};
#endif