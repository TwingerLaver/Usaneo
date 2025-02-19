#include <SDL2/SDL.h>



class Image : public SDL_Surface, SDL_Rect
{
   SDL_Surface sf;
   SDL_Surface screen;
    void add_suf(int w, int h){
        sf.flags = 0;
        sf.clip_rect = {0,0,0,0}; 
        sf.format = NULL;
        sf.h = h;
        sf.w = w;
        sf.pitch = 0;
        sf.locked = 0;
        
    }
    void drawing_screen(SDL_Surface* surface, int x, int y) {
        SDL_LockSurface(surface);
        SDL_memset(screen.pixels, 255, this->screen.h * this->screen.pitch); 
        SDL_UnlockSurface(surface);
    }
};