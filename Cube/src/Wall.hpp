//
//  Wall.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Tile.hpp"

class Wall
{
public:
	Wall(int m, int n);
	~Wall();
	
	void setPos(ofVec3f newPos);
	void setAng(ofVec3f newAng);
	void setCol(ofColor newCol);
	
	void setTileSize(ofVec3f newTileSize);
	void setSize(ofVec2f newBaseDim);
	
	
	ofVec3f getPos();
	ofVec3f getAng();
	ofColor getCol();
	
	void display();
	void tick();
	
	int clip(int val, int min, int max) {
		if (val < min)
			return min;
		else if (val > max)
			return max;
		else
			return val;
	}
	
	ofVec3f testPos;
	float testRot;
	
private:
	const int m, n; // m x n dimensional wall;
	ofVec3f pos;
	ofVec3f ang;
	ofColor col;
	ofVec3f tileSize;
	ofVec2f baseDim;
	
	
	Tile ** tileBoard;
	Tile * tilePointer;
};

#endif /* Wall_hpp */
