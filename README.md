# Cuboid-HW4
256A Fourth Homework Submission


## Summary



This an audiovisual piece composed by the interaccion of the user and the computer's position.
It is based on the famous math game "The Game of Life" by John Conaway. In this game a grid is ruled by specific laws inspired in cell reproduction analysis. Whenever an empty grid is surrounded by three live grids, it borns; whenever there are more than three cells near by a live cell it dies. If there are 2 or 3 cells next to a live cells it keeps living
but if there is only one or no cell nearby a live cell it will die of loneliness. Accordingly in this piece, the grid has its own laws which are not only represented graphically through different colors but through sounds caused every time a cell is born; however they could be easily perturbed or excited by a bouncing ball governed by laws of physics of the real world. Accordingly, the ball itsefl inherits the gravitational field of the real earth so be careful when you move your computer, It will respond to it!. Whenever this pseudoreal ball hits a wall in the cuboid grid, it will instantaneously change the state (live to dead or dead to live) of the corresponding cell creating and destroying at its will.

In the original Game of Live, the ecosystem evolves to more complicated states but at some point it might just crash and cause a massive extinsion; however, whenever the ball is involved, it keeps pushing and moving the ecosystem causing new outbursts of live or dead everytime. The systems keeps making music but without the interaction from the user it might get stucked driven to a stationary ecosystem, keep the computer still to see that happening slowly, but when the ball moves everything starts to shine.

## Usage

Open the application, rise the computer in the air and play with its position. Be careful not to let it drop!
It is also possible to hit the ball by pushing the key  '\' or a mouseClick

## Code Description

The actual project is inside Cuboid!!! The other folders were tests to get to understand differnt parts of the project itslef

The whole project was developed through Open Frameworks using a couple of Add-Ons for the FFT and the Sudden Motion Sensor reader for the MacBook Pro. Keep in mind this add-on uses the IOKit from apple in a 32 bit version; however the one used here was modified to be able to run in a 64 bit environment and keep everything compatible.

The project is divided in two big GUIs and a Sound related part. The Walls and the ball is one of the GUI parts which have a lot of logic and internal laws for when to bounce, how fast, where to fall and how to react to an impact. Inside the wall itself, a class called Tile is used for every square in the grid. This square itself holds the audio generator created in Faust as an FM synthesizer. This means that the software is actually running 256 FmSynthesizers! They are all declared through randomizers to let for spontaneous but structured distribuition of sound properties.

The ball in particular is modeled through real classical physics, having position, speed, acceleration, and external forces such as gravity, an impulsive hit modeled through an exponential function and even friction to avoid static movements in any direction.

Finally the secondary GUI takes care of the lighting the FFT and the osciloscope presented it the back of the figure.

## Example of Use

see this youTube video to check how the project works and sounds ;)

https://youtu.be/9c0S9eRqLmk

## History

Single Commit repo

## Contributing

Created by Juan Sierra
Contributions and greatly appreciated by Megan and Mark

## License

MIT License

Copyright (c) 2016 - Juan Sierra, JuanSaudio

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
