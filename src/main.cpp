#include <window.h>
#include <player.h>

int main(){
  Window w;
  Player p;
  SDL_Event e;
  while(!w.quit){
    
    while(SDL_PollEvent(&e)){
      if(e.type==SDL_QUIT){
        w.quit = true;
      }else if(e.type == SDL_KEYDOWN){
        p.input(e);
      }
    }
    
    w.clear();
    p.update();
    p.draw(w.ren);
    SDL_RenderPresent(w.ren);
  }
  
  return 0;
}