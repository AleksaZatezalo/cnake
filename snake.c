#include "snake.h"

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

#define GRID_SIZE 20
#define GRID_DIM 800

int main(){

    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_INIT_VIDEO < 0){
        fprintf(stderr, "ERROR: SDL_INIT_VIDEO");
    }

    window = SDL_CreateWindow(
        "Snake",
        WINDOW_X,
        WINDOW_Y,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );

    if (!window){
        fprintf(stderr, "ERROR: !window");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer){
        fprintf(stderr, "ERROR: !window");
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;

    while(!quit){
        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYUP:
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}