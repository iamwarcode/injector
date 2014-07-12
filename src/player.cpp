#include <player.h>
    
Player::Player(){
  player.x = 1;
  player.y = 1;
  player.w = 50;
  player.h = 50;  
  
  xVel = yVel = 0;
}
    
Player::~Player(){
    
}

void Player::input(SDL_Event e){
  switch(e.key.keysym.sym){
    case SDLK_UP:
      yVel = -1;
    break;
    case SDLK_DOWN:
      yVel =  1;
    break;
    case SDLK_LEFT:
      xVel = -1;
    break;
    case SDLK_RIGHT:
      xVel =  1;
    break;
  }
}

void Player::update(){
  if(player.x + player.w < 640 && player.x > 0){
      player.x += xVel;
  }else{
      player.x = 1;
  }
  if(player.y + player.h < 360 && player.y > 0){
    player.y += yVel;
  }else{
      player.y = 360-50-1;
  }
  //yVel += 1;
}

void Player::draw(SDL_Renderer *ren){
  SDL_SetRenderDrawColor(ren, 255,255,255,255);
  SDL_RenderDrawRect(ren, &player);
  //xVel = 0;
}