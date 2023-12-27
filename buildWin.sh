#!/bin/bash
rm *.o

echo "Compiling..."
gcc -c src/*.c -I include
gcc *.o -o TowerHackWin.exe -lncurses

echo "Run program? (1/0)"
read user

if [[ user -eq "1" ]] ; then
  ./TowerHackWin.exe
fi
