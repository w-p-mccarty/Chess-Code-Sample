/***********************************************************************
Author: William McCarty
Bishop.cpp SubClass of Piece.h
 ***********************************************************************/
#include "Bishop.h"
#include "Player.h"
#include <iostream>

#define BISHOP 'b'
#define KING 'k'
#define IS_WHITE this->getColor()==1
#define MAX_BOARD 8
#define MIN_BOARD 1
#define NEG_DIF_LIMIT 0
#define NEG_CONVERT -1
#define DEAD_X -1
#define DEAD_Y -1

//Creates New Bishop
Bishop::Bishop(){}

//Destroys Bishop
Bishop::~Bishop(){}

//Gets Bishop Symbol  *Polymorphic*
char Bishop::getSymbol()
{
	return BISHOP;
}

//Checks If Checking *Polymorphic*
bool Bishop::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{

	Piece* p1Piece;
	Piece* p2Piece;

	int x = this->getX();
	int y = this->getY();

	int posX=x;
	int negX=x;
	int posY=y;
	int negY=y;

	posX++;
	negX--;
	posY++;
	negY--;//Offsets Coordinates

	if(IS_WHITE){//Player 1

		while(posX<=MAX_BOARD&&negY>=MIN_BOARD){//Checks If Offset Is On Board, NorthEast

			if(posX==xDes&&negY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(posX,negY);
			p1Piece = player1->findPiece(posX,negY);

			if(p2Piece!=NULL){//Checks If Player 2 Has A Piece At The Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks If Player 1 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posX++;
			negY--;//Increment Offset

		}

		posX=x+1;
		negY=y-1;//Restore to Starting Offset

		while(negX>=MIN_BOARD&&negY>=MIN_BOARD){//Checks If Offset Is On Board, NorthWest

			if(negX==xDes&&negY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(negX,negY);
			p1Piece = player1->findPiece(negX,negY);

			if(p2Piece!=NULL){//Checks If Player 2 Has A Piece At The Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks If Player 1 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			negX--;
			negY--;//Increment Offset

		}

		negX=x-1;
		negY=y-1;//Restore to Starting Offset

		while(posY<=MAX_BOARD&&posX<=MAX_BOARD){//Checks If Offset Is On Board, SouthEast

			if(posX==xDes&&posY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(posX,posY);
			p1Piece = player1->findPiece(posX,posY);

			if(p2Piece!=NULL){//Checks If Player 2 Has A Piece At The Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks If Player 1 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posY++;
			posX++;//Increment Offset

		}

		posX=x+1;
		posY=y+1;//Restore to Starting Offset

		while(posY>=MIN_BOARD&&negX>=MIN_BOARD){//Checks If Offset Is On Board, SouthWest

			if(negX==xDes&&posY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(negX,posY);
			p1Piece = player1->findPiece(negX,posY);

			if(p2Piece!=NULL){//Checks If Player 2 Has A Piece At The Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks If Player 1 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posY++;
			negX--;//Increment Offset

		}

		posY=y+1;
		negX=x-1;//Restore to Starting Offset

		return false;

	}else{//Player 2

		while(posX<=MAX_BOARD&&negY>=MIN_BOARD){//Checks If Offset Is On Board, NorthEast

			if(posX==xDes&&negY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(posX,negY);
			p1Piece = player1->findPiece(posX,negY);

			if(p1Piece!=NULL){//Checks If Player 1 Has A Piece At The Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks If Player 2 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posX++;
			negY--;//Increment Offset

		}

		posX=x+1;
		negY=y-1;//Restore to Starting Offset

		while(negX>=MIN_BOARD&&negY>=MIN_BOARD){//Checks If Offset Is On Board, NorthWest

			if(negX==xDes&&negY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(negX,negY);
			p1Piece = player1->findPiece(negX,negY);

			if(p1Piece!=NULL){//Checks If Player 1 Has A Piece At The Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks If Player 2 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			negX--;
			negY--;//Increment Offset

		}

		negX=x-1;
		negY=y-1;//Restore to Starting Offset

		while(posY<=MAX_BOARD&&posX<=MAX_BOARD){//Checks If Offset Is On Board, SouthEast

			if(posX==xDes&&posY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(posX,posY);
			p1Piece = player1->findPiece(posX,posY);

			if(p1Piece!=NULL){//Checks If Player 1 Has A Piece At The Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks If Player 2 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posY++;
			posX++;//Increment Offset

		}

		posX=x+1;
		posY=y+1;//Restore to Starting Offset

		while(posY>=MIN_BOARD&&negX>=MIN_BOARD){//Checks If Offset Is On Board, SouthWest

			if(negX==xDes&&posY==yDes){break;}//Checks If Hit Position Moved To

			p2Piece = player2->findPiece(negX,posY);
			p1Piece = player1->findPiece(negX,posY);

			if(p1Piece!=NULL){//Checks If Player 1 Has A Piece At The Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Hit Position Moved To

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks If Player 2 Has A Piece At The Location

				break;//Hit Position Moved To

			}

			posY++;
			negX--;//Increment Offset

		}

		posY=y+1;
		negX=x-1;//Restore to Starting Offset
		return false;

	}
}

//Checks If A Valid Move *Polymorphic*
bool Bishop::isValidMove(Player *player1, Player *player2, int &x, int &y)
{
	int xDis = this->getX()-x;
	int yDis = this->getY()-y;

	int curX = this->getX();
	int curY = this->getY();

	Piece* p1Piece;
	Piece* p2Piece;

	bool xFlag = false;
	bool yFlag = false;

	if(xDis<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		xDis*=NEG_CONVERT;//Converts Difference to Positive
		xFlag=true;

	}

	if(yDis<NEG_DIF_LIMIT){//Checks If Difference Is Neg

		yDis*=NEG_CONVERT;//Converts Difference to Positive
		yFlag=true;

	}

	if(xDis==yDis){//Checks If Displacement Of Both x And y Direction Are Equal

		for(int i=1;i<=xDis;i++){//Cycle Through Displacment

			if(i==xDis){//Reached Location

				p1Piece = player1->findPiece(x,y);
				p2Piece = player2->findPiece(x,y);

				if(IS_WHITE){//Player 1

					if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Has Piece At Location

						this->setCord(x,y);//Temporary Moves Piece To Location

						if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

							if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

								p2Piece->setCord(DEAD_X,DEAD_Y);//Remove Pawn Temporarly

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
				}else{//Player 2

					if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Has Piece At Location

						this->setCord(x,y);//Temporary Moves Piece To Location

						if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

							if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

								p1Piece->setCord(DEAD_X,DEAD_Y);

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
						if(p1Piece!=NULL){//Checks if Player 2 Piece Is There

							if(p1Piece->isAlive()){//Checks if Player 2 Piece Is Alive

								p1Piece->setCord(x,y);//Restores Position

							}

						}
						this->setCord(curX,curY);//Restores Position
					}
				}

				return false;

			}else{//Not At Ending Location

				if(xFlag&&yFlag){//Minus x & y

					p1Piece = player1->findPiece(this->getX()+i,this->getY()+i);
					p2Piece = player2->findPiece(this->getX()+i,this->getY()+i);

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							return false;

						}

					}else if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							return false;
						}

					}
				}else if(xFlag&&!yFlag){//Minus x

					p1Piece = player1->findPiece(this->getX()+i,this->getY()-i);
					p2Piece = player2->findPiece(this->getX()+i,this->getY()-i);

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							return false;

						}

					}else if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							return false;

						}
					}

				}else if(!xFlag&&yFlag){//Minus y

					p1Piece = player1->findPiece(this->getX()-i,this->getY()+i);
					p2Piece = player2->findPiece(this->getX()-i,this->getY()+i);

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							return false;

						}

					}else if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							return false;

						}

					}
				}else{//Both Positive

					p1Piece = player1->findPiece(this->getX()-i,this->getY()-i);
					p2Piece = player2->findPiece(this->getX()-i,this->getY()-i);

					if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

						if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

							return false;

						}

					}else if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

						if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

							return false;

						}

					}
				}
			}
		}
	}else{//Displacements Are Not Equal

		return false;

	}
}