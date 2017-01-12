
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Bag.h"
#include "Tile.h"
#include "player.h"

using namespace std;

Player::Player(){
	name = "";
	score =0;
}

Player::~Player(){
}

string Player::getName(){
	return name;
}

int Player::getScore(){
	return score;
}

void Player::setName(string name2){
	name = name2;
}

void Player::setScore(int x){
	score = x;
}

set<Tile*>Player::getTiles(){
	return tiles;
}

void Player::setTiles(set<Tile*> x){
	tiles = x;
}
