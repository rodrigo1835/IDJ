#include "Sprite.h"
#include "Game.h"
#include <string.h>
#include <iostream>
#include <SDL2/SDL_image.h>


Sprite::Sprite() {
    texture = nullptr;
    width = height = 0;
    frameCountW = 1;
    frameCountH = 1;
    currentFrame = 0;
}

Sprite::Sprite(string file) {
    texture = nullptr;
    width = height = 0;
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    currentFrame = 0;
    Open(file);
}

Sprite::Sprite(string file, int frameCountW, int frameCountH) {
    texture = nullptr;
    width = height = 0;
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    currentFrame = 0;
    Open(file);
}


Sprite::~Sprite(){
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
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
    SetClip(0, 0, GetWidth(), GetHeight());
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;

}

void Sprite::SetFrame(int frame) {
    currentFrame = frame;

    int frameW = width / frameCountW;
    int frameH = height / frameCountH;

    int row = frame / frameCountW;
    int col = frame % frameCountW;

    clipRect.x = col * frameW;
    clipRect.y = row * frameH;
    clipRect.w = frameW;
    clipRect.h = frameH;
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH) {
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    SetFrame(0);
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

void Sprite::Render(int x, int y, int w, int h) {
    SDL_Renderer* renderer = Game::GetInstance()->GetRenderer();
    SDL_Rect dstRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, &clipRect, &dstRect);
}

int Sprite::GetWidth() {
    return (frameCountW > 0) ? (width / frameCountW) : width;
}

int Sprite::GetHeight() {
    return (frameCountH > 0) ? (height / frameCountH) : height;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}