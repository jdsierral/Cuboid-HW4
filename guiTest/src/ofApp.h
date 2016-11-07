#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Hit
{
public:
	Hit(){
		p = 0.8;
	}
	void excite(ofVec3f newDir, float newMag) {
		setDir(newDir);
		setMag(newMag);
	}
	
	void excite() {
		setDir(ofVec3f(ofRandom(1), ofRandom(1), ofRandom(1)));
		setMag(ofRandom(100));
		
	}
	
	void setDir(ofVec3f newDir){
		dir = newDir.getNormalized();
	}
	
	void setMag(float newMag){
		mag = newMag;
	}
	
	void setPole(float newPole){
		p = newPole;
	}
	
	ofVec3f tick(){
		double currentSample = mag;
		mag = (mag > 0.00001 ? currentSample * p : 0);
		std::cout<<"Mag: "<<currentSample<<std::endl;
		return currentSample * dir;
	}
	
	ofVec3f dir;
	float mag;
	float p;
};

class Ball
{
public:
	Ball(){
		grav.set(0, 1, 0);
		radi = 50;
		col = ofColor(255);
		acc.set(0,0,0);
		vel.set(0,0,0);
		setPos(ofVec3f(0,0,0));
	}
	
	void setLimits(float baseDim) {
		rearLimit.set(ofVec3f(-baseDim/2.f + radi,
							  -baseDim/2.f + radi,
							  -baseDim/2.f + radi));
		foreLimit.set(ofVec3f(baseDim/2.f - radi,
							  baseDim/2.f - radi,
							  baseDim/2.f - radi));
	}
	
	void setLimits(ofPoint newRearLimit, ofPoint newForeLimit) {
		rearLimit.set(ofVec3f(newRearLimit.x + radi,
							  newRearLimit.y + radi,
							  newRearLimit.z + radi));
		foreLimit.set(ofVec3f(newForeLimit.x - radi,
							  newForeLimit.y - radi,
							  newForeLimit.z - radi));
	}
	
	void setPos(ofVec3f newPos) {
		float newX;
		float newY;
		float newZ;
		
		newX = min(max(rearLimit.x, newPos.x), foreLimit.x);
		newY = min(max(rearLimit.x, newPos.y), foreLimit.x);
		newZ = min(max(rearLimit.x, newPos.z), foreLimit.x);
		
		pos.set(newX, newY, newZ);
	}
	
	void display(){
		ofSetColor(col);
		ofDrawSphere(pos, radi);
	}
	void animate(){
		acc =  hit.tick() - 0.0 * vel + grav;
		vel += acc;
		pos += vel;
		
		if (pos.x <= rearLimit.x){
			vel.x = -vel.x * eCoef;
			pos.x = rearLimit.x + (rearLimit.x - pos.x);
		}
		if (pos.x >= foreLimit.x) {
			vel.x = -vel.x * eCoef;
			pos.x = foreLimit.x - (pos.x - foreLimit.x);
		}
		if (pos.y <= rearLimit.y) {
			vel.y = -vel.y * eCoef;
			pos.y = rearLimit.y + (rearLimit.y - pos.y);
		}
		if (pos.y >= foreLimit.y) {
			vel.y = -vel.y * eCoef;
			pos.y = foreLimit.y - (pos.y - foreLimit.y);
		}
		if (pos.z <= rearLimit.z) {
			vel.z = -vel.z * eCoef;
			pos.z = rearLimit.z + (rearLimit.z - pos.z);
		}
		if (pos.z >= foreLimit.z) {
			vel.z = -vel.z * eCoef;
			pos.z = foreLimit.z - (pos.z - foreLimit.z);
		}
	}
	
	ofVec3f grav;
	ofVec3f pos;
	ofVec3f vel;
	ofVec3f acc;
	Hit hit;
	
	ofPoint rearLimit;
	ofPoint foreLimit;
	
	ofVec3f force;
	
	ofColor col;
	float radi;
	
	float eCoef = 0.95;
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
		void mouseScrolled(int x, int y, float scrollX, float scrollY);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
	ofxPanel gui;
	ofxFloatSlider levelSlider;
	ofxToggle muteToggle;
	
	ofVec3f ang;
	
	ofColor col[5];
	
	bool drawBool = true;
	bool perspective = true;
	bool drawBottom = true;
	bool bDrawLights = true;
	
	
	
	
	float baseDim = 580;
	float posZ = 0;

	Ball ball;
	
	
	ofLight pointLight;
	
};


