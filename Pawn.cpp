/***********************************************************************
Author: William McCarty
Pawn.cpp SubClass of Piece.h
 ***********************************************************************/

#include "Pawn.h"
#include "Player.h"
#include <iostream>

#define IS_WHITE this->getColor()==1
#define MAX_BOARD 8
#define MIN_BOARD 1
#define KING_PIECE 'k'
#define PAWN 'p'
#define PLAYER1_START_LINE 7
#define PLAYER2_START_LINE 2
#define DBL_JUMP 2
#define DEAD_X -1
#define DEAD_Y -1
#define SINGLE_JMP 1
#define RIGHT_OF_PAWN this->getX()+1
#define LEFT_OF_PAWN this->getX()-1
#define NORTH_OF_PAWN this->getY()-y
#define SOUTH_OF_PAWN y-this->getY()

//Creates Pawn Piece
Pawn::Pawn(){}

//Destroys Pawn Piece
Pawn::~Pawn(){}

//Gets Pawn's Symbol *Polymorphic*
char Pawn::getSymbol()
{

	return PAWN;

}

//Checks If Pawn Is Checking *Polymorphic*
bool Pawn::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{

	Piece* p1Piece;
	Piece* p2Piece;

	int x = this->getX();
	int y = this->getY();

	if(IS_WHITE){//Player 1

		if(x<MAX_BOARD){//Checks If Col Is On The Board

			if(y>MIN_BOARD){//Checks If Row Is On The Board

				p2Piece = player2->findPiece(x+1,y-1);

				if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING_PIECE){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}
		if(x>MIN_BOARD){//Checks If Col Is On The Board

			if(y>MIN_BOARD){//Checks If Row Is On The Board

				p2Piece = player2->findPiece(x-1,y-1);

				if(p2Piece!=NULL){//Player 2 Doesnt Have Piece In Location

					if(p2Piece->isAlive()&&p2Piece->getSymbol()==KING_PIECE){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		return false;

	}else{//Player 2

		if(x<MAX_BOARD){//Checks If Col Is On The Board

			if(y<MAX_BOARD){//Checks If Row Is On The Board

				p1Piece = player1->findPiece(x+1,y+1);

				if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING_PIECE){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}
		if(x>MIN_BOARD){//Checks If Col Is On The Board

			if(y<MAX_BOARD){//Checks If Row Is On The Board

				p1Piece = player1->findPiece(x-1,y+1);

				if(p1Piece!=NULL){//Player 1 Doesnt Have Piece In Location

					if(p1Piece->isAlive()&&p1Piece->getSymbol()==KING_PIECE){//Checks If The King Is at Current Location

						return true;

					}
				}
			}
		}

		return false;
	}
}

//Checks If Move Is Valid *Polymorphic*
bool Pawn::isValidMove(Player * player1,Player * player2,int &x, int &y)
{

	Piece* p1Piece =player1->findPiece(x,y);//Gets p1 piece
	Piece* p2Piece = player2->findPiece(x,y);//Gets p2 piece

	int curX = this->getX();
	int curY = this->getY();

	if(IS_WHITE){//White(moves up) Player1

		if(this->getX()==x){//Moving Straight

			if(this->getY()==PLAYER1_START_LINE){//Hasnt moved

				if((NORTH_OF_PAWN)==DBL_JUMP){//Move 2

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(player1->findPiece(x,y+1)==NULL||!player1->findPiece(x,y+1)->isAlive()){//Not Player 1 Piece At Location Prior

							if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

								if(player2->findPiece(x,y+1)==NULL||!player2->findPiece(x,y+1)->isAlive()){//Not Player 2 Piece At Location Prior

									this->setCord(x,y);//Remove Pawn Temporarly

									if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

										this->setCord(curX,curY);//Restores Position
										return true;

									}else{

										this->setCord(curX,curY);//Restores Position
										return false;

									}
								}	
							}
						}
					}
				}else if((NORTH_OF_PAWN)==SINGLE_JMP){//Move 1

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

							this->setCord(x,y);//Remove Pawn Temporarly

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

								this->setCord(curX,curY);//Restores Position
								return true;

							}else{

								this->setCord(curX,curY);//Restores Position
								return false;

							}
						}
					}
				}
			}else{//Has Moved

				if((NORTH_OF_PAWN)==SINGLE_JMP){//Moves 1

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

							this->setCord(x,y);//Remove Pawn Temporarly

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

								this->setCord(curX,curY);//Restores Position
								return true;

							}else{

								this->setCord(curX,curY);//Restores Position
								return false;

							}
						}
					}
				}
			}
		}else{//Killing

			if(x==RIGHT_OF_PAWN){//Attacking To Right

				if((NORTH_OF_PAWN)==SINGLE_JMP){//Moves 1

					if(p2Piece!=NULL&&p2Piece->isAlive()){//Player 2 Has Piece At Location

						p2Piece->setCord(DEAD_X,DEAD_Y);
						this->setCord(x,y);//Remove Pawn Temporarly

						if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

							p2Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return true;

						}else{

							p2Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return false;

						}
					}
				}
			}else if(x==LEFT_OF_PAWN){//Attacking To Left

				if((NORTH_OF_PAWN)==SINGLE_JMP){//Moves 1

					if((p2Piece!=NULL&&p2Piece->isAlive())){//Player 2 Has Piece At Location

						p2Piece->setCord(DEAD_X,DEAD_Y);
						this->setCord(x,y);//Remove Pawn Temporarly

						if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

							p2Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return true;

						}else{

							p2Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return false;

						}
					}
				}
			}
		}
	}else{//Player 2

		if(this->getX()==x){//Moving Striaght

			if(this->getY()==PLAYER2_START_LINE){//Hasnt moved

				if((SOUTH_OF_PAWN)==DBL_JUMP){//Move 2

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(player1->findPiece(x,y-1)==NULL||!player1->findPiece(x,y-1)->isAlive()){//Not Player 1 Piece At Location Prior

							if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

								if(player2->findPiece(x,y-1)==NULL||!player2->findPiece(x,y-1)->isAlive()){//Not Player 2 Piece At Location Prior

									this->setCord(x,y);//Remove Pawn Temporarly

									if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

										this->setCord(curX,curY);//Restores Position
										return true;

									}else{

										this->setCord(curX,curY);//Restores Position
										return false;

									}
								}
							}
						}
					}
				}else if((SOUTH_OF_PAWN)==SINGLE_JMP){//Move 1

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

							this->setCord(x,y);//Remove Pawn Temporarly

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

								this->setCord(curX,curY);//Restores Position
								return true;

							}else{

								this->setCord(curX,curY);//Restores Position
								return false;

							}
						}
					}
				}
			}else{//Has Moved

				if((SOUTH_OF_PAWN)==SINGLE_JMP){//Moves 1

					if(p1Piece==NULL||!p1Piece->isAlive()){//Not Player 1 Piece At Location

						if(p2Piece==NULL||!p2Piece->isAlive()){//Not Player 2 Piece At Location

							this->setCord(x,y);//Remove Pawn Temporarly

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

								this->setCord(curX,curY);//Restores Position
								return true;

							}else{

								this->setCord(curX,curY);//Restores Position
								return false;

							}
						}
					}
				}
			}
		}else{//Attacking Piece

			if(x==RIGHT_OF_PAWN){//Attacking To Right

				if((SOUTH_OF_PAWN)==SINGLE_JMP){//Moves 1

					if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has Piece At Location

						p1Piece->setCord(DEAD_X,DEAD_Y);
						this->setCord(x,y);//Remove Pawn Temporarly

						if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

							p1Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return true;

						}else{

							p1Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return false;

						}
					}
				}
			}else if(x==LEFT_OF_PAWN){//Attacking To Left

				if((SOUTH_OF_PAWN)==SINGLE_JMP){//moves 1/2

					if(p1Piece!=NULL&&p1Piece->isAlive()){//Player 1 Has Piece At Location 

						p1Piece->setCord(DEAD_X,DEAD_Y);
						this->setCord(x,y);//Remove Pawn Temporarly

						if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Check If Results In Check

							p1Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return true;

						}else{

							p1Piece->setCord(x,y);
							this->setCord(curX,curY);//Restores Position
							return false;

						}
					}
				}
			}
		}
	}

	return false;

}
