//
//  Ball.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Wall.hpp"

// Hit class creates an impulse assigned to force value in ball dynamics

class Hit
{
public:
	Hit();
	void excite(ofVec3f newDir, float newMag);
	void excite();
	void setDir(ofVec3f newDir);
	void setMag(float newMag);
	void setPole(float newPole);
	ofVec3f tick();
	ofVec3f dir;
	float mag;
	float p;
};

// Ball is full emulation of classical physics... has gravity, acceleration
// velocity, friction and position;

class Ball
{
public:
	Ball(Wall* someWall);
	~Ball();
	void setLimits(float baseDim, float newNumTiles);
	void setLimits(ofPoint newRearLimit, ofPoint newForeLimit, float newNumTiles);
	void setPos(ofVec3f newPos);
	void setCol(ofColor newCol);
	void setGravity(ofVec3f newGrav);
	void display();
	void animate();
	
	void checkPosition();
	
	Wall* wall;
	Hit hit;
	
	ofVec3f force;
	ofVec3f grav;
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;
	
	ofPoint rearLimit;
	ofPoint foreLimit;
	
	ofColor col;
	
	float radi;
	float eCoef = 0.95;
	float numTiles;
};




#endif /* Ball_hpp */
