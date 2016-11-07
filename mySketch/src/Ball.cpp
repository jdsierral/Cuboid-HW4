//
//  Ball.cpp
//  mySketch
//
//  Created by Juan David Sierra on 11/6/16.
//
//

#include "Ball.hpp"





Ball::Ball(float newRadi)
: radi(newRadi)
{
}

Ball::~Ball(){
}

void Ball::setPos(ofVec3f newPos){
	pos = newPos;
}
void Ball::setVel(ofVec3f newVel){
	vel = newVel;
}
void Ball::setAcc(ofVec3f newAcc){
	acc = newAcc;
}

void Ball::setCol(ofColor newCol){
	col = newCol;
}

void Ball::setECoef(float newECoef){
	eCoef = newECoef;
}

ofVec3f Ball::getPos(){
	return pos;
}

ofVec3f Ball::getVel(){
	return vel;
}
ofVec3f Ball::getAcc(){
	return acc;
}

ofColor Ball::getCol(){
	return col;
}

void Ball::animate(){
	vel += acc;
	pos += vel;
}
void Ball::display(){
	ofSetColor(col);
	ofDrawSphere(pos.x, pos.y, pos.z, radi);
}
