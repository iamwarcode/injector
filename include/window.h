#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>

class Window{
  private:
    SDL_Window *window;
    SDL_Renderer *ren;
    SDL_Texture *image;
  public:
    Window();
    ~Window();
    void Event();
    void Render();
    bool quit;
};
    
#endif
  