#include "State.h"

State::State() {
    quitRequested = false;
    bg = new Sprite();
    LoadAssets();
}


void State::LoadAssets() {
    bg->Open("Recursos/img/Background.png");
    bg->SetClip(0, 0, bg->GetWidth(), bg->GetHeight());
}

void State::Update(float dt) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }
    }
}


void State::Render() {
    if(bg)
        bg->Render(0,0);
}

bool State::QuitRequested() {
    return quitRequested;
}
