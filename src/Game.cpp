#include <iostream>

#include "Game.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

Game * Game::instance = nullptr;

Game::Game(const string& title, int width, int height) {
    this->title = title;
    this->width = width;
    this->height = height;

    initSDL(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
}

void Game::initSDL(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        cerr << "Erro ao inicializar a SDL: " << SDL_GetError() << endl;
        exit(1);
    }
}

Game* Game::GetInstance(const string& title, int width, int height) {
    if ( !instance )
        instance = new Game(title, width, height);

    return instance;
}