//
//  Ball.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Ball.hpp"


Hit::Hit(){
	p = 0.8;
}
void Hit::excite(ofVec3f newDir, float newMag) {
	setDir(newDir);
	setMag(newMag);
}

void Hit::excite() {
	setDir(ofVec3f(ofRandom(1), ofRandom(1), ofRandom(1)));
	setMag(ofRandom(100));
	
}

void Hit::setDir(ofVec3f newDir){
	dir = newDir.getNormalized();
}

void Hit::setMag(float newMag){
	mag = newMag;
}

void Hit::setPole(float newPole){
	p = newPole;
}

ofVec3f Hit::tick(){
	double currentSample = mag;
	mag = (mag > 0.00001 ? currentSample * p : 0);
	return currentSample * dir;
}

Ball::Ball(Wall* someWall){
	wall = someWall;
	grav.set(0, 1, 0);
	radi = 50;
	col = ofColor(255);
	acc.set(0,0,0);
	vel.set(0,0,0);
	setPos(ofVec3f(0,0,0));
}

Ball::~Ball(){};

void Ball::setLimits(float baseDim, float newNumTiles) {
	rearLimit.set(ofVec3f(-baseDim/2.f + radi,
						  -baseDim/2.f + radi,
						  -baseDim/2.f + radi));
	foreLimit.set(ofVec3f(baseDim/2.f - radi,
						  baseDim/2.f - radi,
						  baseDim/2.f - radi));
	numTiles = newNumTiles;
}

void Ball::setLimits(ofPoint newRearLimit, ofPoint newForeLimit, float newNumTiles) {
	rearLimit.set(ofVec3f(newRearLimit.x + radi,
						  newRearLimit.y + radi,
						  newRearLimit.z + radi));
	foreLimit.set(ofVec3f(newForeLimit.x - radi,
						  newForeLimit.y - radi,
						  newForeLimit.z - radi));
	numTiles = newNumTiles;
}

void Ball::setPos(ofVec3f newPos) {
	float newX;
	float newY;
	float newZ;
	
	newX = min(max(rearLimit.x, newPos.x), foreLimit.x);
	newY = min(max(rearLimit.x, newPos.y), foreLimit.x);
	newZ = min(max(rearLimit.x, newPos.z), foreLimit.x);
	
	pos.set(newX, newY, newZ);
}

void Ball::setCol(ofColor newCol) {
	col = newCol;
}

void Ball::setGravity(ofVec3f newGrav) {
	grav = newGrav;
}

void Ball::display(){
	ofSetColor(col);
	ofDrawSphere(pos, radi);
}
void Ball::animate(){
	acc =  hit.tick() - 0.01 * vel + grav;
	vel += acc;
	pos += vel;
	
	if (pos.x <= rearLimit.x){
		vel.x = -vel.x * eCoef;
		pos.x = rearLimit.x + (rearLimit.x - pos.x);
		int m = 0;
		int n = 0;
		m = floor((-pos.y + foreLimit.y)/(2 * foreLimit.y/numTiles));
		n = floor((-pos.z + foreLimit.z)/(2 * foreLimit.z/numTiles));
		wall->switchTileState(m, n);
	}
	
	if (pos.x >= foreLimit.x) {
		vel.x = -vel.x * eCoef;
		pos.x = foreLimit.x - (pos.x - foreLimit.x);
		int m = 0;
		int n = 0;
		m = floor(( pos.y + foreLimit.y)/(2 * foreLimit.y/numTiles))
			+ (2 * numTiles);
		n = floor((-pos.z + foreLimit.z)/(2 * foreLimit.z/numTiles));
		wall->switchTileState(m, n);
	}
	
	if (pos.y <= rearLimit.y) {
		vel.y = -vel.y * eCoef;
		pos.y = rearLimit.y + (rearLimit.y - pos.y);
		int m = 0;
		int n = 0;
		m = floor(( pos.x + foreLimit.x)/(2 * foreLimit.x/numTiles))
			+ (1 * numTiles);
		n = floor((-pos.z + foreLimit.z)/(2 * foreLimit.z/numTiles));
		wall->switchTileState(m, n);
	}
	
	if (pos.y >= foreLimit.y) {
		vel.y = -vel.y * eCoef;
		pos.y = foreLimit.y - (pos.y - foreLimit.y);
		int m = 0;
		int n = 0;
		m = floor((-pos.x + foreLimit.x)/(2 * foreLimit.x/numTiles))
			+ (3 * numTiles);
		n = floor((-pos.z + foreLimit.z)/(2 * foreLimit.z/numTiles));
		wall->switchTileState(m, n);
	}
	
	if (pos.z <= rearLimit.z) {
		vel.z = -vel.z * eCoef;
		pos.z = rearLimit.z + (rearLimit.z - pos.z);
	}
	if (pos.z >= foreLimit.z) {
		vel.z = -vel.z * eCoef;
		pos.z = foreLimit.z - (pos.z - foreLimit.z);
	}
}


void Ball::checkPosition(){
	std::cout<<pos<<std::endl;
}
