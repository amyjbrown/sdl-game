#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#pragma once
namespace Video{
    class Renderer{
        public:
            SDL_Window*     window;
            SDL_Renderer*   renderer;
            SDL_Texture*    texture;
            Renderer();
            void draw();
    };
}