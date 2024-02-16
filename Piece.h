/***********************************************************************
Author: William McCarty
Piece.h
 ***********************************************************************/


#ifndef Piece_h
#define Piece_h


class Player;
class Piece
{

public:

	Piece();//Creates A New Piece
	virtual ~Piece();//Destroys A Piece
	int getX();//Gets Piece X Cord On Board
	int getY();//Gets Piece Y Cord On Board
	bool isAlive();//Returns If Piece Is Still In Play
	void kill();//Kills This Piece From Game
	void setColor(int);//Sets Piece Color
	int getColor();//Gets The Piece's Color
	void setCord(int, int);//Sets Piece's Position On Board
	bool resultCheck(Player *,Player *, int, int, int);//Checks If A Move Will Result In A Check
	void move(Player *, Player *,int &, int &);//Moves Piece
	virtual bool isChecking(Player *,Player *, int, int);//Checks If A Piece Is Checking *Polymorphic*
	virtual char getSymbol();//Gets Piece's Symbol *Polymorphic*
	virtual bool isValidMove(Player *, Player *,int &, int&);//Checks If Move Is Valid *Polymorphic*

private:

	int _x;
	int _y;
	bool _alive;
	int _color;

};
#endif