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
#include "Generator.hpp"
#include "SawOsc.h"

class Tile
{
public:
	Tile ();
	~Tile ();
	void setPos(ofVec3f newPos);
	void setAng(ofVec3f newAng);
	void setDim(ofVec3f newDim);
	void setColor(ofColor newCol);
	
	ofVec3f getPos();
	ofVec3f getAng();
	ofColor getColor();
	
	bool getState();
	void setOn();
	void setOff();
	void setState(bool newState);
	
	void display();
	
	//============================================================//
	
	void setPitch(float newNoteNum);
	void setAttack(float attackInMs);
	void setRelease(float releaseInMs);
	void setModRatio(float modRatio);
	void setModGain(float modGain);

	
	void computeAudio(float *buf, int bufSize, int nChan);
	
private:
	
	void drawBox(ofVec3f pos, ofVec3f dim, ofVec3f ang, ofColor col);
	
	ofBoxPrimitive box;
	ofVec3f dim; //dimensions;
	ofVec3f pos; //position
	ofVec3f ang; //angle
	ofColor colOn; //colors
	ofColor colOff;
	bool state; //on and off states
	
	//============================================================//
	int bufferSize = 512;
	int sampleRate = 44100;
	
	SawOsc sawOsc;
	MapUI oscParams;
	
	float** audioBuf;
	
//	/0x00/freq
//	/0x00/gain
//	/0x00/adsr/att
//	/0x00/adsr/gate
//	/0x00/adsr/rel
};

#endif /* Tile_hpp */
