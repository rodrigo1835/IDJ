#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

class State;

class Game {
    private:
        string title;
        int width,height;

        static Game * instance;
 
        Game(const string& title, int width, int height);

        void initSDL(Uint32 flags);
        void initIMG(Uint32 flags);
        void initMIX(Uint32 Flags);
        void initWindow();
        void initRenderer();

        SDL_Window* window;
        SDL_Renderer* renderer;

        State* state;
        
        void run();

    public:
        static Game * GetInstance(const string& title = "Game", int width = 800, int height = 600);
        State* GetState();
        SDL_Renderer* GetRenderer();
        ~Game();
};

#endif