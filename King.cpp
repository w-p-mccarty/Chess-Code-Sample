/***********************************************************************
Author: William McCarty
King.cpp SubClass of Piece.h
 ***********************************************************************/

#include "King.h"
#include "Player.h"
#include <iostream>

#define KING 'k'
#define NEG_DIF_LIMIT 0
#define NEG_CONVERT -1
#define MOVE_DIS 1
#define IS_WHITE this->getColor()==1

//Creates King
King::King(){}

//Destroys King
King::~King(){}

//Checks If King Is Checking *Polymorphic*
bool King::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{
	int xDif = this->getX()-xDes;
	int yDif = this->getY()-yDes;

	if(xDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		xDif*=NEG_CONVERT;//Converts Difference to Positive

	}

	if(yDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		yDif*=NEG_CONVERT;//Converts Difference to Positive

	}

	if(xDif<=MOVE_DIS&&yDif<=MOVE_DIS){//Checks If Move Distance

		Piece* p1Piece = player1->findPiece(xDes,yDes);
		Piece* p2Piece = player2->findPiece(xDes,yDes);

		if(IS_WHITE){//Player 1

			if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks If Player 2 Has A Piece At Location

				if(p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}
			}
		}else{//Player 2

			if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks If Player 1 Has A Piece At Location

				if(p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}
			}
		}
	}

	return false;

}

//Gets King Symbol *Polymorphic*
char King::getSymbol()
{

	return KING;

}

//Checks If Move Is Valid *Polymorphic*
bool King::isValidMove(Player *player1, Player *player2, int &x, int &y)
{
	Piece* p1Piece =player1->findPiece(x,y);
	Piece* p2Piece = player2->findPiece(x,y);

	int xDif = this->getX()-x;
	int yDif = this->getY()-y;
	int curX = this->getX();
	int curY = this->getY();

	int desX;
	int desY;

	if(xDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		xDif*=NEG_CONVERT;//Converts Difference to Positive

	}

	if(yDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		yDif*=NEG_CONVERT;//Converts Difference to Positive

	}

	if(IS_WHITE){//Player 1

		if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Doesn't Piece At Location

			if(xDif<=MOVE_DIS&&yDif<=MOVE_DIS){//Checks If Move Distance

				if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Has A Piece At Location

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

						this->setCord(curX,curY);//Reverts Piece To Original Position
						return true;

					}

					this->setCord(curX,curY);//Reverts Piece To Original Position

				}else{//Player 2 Has A Piece At Location

					if(p2Piece->getSymbol()==KING){//Checks If Piece Is A King

						return false;

					}

					desX =p2Piece->getX();
					desY =p2Piece->getY();//Save Previous Location

					p2Piece->setCord(-1,-1);
					this->setCord(x,y);//Temporary Moves Piece To Location

					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

						p2Piece->setCord(desX,desY);
						this->setCord(curX,curY);//Reverts Piece To Original Position
						return true;

					}

					p2Piece->setCord(desX,desY);
					this->setCord(curX,curY);//Reverts Piece To Original Position		

				}
			}
		}else{//Player 1 Has Piece At Location

			return false;

		}
	}else{//Player 2

		if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Doesn't Piece At Location

			if(xDif<=MOVE_DIS&&yDif<=MOVE_DIS){//Checks If Move Distance

				if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Has A Piece At Location

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

						this->setCord(curX,curY);//Reverts Piece To Original Position
						return true;

					}

					this->setCord(curX,curY);//Reverts Piece To Original Position

				}else{//Player 1 Has A Piece At Location

					if(p1Piece->getSymbol()==KING){//Checks If Piece Is A King

						return false;

					}

					desX =p1Piece->getX();
					desY =p1Piece->getY();//Save Previous Location

					p1Piece->setCord(-1,-1);
					this->setCord(x,y);//Temporary Moves Piece To Location

					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

						p1Piece->setCord(desX,desY);
						this->setCord(curX,curY);//Reverts Piece To Original Position
						return true;

					}

					p1Piece->setCord(desX,desY);
					this->setCord(curX,curY);//Reverts Piece To Original Position	

				}
			}
		}else{//Player 2 Has Piece At Location

			return false;

		}
	}

	return false;

}