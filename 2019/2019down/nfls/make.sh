#!/bin/bash
cd ~/Desktop/2019/2019down/c++/nfls
filename="1003"
touch ${filename}.cpp
cp temp.cpp ${filename}.cpp
g++-7 ${filename}.cpp -o ${filename}
