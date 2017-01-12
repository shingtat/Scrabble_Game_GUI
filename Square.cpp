#include "Square.h"

using namespace std;

Square::Square(){
	what="";
	tile=NULL;
	multiplier=0;
}

Square::Square(string temp){
	what = temp;
	tile = NULL;
	multiplier = 0;
	//a=' ';
}

Square::~Square(){
	delete tile;

}

// char Square::getChar(){
// 	return a;
// }

// void Square::setChar(char b){
// 	a=b;
// }
void Square::setMultiplier(int x){
	multiplier=x;
}

int Square::getMultiplier(){
	return multiplier;
}

string Square::getString(){
	return what;
}

Tile* Square::getTile(){
	return tile;
}


bool Square::isOccupied(){
	if(tile==NULL){
		return false;
	}
	else{
		return true;
	}
}

void Square::setTile(Tile* temp){
	tile = temp;
}

void Square::setString(string temp){
	what = temp;
}

void Square::setTileNull(){
	tile=NULL;
}


