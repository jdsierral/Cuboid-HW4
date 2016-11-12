#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	wall = new Wall(numTiles * 4, numTiles);
	ball = new Ball();
	
	wall->setSize(ofVec2f(baseDim * 4, baseDim));
	wall->setCol(200);
	
	ball->setLimits(baseDim);
	ball->setCol(ofColor(255, 0, 0));
	
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
	
	ofEnableDepthTest();
	ofBackground(200);
}

//--------------------------------------------------------------
void ofApp::update(){
	sms.readMotion();
	if (ofGetFrameRate() != 0) {
		if (ellapsedSeconds != ofGetSeconds()){
			ellapsedSeconds = ofGetSeconds();
			wall->tick();
		}
	}
	
	ofPoint accPoint = sms.getSmoothedXYZ()/100;
	ball->setGravity(ofPoint(-accPoint.x, accPoint.z, accPoint.y));
	ball->animate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
	ball->display();
	ofTranslate(pos);
	ofRotateX(ang.y);
	ofRotateY(ang.x);
	ofRotateZ(ang.z);
	ofSetColor(200);
	ofDrawBox(0, 0, -baseDim/2, baseDim, baseDim, 1);
	ofRotateX(90);
	wall->display();
	ofPopMatrix();
}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	if (!bypass) {
		wall->computeAudio(output, bufferSize, nChan);
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]	  /= 256;
			output[2*i+1] /= 256;
		}
	} else {
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]	  *= 0.05;
			output[2*i+1] *= 0.05;
			if (output[2*i] > 1) {
				std::cout<<"SampleClipped"<<std::endl;
			}
		}
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

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY ){
	wall->testPos.z += scrollY;
	wall->testRot += scrollX;
	
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
