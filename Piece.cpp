/***********************************************************************
Author: William McCarty
Piece.cpp
 ***********************************************************************/

#include "Piece.h"
#include "Player.h"
#include <iostream>

#define DEAD_X -1
#define DEAD_Y -1
#define MAX_PIECES 16
#define IS_WHITE this->getColor()==1

//Creates A New Piece
Piece::Piece()
{
	_alive=true;

}

//Destroys A Piece
Piece::~Piece(){}

//Gets Piece's X Cord On Board
int Piece::getX()
{

	return _x;

}

//Gets Piece's Y Cord On Board
int Piece::getY()
{

	return _y;

}

//Returns If Piece Is Still In Play
bool Piece::isAlive()
{

	return _alive;

}

//Kills This Piece From Game
void Piece::kill()
{

	setCord(DEAD_X,DEAD_Y);
	_alive=false;

}

//Sets Piece's Color
void Piece::setColor(int color)
{

	_color=color;

}

//Gets The Piece's Color
int Piece::getColor()
{

	return _color;

}

//Sets Piece's Position On Board
void Piece::setCord(int x, int y)
{

	_x = x;
	_y = y;

}

//Checks If A Move Will Result In A Check
bool Piece::resultCheck(Player * player1,Player * player2, int player, int xDes, int yDes)
{

	if(player1->getColor()==player){

		for(int i=0;i<MAX_PIECES;i++){

			if(player2->getPieces()[i]->isChecking(player1,player2,xDes,yDes)){

				return true;

			}	
		}
	}else{

		for(int i=0;i<MAX_PIECES;i++){

			if(player1->getPieces()[i]->isChecking(player1,player2,xDes,yDes)){

				return true;

			}
		}
	}

	return false;

}

//Moves Piece
void Piece::move(Player * player1, Player * player2,int &x, int&y)
{

	int curX = this->getX();
	int curY = this->getY();

	if(IS_WHITE){

		if(player2->findPiece(x,y)!=NULL){

			player2->findPiece(x,y)->kill();

		}
	}else{

		if(player1->findPiece(x,y)!=NULL){

			player1->findPiece(x,y)->kill();

		}
	}

	this->setCord(x,y);

	if(isChecking(player1,player2,x,y)){

		if(IS_WHITE){

			std::cout<<"Player 2 In Check\n";
			player2->setCheck(true);

		}
		else{

			std::cout<<"Player 1 In Check\n";
			player1->setCheck(true);

		}
	}
}

//Checks If A Piece Is Checking*Polymorphic*
bool Piece::isChecking(Player * player1,Player * player2, int xDes, int yDes)
{

	return false;

}

//Gets Piece's Symbol *Polymorphic*
char Piece::getSymbol()
{

	return '0';

}

//Checks If Move Is Valid *Polymorphic*
bool Piece::isValidMove(Player * player1, Player * player2,int &x, int&y)
{

	return false;

}