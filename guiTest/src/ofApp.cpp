#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(levelSlider.setup("levelSlider", 0, -60, 12));
	gui.add(muteToggle.setup("muteToggle", false));
	
	ofEnableDepthTest();
	ofSetupScreenPerspective();
	ofSetupScreenOrtho();
	
	
	for (int i = 0; i < 5; i++){
		col[i] = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	}
	
	ang.set(0, 0, 0);
	
	ball.setLimits(baseDim);
	
	ofSetSmoothLighting(true); //change;
	pointLight.setDiffuseColor(ofColor(100, 10, 200));
	pointLight.setSpecularColor(ofColor(10, 100, 20));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	pointLight.setPosition(ofGetMouseX(), ofGetMouseY(), posZ);
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableLighting();
	pointLight.enable();
	ofPushMatrix();
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	
	if(bDrawLights) {
		ofFill();
		ofSetColor(pointLight.getDiffuseColor());
		pointLight.draw();
	}


	
	if (drawBool) {
		ofRotateY(ang.x);
		ofRotateX(ang.y);
		ofRotateZ(ang.z);
		
		
		ofPushMatrix();
		ofTranslate(+baseDim/2.f, 0);
		ofRotateY(90);
		ofSetColor(col[0]);
		ofDrawBox(0, 0, 0, baseDim, baseDim, 1);
		ofPopMatrix();
		
		ofPushMatrix();
		ofTranslate(-baseDim/2.f, 0);
		ofRotateY(90);
		ofSetColor(col[1]);
		ofDrawBox(0, 0, 0, baseDim, baseDim, 1);
		ofPopMatrix();
		
		ofPushMatrix();
		ofTranslate(0, +baseDim/2.f);
		ofRotateX(90);
		ofSetColor(col[2]);
		ofDrawBox(0, 0, 0, baseDim, baseDim, 1);
		ofPopMatrix();
		
		ofPushMatrix();
		ofTranslate(0, -baseDim/2.f);
		ofRotateX(90);
		ofSetColor(col[3]);
		ofDrawBox(0, 0, 0, baseDim, baseDim, 1);
		ofPopMatrix();
		
		if (drawBottom) {
			ofPushMatrix();
			ofTranslate(0, 0, -baseDim/2.f);
			ofRotateX(0);
			ofSetColor(col[4]);
			ofDrawBox(0, 0, 0, baseDim, baseDim, 1);
			ofPopMatrix();
		}
	}
	ball.animate();
	ball.display();
	ofPopMatrix();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case ' ':
			drawBool = !drawBool;
			break;
		case '8':
			ang.y++;
			break;
		case '2':
			ang.y--;
			break;
		case '6':
			ang.x++;
			break;
		case '4':
			ang.x--;
			break;
		case '9':
			ang.z++;
			break;
		case '7':
			ang.z--;
			break;
		case 'a':
			perspective = !perspective;
//			if (perspective)
//				ofSetupScreenPerspective();
//			else
//				ofSetupScreenOrtho();
//			break;
		case 'b':
			drawBottom = !drawBottom;
			break;
		default:
			break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ball.hit.excite();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){
	posZ += scrollY;
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
