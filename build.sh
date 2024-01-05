#!/bin/bash
rm *.o

echo "Compiling..."
gcc -c src/*.c -I include -g
gcc *.o -o TowerHack -lncurses

echo "Run program? (1/0)"
read user

if [[ user -eq "1" ]] ; then
  ./TowerHack
fi
