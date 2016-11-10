#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	
	bufferSize = 512;
	
	sampleRate = 44100;
	nChan = 2;
	
	audioBuf = new float*[2];
	audioBuf[0] = new float[bufferSize];
	audioBuf[1] = new float[bufferSize];
	
	outStream.printDeviceList();
	if (bInternalSpeakers) {
		inStream.setDeviceID(0);
		inStream.setup(this, 0, nChan, sampleRate, bufferSize, 2);
		outStream.setDeviceID(1);
		outStream.setup(this, nChan, 0, sampleRate, bufferSize, 2);
	} else {
		outStream.setDeviceID(7);
		outStream.setup(this, nChan, nChan, sampleRate, bufferSize, 2);
	}
	
	
	ofSetFrameRate(30);
	
	
	sinOsc.init(sampleRate);
	sinOsc.buildUserInterface(&ui);
	
	for(int i=0; i < ui.getParamsCount(); i++){
		std::cout << ui.getParamAdress(i) << "\n";
	}
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
//	vol = 0;
//	for (int i = 0; i < bufferSize; i++) {
//		vol += fabs(input[2*i]);
//		vol += fabs(input[2*i+1]);
//	}
//	vol /= 2 * bufferSize + 1;
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	
	if (true) {
		sinOsc.compute(bufferSize, NULL, audioBuf);
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]   = audioBuf[0][i];
			output[2*i+1] = output[2*i];
		}
	} else {
		for (int i = 0; i < bufferSize; i++) {
			output[2*i] = ofRandom(-1, 1);
			output[2*i+1] = output[2*i];
		}
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case 'x':
			ui.setParamValue("/SinOsc/on", 1);
			break;
		case 'z':
			ui.setParamValue("/SinOsc/on", 0);
			break;
		default:
			break;
	}
	std::cout<<ui.getParamValue("/SinOsc/freq")<<std::endl;
	std::cout<<ui.getParamValue("/SinOsc/gain")<<std::endl;
	std::cout<<ui.getParamValue("/SinOsc/gate")<<std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	ui.setParamValue("/SinOsc/freq", x);
	ui.setParamValue("/SinOsc/gain",(float)y/(float)ofGetHeight());
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
