//
//  Tile.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Tile.hpp"


Tile::Tile() {
	state = false;
	setPos(ofVec3f(0, 0, 0));
	
	fmOsc.init(sampleRate);
	fmOsc.buildUserInterface(&oscParams);
	
	audioBuf = new float*[2];
	audioBuf[0] = new float[bufferSize];
	audioBuf[1] = new float[bufferSize];
	
	alphaFilter.setExciteVal(255);
	alphaFilter.setPole(0.95);
	oscParams.setParamValue("/Gen/Env/gate", 0);
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

void Tile::setColorOn(ofColor newCol){
	colOn = newCol;
}

void Tile::setColorOff(ofColor newCol){
	colOff = newCol;
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
	if(state == false) {
		state = true;
		oscParams.setParamValue("/Gen/Env/gate", 1);
		alphaFilter.excite();
	}
}

void Tile::setOff(){
	if (state == true) {
		state = false;
		oscParams.setParamValue("/Gen/Env/gate", 0);
	}
}

void Tile::switchState(){
	state = !state;
	oscParams.setParamValue("/Gen/Env/gate", (state ? 1 : 0));
	if (state)
		alphaFilter.excite();
}

void Tile::setState(bool newState){
	if (newState != state)
		state = newState;
	oscParams.setParamValue("/Gen/Env/gate", (state? 1 : 0));
	if (state)
		alphaFilter.excite();
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
	oscParams.setParamValue("/Gen/carfreq", newFreq);
}

void Tile::setAttack(float attackInMs){
	oscParams.setParamValue("/Gen/Env/att", attackInMs);
}
void Tile::setRelease(float releaseInMs){
	oscParams.setParamValue("/Gen/Env/rel", releaseInMs);
}
void Tile::setModRatio(float modRatio){
	oscParams.setParamValue("/Gen/modRatio", modRatio);
}
void Tile::setModGain(float modGain){
	oscParams.setParamValue("/Gen/modGain", modGain);
}
void Tile::setGain(float gainInDb){
	oscParams.setParamValue("/Gen/gain", powf(10, gainInDb/20));
}

void Tile::setPan(float pan){
	oscParams.setParamValue("/Gen/pan", pan);
}


void Tile::computeAudio(float *buf, int bufSize, int nChan){
	fmOsc.compute(bufSize, NULL, audioBuf);
	for (int i = 0; i < bufSize; i++) {
		buf[2 * i]	+= audioBuf[0][i];
		buf[2*i+1]  += audioBuf[1][i];
	}
}


//==============================================================================

void Tile::drawBox(ofVec3f pos, ofVec3f dim, ofVec3f ang, ofColor col){
	ofPushMatrix();
	ofTranslate(pos);
	col.setBrightness(alphaFilter.tick((state ? 200 : 20)));
	ofSetColor(col);
	ofDrawEllipse(dim.x/2.f, dim.y/2.f, 0, dim.x, dim.y);
	ofPopMatrix();
}


