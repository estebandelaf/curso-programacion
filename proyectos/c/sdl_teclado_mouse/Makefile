CC="gcc"
CFLAGS="-Wall"

all: ej01

ej01: sdl.o
	$(CC) $(CFLAGS) ej01.c sdl.o -o ej01 -lSDL -lSDL_ttf -lSDL_mixer

sdl.o:

clean:
	rm -f ej01 *.o
