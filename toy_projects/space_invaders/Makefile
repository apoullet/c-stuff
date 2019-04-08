default: build

build:
	gcc -o spaceinvaders main.c drawing.c calculations.c game.h -lncurses

run: build
	./spaceinvaders && rm spaceinvaders
