/*
 * Board.h
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include "Square.h"

class Board {
public:
	Board (std::string board_file_name);

	~Board();

	// What else will this need?
	Square*** getBoard();

	void printBoard();
	int _x, _y;

	int getFirstMoveX();
	int getFirstMoveY();

private:
	int _startx, _starty;
	Square*** board;

	// What else will this need?

};


#endif /* BOARD_H_ */
