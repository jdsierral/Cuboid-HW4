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

class Ball
{
public:
	Ball(Wall* someWall);
	~Ball();
	void setLimits(float baseDim);
	void setLimits(ofPoint newRearLimit, ofPoint newForeLimit);
	void setPos(ofVec3f newPos);
	void setCol(ofColor newCol);
	void setGravity(ofVec3f newGrav);
	void display();
	void animate();
	
	void checkPosition();
	
	ofVec3f grav;
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;
	Hit hit;
	
	ofPoint rearLimit;
	ofPoint foreLimit;
	
	ofVec3f force;
	
	ofColor col;
	float radi;
	
	float eCoef = 0.95;
	
	Wall* wall;
};




#endif /* Ball_hpp */
