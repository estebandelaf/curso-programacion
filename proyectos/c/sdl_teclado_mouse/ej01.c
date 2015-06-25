#include "ej01.h"

int main (int argc, char **argv) {

	// variables
	SDL_Surface *screen; // pantalla
	SDL_Event event; // para los eventos de SDL (teclado y/o mouse)
	Uint8 *keystates = SDL_GetKeyState(NULL); // para detectar teclas mantenidas presionadas
	Uint8 salir = 0; // para determinar cuando se cierra la ventana
	int mouse_x=0, mouse_y=0; // coordenadas del mouse
	char info1[100]; // texto para mostrar informacion variada linea 1
	char info2[100]; // texto para mostrar informacion variada linea 2

	SDL_Rect objeto = (SDL_Rect) { 0, 0, 32, 32 }; // x, y, w, h
	/*SDL_Rect objeto;
	objeto.x = 0;
	objeto.y = 0;
	objeto.w = 32;
	objeto.h = 32;*/
	SDL_Rect background = (SDL_Rect) { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; // x, y, w, h

	// inicializar sistema
	sdl_init(&screen);
	// cargar fuente
	TTF_Font *fuente = ttf_load(FONT_NAME, FONT_SIZE, FONT_STYLE);

	// ciclo infinito para refrescar la imagen de la pantalla
	while (!salir) {
		// revisar si existen eventos de SDL
		while (SDL_PollEvent(&event)) {
			// salir del programa
			if(event.type==SDL_QUIT) salir = 1;
			// si se presiona una tecla
			else if(event.type==SDL_KEYDOWN) {
				// cambiar a pantalla completa
				if(event.key.keysym.sym==SDLK_f) SDL_WM_ToggleFullScreen(screen);
				// salir del juego
				else if(event.key.keysym.sym==SDLK_ESCAPE) salir = 1;
			}
			// si se mueve el mouse
			else if(event.type==SDL_MOUSEMOTION) {
				// guardar coordenadas del mouse
				mouse_x = event.motion.x;
				mouse_y = event.motion.y;
			}
			// si se presiona el mouse
			else if(event.type == SDL_MOUSEBUTTONDOWN ) {
				// guardar coordenadas del mouse
				mouse_x = event.button.x;
				mouse_y = event.button.y;
				// si se presiono el boton izquierdo
				if(event.button.button==SDL_BUTTON_LEFT) {
// 					Mix_PlayChannel(-1, pj->primary->sound, 0);
				}
				// si se presiono el boton derecho
				else if(event.button.button==SDL_BUTTON_RIGHT) {
					
				}
			}
		}
		// mover cuadrado
		// mover hacia arriba
		if(keystates[SDLK_UP]||keystates[SDLK_w]) {
			objeto.y -= 10;
			if(objeto.y<0)
				objeto.y=0;
		}
		// mover hacia abajo
		else if(keystates[SDLK_DOWN]||keystates[SDLK_s]) {
			objeto.y += 10;
			if((objeto.y+32)>SCREEN_HEIGHT)
				objeto.y=SCREEN_HEIGHT-32;
		}
		// mover hacia la izquierda
		else if(keystates[SDLK_LEFT]||keystates[SDLK_a]) {
			objeto.x -= 10;
				if(objeto.x<0) objeto.x=0;
		}
		// mover hacia la derecha
		else if(keystates[SDLK_RIGHT]||keystates[SDLK_d]) {
			objeto.x += 10;
			if((objeto.x+32)>SCREEN_WIDTH) objeto.x=SCREEN_WIDTH-32;
		}
		// limpiar
		SDL_FillRect(screen, &background, SDL_MapRGBA(screen->format,0,0,0,0));
		// primera linea informacion
		sprintf(info1, "[info1] mouse: (%04d,%04d)", mouse_x, mouse_y);
		sdl_printf(screen, info1, 10, 0, fuente, (SDL_Color) {255,255,255,0});
		// segunda linea informacion
		sprintf(info2, "[info2] mouse: (%04d,%04d)", mouse_x, mouse_y);
		sdl_printf(screen, info2, 10, 12, fuente, (SDL_Color) {255,255,255,0});
		// dibujar cuadrado
		SDL_FillRect(screen, &objeto, SDL_MapRGBA(screen->format,255,0,255,0));
		// actualizar screen sdl
		SDL_Flip(screen);
		SDL_Delay(1000/FPS);
	}

	// cerrar fuentes
	TTF_CloseFont(fuente);
	TTF_Quit();

	// cerrar SDL
	SDL_FreeSurface(screen);
	SDL_Quit();

	// retorno del sistema
	return EXIT_SUCCESS;

}
