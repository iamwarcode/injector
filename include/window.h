#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window{
  private:
    SDL_Window *window;
    
  public:
    Window();
    ~Window();
    void clear();
    bool quit;
    SDL_Renderer *ren;
};
    
#endif
  