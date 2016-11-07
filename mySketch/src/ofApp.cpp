#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	
	nWall = new Wall(numTiles, numTiles);
	sWall = new Wall(numTiles, numTiles);
	eWall = new Wall(numTiles, numTiles);
	wWall = new Wall(numTiles, numTiles);
	nWall->setTileSize(ofVec3f(100, 100));
	nWall->setCol(250);
	sWall->setTileSize(ofVec3f(100, 100));
	sWall->setCol(250);
	eWall->setTileSize(ofVec3f(100, 100));
	eWall->setCol(250);
	wWall->setTileSize(ofVec3f(100, 100));
	wWall->setCol(250);
	
	sms.setupHardware();
	sms.setVerbose(false);
	sms.setValueMode(OFX_SM_SCALED);
	sms.setSmoothPct(0.9);
	
	fr = ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::update(){
	nWall->tick();
	sWall->tick();
	eWall->tick();
	wWall->tick();
	pos.set(ofGetMouseX(), ofGetMouseY(), ofMouseDepth);
	
	sms.readMotion();
	
	//get the smoothed data as an ofPoint
	ofPoint smoothed = sms.getSmoothedXYZ();
	
//	printf("smoothed (x,y,z) = ( %2.2f, %2.2f, %2.2f )\n", smoothed.x, smoothed.y, smoothed.z);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	if (n0) {
		ofPushMatrix();
		ofRotateX(-90);
		ofTranslate(ofGetWidth()/4.f, ofGetHeight()/4.f);
		nWall->display();
		ofPopMatrix();
	}
	
	if (n1) {
		ofPushMatrix();
		ofRotateX(90);
		ofTranslate(ofGetWidth()/4.f, 3 * ofGetHeight()/4.f);
		sWall->display();
		ofPopMatrix();
	}
	if (n2) {
		ofPushMatrix();
		ofRotateY(-90);
		ofTranslate(ofGetWidth()/4.f, ofGetHeight()/4.f);
		eWall->display();
		ofPopMatrix();
	}
	
	if (n3) {
		ofPushMatrix();
		ofRotateY(90);
		ofTranslate(3 * ofGetWidth()/4.f, ofGetHeight()/4.f);
		wWall->display();
		ofPopMatrix();
	}
	
	ofPushMatrix();
	ofTranslate(pos);
	ofDrawSphere(0, 0, 0, 30);
	ofPopMatrix();
	
	
	//lets draw a circle that is controlled by x and y
	ofSetHexColor(0);
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
	ofDrawCircle(-3.0 * sms.smoothX, sms.smoothZ * 0.1, 100 + sms.smoothY*0.6);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == ' '){
		sms.storeOffset();
	}else if(key == 'c'){
		sms.clearOffset();
	}
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
