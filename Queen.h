/***********************************************************************
Author: William McCarty
Queen.h SubClass of Piece.h
 ***********************************************************************/

#ifndef Queen_h
#define Queen_h

#include "Piece.h"

class Queen:public Piece
{

public:

	Queen();//Creates New Queen
	virtual ~Queen();//Destroys Queen
	bool isChecking(Player *,Player *, int, int);//Checks If Checking *Polymorphic*
	char getSymbol();//Gets Queen Symbol  *Polymorphic*
	bool isValidMove(Player *,Player *,int &,int &);//Checks If A Valid Move *Polymorphic*

};
#endif