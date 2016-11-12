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
//		pointLight.setDiffuseColor(ofColor(255));
		pointLight.setDiffuseColor(ofColor(255));
		pointLight.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
		pointLight.setSpecularColor( ofColor(255.f, 255.f, 0.f));
		pointLight.setPointLight();
		
		directionalLight.setDiffuseColor(ofColor(0.f, 0.f, 255.f));
		directionalLight.setSpecularColor(ofColor(255.f, 255.f, 255.f));
		directionalLight.setDirectional();
		
		// set the direction of the light
		// set it pointing from left to right -> //
		directionalLight.setOrientation( ofVec3f(0, 90, 0) );
		
		pointLight.enable();
		spotLight.enable();
		directionalLight.enable();
	}
	
	~GenLights(){
	}
	
	void draw(){
		ofPushMatrix();
		ofTranslate(pos);
		ofEnableLighting();
		pointLight.enable();
		ofFill();
		pointLight.draw();
		spotLight.draw();
		directionalLight.draw();
		ofPopMatrix();
	}
	
	void setPos (ofVec3f newPos) {
		pos = newPos;
	}

private:
	
	ofLight pointLight;
	ofLight spotLight;
	ofLight directionalLight;
	ofVec3f pos;
	
	
};

#endif /* Lights_hpp */
