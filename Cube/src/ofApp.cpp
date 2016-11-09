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
	
	ofEnableDepthTest();
	
	
	
	wall = new Wall(numTiles * 4, numTiles);
	ball = new Ball();
	
	wall->setSize(ofVec2f(baseDim * 4, baseDim));
	wall->setCol(200);
	
	
	ball->setLimits(baseDim);
	ball->setCol(ofColor(255, 0, 0));
	
	
	ofBackground(200);
	
	
	for (int i = 0; i < 5; i++){
		col[i] = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	sms.readMotion();
	if (ofGetFrameRate() != 0) {
		if (0 == (int)ofGetFrameNum()%(int)ofGetFrameRate()){
			wall->tick();
		}
	}
	ball->animate();
	ofPoint accPoint = sms.getSmoothedXYZ()/100;
	ball->setGravity(ofPoint(-accPoint.x, accPoint.z, accPoint.y));
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
	for (int i = 0; i < bufferSize; i++) {
		output[2*i] = 0;//osc->tick();
		output[2*i+1] = output[2*i];
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	  case 'i':
			pos.y += fact;
			break;
		case 'k':
			pos.y -= fact;
			break;
		case 'l':
			pos.x += fact;
			break;
		case 'j' :
			pos.x -= fact;
			break;
		case 'o':
			pos.z += fact;
			break;
		case 'm':
			pos.z -= fact;
			break;
		case 'e':
			ang.y += fact;
			break;
		case 'd':
			ang.y -= fact;
			break;
		case 's':
			ang.x -= fact;
			break;
		case 'f':
			ang.x += fact;
			break;
		case 'w':
			ang.z += fact;
			break;
		case 'v':
			ang.z -= fact;
			break;
		case ' ':
			mouseBool = !mouseBool;
			break;
		case 'z':
			bDummyGUI = !bDummyGUI;
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
	if (mouseBool) {
		wall->testPos.x = x - ofGetWidth()/2.f;
		wall->testPos.y = y - ofGetHeight()/2.f;
	}
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
