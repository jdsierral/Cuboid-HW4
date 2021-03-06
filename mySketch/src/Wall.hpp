//
//  Wall.hpp
//  mySketch
//
//  Created by Juan David Sierra on 11/1/16.
//
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "Wall.hpp"
#include "ofMain.h"
#include "Tile.hpp"
#include "math.h"

class Wall
{
public:
	Wall(int m, int n);
	~Wall();
	
	void setPos(ofVec3f newPos);
	void setAng(ofVec3f newAng);
	void setCol(ofColor newCol);
	
	void setTileSize(ofVec3f newTileSize);
	
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
	
private:
	const int m, n; // m x n dimensional wall;
	ofVec3f pos;
	ofVec3f ang;
	ofColor col;
	ofVec3f tileSize;
	
	Tile ** tileBoard;
	Tile * tilePointer;
};

#endif /* Wall_hpp */
