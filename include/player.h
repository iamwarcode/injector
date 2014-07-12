#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>    
#include <iostream>
class Player{
  private:
    int xVel, yVel;
    SDL_Rect player;
  public:
    Player();
    ~Player();
    void input(SDL_Event e);
    void update();
    void draw(SDL_Renderer *ren);
};
    
#endif
  