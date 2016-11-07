#pragma once

#include "ofMain.h"


class Osc
{
public:
	Osc (float sampleRate) : sr(sampleRate) {
		ang = 0;
		angDelta = 0;
		p = 0.8;
	}
	void setFreq(float newFreq){
		const double cyclesPerSample = newFreq / sr;
		angDelta = cyclesPerSample * PIx2;
	}
	void setGain(float newGain){
		gain = newGain;
	}
	
	void excite(){
		magn = 1;
	}
	
	void setPole(float newPole){
		p = newPole;
	}

	float tick(){
		double currentSample = magn;
		magn = (magn > 0.00001 ? currentSample * p : 0);
		std::cout<<"Mag: "<<currentSample<<std::endl;
		
		ang += angDelta;
		if(ang > PIx2)
			ang -= PIx2;
		
		return currentSample * std::sin(ang) * gain;;
		
	}
private:
	const double PIx2 = M_PI * 2;
	float sr;
	
	float freq;
	float gain;
	float magn;
	float ang;
	float angDelta;
	float p;
	
};

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	void audioIn(float *input, int bufferSize, int nChan);
	void audioOut(float *input, int bufferSize, int nChan);
	
private:
	ofSoundStream inStream;
	ofSoundStream outStream;
	
	int sampleRate, nChan;
	float vol;
	Osc* osc;
	
};
