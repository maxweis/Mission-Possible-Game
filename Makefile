WINDOWS_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows -municode -mwin32

OUTPUT=exec

windows:
	gcc src/*.c -std=c11 -o $(OUTPUT).exe $(WINDOWS_FLAGS)
all:
	clang src/*.c -std=c11 -o $(OUTPUT) -lm -lSDL2 -lSDL2_image -lSDL2_ttf
