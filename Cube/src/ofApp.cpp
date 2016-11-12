#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(FR);
	ofEnableDepthTest();
	
	wall = new Wall(numTiles * 4, numTiles, BUF_SIZE);
	ball = new Ball(wall);
	
	wall->setSize(ofVec2f(baseDim * 4, baseDim));
	wall->setCol(200);
	
	ball->setLimits(baseDim, numTiles);
	ball->setCol(ofColor(255, 0, 0));
	
	waveform = new Waveform(BUF_SIZE, baseDim);
	waveform->setWaveformGain(40);
	
	genLights = new GenLights();
	
	sms.setupHardware();
	sms.setVerbose(true);
	sms.setValueMode(OFX_SM_SCALED);
	sms.setSmoothPct(0.9);
	
	ofBackground(200);
	
	int AudioInterface = 0;
	
	// 0 is Default.
	// 1 is Internal Speakers and Mic.
	// 7 is Motu on my system.
	
	switch (AudioInterface) {
		case 0:
			break;
		case 1:
			stream.printDeviceList();
			stream.setDeviceID(1);
			break;
		case 2:
			stream.printDeviceList();
			stream.setDeviceID(7);
			break;
			
		default:
			break;
	}
	
	stream.setup(this, NUM_CHAN, 0, SR, BUF_SIZE, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
	sms.readMotion();
	if (ofGetFrameRate() != 0) {
		if (!(ofGetElapsedTimeMillis() < timer)){
			wall->tick();
			timer += timeLapse;
		}
	}
	
	ofPoint accPoint = sms.getSmoothedXYZ()/100;
	ball->setGravity(ofPoint(-accPoint.x, accPoint.z, accPoint.y));
	ball->animate();
}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofTranslate(pos);
//	ofRotateX(ang.y);
//	ofRotateY(ang.x);
//	ofRotateZ(ang.z);
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		ball->display();
		ofSetColor(200);
		ofDrawBox(0, 0, -baseDim/2, baseDim, baseDim, 1);
		ofRotateX(-90);
		wall->display();
	ofPopMatrix();
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		waveform->setPos(pos);
		waveform->drawWaveform();
		genLights->draw();
	ofPopMatrix();
}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	if (!bypass) {
		wall->computeAudio(output, bufferSize, nChan);
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]	  /= 20.f;
			output[2*i+1] /= 20.f;
			if (output[2*i] > 1) {
				std::cout<<"SampleClipped"<<std::endl;
			}
		}
		waveform->setWaveform(output);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case ' ':
			ball->checkPosition();
			break;
		default:
			break;
	}

	std::cout<<"Mouse: "<<pos<<std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	pos.x = x - ofGetWidth()/2.f;
	pos.y = y - ofGetHeight()/2.f;
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

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY ){
	pos.z += scrollY;
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
