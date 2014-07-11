#include <SDL.h>
#include <SDL_render.h>
#include <window.h>

int main(){  
  Window w;
  while(!w.quit){
    w.Event();
    w.Render();
  }
  return 0;
}