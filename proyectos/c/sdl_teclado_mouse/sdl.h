#ifndef __SDL_H__
#define __SDL_H__

// bibliotecas
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

// definiciones
#define TITLE "Ejemplo SDL"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_BPP 32
#define FPS 100
#define FONT_NAME "data/font/FreeMono.ttf"
#define FONT_SIZE 18
#define FONT_STYLE TTF_STYLE_BOLD

// estructuras

// prototipos
void sdl_init (SDL_Surface **screen);
TTF_Font *ttf_load (char *name, short int size, Uint8 style);
void sdl_printf (SDL_Surface *screen, char *txt, int x, int y, TTF_Font *font, SDL_Color color);

#endif
