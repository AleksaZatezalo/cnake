#include "snake.h"

#define WINDOW_X 10
#define WINDOW_Y -20
#define WINDOW_WIDTH 1770
#define WINDOW_HEIGHT 1405

#define GRID_SIZE 20
#define GRID_DIM 800

void render_grid(SDL_Renderer *renderer, int x, int y)
{
    int cell_size = GRID_DIM / GRID_SIZE;
    SDL_Rect cell;
    cell.w = cell_size;
    cell.h = cell_size;

    for (int i = 0; i < GRID_SIZE; i++){
        for(int j; j < GRID_SIZE; j++){
            cell.x = x + i * cell_size;
            cell.y = y + j * cell_size;
        }
    }
    return; 
}

int main(){

    SDL_Window *window;
    SDL_Renderer *renderer;

    if(SDL_INIT_VIDEO < 0){
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
        fprintf(stderr, "ERROR: !renderer");
    }

    
    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            quit=true;
                            break;
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 255);
        SDL_RenderClear(renderer);
        render_grid(renderer, 1, 1);
        SDL_RenderPresent(renderer);

    }

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}