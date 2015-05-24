all:
	clang src/*.c -o exec -lm -lSDL2 -lSDL2_image
