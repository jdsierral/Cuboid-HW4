#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(FR);
	ofEnableDepthTest();
//	ofEnableSmoothing();
//	ofEnableAntiAliasing();
	ofEnableAlphaBlending();
//	ofSetSmoothLighting(true);
//	ofSetSphereResolution(20);
	
	wall = new Wall(numTiles * 4, numTiles, BUF_SIZE);
	ball = new Ball(wall);
	
	wall->setSize(ofVec2f(baseDim * 4, baseDim));
	
	ball->setLimits(baseDim, numTiles);
	ball->setCol(ofColor(150));
	
	waveform = new Waveform(BUF_SIZE, baseDim);
	waveform->setWaveformGain(40);
	
	fftDraw = new FFTDraw(BUF_SIZE, baseDim);
	fftDraw->setWaveformGain(40);
	
	genLights = new GenLights();
	
	sms.setupHardware();
	sms.setVerbose(true);
	sms.setValueMode(OFX_SM_SCALED);
	sms.setSmoothPct(0.9);
	
	ofBackground(44);
	
	int AudioInterface = 1;
	
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

void ofApp::exit(){
//	delete [] wall;
//	delete [] ball;
//	delete [] waveform;
//	delete [] genLights;
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
	
	if (bSms) {
		ofPoint accPoint = sms.getSmoothedXYZ()/100;
		ball->setGravity(ofPoint(-accPoint.x, accPoint.z, accPoint.y));
	}
	ball->animate();
	
	genLights->setPos(pos);
}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofTranslate(pos);
//	ofRotateX(ang.y);
//	ofRotateY(ang.x);
//	ofRotateZ(ang.z);
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		if (bBall) ball->display();
		if (bWall) wall->display();
	ofPopMatrix();
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		if (bWaveform) waveform->drawWaveform();
		if (bGenLights) genLights->draw();
		else ofDisableLighting();

	ofPopMatrix();
}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	if (bStream) {
		wall->computeAudio(output, bufferSize, nChan);
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]	  /= 20.f;
			output[2*i+1] /= 20.f;
			if (output[2*i] > 1) {
				std::cout<<"SampleClipped"<<std::endl;
			}
		}
		if (bWaveform) waveform->setWaveform(output);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case '1':
			bWall = !bWall;
			std::cout<<"Wall Changed"<<std::endl;
			break;
		case '2':
			bBall = !bBall;
			std::cout<<"Ball Changed"<<std::endl;
			break;
		case '3':
			bWaveform = !bWaveform;
			std::cout<<"Waveform Changed"<<std::endl;
			break;
		case '4':
			bGenLights = !bGenLights;
			std::cout<<"GenLights Changed"<<std::endl;
			break;
		case '5':
			bStream = !bStream;
			std::cout<<"Audio Changed"<<std::endl;
			break;
		case '6':
			bSms = !bSms;
			std::cout<<"SMS Changed"<<std::endl;
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
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
