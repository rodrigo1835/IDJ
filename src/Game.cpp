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
    initWindow();
    initRenderer();

}

Game* Game::GetInstance(const string& title, int width, int height) {
    if ( !instance )
        instance = new Game(title, width, height);

    return instance;
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
        exit(1);
    }
}

void Game::initMIX(Uint32 flags) {
    int iniciado = Mix_Init(flags);

    if((iniciado & flags) != flags
        || Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)
    ){
        cerr << "Erro ao inicializar Audios: " << Mix_GetError() << endl;
        exit(1);
    }
}

void Game::initWindow() {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(!window){
        cerr << "Erro ao criar janela: " << SDL_GetError() << endl;
        exit(1);
    }
}

void Game::initRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer){
        cerr << "ERro ao criar render: " << SDL_GetError() << endl;
        exit(1);
    }
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}


Game::~Game() {
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    //ADSDAS

}

