#pragma once

#include "ofMain.h"
#include "Generator.hpp"
#include "Wall.hpp"
#include "Ball.hpp"
#include "Waveform.hpp"
#include "FFTDraw.h"
#include "GenLights.hpp"
#include "Reverb.h"
#include "ofxSuddenMotion.h"



//--------------------------------------------------------------------------//
//							Preprocessor definitions						//
//--------------------------------------------------------------------------//

#define SR				44100	// sample rate
#define FR				30		// frame Rate;
#define NUM_CHAN		2		// number of channels
#define BUF_SIZE		512		// number of frames in a buffer

//--------------------------------------------------------------------------//
//									Application								//
//--------------------------------------------------------------------------//

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void audioIn(float *input, int bufferSize, int nChan);
	void audioOut(float *input, int bufferSize, int nChan);

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);

private:
	ofVec3f pos;
	ofVec3f ang;
	
	// booleans for test purposes
	
	bool bWall = true;
	bool bBall = true;
	bool bWaveform = true;
	bool bFft = true;
	bool bGenLights = true;
	bool bStream = true;
	bool bSms = true;
	bool bAdjustPos = true;
	
	Wall* wall;
	Ball* ball;
	Waveform* waveform;
	FFTDraw* fft;
	
	float **audioBuf;
	Reverb reverb;
	MapUI reverbParams;
	
	GenLights* genLights;
	
	ofSoundStream stream;
	ofxSuddenMotion sms;
	
	
	const float baseDim = 530;
	const int numTiles = 8;
	
	
	bool bypass = false;
	int timer = 0;
	int timeLapse = 500;
	
	float speed = 1;
	
	
};
