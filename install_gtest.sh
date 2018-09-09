#!/bin/bash

sudo apt-get install libgtest-dev

sudo apt-get install cmake # install cmake

cd /usr/src/gtest

sudo cmake -DBUILD_SHARED_LIBS=ON CMakeLists.txt
 
sudo make

sudo cp *.so /usr/lib

sudo ln -s /usr/lib/libgtest.so /usr/local/lib/libgtest.so

sudo ln -s /usr/lib/libgtest_main.so /usr/local/lib/libgtest_main.so
