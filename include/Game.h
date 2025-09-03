#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

class Game {
    private:
        string title;
        int width,height;

        static Game * instance;
        ~Game();
        
        Game(const string& title, int width, int height);

        void initSDL(Uint32 flags);
        void initIMG(Uint32 flags);
        void initMIX(Uint32 Flags);

        SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags);
        SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags);
        
    public:
        static Game * GetInstance(const string& title = "Game", int width = 800, int height = 600);
    
};

#endif