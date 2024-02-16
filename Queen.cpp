/***********************************************************************
Author: William McCarty
Queen.cpp SubClass of Piece.h
 ***********************************************************************/

#include "Player.h"
#include "Queen.h"
#include <iostream>

#define QUEEN 'q'
#define KING 'k'
#define IS_WHITE this->getColor()==1
#define MAX_BOARD 8
#define MIN_BOARD 1
#define NEG_DIF_LIMIT 0
#define NEG_CONVERT -1
#define DEAD_X -1
#define DEAD_Y -1
#define MOVE_DIS 1

//Creates New Queen
Queen::Queen(){}

//Destroys Queen
Queen::~Queen(){}

//Checks If Checking *Polymorphic*
bool Queen::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{
	int x = this->getX();
	int y = this->getY();

	Piece* p1Piece;
	Piece* p2Piece;

	int posX=x;
	int negX=x;
	int posY=y;
	int negY=y;

	bool flag=false;

	posX++;
	negX--;
	posY++;
	negY--;//Offset

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

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){

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

	}

	posX=x;
	negX=x;
	posY=y;
	negY=y;
	posX++;
	negX--;
	posY++;
	negY--;//Start New Offset

	if(IS_WHITE){//Player 1

		while(posX<=MAX_BOARD){//While In Board

			if(posX==xDes&&y==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(posX,y);
			p1Piece = player1->findPiece(posX,y);

			if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			posX++;//Move Location

		}

		while(negX>=MIN_BOARD){//While In Board

			if(negX==xDes&&y==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(negX,y);
			p1Piece = player1->findPiece(negX,y);

			if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			negX--;//Move Location

		}

		while(posY<=MAX_BOARD){//While In Board

			if(x==xDes&&posY==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(x,posY);
			p1Piece = player1->findPiece(x,posY);

			if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			posY++;//Move Location

		}

		while(negY>=MIN_BOARD){//While In Board

			if(x==xDes&&negY==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(x,negY);
			p1Piece = player1->findPiece(x,negY);

			if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

				if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			negY--;//Move Location

		}

		return false;

	}else{//Player 2

		while(posX<=MAX_BOARD){//While In Board

			if(posX==xDes&&y==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(posX,y);
			p1Piece = player1->findPiece(posX,y);

			if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Player 2 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			posX++;//Move Location

		}

		while(negX>=MIN_BOARD){//While In Board

			if(posX==xDes&&y==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(negX,y);
			p1Piece = player1->findPiece(negX,y);

			if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Player 2 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			negX--;//Move Location

		}

		while(posY<=MAX_BOARD){//While In Board

			if(x==xDes&&posY==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(x,posY);
			p1Piece = player1->findPiece(x,posY);

			if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Player 2 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			posY++;//Move Location

		}

		while(negY>=MIN_BOARD){//While In Board

			if(x==xDes&&negY==yDes){break;}//Hit Testing Piece

			p2Piece = player2->findPiece(x,negY);
			p1Piece = player1->findPiece(x,negY);

			if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

				if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING){//Checks If The King Is at Current Location

					return true;

				}

				break;//Piece Was Hit*blocking*

			}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Player 2 Has a Piece In Location

				break;//Piece Was Hit*blocking*

			}

			negY--;//Move Location

		}
	}

	return false;

}

//Gets Queen Symbol  *Polymorphic*
char Queen::getSymbol()
{
	return QUEEN;
}

//Checks If A Valid Move *Polymorphic*
bool Queen::isValidMove(Player *player1, Player *player2, int &x, int &y)
{
	Piece* des1 = player1->findPiece(x,y);
	Piece* des2 = player2->findPiece(x,y);

	Piece* p1Piece = player1->findPiece(x,y);
	Piece* p2Piece = player2->findPiece(x,y);

	int curX = this->getX();
	int curY = this->getY();

	int xDis = this->getX()-x;
	int yDis = this->getY()-y;

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

	if((xDis==MOVE_DIS&&yDis<=MOVE_DIS)||(yDis==1&&xDis<=1)){//Checks Surrounding Locations

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

				this->setCord(curX,curY);//Restores Position

				if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

					if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

						p2Piece->setCord(x,y);//Restores Position

					}
				}
			}
		}else{//Player 2

			if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Has Piece At Location

				this->setCord(x,y);//Temporary Moves Piece To Location

				if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

					if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

						p1Piece->setCord(DEAD_X,DEAD_Y);//Remove Pawn Temporarly

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
				this->setCord(curX,curY);//Restores Position

				if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

					if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

						p1Piece->setCord(x,y);//Restores Position

					}
				}
			}
		}

		return false;

	}else if(xDis==yDis){//Checks If Displacement Of Both x And y Direction Are Equal

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
						
						this->setCord(curX,curY);//Restores Position

						if(p2Piece!=NULL){//Checks if Player 2 Piece Is There

							if(p2Piece->isAlive()){//Checks if Player 2 Piece Is Alive

								p2Piece->setCord(x,y);//Restores Position

							}

						}
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

						this->setCord(curX,curY);//Restores Position

						if(p1Piece!=NULL){//Checks if Player 1 Piece Is There

							if(p1Piece->isAlive()){//Checks if Player 1 Piece Is Alive

								p1Piece->setCord(x,y);//Restores Position

							}
						}
					}
				}

				return false;

			}else{//Not At Ending Location

				if(xFlag&&yFlag){//minus both

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
				}else if(xFlag&&!yFlag){//minus x

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
				}else if(!xFlag&&yFlag){//minus y

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
				}else{//no minus

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
	}
	else if(this->getX()==x){
		int yDif = this->getY()-y;
		if(yDif<0){
			yDif*=-1;
			for(int i=1;i<=yDif;i++){
				if((this->getY()+i)==y){
					if(this->getColor()==1){
						if(player1->findPiece(x,this->getY()+i)==NULL||!player1->findPiece(x,this->getY()+i)->isAlive()){
							return true;
						}
					}else{
						if(player2->findPiece(x,this->getY()+i)==NULL||!player2->findPiece(x,this->getY()+i)->isAlive()){
							return true;
						}	
					}
				}else{
					if((player1->findPiece(x,this->getY()+i)!=NULL&&player1->findPiece(x,this->getY()+i)->isAlive())||(player2->findPiece(x,this->getY()+i)!=NULL&&player2->findPiece(x,this->getY()+i)->isAlive())){
						return false;
					}
				}
			}
		}
		else{
			for(int i=1;i<=yDif;i++){
				if((this->getY()-i)==y){
					if(this->getColor()==1){
						if(player1->findPiece(x,this->getY()-i)==NULL||!player1->findPiece(x,this->getY()-i)->isAlive()){
							return true;
						}
					}else{
						if(player2->findPiece(x,this->getY()-i)==NULL||!player2->findPiece(x,this->getY()-i)->isAlive()){
							return true;
						}	
					}
				}else{
					if((player1->findPiece(x,this->getY()-i)!=NULL&&player1->findPiece(x,this->getY()-i)->isAlive())||(player2->findPiece(x,this->getY()-i)!=NULL&&player2->findPiece(x,this->getY()-i)->isAlive())){
						return false;
					}
				}
			}
		}
	}else if(this->getY()==y){
		int xDif = this->getX()-x;
		if(xDif<0){
			xDif*=-1;
			for(int i=1;i<=xDif;i++){
				if((this->getX()+i)==x){
					if(IS_WHITE){
						if(player1->findPiece(this->getX()+i,y)==NULL||!player1->findPiece(this->getX()+i,y)->isAlive()){
							this->setCord(x,y);
							if(player2->findPiece(x,y)!=NULL){
								if(player2->findPiece(x,y)->isAlive()){
									p2Piece->setCord(DEAD_X,DEAD_Y);//Remove Pawn Temporarly
								}
							}
							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location
								this->setCord(curX,curY);
								if(player2->findPiece(x,y)!=NULL){
									if(player2->findPiece(x,y)->isAlive()){
										p2Piece->setCord(x,y);//Remove Pawn Temporarly
									}
								}
								return true;
							}
							this->setCord(curX,curY);
							if(player2->findPiece(x,y)!=NULL){
								if(player2->findPiece(x,y)->isAlive()){
									p2Piece->setCord(x,y);//Remove Pawn Temporarly
								}
							}

						}
					}else{//Player 2
						if(player2->findPiece(this->getX()+i,y)==NULL||!player2->findPiece(this->getX()+i,y)->isAlive()){
							this->setCord(x,y);
							if(player1->findPiece(x,y)!=NULL){
								if(player1->findPiece(x,y)->isAlive()){
									p1Piece->setCord(DEAD_X,DEAD_Y);//Restores Position
								}
							}
							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location
								this->setCord(curX,curY);
								if(player1->findPiece(x,y)!=NULL){
									if(player1->findPiece(x,y)->isAlive()){
										p1Piece->setCord(x,y);//Restores Position
									}
								}
								return true;
							}
							this->setCord(curX,curY);
							if(player1->findPiece(x,y)!=NULL){
								if(player1->findPiece(x,y)->isAlive()){
									p1Piece->setCord(x,y);//Restores Position
								}
							}
						}	
					}
				}else{
					if((player1->findPiece(this->getX()+i,y)!=NULL&&player1->findPiece(this->getX()+i,y)->isAlive())||(player2->findPiece(this->getX()+i,y)!=NULL&&player2->findPiece(this->getX()+i,y)->isAlive())){
						return false;
					}
				}
			}
		}else{
			for(int i=1;i<=xDif;i++){
				if((this->getX()-i)==x){
					if(this->getColor()==1){
						if(player1->findPiece(this->getX()-i,y)==NULL||!player1->findPiece(this->getX()-i,y)->isAlive()){
							this->setCord(x,y);
							if(player2->findPiece(x,y)!=NULL){
								if(player2->findPiece(x,y)->isAlive()){
									p2Piece->setCord(DEAD_X,DEAD_Y);//Remove Pawn Temporarly
								}
							}
							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location
								this->setCord(curX,curY);
								if(player2->findPiece(x,y)!=NULL){
									if(player2->findPiece(x,y)->isAlive()){
										p2Piece->setCord(x,y);//Remove Pawn Temporarly
									}
								}
								return true;
							}
							this->setCord(curX,curY);
							if(player2->findPiece(x,y)!=NULL){
								if(player2->findPiece(x,y)->isAlive()){
									p2Piece->setCord(x,y);//Remove Pawn Temporarly
								}
							}	
						}
					}else{//Player 2
						if(player2->findPiece(this->getX()-i,y)==NULL||!player2->findPiece(this->getX()-i,y)->isAlive()){
							this->setCord(x,y);
							if(player1->findPiece(x,y)!=NULL){
								if(player1->findPiece(x,y)->isAlive()){
									p1Piece->setCord(DEAD_X,DEAD_Y);//Remove Pawn Temporarly
								}
							}
							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If The King Is at Current Location
								this->setCord(curX,curY);
								if(player1->findPiece(x,y)!=NULL){
									if(player1->findPiece(x,y)->isAlive()){
										p1Piece->setCord(x,y);//Remove Pawn Temporarly
									}
								}
								return true;
							}
							this->setCord(curX,curY);
							if(player1->findPiece(x,y)!=NULL){
								if(player1->findPiece(x,y)->isAlive()){
									p1Piece->setCord(x,y);//Remove Pawn Temporarly
								}
							}
						}	
					}
				}else{
					if((player1->findPiece(this->getX()-i,y)!=NULL&&player1->findPiece(this->getX()-i,y)->isAlive())||(player2->findPiece(this->getX()-i,y)!=NULL&&player2->findPiece(this->getX()-i,y)->isAlive())){
						return false;
					}
				}
			}
		}
	}
	return false;
}
