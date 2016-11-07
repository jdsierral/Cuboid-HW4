//
//  Wall.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Wall.hpp"

Wall::Wall(int m, int n): m(m), n(n) {
	tilePointer = new Tile[m * n];
	tileBoard = new Tile*[m];
	
	for (int i = 0; i< m; i++){
		tileBoard[i] = &tilePointer[n * i];
	}
}
Wall::~Wall(){
	delete [] tileBoard;
	delete [] tilePointer;
}

void Wall::setPos(ofVec3f newPos){
	pos = newPos;
}
void Wall::setAng(ofVec3f newAng){
	ang = newAng;
}
void Wall::setCol(ofColor newCol){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tileBoard[i][j].setColor(newCol);
		}
	}
}

void Wall::setTileSize(ofVec3f newTileSize){
	tileSize = newTileSize;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tileBoard[i][j].setDim(tileSize);
		}
	}
}

ofVec3f Wall::getPos(){
	return pos;
}
ofVec3f Wall::getAng(){
	return ang;
}
ofColor Wall::getCol(){
	return col;
}

void Wall::display(){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ofPushMatrix();
			ofTranslate(tileSize.x * i + 10, tileSize.y * j + 10);
			tileBoard[i][j].display();
			ofPopMatrix();
		}
	}
}

void Wall::tick(){
	for (int i = 0; i < m-1; i++) {
		for (int j = 0; j < n-1; j++) {
			
			//recheck logic... might fail by double checking ints
			int state = 0;
			if (tileBoard[max<int>(i-1, 0)][max<int>(j-1, 0)].getState())
				state++;
			if (tileBoard[i][max<int>(j-1, 0)].getState())
				state++;
			if (tileBoard[min<int>(i+1, n)][j].getState())
				state++;
			if (tileBoard[max<int>(i-1, 0)][j].getState())
				state++;
			if (tileBoard[min<int>(i+1,n)][j].getState())
				state++;
			if (tileBoard[max<int>(i-1, 0)][min<int>(j+1, n)].getState())
				state++;
			if (tileBoard[i][min<int>(j+1, n)].getState())
				state++;
			if (tileBoard[min<int>(i+1, m)][min<int>(j+1, n)].getState())
				state++;
			if(tileBoard[i][j].getState()) {
				if (state < 2)
					tileBoard[i][j].setOff();
				if (state == 2 || state == 3)
					tileBoard[i][j].setOn();
				if (state > 3)
					tileBoard[i][j].setOff();
			} else {
				if (state == 3)
					tileBoard[i][j].setOn();
			}
		}
	}
}
