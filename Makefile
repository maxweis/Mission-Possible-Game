all:
	clang src/*.c -std=c11 -o exec -lm -lSDL2 -lSDL2_image
