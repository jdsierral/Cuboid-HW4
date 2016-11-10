declare name "Fm Synthesizer";
declare author "Juan Sierra";

//===		Library Import		===//
import("stdfaust.lib");
//===	  Sliders to be Used	===//

//===		FM Oscilator		===//
carFreq = nentry("carfreq", 440, 20, 20000, 1);
modRatio = nentry("modRatio", 2, 1, 10, 1);
modGain = nentry("modGain", 5, 0, 1000, 1);

//===		 Envelope			===//
attack  = nentry("att", 1,0, 1000, 1);
release = nentry("rel",200, 1, 2000, 1);

mainGain = nentry("gain", 0.1, 0, 1, 0.01) : si.smoo;
mainGate = button("gate");

//===		 FM array			===//
freqList = (carFreq, carFreq * modRatio);

process = vgroup("Gen", gen * env * mainGain) with {
    // Generator //
    gen = sy.fm(freqList, modGain);
    // Envelope //
    env = vgroup("Env", en.ar(attack/1000, release/1000, mainGate));
};



