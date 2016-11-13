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
	
	void display() {
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(-ofGetWidth(), 24, -261);
		ofSetLineWidth(3);
		ofNoFill();
		ofColor lineColor = ofColor(7,195,213, 100);
		ofSetColor(lineColor);
		ofBeginShape();
		
		for (int i = 0; i < bufSize; i++){
			ofVertex(i * 2 * ofGetWidth()/(float)bufSize, waveFormGain * signal[i], 0);
		}
		ofEndShape(false);
		
		lineColor.setBrightness(10);
		ofSetColor(lineColor);
		ofBeginShape();
		float delta = 3;
		for (int i = 0; i < bufSize; i++){
			ofVertex(delta + i * 2 * ofGetWidth()/(float)bufSize,delta + waveFormGain * signal[i], -delta);
		}
		ofEndShape(false);
		
		ofPopMatrix();
		ofPopStyle();
	}
	
	void setSignal(float *newSignal){
		for (int i = 0; i < bufSize; i++) {
			signal[i] = (newSignal[i] + newSignal[2*i+1]) * waveFormGain;
		}
	}
	
	void setGain(float newGain) {
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
