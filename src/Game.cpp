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
    initIMG(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    initMIX(MIX_INIT_MP3 | MIX_INIT_OGG);
}

Game* Game::GetInstance(const string& title, int width, int height) {
    if ( !instance )
        instance = new Game(title, width, height);

    return instance;
}

Game::~Game() {
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::initSDL(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        cerr << "Erro ao inicializar a SDL: " << SDL_GetError() << endl;
        exit(1);
    }
}

void Game::initIMG(Uint32 flags) {
    int iniciado = IMG_Init(flags);

    if((iniciado & flags) != flags) {
        cerr << "Erro ao inicializar imagens: " << IMG_GetError() << endl;
    }
}

void Game::initMIX(Uint32 flags) {
    int iniciado = Mix_Init(flags);

    if((iniciado & flags) != flags
        || Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)
    ){
        cerr << "Erro ao inicializar Audios: " << Mix_GetError() << endl;
    }
}

