declare name "Sine Synthesizer";
declare author "Juan Sierra";

//===		Library Import		===//
import("stdfaust.lib");
//===	  Sliders to be Used	===//

//===		Saw Oscilator		===//
freq = nentry("freq",440,20,20000,0.01);
gain = nentry("gain",1,0,1,0.01) : si.smoo;
gate = button("gate");

//===		 Envelope			===//
att = nentry("att", 1, 1, 1000, 1);
rel = nentry("rel", 200, 1, 2000, 1);


process = gen * env * gain
with {
	// Generator //
	gen = os.osc(freq);
	// Envelope //
	env = vgroup("adsr", en.ar(att/1000, rel/1000, gate));
};
