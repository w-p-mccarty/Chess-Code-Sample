/***********************************************************************
Author: William McCarty
Board.cpp
 ***********************************************************************/

#include <iostream>
#include "Board.h"

#define Y_MAX 16
#define X_MAX 16
#define IS_Y_EVEN y%2==0
#define IS_X_EVEN x%2==0
#define ROW_NUMBER 9-(y-pieceRowCounter)
#define Y_MOD_NOT_ZERO y%2!=0

//Creates The Board
Board::Board(Player *player1, Player *player2)
{

	_player1=player1;
	_player2=player2;//Defines Globals
	createBoard();//Generates Board

}

//Destroys The Board
Board::~Board(){}

//Displays the Current Board
void Board::createBoard()
{

	int pieceColCounter=0;
	int pieceRowCounter=0;

	cout<<"  a b c d e f g h \n";//Prints Columns Of Board

	for(int y=0;y<=Y_MAX;y++){

		if(IS_Y_EVEN){

			cout<<' ';//Empty Row Spacing

		}else{

			cout<<ROW_NUMBER;//prints Rows Of Board

		}

		for(int x=0;x<=X_MAX;x++){

			if(IS_Y_EVEN){

				cout<<'*';//Part Of Board

			}else{

				if(IS_X_EVEN){

					cout<<'*';//Part Of Board

				}else{

					Piece* p1Piece = _player1->findPiece(x-pieceColCounter,y-pieceRowCounter);
					Piece* p2Piece = _player2->findPiece(x-pieceColCounter,y-pieceRowCounter);

					if(p1Piece!=NULL&&p1Piece->isAlive()){//Checks if Player 1 Piece is at current coordinate thats still in play

						if('r'==p1Piece->getSymbol()){//Player 1 Rook

							cout<<'r';

						}else if('b'==p1Piece->getSymbol()){//Player 1 Bishop

							cout<<'b';

						}else if('k'==p1Piece->getSymbol()){//Player 1 King

							cout<<'k';

						}else if('p'==p1Piece->getSymbol()){//Player 1 Pawn

							cout<<'p';

						}else if('h'==p1Piece->getSymbol()){//Player 1 Knight

							cout<<'h';

						}else if('q'==p1Piece->getSymbol()){//Player 1 Queen

							cout<<'q';

						}
					}else if(p2Piece!=NULL&&p2Piece->isAlive()){//Checks if Player 2 Piece is at current coordinate thats still in play

						if('r'==p2Piece->getSymbol()){//Player 2 Rook

							cout<<'R';

						}else if('b'==p2Piece->getSymbol()){//Player 2 Bishop

							cout<<'B';

						}else if('k'==p2Piece->getSymbol()){//Player 2 King

							cout<<'K';

						}else if('p'==p2Piece->getSymbol()){//Player 2 Pawn

							cout<<'P';

						}else if('h'==p2Piece->getSymbol()){//Player 2 Knight

							cout<<'H';

						}else if('q'==p2Piece->getSymbol()){//Player 2 Queen

							cout<<'Q';

						}

					}else{

						cout<<' ';//Empty Slot In Board

					}

					pieceColCounter++;

				}
			}
		}

		if(Y_MOD_NOT_ZERO){

			pieceRowCounter++;

		}

		cout<<'\n';
		pieceColCounter=0;
	}
}

