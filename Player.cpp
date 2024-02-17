/***********************************************************************
Author: William McCarty
Player.cpp
 ***********************************************************************/

#include "Player.h"
#include <iostream>

#define MAX_PIECES 16

//Creates Player
Player::Player(int playerNum, int color)
{
	_color=color;
	_player=playerNum;
	_inCheck=false;

	Piece *pawn1 = new Pawn();
	Piece *pawn2 = new Pawn();
	Piece *pawn3 = new Pawn();
	Piece *pawn4 = new Pawn();
	Piece *pawn5 = new Pawn();
	Piece *pawn6 = new Pawn();
	Piece *pawn7 = new Pawn();
	Piece *pawn8 = new Pawn();
	Piece *lKnight = new Knight();
	Piece *rKnight = new Knight();
	Piece *lBishop = new Bishop();
	Piece *rBishop = new Bishop();
	Piece *rRook = new Rook();
	Piece *lRook = new Rook();
	Piece *queen = new Queen();
	Piece *king = new King();

	_piece[0]=pawn1;
	_piece[1]=pawn2;
	_piece[2]=pawn3;
	_piece[3]=pawn4;
	_piece[4]=pawn5;
	_piece[5]=pawn6;
	_piece[6]=pawn7;
	_piece[7]=pawn8;
	_piece[8]=lRook;
	_piece[9]=rRook;
	_piece[10]=lKnight;
	_piece[11]=rKnight;
	_piece[12]=lBishop;
	_piece[13]=rBishop;
	_piece[14]=queen;
	_piece[15]=king;

	pawn1->setColor(color);
	pawn2->setColor(color);
	pawn3->setColor(color);
	pawn4->setColor(color);
	pawn5->setColor(color);
	pawn6->setColor(color);
	pawn7->setColor(color);
	pawn8->setColor(color);
	lRook->setColor(color);
	rRook->setColor(color);
	lKnight->setColor(color);
	rKnight->setColor(color);
	lBishop->setColor(color);
	rBishop->setColor(color);
	queen->setColor(color);
	king->setColor(color);

	if(color==1){//Player 1 Setup

		pawn1->setCord(1, 7);
		pawn2->setCord(2, 7);
		pawn3->setCord(3, 7);
		pawn4->setCord(4, 7);
		pawn5->setCord(5, 7);
		pawn6->setCord(6, 7);
		pawn7->setCord(7, 7);
		pawn8->setCord(8, 7);
		lRook->setCord(1, 8);
		rRook->setCord(8, 8);
		lKnight->setCord(2, 8);
		rKnight->setCord(7, 8);
		lBishop->setCord(3, 8);
		rBishop->setCord(6, 8);
		queen->setCord(4, 8);
		king->setCord(5, 8);

	}else{//Player 2 Setup

		pawn1->setCord(1, 2);
		pawn2->setCord(2, 2);
		pawn3->setCord(3, 2);
		pawn4->setCord(4, 2);
		pawn5->setCord(5, 2);
		pawn6->setCord(6, 2);
		pawn7->setCord(7, 2);
		pawn8->setCord(8, 2);
		lRook->setCord(1, 1);
		rRook->setCord(8, 1);
		lKnight->setCord(2, 1);
		rKnight->setCord(7, 1);
		lBishop->setCord(3, 1);
		rBishop->setCord(6, 1);
		queen->setCord(4, 1);
		king->setCord(5, 1);

	}
}

//Destroys Player
Player::~Player()
{
	for(int i=0;i<MAX_PIECES;i++){

		delete _piece[i];//Remove Allocated Pieces

	}
}

//Returns Whether Player Is In Check
bool Player::isInCheck()
{

	return _inCheck;
}

//Modifies Player Check Status
void Player::setCheck(bool check)
{

	_inCheck=check;

}

//Returns Piece Color
int Player::getColor()
{

	return this->_color;

}

//Returns All Pieces Of Player
Piece** Player::getPieces()
{

	return _piece;

}

//Finds A Piece In Location
Piece* Player::findPiece(int x, int y)
{
	for(int i=0;i<MAX_PIECES;i++){

		if(_piece[i]->getX()==x){

			if(_piece[i]->getY()==y){

				return _piece[i];//Piece Was Found

			}
		} 
	}

	return NULL;//Piece Not Found
}
