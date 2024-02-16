/***********************************************************************
Author: William McCarty
Rook.cpp SubClass of Piece.h
 ***********************************************************************/

#include "Rook.h"
#include "Player.h"
#include <iostream>

#define ROOK 'r'
#define KING 'k'
#define IS_WHITE this->getColor()==1
#define MAX_BOARD 8
#define MIN_BOARD 1
#define NEG_CONVERT -1
#define NEG_DIF_LIMIT 0

//Creates A New Rook
Rook::Rook(){}

//Destroys Rook
Rook::~Rook(){}

//Gets Rook Symbol *Polymorphic*
char Rook::getSymbol()
{

	return ROOK;

}

//Checks If Rook Is Checking *Polymorphic*
bool Rook::isChecking(Player* player1,Player* player2, int xDes, int yDes)
{

	int x = this->getX();
	int y = this->getY();
	Piece* p1Piece;
	Piece* p2Piece;

	int posX=x;
	int negX=x;
	int posY=y;
	int negY=y;

	posX++;
	negX--;
	posY++;
	negY--;

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

	}else{

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

		return false;

	}
}

//Checks If Move Is Valid *Polymorphic*
bool Rook::isValidMove(Player *player1, Player *player2, int &x, int &y)
{
	int curX=this->getX();
	int curY=this->getY();

	Piece* des2 = player2->findPiece(x,y);
	Piece* des1 = player1->findPiece(x,y);

	Piece* p1Piece;
	Piece* p2Piece;

	if(this->getX()==x){//Same Col

		int yDif = this->getY()-y;//Gets Space Between Locations

		if(yDif<NEG_DIF_LIMIT){//Moving Down

			yDif*=NEG_CONVERT;//Converts Difference to Positive

			for(int i=1;i<=yDif;i++){//Cycles Through Location Difference

				p1Piece = player1->findPiece(x,this->getY()+i);
				p2Piece =player2->findPiece(x,this->getY()+i);

				if((this->getY()+i)==y){//Reached Destination Row

					if(IS_WHITE){//Player 1

						if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In a Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}		
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}

								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;
							}					
						}
					}else{//Player 2

						if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In a Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}			
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}	
						}
					}
				}else{//Not At Final Location

					if((p1Piece!=NULL&&p1Piece->isAlive())||(p2Piece!=NULL&&p2Piece->isAlive())){//Checks If A Piece Is Blocking Path

						return false;

					}
				}	
			}
		}else{//Moving Up

			for(int i=1;i<=yDif;i++){//Cycles Through Location Difference

				p1Piece = player1->findPiece(x,this->getY()-i);
				p2Piece =player2->findPiece(x,this->getY()-i);

				if((this->getY()-i)==y){//Reached Destination Row

					if(IS_WHITE){//Player 1

						if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position
										}
									}		
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position
										}
									}
								}
								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;
							}
						}
					}else{//Player 2

						if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}	
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}	
						}
					}
				}else{//Not At Final Location

					if((p1Piece!=NULL&&p1Piece->isAlive())||(p2Piece!=NULL&&p2Piece->isAlive())){//Checks If A Piece Is Not Blocking The Path

						return false;

					}
				}
			}
		}
	}else if(this->getY()==y){//Same Row

		int xDif = this->getX()-x;//Gets Space Between Locations

		if(xDif<NEG_DIF_LIMIT){//Moving Right

			xDif*=NEG_CONVERT;//Converts Difference to Positive

			for(int i=1;i<=xDif;i++){//Cycles Through Location Difference

				p1Piece = player1->findPiece(this->getX()+i,y);
				p2Piece =player2->findPiece(this->getX()+i,y);

				if((this->getX()+i)==x){//Reached Destination Col

					if(IS_WHITE){//Player 1

						if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position
										}
									}		
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}
						}					
					}else{//Player 2

						if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}	
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}
						}else{//Not At Final Location

							if((p1Piece!=NULL&&p1Piece->isAlive())||(p2Piece!=NULL&&p2Piece->isAlive())){//Checks If A Piece Is Not Blocking The Path

								return false;

							}
						}
					}
				}
			}
		}else{//Moving Left

			for(int i=1;i<=xDif;i++){//Cycles Through Location Difference

				p1Piece = player1->findPiece(this->getX()-i,y);
				p2Piece =player2->findPiece(this->getX()-i,y);

				if((this->getX()-i)==x){//Reached Destination Col

					if(IS_WHITE){//Player 1

						if(p1Piece==NULL||!p1Piece->isAlive()){//Checks If Player 1 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}					
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}
						}
					}else{//Player 2

						if(p2Piece==NULL||!p2Piece->isAlive()){//Checks If Player 2 Doesn't Piece At Location

							this->setCord(x,y);//Temporary Moves Piece To Location

							if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return true;

							}else{//Results In Check

								p1Piece = player1->findPiece(x,y);
								p2Piece =player2->findPiece(x,y);

								if(IS_WHITE){//Player 1

									if(p2Piece!=NULL){//Checks If A Player 2 Piece At Location

										if(p2Piece->isAlive()){//Checks If Player 2 Piece Is Alive

											des2->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des2->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des2->setCord(x,y);//Reverts Piece To Original Position

										}
									}	
								}else{//Player 2

									if(p1Piece!=NULL){//Checks If A Player 1 Piece At Location

										if(p1Piece->isAlive()){//Checks If Player 1 Piece Is Alive

											des1->setCord(x,y);//Temporary Moves Piece To Location

											if(!this->resultCheck(player1,player2,this->getColor(),x,y)){//Checks If Move Results In a Check

												this->setCord(curX,curY);
												des1->setCord(x,y);//Reverts Piece To Original Position
												return true;

											}

											des1->setCord(x,y);//Reverts Piece To Original Position

										}
									}
								}

								this->setCord(curX,curY);//Reverts Piece To Original Position
								return false;

							}	
						}
					}
				}else{//Not At Final Location

					if((p1Piece!=NULL&&p1Piece->isAlive())||(p2Piece!=NULL&&p2Piece->isAlive())){//Checks If A Piece Is Not Blocking The Path

						return false;

					}
				}
			}
		}	
	}

	return false;

}