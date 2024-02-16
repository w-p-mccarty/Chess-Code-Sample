/***********************************************************************
Author: William McCarty
Knight.cpp SubClass of Piece.h
 ***********************************************************************/

#include "Knight.h"
#include "Player.h"
#include <iostream>

#define IS_WHITE this->getColor()==1
#define MAX_BOARD 8
#define MIN_BOARD 1
#define KING 'k'
#define KNIGHT 'h'
#define NEG_CONVERT -1
#define NEG_DIF_LIMIT 0
#define INIT_MOVE 2
#define TURN_MOVE 1
#define DEAD_X -1
#define DEAD_Y -1

//Creates New Knight
Knight::Knight(){}

//Destroys Knight
Knight::~Knight(){}

//Checks If Checking *Polymorphic*
bool Knight::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{
	int x = this->getX();
	int y = this->getY();

	Piece* p1Piece;
	Piece* p2Piece;

	int posX=x;
	int negX=x;
	int posY=y;
	int negY=y;

	posX+=2;
	posY++;
	negY--;
	negX-=2;

	if(IS_WHITE){//Player 1

		if(posX<=MAX_BOARD){//Checks If 2 Spaces To Right Is On Board

			if(posY<=MAX_BOARD){//Checks If 1 Space To Down Is On Board

				p2Piece = player2->findPiece(posX,posY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negY>=MIN_BOARD){//Checks If 1 Space To Up Is On Board

				p2Piece = player2->findPiece(posX,negY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		if(negX>=MIN_BOARD){//Checks If 2 Spaces To Left Is On Board

			if(posY<=MAX_BOARD){//Checks If 1 Space To Down Is On Board

				p2Piece = player2->findPiece(negX,posY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negY>=MIN_BOARD){//Checks If 1 Space To Up Is On Board

				p2Piece = player2->findPiece(negX,negY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		posX=x+1;
		posY=y+2;
		negY=y-2;
		negX=x-1;

		if(posY<=MAX_BOARD){//Checks If 2 Spaces To Down Is On Board

			if(posX<=MAX_BOARD){//Checks If 1 Space To Right Is On Board

				p2Piece = player2->findPiece(posX,posY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negX>=MIN_BOARD){//Checks If 1 Space To Left Is On Board

				p2Piece = player2->findPiece(negX,posY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		if(negY>=MIN_BOARD){//Checks If 2 Spaces To Up Is On Board

			if(posX<=MAX_BOARD){//Checks If 1 Space To Right Is On Board

				p2Piece = player2->findPiece(posX,negY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negX>=MIN_BOARD){//Checks If 1 Space To Left Is On Board

				p2Piece = player2->findPiece(negX,negY);

				if(p2Piece!=NULL){//Player 2 Has Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}
	}else{//Player 2

		if(posX<=MAX_BOARD){//Checks If 2 Spaces To Right Is On Board

			if(posY<=MAX_BOARD){//Checks If 1 Space To Down Is On Board

				p1Piece = player1->findPiece(posX,posY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negY>=MIN_BOARD){//Checks If 1 Space To Up Is On Board

				p1Piece = player1->findPiece(posX,negY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		if(negX>=MIN_BOARD){//Checks If 2 Spaces To Left Is On Board

			if(posY<=MAX_BOARD){//Checks If 1 Space To Down Is On Board

				p1Piece = player1->findPiece(negX,posY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negY>=MIN_BOARD){//Checks If 1 Space To Up Is On Board

				p1Piece = player1->findPiece(negX,negY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		posX=x+1;
		posY=y+2;
		negY=y-2;
		negX=x+1;

		if(posY<=MAX_BOARD){//Checks If 2 Spaces To Down Is On Board

			if(posX<=MAX_BOARD){//Checks If 1 Space To Right Is On Board

				p1Piece = player1->findPiece(posX,posY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negX>=MIN_BOARD){//Checks If 1 Space To Left Is On Board

				p1Piece = player1->findPiece(negX,posY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		if(negY>=MIN_BOARD){//Checks If 2 Spaces To Up Is On Board

			if(posX<=MAX_BOARD){//Checks If 1 Space To Right Is On Board

				p1Piece = player1->findPiece(posX,negY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}

			if(negX>=MIN_BOARD){//Checks If 1 Space To Left Is On Board

				p1Piece = player1->findPiece(negX,negY);

				if(p1Piece!=NULL){//Player 1 Has Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}
	}

	return false;

}

//Gets Queen Symbol  *Polymorphic*
char Knight::getSymbol()
{
	return KNIGHT;
}

//Checks If A Valid Move *Polymorphic*
bool Knight::isValidMove(Player *player1, Player *player2, int &x, int &y)
{
	Piece* p1Piece =player1->findPiece(x,y);
	Piece* p2Piece = player2->findPiece(x,y);

	int curX = this->getX();
	int curY = this->getY();

	if(IS_WHITE){//Player 1

		if(p1Piece==NULL||!p1Piece->isAlive()){//Checks if Player 1 Has A Piece At Location

			int yDif = this->getY()-y;

			if(yDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

				yDif*=NEG_CONVERT;//Converts Difference to Positive

			}

			int xDif = this->getX()-x;

			if(xDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

				xDif*=NEG_CONVERT;//Converts Difference to Positive

			}

			if(yDif==INIT_MOVE){//Checks If Difference Is 2 Rows

				if(xDif==TURN_MOVE){//Checks If Difference Is 1 Col

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							p2Piece->setCord(DEAD_X,DEAD_Y);//Temporary Moves Piece To Location

						}
					}
					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location

						this->setCord(curX,curY);//Restores Position

						if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

							if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

								p2Piece->setCord(x,y);//Restores Position

							}

						}

						return true;

					}
					if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							p2Piece->setCord(x,y);//Restores Position

						}

					}
					this->setCord(curX,curY);//Restores Position
				}
			}else if(xDif==INIT_MOVE){//Checks If Difference Is 2 Col

				if(yDif==TURN_MOVE){//Checks If Difference Is 1 Rows

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							p2Piece->setCord(DEAD_X,DEAD_Y);//Temporary Moves Piece To Location

						}
					}
					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location

						this->setCord(curX,curY);//Restores Position

						if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

							if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

								p2Piece->setCord(x,y);//Restores Position

							}

						}

						return true;

					}
					if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							p2Piece->setCord(x,y);//Restores Position

						}

					}
					this->setCord(curX,curY);//Restores Position

				}
			}
		}else{//Player 1 Has Piece At Location

			return false;

		}
	}else{//Player 2

		if(p2Piece==NULL||!p2Piece->isAlive()){//Checks if Player 1 Has A Piece At Location

			int yDif = this->getY()-y;

			if(yDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

				yDif*=NEG_CONVERT;//Converts Difference to Positive

			}

			int xDif = this->getX()-x;

			if(xDif<NEG_DIF_LIMIT){//Checks If Difference Is Neg

				xDif*=NEG_CONVERT;//Converts Difference to Positive

			}

			if(yDif==INIT_MOVE){//Checks If Difference Is 2 Rows

				if(xDif==TURN_MOVE){//Checks If Difference Is 1 Col

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							p1Piece->setCord(DEAD_X,DEAD_Y);//Temporary Moves Piece To Location

						}
					}
					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location

						this->setCord(curX,curY);//Restores Position

						if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

							if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

								p1Piece->setCord(x,y);//Restores Position

							}

						}

						return true;

					}
					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							p1Piece->setCord(x,y);//Restores Position

						}

					}
					this->setCord(curX,curY);//Restores Position
				}
			}else if(xDif==INIT_MOVE){//Checks If Difference Is 2 Col

				if(yDif==TURN_MOVE){//Checks If Difference Is 1 Row

					this->setCord(x,y);//Temporary Moves Piece To Location

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							p1Piece->setCord(DEAD_X,DEAD_Y);//Temporary Moves Piece To Location

						}
					}
					if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location

						this->setCord(curX,curY);//Restores Position

						if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

							if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

								p1Piece->setCord(x,y);//Restores Position

							}

						}

						return true;

					}

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							p1Piece->setCord(x,y);//Restores Position

						}

					}
					this->setCord(curX,curY);//Restores Position
				}
			}
		}else{//Player 1 Has Piece At Location

			return false;

		}
	}
	return false;
}