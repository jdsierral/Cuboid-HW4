//
//  Header.h
//  Cube
//
//  Created by Juan David Sierra on 11/12/16.
//
//

#ifndef FFTDraw_h
#define FFTDraw_h

#include "ofMain.h"

class FFTDraw {
public:
	FFTDraw(int bufSize, int baseDim) : bufSize(bufSize), baseDim(baseDim){
		signal.resize(bufSize, 0);
	}
	
	~FFTDraw(){
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(-263, 60, -261);
		ofSetLineWidth(3);
		ofNoFill();
		
		ofSetColor(7,195,213);
		ofBeginShape();
		
		for (int i = 0; i < bufSize; i++){
			ofVertex(i*baseDim/(float)bufSize, fftGain * signal[i], 0);
		}
		ofEndShape(false);
		
		ofPopMatrix();
		ofPopStyle();
	};
	
	void setFFTVector(float *newSignal){
		for (int i = 0; i < bufSize; i++) {
			signal[i] = (newSignal[i] + newSignal[2*i+1])*fftGain;
		}
	}
	
	void draw(){}
	void setPos(ofVec3f newPos){
		pos = newPos;
	}
	
	void setWaveformGain(float newGain) {
		fftGain = newGain;
	}
	
	void setPosition(ofVec3f newPos) {
		pos = newPos;
	}
private:
	ofVec3f pos;
	vector<float> signal;
	int bufSize;
	float baseDim;
	float fftGain;
};

#endif /* FFTDraw */
