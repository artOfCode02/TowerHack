# TowerHack

## Disclaimer

This project is a work-in-progress for now, so don't expect the game to even be remotely complete.

## About

TowerHack is a rougelike game where you climb the Cursed Tower to get the fabled Book of Gods.
This rougelike is spell based, and it has vertical gameplay (no jumping though).<br>
OSX/macOS and Linux are supported, Windows version isn't supported.

## Build

To build you must:
1. Clone this repo
```shell
git clone https://github.com/artOfCode02/TowerHack.git/
```
3. Go to the directory where you cloned to.
```shell
cd TowerHack
```
4. Run automatic build in your terminal.
```shell
./build.sh
```


If you want to compile manually, run this from top directory:
```shell
gcc -c src/*.c -I include
gcc *.o -o TowerHack -lncurses
```

For Windows, you will have to change the executable name (TowerHack) to 'TowerHackWin'


To run program, while in TowerHack directory, run:
```shell
./build.sh
```
