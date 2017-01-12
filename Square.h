#ifndef SQUARE_H_
#define SQUARE_H_

#include "Tile.h"
#include <string>
#include <set>

using namespace std;

class Square {

public:
	Square();
	Square(string temp);
	~Square();
	//char getChar();
	int getMultiplier();
	bool isOccupied();
	string getString();
	Tile* getTile();
	void setTile(Tile* temp);
	void setString(string temp);
	void setTileNull();
	void setMultiplier(int x);
	//void setChar(char b);

private:
	Tile* tile;
	int multiplier;
	string what;
	//char a;


};

#endif