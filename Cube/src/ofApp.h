#pragma once

#include "ofMain.h"
#include "Generator.hpp"
#include "Wall.hpp"
#include "Ball.hpp"
#include "Lights.hpp"
#include "ofxSuddenMotion.h"

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
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
	
	ofxSuddenMotion sms;
	
	Wall* wall;
//	Tile* testTile;
	Ball ball;
	
	const int numTiles = 8;
	
	float fr;
	int sampleRate;
	int nChan;
	int bufSize;
	
	ofSoundStream inStream;
	ofSoundStream outStream;
};
