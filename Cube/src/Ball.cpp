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
	std::cout<<"Mag: "<<currentSample<<std::endl;
	return currentSample * dir;
}

Ball::Ball(){
	grav.set(0, 1, 0);
	radi = 50;
	col = ofColor(255);
	acc.set(0,0,0);
	vel.set(0,0,0);
	setPos(ofVec3f(0,0,0));
}

Ball::~Ball(){};

void Ball::setLimits(float baseDim) {
	rearLimit.set(ofVec3f(-baseDim/2.f + radi,
						  -baseDim/2.f + radi,
						  -baseDim/2.f + radi));
	foreLimit.set(ofVec3f(baseDim/2.f - radi,
						  baseDim/2.f - radi,
						  baseDim/2.f - radi));
}

void Ball::setLimits(ofPoint newRearLimit, ofPoint newForeLimit) {
	rearLimit.set(ofVec3f(newRearLimit.x + radi,
						  newRearLimit.y + radi,
						  newRearLimit.z + radi));
	foreLimit.set(ofVec3f(newForeLimit.x - radi,
						  newForeLimit.y - radi,
						  newForeLimit.z - radi));
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

void Ball::display(){
	ofSetColor(col);
	ofDrawSphere(pos, radi);
}
void Ball::animate(){
	acc =  hit.tick() - 0.0 * vel + grav;
	vel += acc;
	pos += vel;
	
	if (pos.x <= rearLimit.x){
		vel.x = -vel.x * eCoef;
		pos.x = rearLimit.x + (rearLimit.x - pos.x);
	}
	if (pos.x >= foreLimit.x) {
		vel.x = -vel.x * eCoef;
		pos.x = foreLimit.x - (pos.x - foreLimit.x);
	}
	if (pos.y <= rearLimit.y) {
		vel.y = -vel.y * eCoef;
		pos.y = rearLimit.y + (rearLimit.y - pos.y);
	}
	if (pos.y >= foreLimit.y) {
		vel.y = -vel.y * eCoef;
		pos.y = foreLimit.y - (pos.y - foreLimit.y);
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
