/***********************************************************************
Author: William McCarty
Main.cpp
 ***********************************************************************/

#include <iostream>
#include <string>
#include "GameEngine.h"

class GameEngine;

int main(int argc, char** argv){
	GameEngine *engine = new GameEngine();

	cout<<"    Game Start"<<endl;
	cout<<"------------------"<<endl;
	cout<<"Player1=lowercase;Player2=uppercase\ncommand template: FromPosition ToPosition\ntype 'e' to end the game"<<endl;
	cout<<"Player "<<1<<": ";
	int player=1;
	string currentCommand = engine->getCommand();
	while(currentCommand!="e"){
		if(currentCommand.length()==5){
			string fromCord = currentCommand.substr(0,2);
			string toCord = currentCommand.substr(3,5);
	        fromCord = engine->cordConvert(fromCord);
	        toCord = engine->cordConvert(toCord);
			int fromX=atoi(fromCord.substr(0,1).c_str());
			int fromY=atoi(fromCord.substr(1,2).c_str());
			int toX=atoi(toCord.substr(0,1).c_str());
			int toY=atoi(toCord.substr(1,2).c_str());
			bool validPiece = engine->isValidPiece(player, fromX, fromY);
			bool validDomain1 = engine->validateBoardDomain(fromX);
			bool validDomain2 = engine->validateBoardDomain(fromY);
			bool validDomain3 = engine->validateBoardDomain(toX);
			bool validDomain4 = engine->validateBoardDomain(toY);
			if(!validDomain1||!validDomain2||!validDomain3||!validDomain4){
				cout<<"Invalid Board Domain"<<endl;
				cout<<"Player "<<player<<": ";
				currentCommand = engine->getCommand();
				continue;
			}
			if(!validPiece){
				cout<<"Invalid Piece Selected"<<endl;
				cout<<"Player "<<player<<": ";
				currentCommand = engine->getCommand();
				continue;
			}
			if(player==1){
				bool validMove = engine->getPlayer1()->findPiece(fromX,fromY)->isValidMove(engine->getPlayer1(),engine->getPlayer2(),toX,toY);
				if(!validMove){
					cout<<"Invalid Move Attempt"<<endl;
					cout<<"Player "<<player<<": ";
					currentCommand = engine->getCommand();
					continue;
				}
				engine->getPlayer1()->findPiece(fromX,fromY)->move(engine->getPlayer1(),engine->getPlayer2(),toX,toY);
			}else{
				bool validMove = engine->getPlayer2()->findPiece(fromX,fromY)->isValidMove(engine->getPlayer1(),engine->getPlayer2(),toX,toY);
				if(!validMove){
					cout<<"Invalid Move Attempt"<<endl;
					cout<<"Player "<<player<<": ";
					currentCommand = engine->getCommand();
					continue;
				}
				engine->getPlayer2()->findPiece(fromX,fromY)->move(engine->getPlayer1(),engine->getPlayer2(),toX,toY);
			}

			engine->updateBoard();
			player = engine->switchPlayer(player);
		}else{
			cout<<"Invalid Command\n"<<"command template: FromPosition ToPosition"<<endl;
		}
		cout<<"Player "<<player<<": ";
		currentCommand = engine->getCommand();
	}
	engine->~GameEngine();
}