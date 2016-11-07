//
//  Generator.cpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#include "Generator.hpp"


Osc::Osc (float sampleRate) : sr(sampleRate) {
	ang = 0;
	angDelta = 0;
	p = 0.999;
}
void Osc::setFreq(float newFreq){
	const double cyclesPerSample = newFreq / sr;
	angDelta = cyclesPerSample * PIx2;
}
void Osc::setGain(float newGain){
	gain = newGain;
}

void Osc::excite(){
	magn = 1;
}

void Osc::setPole(float newPole){
	p = newPole;
}

float Osc::tick(){
	double currentSample = magn;
	magn = (magn > 0.00001 ? currentSample * p : 0);
	ang += angDelta;
	if(ang > PIx2)
		ang -= PIx2;
	return currentSample * std::sin(ang) * gain;
}
