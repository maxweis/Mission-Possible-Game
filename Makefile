WINDOWS_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows

OUTPUT=exec

all:
	clang src/*.c -std=c11 -o $(OUTPUT) -lm -lSDL2 -lSDL2_image -lSDL2_ttf
windows:
	mv dlls/* ./
	rm dlls -d
	i686-w64-mingw32-gcc src/*.c -std=c11 -o $(OUTPUT).exe $(WINDOWS_FLAGS)
