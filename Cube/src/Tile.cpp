//
//  Tile.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Tile.hpp"


Tile::Tile() {
	float newState = ofRandom(-1, 1);
	state = (newState > 0 ? true : false);
	setColor(ofColor(200, 50, 200));
	setPos(ofVec3f(0, 0, 0));
	
	sawOsc.init(sampleRate);
	sawOsc.buildUserInterface(&oscParams);
	
	audioBuf = new float*[2];
	audioBuf[0] = new float[bufferSize];
	audioBuf[1] = new float[bufferSize];
}

Tile::~Tile(){}


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

void Tile::setOn(){
	state = true;
	oscParams.setParamValue("/0x00/adsr/gate", 1);
}

void Tile::setOff(){
	state = false;
	oscParams.setParamValue("/0x00/adsr/gate", 0);
}

void Tile::setState(bool newState){
	if (newState != state)
		state = newState;
	oscParams.setParamValue("/0x00/adsr/gate", (state? 1 : 0));
}

void Tile::display(){
	if (state) {
		drawBox(pos, dim, ang, colOn);
	} else {
		drawBox(pos, dim, ang, colOff);
	}
}


void Tile::setPitch(float newNoteNum){
	float newFreq = 440 * powf(2, (newNoteNum - 69)/12);
	oscParams.setParamValue("/0x00/freq", newFreq);
}

void Tile::setAttack(float attackInMs){
	oscParams.setParamValue("/0x00/adsr/att", attackInMs);
}
void Tile::setRelease(float releaseInMs){
	oscParams.setParamValue("/0x00/adsr/rel", releaseInMs);
}
void Tile::setModRatio(float modRatio){
	oscParams.setParamValue("/0x00/osc/modRatio", modRatio);
}
void Tile::setModGain(float modGain){
	oscParams.setParamValue("/0x00/osc/modGain", modGain);
}


void Tile::computeAudio(float *buf, int bufSize, int nChan){
	sawOsc.compute(bufSize, NULL, audioBuf);
	for (int i = 0; i < bufSize; i++) {
		buf[2*i]	+= audioBuf[0][i];
		buf[2*i+1]  += audioBuf[0][i];
	}
}


//==============================================================================

void Tile::drawBox(ofVec3f pos, ofVec3f dim, ofVec3f ang, ofColor col){
	ofPushMatrix();
	ofTranslate(pos);
	ofSetColor(col);
	ofDrawBox(dim.x/2, dim.y/2, 0, dim.x, dim.y, dim.z);
	ofPopMatrix();
}
