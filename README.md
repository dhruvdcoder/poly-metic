# README #


### What is this repository for? ###

* A library for polynomial arithmetic and related algorithms which are used in kinematics of Robot Manipulators. 
* Version: 1.0

### How do I get set up? ###

1. Clone the repo

2. Use the Makefile to build

* Directory structure

	include/	: The header files (.hpp) and template implementation files (.ipp)
	
	src/ 		: The cpp/implementation files
	
	doc/		: The doxygen configureation files.
	
	bin/		: The files in this directory are ignore by git. Used to keep the executables
	
	obj/		: The files in this directory are ignore by git. Used to keep .o and other temporary files
	
	snippets/	: Specific vim snippets. Can be ignore if not using vim and snipmate plugin
	
* Dependencies : google-test (if you wish to build the tests), GMP if you wish to use integers, rationals and variable precision reals as the field for the polynomials. 

### Who do I talk to? ###

* Please mail me at dhruvdplayer@gmail.com for questions
