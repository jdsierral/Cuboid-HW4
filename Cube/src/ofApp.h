#pragma once

#include "ofMain.h"
#include "Generator.hpp"
#include "Wall.hpp"
#include "Ball.hpp"
#include "Waveform.hpp"
#include "GenLights.hpp"
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
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	void mouseScrolled(int x, int y, float scrollX, float scrollY );
	
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	ofVec3f pos;
	ofVec3f ang;
	
	bool bWall = true;
	bool bBall = true;
	bool bWaveform = true;
	bool bGenLights = true;
	bool bStream = true;
	bool bSms = true;
	
	Wall* wall;
	Ball* ball;
	Waveform* waveform;
	GenLights* genLights;
	
	ofSoundStream stream;
	ofxSuddenMotion sms;
	
	
	const float baseDim = 530;
	const int numTiles = 8;
	
	
	bool bypass = false;
	int timer = 0;
	int timeLapse = 500;
	
	
};
