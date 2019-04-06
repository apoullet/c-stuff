default: build

build: main.c drawing.c calculations.c
	gcc -o snake main.c drawing.c calculations.c -lncurses

clean:
	rm snake

run: build
	./snake && rm snake
