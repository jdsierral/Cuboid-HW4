/*
 ==============================================================================
 
 OnePoleLPF.h
 Created: 22 Oct 2016 11:12:34am
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#ifndef ONEPOLELPF_H_INCLUDED
#define ONEPOLELPF_H_INCLUDED

class OnePoleLPF{
private:
	float delay,p, input, exciteVal;
	
public:
	OnePoleLPF():delay(0.0),p(0.0){}
	
	// set the smoothing (pole)
	
	void setPole(float newPole){
		p = newPole;
	}
	
	void setExciteVal(float newExciteVal){
		exciteVal = newExciteVal;
	}
	
	// compute one sample
	float tick(float newInput){
		input = newInput;
		float currentSample = input * (1.0-p);
		currentSample = currentSample + delay;
		delay = currentSample * p;
		return currentSample;
	}
	
	float tick() {
		float currentSample = input;
		input = (input > 0.0001 ? currentSample * p : 0);
		return currentSample;
	}
	
	void excite(){
		input = exciteVal;
	}
};


class ValueFilter{
public:
	ValueFilter() : delay(0.0), p(0.99), value(0) {
	}
	
	ValueFilter(float newVal) : delay(0.0), p(0.99), value(newVal) {
	}
	
	// set the smoothing (pole)
	void setPole(double newPole){
		p = newPole;
	}
	
	void set(double newValue) {
		value = newValue;
	}
	
	// compute one sample
	double tick(){
		double currentSample = value * (1.0 - p);
		currentSample = currentSample + delay;
		delay = currentSample * p;
		return currentSample;
	}
	
	// gets current value without computing smoothing
	double get(){
		return value;
	}
	
private:
	double delay, p, value;
};




#endif  // ONEPOLELPF_H_INCLUDED
