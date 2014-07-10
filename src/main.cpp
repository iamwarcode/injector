#include <SDL.h>
#include <SDL_render.h>

int main(){
  SDL_Init(SDL_INIT_EVERYTHING);
  
  SDL_Window *window = SDL_CreateWindow("injector", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, 0 );
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Event e;
  
  bool quit = false;
  bool animate_arrow = false;
  
  int arrow_power = 0;
  
  SDL_Color color = {255,255,255,255};
  
  SDL_Rect r = {0,260,640,100};
  SDL_Rect p = {50,180,20,80};
  SDL_Rect q = {590,180,20,80};
  
  SDL_Rect hud = {25,150,75,10};
  SDL_Rect hud_fill = {25, 150, 0, 10};
  
  SDL_Rect arrow = {50,180,20, 20};
  
  while(!quit){
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT){
        quit = true;
      }
      if(e.type == SDL_KEYDOWN){
        if(hud_fill.w < 74){
          hud_fill.w += 2;  
        }
      }
      if(e.type == SDL_KEYUP){
        arrow_power = hud_fill.w;
        hud_fill.w = 0;
        animate_arrow = true;
      }
    }
    
    if(animate_arrow){
      SDL_Delay(200/arrow_power);
      
      arrow.x += 1;
      if(arrow.x <  arrow_power*(320/75)){
        arrow.y -= 1;
      }
      else{
        arrow.y += 1;
      }
      if(arrow.x > arrow_power*(640/75)){
        animate_arrow = false;
        arrow.x = 50;
        arrow.y = 180;
      }
    }
    
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderFillRect(renderer, &r);
    SDL_SetRenderDrawColor(renderer, 0,255,0,255);
    SDL_RenderFillRect(renderer, &p);
    SDL_SetRenderDrawColor(renderer, 0,0,255,255);
    SDL_RenderFillRect(renderer, &q);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderDrawRect(renderer, &hud);
    SDL_RenderFillRect(renderer, &hud_fill);
    SDL_RenderFillRect(renderer, &arrow);
    SDL_RenderPresent(renderer);
    
  }
  
  return 0;
}