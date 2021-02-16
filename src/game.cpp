#include "game.hpp"
using namespace Common;

#include "game.hpp"

using namespace Common;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
        // SDL_Texture* texture;
    window_ = SDL_CreateWindow(
        title,
        (xpos == 0? SDL_WINDOWPOS_CENTERED : xpos), 
        (ypos == 0? SDL_WINDOWPOS_CENTERED : ypos),
        width, height,
        fullscreen? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    renderer_ = SDL_CreateRenderer(
        window_,
        -1,
        0
    );

    if (window_ == nullptr || renderer_ == nullptr){
        SDL_Log("Couldn't initialize window and renderer: %s\\n", SDL_GetError());
        return false;
    }

    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    // Sets the logical render size for future purposes
    // SDL_RenderSetLogicalSize(renderer_, 640, 480);
    // Sets default background color to bright red;
    // I find this clearer for debugging
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);

    running_ = true;
    return true;
}

void Game::draw(){
    SDL_RenderClear(renderer_);  // redraw window   
    SDL_RenderPresent(renderer_);

}

void Game::update(){
    return;
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                running_ = false;
                break;
            default:
                break;
        }
    }
}

void Game::cleanup(){
    // Cleanup resources
    SDL_DestroyWindow(window_);  
    SDL_DestroyRenderer(renderer_);
    SDL_Log("Cleaned up render and window\n");
}
