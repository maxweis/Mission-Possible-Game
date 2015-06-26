WINDOWS_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

OUTPUT=exec

windows:
	gcc src/*.c -std=c11 -o $(OUTPUT).exe $(WINDOWS_FLAGS)
all:
	clang src/*.c -std=c11 -o $(OUTPUT) -lm -lSDL2 -lSDL2_image -lSDL2_ttf
