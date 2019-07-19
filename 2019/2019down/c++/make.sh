#!/bin/bash
folder=$1
cd ~/Desktop/2019/2019down/c++
# rm -r ${folder}
if [ -d ${folder} ];then
echo "Can't"
else
mkdir ${folder}
cd ${folder}
touch A.cpp
touch B.cpp
touch C.cpp
touch D.cpp
cp ../temp.cpp A.cpp
cp ../temp.cpp B.cpp
cp ../temp.cpp C.cpp
cp ../temp.cpp D.cpp
g++-7 A.cpp -o A
g++-7 B.cpp -o B
g++-7 C.cpp -o C
g++-7 D.cpp -o D
fi