//
//  Generator.hpp
//  Cube
//
//  Created by Juan David Sierra on 11/7/16.
//
//

#ifndef Generator_hpp
#define Generator_hpp

#include <stdio.h>
#include "Math.h"

class Osc
{
public:
	Osc (float sampleRate);
	
	void setFreq(float newFreq);
	
	void setGain(float newGain);
	
	void excite();
	
	void setPole(float newPole);
	
	float tick();
	
private:
	
	const double PIx2 = M_PI * 2;
	float sr;
	
	float freq;
	float gain;
	float magn;
	float ang;
	float angDelta;
	float p;
	
};

#endif /* Generator_hpp */
