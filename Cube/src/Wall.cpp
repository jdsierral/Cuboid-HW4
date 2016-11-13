//
//  Wall.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Wall.hpp"

Wall::Wall(int m, int n, int bufSize): m(m), n(n), bufferSize(bufSize) {
	tilePointer = new Tile[m * n];
	tileBoard = new Tile*[m];
	
	for (int i = 0; i< m; i++){
		tileBoard[i] = &tilePointer[n * i];
	}
	
	int noteArray  []{55, 60, 62, 64, 67, 69, 72, 76};
	int noteArraySize = sizeof(noteArray)/sizeof(int);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (0 == floor((float)i/(float)n)) {
				tileBoard[i][j].setPitch(noteArray[(int)ofRandom(noteArraySize)] + 12 * -1);
				tileBoard[i][j].setAttack  (150);
				tileBoard[i][j].setRelease (800);
				tileBoard[i][j].setModRatio(4);
				tileBoard[i][j].setModGain (ofRandom(20));
				tileBoard[i][j].setGain	   (-12.f);
				tileBoard[i][i].setPan	   (ofRandom(0.0,0.25));
			}
			if (1 == floor((float)i/(float)n)) {
				tileBoard[i][j].setPitch(noteArray[(int)ofRandom(noteArraySize)] + 12 * -2);
				tileBoard[i][j].setAttack  (10);
				tileBoard[i][j].setRelease (800);
				tileBoard[i][j].setModRatio(2);
				tileBoard[i][j].setModGain (20);
				tileBoard[i][j].setGain	   (-8.f);
				tileBoard[i][i].setPan	   (ofRandom(0.33, 0.66));
			}
			if (2 == floor((float)i/(float)n)) {
				tileBoard[i][j].setPitch(noteArray[(int)ofRandom(noteArraySize)] + 12 * -1);
				tileBoard[i][j].setAttack  (150);
				tileBoard[i][j].setRelease (800);
				tileBoard[i][j].setModRatio(5);
				tileBoard[i][j].setModGain (ofRandom(20));
				tileBoard[i][j].setGain	   (-12.f);
				tileBoard[i][i].setPan	   (ofRandom(0.75,1));
			}
			if (3 == floor((float)i/(float)n)) {
				tileBoard[i][j].setPitch(noteArray[(int)ofRandom(noteArraySize)] + 12 * 1);
				tileBoard[i][j].setAttack  (1);
				tileBoard[i][j].setRelease (800);
				tileBoard[i][j].setModRatio(1);
				tileBoard[i][j].setModGain (ofRandom(5));
				tileBoard[i][j].setGain	   (-6.f);
				tileBoard[i][j].setPan	   (0.5);
			}
			tileBoard[i][j].setColorOn (ofColor(206,255,47));
			tileBoard[i][j].setColorOff(ofColor(206,255,47));
		}
	}
}
Wall::~Wall(){
	for (int i = 0; i < m; i++) {
		delete[] tileBoard[i];
	}
	
	delete [] tileBoard;
}

void Wall::setPos(ofVec3f newPos){
	pos = newPos;
}
void Wall::setAng(ofVec3f newAng){
	ang = newAng;
}
void Wall::setCol(ofColor newCol){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tileBoard[i][j].setColorOn(newCol);
		}
	}
}

void Wall::setTileSize(ofVec3f newTileSize){
	tileSize = newTileSize;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tileBoard[i][j].setDim(tileSize);
		}
	}
}

void Wall::setSize(ofVec2f newBaseDim){
	baseDim = newBaseDim;
	setTileSize(ofVec3f(baseDim.x/(float)m, baseDim.y/(float)n, 1));
}

void Wall::switchTileState(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n)
		tileBoard[x][y].switchState();
}

ofVec3f Wall::getPos(){
	return pos;
}
ofVec3f Wall::getAng(){
	return ang;
}
ofColor Wall::getCol(){
	return col;
}

Tile Wall::getTile(int m, int n){
	return tileBoard[m][n];
}

void Wall::display(){
	ofSetColor(col);
//	ofDrawBox(0, 0, -baseDim.x/2, baseDim.x, baseDim.y, 1);
	ofPushMatrix();
	ofRotateX(-90);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (0 == floor((float)i/(float)n)) {
				ofPushMatrix();
				ofTranslate(-baseDim.x/8, -baseDim.y/2, baseDim.y/2);
				ofRotateY(90);
				ofTranslate(tileSize.x * i, tileSize.y * j);
				tileBoard[i][j].display();
				ofPopMatrix();
			}
			
			if (1 == floor((float)i/(float)n)) {
				ofPushMatrix();
				ofTranslate(-3*baseDim.x/8, -baseDim.y/2, -baseDim.y/2);
				ofTranslate(tileSize.x * i, tileSize.y * j);
				tileBoard[i][j].display();
				ofPopMatrix();
			}
			
			if (2 == floor((float)i/(float)n)) {
				ofPushMatrix();
				ofTranslate(baseDim.x/8, -baseDim.y/2, -5*baseDim.y/2);
				ofRotateY(-90);
				ofTranslate(tileSize.x * i, tileSize.y * j);
				tileBoard[i][j].display();
				ofPopMatrix();
			}
			
			if (3 == floor((float)i/(float)n)) {
				ofPushMatrix();
				ofTranslate(7*baseDim.x/8, -baseDim.y/2, baseDim.y/2);
				ofRotateY(180);
				ofTranslate(tileSize.x * i, tileSize.y * j);
				tileBoard[i][j].display();
				ofPopMatrix();
			}
		}
	}
	ofPopMatrix();
}

void Wall::tick(){
	for (int i = 0; i < m-1; i++) {
		for (int j = 0; j < n-1; j++) {
			int state = 0;
			
			if (tileBoard[(i-1+m)%m][(j-1+n)%n].getState())
				state++;
			if (tileBoard[    i    ][(j-1+n)%n].getState())
				state++;
			if (tileBoard[(i+1) % m][    j    ].getState())
				state++;
			if (tileBoard[(i-1+m)%m][    j    ].getState())
				state++;
			if (tileBoard[(i+1) % m][    j    ].getState())
				state++;
			if (tileBoard[(i-1+m)%m][(j+1) % m].getState())
				state++;
			if (tileBoard[    i    ][(j+1) % m].getState())
				state++;
			if (tileBoard[(i+1) % m][(j+1) % m].getState())
				state++;

			if(tileBoard[i][j].getState()) {
				if (state < 2)
					tileBoard[i][j].setOff();
				if (state == 2 || state == 3)
					tileBoard[i][j].setOn();
				if (state > 3)
					tileBoard[i][j].setOff();
			} else {
				if (state == 3)
					tileBoard[i][j].setOn();
			}
		}
	}
}


void Wall::computeAudio(float *output, int bufferSize, int nChan){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tileBoard[i][j].computeAudio(output, bufferSize, nChan);
		}
	}
}
