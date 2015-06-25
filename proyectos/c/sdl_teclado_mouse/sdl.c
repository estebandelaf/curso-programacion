#include "sdl.h"

/**
 * Inicializa los componentes a utilizar de SDL y crea la pantalla
 */
void sdl_init (SDL_Surface **screen) {
	// inicializar SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) {
		printf("No fue posible inicializar SDL\n");
		exit(EXIT_FAILURE);
	}
	// colocar titulo
	SDL_WM_SetCaption(TITLE, NULL);
	// inicializar ttf
	if (TTF_Init()==-1) {
		printf("No fue posible inicializar TTF: %s \n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	// inicializar sonido
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096 )==-1) {
		printf("No fue posible inicializar el sonido\n");
		exit(EXIT_FAILURE);
	}
	// crear pantalla
	*screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if(screen==NULL) {
		printf("No fue posible inicializar la pantalla\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * Carga una fuente TTF
 */
TTF_Font *ttf_load (char *name, short int size, Uint8 style) {
	TTF_Font *fuente = TTF_OpenFont(name, size);
	if(fuente==NULL) {
		printf("Fallo al abrir la fuente %s\n", name);
		exit(EXIT_FAILURE);
	}
	// estilo de la fuente
	TTF_SetFontStyle(fuente, style);
	return fuente;
}

/**
 * Escribir texto en la pantalla
 */
void sdl_printf (SDL_Surface *screen, char *txt, int x, int y, TTF_Font *font, SDL_Color color) {
	// crear superficie con el texto
	SDL_Surface *surface = TTF_RenderText_Blended(font, txt, color);
	// crear rectangulo donde se ubicara la superficie (no se ocupa ni ancho ni alto, por eso son 0s)
	SDL_Rect rect = (SDL_Rect) {x, y, 0, 0};
	// dibujar en la pantalla
	SDL_BlitSurface(surface, NULL, screen, &rect);
	// liberar superficie
	SDL_FreeSurface(surface);
}

SDL_Surface *image_load(const char *file) {

        SDL_Surface* loadedImage = NULL; //Temporary storage for the image that's loaded
        SDL_Surface* optimizedImage = NULL; //The optimized image that will be used

	loadedImage = SDL_LoadBMP( file ); //Load the image
    
        // If nothing went wrong in loading the image
        if( loadedImage != NULL ) {
                // Create an optimized image
                optimizedImage = SDL_DisplayFormat( loadedImage );
                // Free the old image
                SDL_FreeSurface( loadedImage );
        }
        
        // Return the optimized image
        return optimizedImage;

}

void surface_apply( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
        //Make a temporary rectangle to hold the offsets
        SDL_Rect offset;
    
        //Give the offsets to the rectangle
        offset.x = x;
        offset.y = y;
    
        //Blit the surface
        SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface *image_create(unsigned char *src, int w, int h) {

        /// revisar lazyfoo.net capitulo 31
        /// obtener pixel (x,y): pixels[ ( y * surface->w ) + x ];
        /// http://www.libsdl.org/cgi/docwiki.cgi/SDL_CreateRGBSurface

        SDL_Surface *image;
        int i,j,bpp;
        Uint32 *pixels,color;
        
        image = SDL_CreateRGBSurface( SDL_SWSURFACE, w, h, 32, 0, 0, 0, 0 );
        pixels = (Uint32*) calloc(w*h,sizeof(Uint32));
        bpp = 16;
        j=0; // contador para recorrer el arreglo src
        
        for(i=0;i<w*h;i++) {
                if(bpp==8) { color = src[j]; j += 1; }
                if(bpp==16) { color = src[j]<<8 | src[j+1]; j += 2; }
                if(bpp==24) { color = src[j]<<16 | src[j+1]<<8 | src[j+2]; j += 3; }
                if(bpp==32) { color = src[j]<<24 | src[j+1]<<16 | src[j+2]<<8 | src[j+3]; j += 4; }
                pixels[i] = color;
        }
        
        image->pixels = (int*) pixels;
        
        return image;
        
}

Uint32 get_pixel32( SDL_Surface *surface, int x, int y) {
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel) {
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}
