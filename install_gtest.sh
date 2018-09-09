#!/bin/bash

sudo apt-get install libgtest-dev

sudo apt-get install cmake # install cmake

cd /usr/src/gtest

sudo cmake -DBUILD_SHARED_LIBS=ON CMakeLists.txt
 
sudo make

sudo cp *.a /usr/lib

sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a

sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a
