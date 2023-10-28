#!bin/zsh

echo "Compiling..."
gcc src/*.c -lncurses
touch TowerHack
gcc *.o -o TowerHack

echo "Want to play? (y/n)"
read user

if [[ user -eq "y" ]]; then
  ./TowerHack
fi
