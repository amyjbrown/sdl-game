#pragma once
#include <SDL2/SDL.h>


namespace Common{
    class Game{
        public:
            Game(){};
            ~Game(){};

            /*** Startupt initialization
             * title (char*): Title of window
             * x (int): Starting x position of window, 0 for centered
             * y (int): Starting y position of window, 0 for centered
             * width (int): width of window
             * height (int): height of window
             * fullscreen (bool): `true` for Fullscreen, False for windowed
             */
            bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
            // Draw screen
            void draw();
            // Handle update tick()
            void update();
            // Handle event loop
            void handleEvents();
            // Perform cleanup for shutdown
            void cleanup();

            // getter for running
            bool inline running(){return running_;}
        private:
            bool running_;
            SDL_Window* window_;
            SDL_Renderer* renderer_;
    };
}