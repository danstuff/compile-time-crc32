#!/bin/bash

clear

printf "\n ====================================== Building Project... ====================================== \n\n"
cd build
cmake ..
if cmake --build .; then
  cd ..
  ./debug.sh 
fi
