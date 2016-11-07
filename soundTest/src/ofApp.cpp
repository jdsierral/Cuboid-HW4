#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	
	int bufferSize = 512;
	
	sampleRate = 44100;
	nChan = 2;
	
	inStream.printDeviceList();//??
	inStream.setDeviceID(0);
	inStream.setup(this, 0, nChan, sampleRate, bufferSize, 2);
	outStream.setDeviceID(1);
	outStream.setup(this, nChan, 0, sampleRate, bufferSize, 2);
	
	ofSetFrameRate(30);
	
	osc = new Osc(sampleRate);
	osc->setFreq(1000);
	osc->setGain(0.3);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawCircle(ofRandom(ofGetWidth()),
				 ofRandom(ofGetHeight()),
				 ofRandom(vol) * ofRandom(1000));
}

//==============================================================
void ofApp::audioIn(float *input, int bufferSize, int nChan){
	vol = 0;
	for (int i = 0; i < bufferSize; i++) {
		vol += fabs(input[2*i]);
		vol += fabs(input[2*i+1]);
	}
	vol /= 2 * bufferSize + 1;
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	for (int i = 0; i < bufferSize; i++) {
		output[2*i] = osc->tick();
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
	float noteInterval = 2 * x/ofGetWidth();
	osc->setFreq(400 * noteInterval);
	osc->excite();
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
