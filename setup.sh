#! /bin/bash

for fileno in $1
do 
   cp ~/Projects/CP/boilers/boiler_cpp.cpp ${fileno + 'A'}.cpp
done
