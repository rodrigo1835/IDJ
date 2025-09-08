#include "Sprite.h"
#include "Game.h"
#include <string.h>
#include <iostream>
#include <SDL2/SDL_image.h>


Sprite::Sprite() {
    this->texture = nullptr;
}

Sprite::Sprite(string file) {
    this->texture = nullptr;

    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
    if(this->texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    SDL_Renderer* renderer = Game::GetInstance()->GetRenderer(); 
    texture = IMG_LoadTexture(renderer, file.c_str());
    if(!texture){
        cerr << "Erro ao carregar textura: " << SDL_GetError() << endl;
        exit(1);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;

}

void Sprite::Render(int x, int y) {
    SDL_Renderer* renderer = Game::GetInstance()->GetRenderer();

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = clipRect.w;
    dstRect.h = clipRect.h;

    SDL_RenderCopy(renderer, texture, &clipRect, &dstRect);

}

int Sprite::GetHeight() {
    return height;
}

int Sprite::GetWidth() {
    return width;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}