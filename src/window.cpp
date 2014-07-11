#include <window.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 360

SDL_Texture* renderText(const std::string &text, const std::string &file, SDL_Color color, int fontsize, SDL_Renderer *ren){
  TTF_Font *font = TTF_OpenFont(file.c_str(), fontsize);
  SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surf);
  SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

Window::Window(){
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  window = SDL_CreateWindow("injector", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  
  ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  quit = false;

  SDL_Color color = { 255, 255, 255, 255 };
  image = renderText("INJECTOR", "oneway.ttf",
	color, 64, ren);
}

Window::~Window(){
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(window);
  
  SDL_Quit();
}

void Window::Event(){
  SDL_Event e;
  while(SDL_PollEvent(&e)){
    if(e.type==SDL_QUIT){
      quit = true;
    }
  }
}  


void Window::Render(){
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
  renderTexture(image, ren, 200, 140);
  SDL_RenderPresent(ren);
}