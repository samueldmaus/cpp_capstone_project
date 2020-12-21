# wxWidgets Calculator - Udacity C++ Nanodegree Capstone Project

## Description
This is my capstone project for the Udacity C++ Nanodegree Program. This calculator was built using wxWidgets for the graphical user interface.
The calculator has two modes, "Standard" or "Scientific". The standard mode will ignore order of operations and performs calculations going from
left to right. The scientific mode will perform operations according to the rules of order of operations, including the use of '()' to force precedence on certain
calculations. The mode of the calculator can be switched in the file menu under the 'type' submenu by selecting either 'standard' or 'scientific'. The modes are modeled after the 'standard' and 'scientific' modes currently available on the calculator application in Windows 10.

## Screenshots
![basecalc](/imgs/base_calc.png)
![equationcalc](/imgs/equation_calc.png)

## Dependencies
* cmake >= 3.11
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* wxWidgets >= 3.0
  * Linux: `sudo apt-get install libwxgtk3.0-dev libwxgtk3.0-0v5-dbg`
  * Mac: There is a [homebrew installation available](https://formulae.brew.sh/formula/wxmac).
  * Installation instructions can be found [here](https://wiki.wxwidgets.org/Install). Some version numbers may need to be changed in instructions to install v3.0 or greater.

## Build Instructions
1. Clone this repo.
2. Make a build repo in the top level directory using: `mkdir build && cd build`
3. Compile using: `cmake .. && make`
4. Run using: `./capstone`

## Rubric Points Addressed
1. The project demonstrates an understanding of C++ functions and control structures -- All Files
2. The project accepts user input and processes the input -- app_gui.cpp: 59-63, 87-92
3. The project uses Object Oriented Programming techniques -- All Files
4. The project uses multithreading -- app_gui.cpp: 109-119 && stack.cpp: 5-16
5. A promise and future is used in the project -- app_gui.cpp; 109-119 && stack.cpp: 5-16
6. A mutex or lock is used in the project -- app.gui: 88

## Support
If you have suggestions or questions, please email me at samueldmaus@gmail.com