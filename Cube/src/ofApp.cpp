#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	/*
	osc = new Osc(sampleRate);
	osc->setFreq(1000);
	osc->setGain(0.3);
	
	
	ball.setLimits(baseDim);
	
	ofSetSmoothLighting(true); //change;
	pointLight.setDiffuseColor(ofColor(100, 10, 200));
	pointLight.setSpecularColor(ofColor(10, 100, 20));
	
	
	ofPoint smoothed = sms.getSmoothedXYZ();
	*/
	
	inStream.printDeviceList();
	inStream.setDeviceID(0);
	inStream.setup(this, 0, NUM_CHAN, SR, BUF_SIZE, 2);
	outStream.setDeviceID(1);
	outStream.setup(this, NUM_CHAN, 0, SR, BUF_SIZE, 2);
	
	ofSetFrameRate(FR);

	sms.setupHardware();
	sms.setVerbose(true);
	sms.setValueMode(OFX_SM_SCALED);
	sms.setSmoothPct(0.9);
	
	ofPoint smoothed = sms.getSmoothedXYZ();
	
	wall = new Wall(4 * numTiles, numTiles);
	ball = new Ball();
	
	ball->setLimits(baseDim);
	
	wall->setTileSize(ofVec3f(100, 100));
	wall->setCol(250);
	
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	sms.readMotion();
	wall->tick();
	ball->animate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
	ball->display();
	ofRotateX(90);
	wall->display();
	ofPopMatrix();
	
}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	for (int i = 0; i < bufferSize; i++) {
		output[2*i] = 0;//osc->tick();
		output[2*i+1] = output[2*i];
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ball->hit.excite();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
