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
#include "OnePoleLPF.h"
#include "Faust/FmOsc.h"

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
	void switchState();
	
	void setState(bool newState);
	
	void display();
	
	//============================================================//
	
	void setPitch(float newNoteNum);
	void setAttack(float attackInMs);
	void setRelease(float releaseInMs);
	void setModRatio(float modRatio);
	void setModGain(float modGain);
	void setGain(float gainInDb);
	void setPan(float pan);

	
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
	
	FmOsc fmOsc;
	MapUI oscParams;
	
	float** audioBuf;
	
	OnePoleLPF alphaFilter;
	
	
	///Gen/Env/att
	///Gen/Env/gate
	///Gen/Env/rel
	///Gen/carfreq
	///Gen/gain
	///Gen/modGain
	///Gen/modRatio
};

#endif /* Tile_hpp */
