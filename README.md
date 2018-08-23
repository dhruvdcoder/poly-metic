
# Polymetic #
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

### What is it? ###

Polymetic is a library for polynomial arithmetic and for arithmetic of matrices with polynomial entries. The need for common subroutines to solve complex computational problems arising in Kinematics of Robot Manipulators inspired the creation of this library. 

Created by [Dhruvesh Patel](dhruveshp.com) under the guidance of [Dr. Bandyopadhyay](https://ed.iitm.ac.in/~sandipan/) at [Robotics Lab](https://www.researchgate.net/lab/Manipulator-Robotics-Group-Robotics-Lab-Engineering-Design-IIT-Madras-Sandipan-Bandyopadhyay), IIT Madras, the project is not under active development currently. However, if you wish to contribute or maintain the project, please contact us.

* It contains the following functionalities at this point:

	1. Univariate polynomial class with addition and multiplication as the supported operations.

	2. Algorithm to find the determinant of a matrix with polynomial entires. ( tested with 20x20 matrix)

* Version: 1.1

### How do I get started? ###

1. Clone the [repository](https://github.com/dhruvdcoder/poly-metic).

2. Install the [dependencies](#Dependencies)

3. Use the Makefile to build

	1. Use `$ make Doc` to build the doxygen documentation of the code. To view the generated doc, open the *index.html* in *doc/html/*
	
	2. Use `$ make Demos` to build the demos
	
	3. Use `$ make Test_MatrixAlgorithms` to build the test for the determinant algorithm. The *test/Test_MatrixAlgorithms_polynomial_double.cpp* shows how one can use the main APIs to find the determinant of a matrix with polynomial entries. 

4. See [online documentation](http://dhruveshp.com/poly-metic) for exhaustive code documentation.

### Directory structure ###

	include/	: The header files (.hpp) and template implementation files (.ipp)
	
	src/ 		: The cpp/implementation files
	
	doc/		: The doxygen configureation files.
	
	bin/		: The files in this directory are ignore by git. Used to keep the executables
	
	obj/		: The files in this directory are ignore by git. Used to keep .o and other temporary files
	
	snippets/	: Specific vim snippets. Can be ignore if not using vim and snipmate plugin
	
### Dependencies ###
	1. google-test: If you wish to build the tests
	2. GMP: If you wish to use integers, rationals and variable precision reals as the field for the polynomials. 
	3. Boost ublas library : To work with matrices with polynomial entires. (http://www.boost.org/doc/libs/1_66_0/libs/numeric/ublas/doc/index.html)
	4. doxygen: To generate the documentation


### Acknowledgements ###

1. [Dr. Bandyopadhyay](https://ed.iitm.ac.in/~sandipan/) : For the conception of the idea, guidance during implementation and provision of required resources. 
    
2. [Vikranth Kattakuri](https://www.linkedin.com/in/vikranth-kattakuri-b2225465/) : The algorithm for finding determinant of matrices with polynomial entries has been adopted from his work as a master's student at IIT Madras. 

3. [Anirban Nag](https://www.linkedin.com/in/anirban-nag-86bb4458/) : For helping in finding relevant references and previous works on the topic.

### Who do I talk to? ###

* Please mail me at dhruvdplayer@gmail.com for any kind of issues faced while setting up the repository
