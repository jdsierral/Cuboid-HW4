//
//  Tile.cpp
//  mySketch
//
//  Created by Juan David Sierra on 11/1/16.
//
//

#include "Tile.hpp"


Tile::Tile() {
	float newState = ofRandom(-1, 1);
	state = (newState > 0 ? true : false );
	setColor(ofColor(200, 50, 200));
	setPos(ofVec3f(0, 0, 0));	
}

Tile::~Tile() {
	
}


void Tile::setPos(ofVec3f newPos){
	pos = newPos;
}

void Tile::setAng(ofVec3f newAng){
	ang = newAng;
}

void Tile::setDim(ofVec3f newDim){
	dim = newDim;
}

void Tile::setColor(ofColor newCol){
	colOn = newCol;
	colOff = colOn.getInverted();
	//Check better relation for aesthetical purposes
	
}
void Tile::setOn(){
	state = true;
}
void Tile::setOff(){
	state = false;
}
void Tile::setState(bool newState){
	if (newState != state)
		state = newState;
}


ofVec3f Tile::getPos(){
	return pos;
}
ofVec3f Tile::getAng(){
	return ang;
}
ofColor Tile::getColor(){
	return colOn;
}
bool Tile::getState(){
	return state;
}


void Tile::display(){
	if (state) {
		drawBox(pos, dim, ang, colOn);
	} else {
		drawBox(pos, dim, ang, colOff);
	}
}

//==============================================================================

void Tile::drawBox(ofVec3f pos, ofVec3f dim, ofVec3f ang, ofColor col){
	ofPushMatrix();
	ofTranslate(pos);
	ofSetColor(col);
	ofDrawBox(0, 0, 0, dim.x, dim.y, dim.z);
	ofPopMatrix();
}
