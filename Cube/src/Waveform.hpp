//
//  Waveform.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/11/16.
//
//

#ifndef Waveform_hpp
#define Waveform_hpp

#include <stdio.h>
#include "ofMain.h"

class Waveform
{
public:
	Waveform(int bufSize, int baseDim) : bufSize(bufSize), baseDim(baseDim){
		signal.resize(bufSize, 0);
	}
	
	~Waveform();
	void drawWaveform() {
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(-263, 24, -261);
		ofSetLineWidth(3);
		ofNoFill();
		
		ofSetColor(7,195,213);
		ofBeginShape();
		
		for (int i = 0; i < bufSize; i++){
			ofVertex(i*baseDim/(float)bufSize, waveFormGain * signal[i], 0);
		}
		ofEndShape(false);
		
		ofPopMatrix();
		ofPopStyle();
	}
	
	void setWaveform(float *newSignal){
		for (int i = 0; i < bufSize; i++) {
			signal[i] = (newSignal[i] + newSignal[2*i+1])*waveFormGain;
		}
	}
	
	void setWaveformGain(float newGain) {
		waveFormGain = newGain;
	}
	
	void setPos(ofVec3f newPos) {
		pos = newPos;
	}
	
private:
	
	vector<float> signal;
	int bufSize;
	float baseDim;
	float waveFormGain;
	ofVec3f pos;
	
	
};

#endif /* Waveform_hpp */
