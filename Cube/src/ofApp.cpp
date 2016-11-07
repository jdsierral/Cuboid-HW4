#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//	bufSize = 512;
//	sampleRate = 44100;
//	nChan = 2;
//	
//	inStream.printDeviceList();//??
//	inStream.setDeviceID(0);
//	inStream.setup(this, 0, nChan, sampleRate, bufSize, 2);
//	outStream.setDeviceID(1);
//	outStream.setup(this, nChan, 0, sampleRate, bufSize, 2);
//	
//	ofSetFrameRate(30);
//	
//	osc = new Osc(sampleRate);
//	osc->setFreq(1000);
//	osc->setGain(0.3);
//	
//	
//	ball.setLimits(baseDim);
//	
//	ofSetSmoothLighting(true); //change;
//	pointLight.setDiffuseColor(ofColor(100, 10, 200));
//	pointLight.setSpecularColor(ofColor(10, 100, 20));
//	
//	sms.setupHardware();
//	sms.setVerbose(false);
//	sms.setValueMode(OFX_SM_SCALED);
//	sms.setSmoothPct(0.9);
//	
//	fr = ofGetFrameRate();
//	
//	ofPoint smoothed = sms.getSmoothedXYZ();
//	ofBackground(0);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){

	sms.readMotion();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
	//	vol = 0;
	//	for (int i = 0; i < bufferSize; i++) {
	//		vol += fabs(input[2*i]);
	//		vol += fabs(input[2*i+1]);
	//	}
	//	vol /= 2 * bufferSize + 1;
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
