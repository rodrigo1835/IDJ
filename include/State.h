#ifndef STATE_H
#define STATE_H

#include <string>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State{
    private:
        Sprite* bg;
        Music* music;
        bool quitRequested;


    public:

        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};

#endif