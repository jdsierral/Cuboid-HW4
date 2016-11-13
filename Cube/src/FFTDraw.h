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
#include "ofxFft.h"
///Users/JuanS/Developer/OF/OF-Rep/addons/ofxFft/src/ofxFft.h
class FFTDraw {
public:
	FFTDraw(int bufSize, int baseDim) : bufSize(bufSize), baseDim(baseDim){
		fft = ofxFft::create(bufSize, OF_FFT_WINDOW_HAMMING);
		signal.resize(bufSize);
		audioBins.resize(fft->getBinSize());
	}
	
	void update() {
		fft->setSignal(&signal[0]);
		float* curFft = fft->getAmplitude();
		for (int i = 0; i < fft->getBinSize(); i++) {
			audioBins[i] = fftGain * curFft[i];
		}
	}
	
	void display(){
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(-ofGetWidth(), 24, -261);
		ofSetColor(ofColor(7,195,213, 20));
		int numBins = fft->getBinSize();
		for (int i = 0; i < numBins; i++) {
			ofDrawRectangle(i * 2 * ofGetWidth()/(float)numBins, 0, 0, ofGetWidth()/(float)numBins, audioBins[i]);
			ofDrawRectangle(i * 2 * ofGetWidth()/(float)numBins, 0, 0, ofGetWidth()/(float)numBins, -audioBins[i]);
		}
		ofPopMatrix();
		ofPopStyle();
	}
	
	void setSignal(float *newSignal){
		for (int i = 0; i < bufSize; i++) {
			signal[i] = (newSignal[i] + newSignal[2*i+1]);
		}
	}
	
	void setGain(float newGain) {
		fftGain = newGain;
	}
	
	void setPos(ofVec3f newPos){
		pos = newPos;
	}
	
private:
	vector<float> signal, audioBins;
	int bufSize;
	float baseDim;
	float fftGain;
	ofVec3f pos;
	ofxFft* fft;
};

#endif /* FFTDraw */
