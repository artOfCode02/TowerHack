#!/bin/zsh

echo "Compiling..."
gcc -c src/*.c
gcc *.o -o TowerHack -lncurses

echo "Run program? (y/n)"
read user

if [[ user -eq "y" ]]; then
  ./TowerHack
fi
