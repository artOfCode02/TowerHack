#!/bin/zsh

echo "Compiling..."
gcc -c src/*.c
gcc *.o -o TowerHack -lncurses

echo "Run program? (1/0)"
read user

if [[ user -eq "1" ]]; then
  ./TowerHack
fi
