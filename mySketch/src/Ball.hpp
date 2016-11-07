//
//  Ball.hpp
//  mySketch
//
//  Created by Juan David Sierra on 11/6/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball
{
public:
	Ball(float newRadi);
	~Ball();
	
	void setPos(ofVec3f newPos);
	void setVel(ofVec3f newVel);
	void setAcc(ofVec3f newAcc);
	void setCol(ofColor newCol);
	
	void setECoef(float newECoef);
	
	ofVec3f getPos();
	ofVec3f getVel();
	ofVec3f getAcc();
	ofColor getCol();
	
	void animate();
	void display();
	
private:
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;
	ofColor col;
	float eCoef;
	float radi;
};

#endif /* Ball_hpp */
