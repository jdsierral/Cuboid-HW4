#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	// Setting up general values;
	
	ofSetVerticalSync(true);
	ofSetFrameRate(FR);
	ofEnableDepthTest();
	ofEnableAntiAliasing();
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofEnableLighting();
	
	// initializing wall and ball;
	
	wall = new Wall(numTiles * 4, numTiles, BUF_SIZE);
	ball = new Ball(wall);
	wall->setSize(ofVec2f(baseDim * 4, baseDim));
	ball->setLimits(baseDim, numTiles);
	ofColor ballCol = ofColor(195,254,0);
	ballCol.setBrightness(100);
	ball->setCol(ofColor(ballCol));
	
	// initilizing metering graphics
	waveform = new Waveform(BUF_SIZE, ofGetWidth());
	waveform->setGain(30);
	fft = new FFTDraw(BUF_SIZE, baseDim);
	fft->setGain(600000);
	
	// Initializing lights
	
	genLights = new GenLights();
	sms.setupHardware();
	sms.setVerbose(true);
	sms.setValueMode(OFX_SM_SCALED);
	sms.setSmoothPct(0.9);
	ofBackground(44);
	
	// Audio setup to get Default..
	// could get specific values for testing purposes
	
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
	
	// Audio Buf for faust processing;
	
	audioBuf = new float*[2];
	audioBuf[0] = new float[BUF_SIZE];
	audioBuf[1] = new float[BUF_SIZE];
	
	//Reverb Init
	
	reverb.init(SR);
	reverb.buildUserInterface(&reverbParams);
	
	for (int i = 0; i < reverbParams.getParamsCount(); i++) {
		std::cout<<reverbParams.getParamAdress(i)<<std::endl;
	}
	
	reverbParams.setParamValue("/Zita_Rev1/Output/Dry/Wet_Mix", -0.25);
	reverbParams.setParamValue("/Zita_Rev1/Output/Level", 0);
	
	// Audio Stream setup;
	
	stream.setup(this, NUM_CHAN, 0, SR, BUF_SIZE, 2);
}


//--------------------------------------------------------------
void ofApp::update(){
	
	// Get Values required every frame;
	// Check SMS sudden Motion Sensor
	
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
	
	// Animate ball
	ball->animate();
	// update fft;
	fft->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// Simplistic drawing method moving every process to dedicated
	// classes
	
	// Draw Sphere, Lights, Osc, and FFT
	// Booleans are available for testing purposes
	
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		ofSetColor(80);
		ofDrawSphere(0, 0, 0, 1200);
		if (bGenLights) genLights->draw();
		if (bWaveform) waveform->display();
		if (bFft)  fft->display();
	ofPopMatrix();
	
	// Draw ball and wall
	
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2.f, ofGetHeight()/2.f);
		if (bBall) ball->display();
		if (bWall) wall->display();
	ofPopMatrix();
}

void ofApp::audioIn(float *input, int bufferSize, int nChan){
}

void ofApp::audioOut(float *output, int bufferSize, int nChan){
	
	// Audio Processing with its own boolean
	
	if (bStream) {
		
		// The wall itself has the the generators... so compute audio
		
		wall->computeAudio(output, bufferSize, nChan);
		
		// Get buffer and feed it into Faust Buffer
		
		for (int i = 0; i < bufferSize; i++) {
			audioBuf[0][i] = output[2*i];
			audioBuf[1][i] = output[2*i+1];
		}
		
		// Compute Reverb
		
		reverb.compute(bufferSize, audioBuf, audioBuf);
		
		// Reconvert buffer to meet OF standard... check for overloading
		
		for (int i = 0; i < bufferSize; i++) {
			output[2*i]	  = audioBuf[0][i] / 20.f;
			output[2*i+1] = audioBuf[1][i] / 20.f;
			if (output[2*i] > 1) {
				std::cout<<"SampleClipped"<<std::endl;
			}
		}
		
		// feed signal to waveform drawer and fft

		if (bWaveform) waveform->setSignal(output);
		if (bFft) fft->setSignal(output);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// logic to manage booleans NOT REQUIRED FOR RELEASE
	
//	switch (key) {
//		case '1':
//			bWall = !bWall;
//			std::cout<<"Wall Changed"<<std::endl;
//			break;
//		case '2':
//			bBall = !bBall;
//			std::cout<<"Ball Changed"<<std::endl;
//			break;
//		case '3':
//			bWaveform = !bWaveform;
//			std::cout<<"Waveform Changed"<<std::endl;
//			break;
//		case '4':
//			bFft = !bFft;
//			std::cout<<"FFT Changed"<<std::endl;
//			break;
//		case '5':
//			bGenLights = !bGenLights;
//			if (bGenLights) ofEnableLighting();
//			else ofDisableLighting();
//			std::cout<<"GenLights Changed"<<std::endl;
//			break;
//		case '6':
//			bStream = !bStream;
//			std::cout<<"Audio Changed"<<std::endl;
//			break;
//		case '7':
//			bSms = !bSms;
//			std::cout<<"SMS Changed"<<std::endl;
//			break;
//		case '8':
//			break;
//		case '9':
//			break;
//		case ' ':
//			bAdjustPos = !bAdjustPos;
//			break;
//		case 'c':
//			std::cout<<"CurPos: "<<pos<<std::endl;
//			std::cout<<"CurAng: "<<ang<<std::endl;
//			break;
//		case OF_KEY_UP :
//			speed *= 2.f;
//			break;
//		case OF_KEY_DOWN:
//			speed *= 0.5;
//			break;
//		default:
//			break;
//	}
	
	// if the user presses \ the ball bounces hard
	
	switch (key) {
  case '\\':
			ball->hit.excite();
			break;
			
  default:
			break;
	}
}

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){
	// ball can also be hitted by pressing mouse;
	ball->hit.excite();
}

