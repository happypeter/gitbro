#!/bin/bash
make clean
qmake -project
qmake 
make
echo "you want to run it? [y] or [n]?"
read h
 if [ "$h" = "y" ]; then
#Beaware of the spaces above
./reader
else
echo bye
fi
