#pragma once

#include "ofMain.h"
#include "Generator.hpp"
#include "Wall.hpp"
#include "Ball.hpp"
#include "Lights.hpp"
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
	
	bool mouseBool;
	bool bDummyGUI;
	
	ofxSuddenMotion sms;
	
	Wall* wall;
	Ball* ball;
	
	float baseDim = 530;
	const int numTiles = 8;
	
	float fr;
	int sr;
	
	int nChan;
	int bufSize;
	float fact = 20;
	
	ofSoundStream inStream;
	ofSoundStream outStream;
	
	bool bypass = false;
	int ellapsedSeconds = 0;
};
