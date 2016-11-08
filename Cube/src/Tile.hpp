//
//  Tile.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "ofMain.h"

class Tile
{
public:
	Tile ();
	~Tile ();
	void setPos(ofVec3f newPos);
	void setAng(ofVec3f newAng);
	void setDim(ofVec3f newDim);
	void setColor(ofColor newCol);
	void setOn();
	void setOff();
	void setState(bool newState);
	
	ofVec3f getPos();
	ofVec3f getAng();
	ofColor getColor();
	bool getState();
	
	void display();
	
private:
	
	void drawBox(ofVec3f pos, ofVec3f dim, ofVec3f ang, ofColor col);
	
	ofBoxPrimitive box;
	ofVec3f dim; //dimensions;
	ofVec3f pos; //position
	ofVec3f ang; //angle
	ofColor colOn; //colors
	ofColor colOff;
	bool state; //on and off states
};

#endif /* Tile_hpp */
