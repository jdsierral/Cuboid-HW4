//
//  Lights.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#ifndef Lights_hpp
#define Lights_hpp

#include <stdio.h>
#include "ofMain.h"

class GenLights
{
public:
	GenLights(){
		ofEnableLighting();
		pointLight.setPointLight();
		pointLight.setDiffuseColor( ofColor(195,254,0));
		pointLight.setSpecularColor( ofColor(255));
		pointLight.setGlobalPosition(500, 300, 400);
		pointLight.setPointLight();
		pointLight.enable();

		
		directionalLight.setDiffuseColor(ofColor(65, 148, 255));
		directionalLight.setSpecularColor(ofColor(255));
		directionalLight.setDirectional();
		directionalLight.setOrientation(ofVec3f(180, 0, 0));
		directionalLight.enable();
		
		
		spotLight1.setDiffuseColor( ofColor(255,173,47));
		spotLight1.setSpecularColor( ofColor(255.f, 255.f, 255.f));
		spotLight1.setSpotlight();
		spotLight1.setSpotlightCutOff( 50 );
		spotLight1.setSpotConcentration( 45 );
		spotLight1.setOrientation(ofVec3f(-85, -161, 235));
		spotLight1.setPosition(-256, 254, 187.7);
		spotLight1.enable();
		
		ambientLight.setDiffuseColor(ofColor(255));
		
	}
	
	~GenLights(){
	}
	
	void draw(){
		ofSetGlobalAmbientColor(ofColor(75));
		ofPushMatrix();
		ofPopMatrix();
	}
	
	void setPos (ofVec3f newPos) {
		pos = newPos;
	}
	
	void setAng (ofVec3f newAng) {
		ang = newAng;
	}

private:
	
	ofLight pointLight;
	ofLight spotLight1;
	ofLight directionalLight;
	ofLight ambientLight;
	ofVec3f pos;
	ofVec3f ang;
	
	
};

#endif /* Lights_hpp */
