#include "State.h"
#include "Zombie.h"
#include "SpriteRenderer.h"
#include <SDL2/SDL.h>

State::State() {
    quitRequested = false;
    music = nullptr;
    LoadAssets();
}

State::~State() {
    objectArray.clear();
    if (music) {
        delete music;
        music = nullptr;
    }
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {

    GameObject* bg = new GameObject();
    SpriteRenderer* sprBg = new SpriteRenderer(*bg, "Recursos/img/Background.png", 1, 1);
    bg->AddComponent(sprBg);
    AddObject(bg);

    // Zombie
    GameObject* zgo = new GameObject();
    zgo->box.x = 600.0f;
    zgo->box.y = 450.0f;
    Zombie* zcomp = new Zombie(*zgo);
    zgo->AddComponent(zcomp); // adiciona o componente principal (Zombie)
    AddObject(zgo);
}


void State::Update(float dt) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }
    }

    // Atualiza todos os objetos
    for (size_t i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Update(dt);
    }

    // Remove objetos mortos
    for (size_t i = 0; i < objectArray.size(); i++) {
        if (objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
            i--;
        }
    }
}

void State::Render() {
    for (size_t i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Render();
    }
}

void State::AddObject(GameObject* go) {
    objectArray.emplace_back(go);
}
