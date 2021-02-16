#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>

#include "game.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char** argv){
    using namespace Common;
    /**
     * Initialization:
     *  Initialize Window
     *  If necessary, create Renderer and backing texture
     *  Else, have the appropriate setup
     * 
     * Game Loop:
     * while not done do
     *  handler()
     *  update(dt)
     *  render()
     *  capFrameRate()
     * end
     * 
     * Cleanup
    */
   /*   Initialization   */
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
        SDL_Log("Could not initialize SDL systems: %s\n", SDL_GetError());
        SDL_Log("Shutting down...\n");
        SDL_Quit();
        return 1;
    }


    auto game = Game();
    if (not game.init("Chapter 1", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, false)){
        SDL_Log("Shutting down...\n");
        SDL_Quit();
        return 1;
    }
    /// TODO: until I actually work backend rendering
    // texture = SDL_CreateTexture(
    //     renderer,
    //     SDL_PIXELFORMAT_ARGB8888,
    //     SDL_TEXTUREACCESS_STREAMING,
    //     640, 480
    // );

    // if (texture == nullptr){
    //     SDL_Log("Couldn't initialize texture: %s\n", SDL_GetError());
    //     exit(1);
    // }

    // auto pixelBuffer = new Uint32[480][640];

    while(game.running()){
        game.handleEvents();
        game.update();
        game.draw();
    }    
    

    /*  Cleanup   */
    // delete[] pixelBuffer;
    game.cleanup();
    SDL_Log("Shutting Down...\n");
    SDL_Quit();
    return 0;
}
