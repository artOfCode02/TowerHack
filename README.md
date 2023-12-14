# TowerHack

## Disclaimer

This project is a work-in-progress for now, so don't expect the game to even be remotely complete.

As of now, there is no Windows support, we will add this later after development is done.

## About

TowerHack is a rougelike game where you climb the Cursed Tower to get the fabled Book of Gods.
This rougelike is spell based, and it has vertical gameplay (no jumping though).

## Build

To build you must:
1. Clone this repo
```shell
git clone https://github.com/artOfCode02/TowerHack/TowerHack.git/
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

To run program, while in TowerHack directory, run:
```shell
./build.sh
```

## Contribute

To contribute to this repository, you must:
1. Fork this repo
2. Make main branch
3. Commit to main branch
4. Open up a pull request and wait for changes to be accepted.

## Closing
Have fun developing (or playing)!
