#include <window.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 360    

Window::Window(){
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("injector", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  
  ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  quit=false;
}
    
Window::~Window(){
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Window::clear(){
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
}