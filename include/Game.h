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
        
        Game(const string& title, int width, int height);

        void initSDL(Uint32 flags);

    public:
        static Game * GetInstance(const string& title = "Game", int width = 800, int height = 600);
    
};

#endif