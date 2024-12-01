#!/bin/bash

mkdir day$1
cd day$1

touch input.txt
cp ../template/starter.cpp ./sol1.cpp 
cp ../template/starter.cpp ./sol2.cpp 
cp ../template/run.sh ./run.sh
chmod +x run.sh
