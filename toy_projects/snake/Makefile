default: build

build: main.c drawing.c calculations.c
	gcc -o snake main.c drawing.c calculations.c -lncurses

run: build
	./snake && rm snake
