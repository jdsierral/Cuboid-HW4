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
	}
	
	~GenLights(){
	}
	
	void draw(){
		ofEnableLighting();
		pointLight.enable();
		difuseLight.enable();
		ofFill();
		ofSetColor(difuseLight.getDiffuseColor());
		ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
		ofSetColor(pointLight.getDiffuseColor());
	}

private:
	
	ofLight pointLight;
	ofLight difuseLight;
	
	
};

#endif /* Lights_hpp */
