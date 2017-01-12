/*
 * Board.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Board.h"
#include "Tile.h"
#include "Square.h"

using namespace std;

Board::Board (string board_file_name)
{
	ifstream boardFile (board_file_name.c_str());
	string row;

	_x = _y = _startx = _starty = 0; // to appease compiler
	if (!boardFile.is_open())
		throw invalid_argument("Cannot open file: " + board_file_name);
	getline (boardFile, row);
	stringstream s1 (row);
	s1 >> _x >> _y;
	getline (boardFile, row);
	stringstream s2 (row);
	s2 >> _startx >> _starty;
	_startx --; _starty --;  // coordinates from 0 in array

	board = new Square**[_x];
	for(int i = 0; i<_x; i++){
		board[i] = new Square*[_y];
	}

	// Anything else you need to initialize?

	for (int i = 0 ; i <_x; i++)
	{
		 //cout<<i+1<<" "<<endl;
		//cout<<endl;
		
		getline (boardFile, row);
		for (int j = 0; j <_y; j++)
		{

			if (i == _starty && j == _startx) { 
					board[i][j] = new Square("*** ");
			}
			

			else switch (row[j]) {	


			case '.': board[i][j] = new Square("... ");
					  //cout<<board[i][j]->getString();	
			break;
			case '2' : board[i][j] = new Square("2L  ");
					   board[i][j]->setMultiplier(2);
					  //cout<<board[i][j]->getString();			
			break;
			case '3' : board[i][j] = new Square("3L  ");
					   board[i][j]->setMultiplier(3);			
					  //cout<<board[i][j]->getString();			
			break;
			case 'd' : board[i][j] = new Square("2W  ");
					   board[i][j]->setMultiplier(2);

					  //cout<<board[i][j]->getString();			
			break;
			case 't' : board[i][j] = new Square("3W  ");
					   board[i][j]->setMultiplier(3);

					  //cout<<board[i][j]->getString();			
			break;
			default:
				string error = "Improper character in Board file: ";
				throw invalid_argument(error + row[j]);
			}
			//cout << endl;
		//} //else bracket
	}//j forloop bracket
}//i forloop
	//cout<<endl;
	boardFile.close ();
}


Board::~Board(){
	for(int i=0; i<_x; i++){
		for(int j=0; j<_y; j++){
			delete board[i][j];
		}
		delete [] board[i];
	}
	delete [] board;
}


Square*** Board::getBoard(){
	return board;
}

void Board::printBoard(){
	for(int i=0; i<_y; i++){
		cout<<endl;
		for(int j=0; j<_x; j++){			
			cout<<board[i][j]->getString();
			}
		}
	
		cout<<endl;
		cout<<"To pass your turn, type PASS"<<endl;
		cout<<"To discard tiles, type EXCHANGE, followed by a string of those tiles."<<endl;
		cout<<"To place a word, type PLACE, followed by the following:"<<endl;
		cout<<"   first, either a | or - for vertical/horizontal placement;"<<endl;
		cout<<"   second, the row (from the top), the column (from the left),"<<endl;
		cout<<"   third, a sequence of letters to place;"<<endl;
		cout<<"   to use a blank tile, type ? followed by the letter you want to use it for."<<endl;
		cout<<endl;

}

int Board::getFirstMoveX(){
	return _startx;
}

int Board::getFirstMoveY(){
	return _starty;
}
