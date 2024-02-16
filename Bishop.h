/***********************************************************************
Author: William McCarty
Bishop.h SubClass of Piece.h
 ***********************************************************************/

#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"


class Bishop:public Piece
{

public:

	Bishop();//Creates New Bishop
	virtual ~Bishop();//Destroys Bishop
	char getSymbol();//Gets Bishop Symbol  *Polymorphic*
	bool isChecking(Player *,Player *, int, int);//Checks If Checking *Polymorphic*
	bool isValidMove(Player *, Player *, int &, int &);//Checks If A Valid Move *Polymorphic*

};
#endif