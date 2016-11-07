#pragma once

#include "ofMain.h"
#include "Wall.hpp"
#include "Ball.hpp"
#include "ofxSuddenMotion.h"

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
private:
	Wall* sWall;
	Wall* nWall;
	Wall* eWall;
	Wall* wWall;
	Tile* testTile;
	Ball* ball;
//	ofEasyCam cam; // add mouse controls for camera movement
	
	ofVec3f pos;
	ofVec3f ang;
	ofLight bulb;
	
	ofxSuddenMotion sms;
	
	float ofMouseDepth = 0;
	
	const int numTiles = 8;
	
	int fr;
	
	bool n0 = true, n1 = true,  n2 = true, n3 = true;
	
};
