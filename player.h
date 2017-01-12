#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
#include <set>
#include "Tile.h"

using namespace std;

class Player {

public: 

	Player();
	~Player();

	// void place(set<Tile*> tiles, int x, int y);
	// void pass();
	// void exchange(set<Tile*>tiles);


	void setName(string name);
	void setScore(int x);
	void setTiles(set<Tile*> x);
	string getName();
	int getScore();
	set<Tile*> getTiles();
	void place();
	void exchange();
	void pass();


private: 
	string name;
	int score;
	set<Tile*>tiles;


};

#endif