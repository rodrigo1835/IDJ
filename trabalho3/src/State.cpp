#include "State.h"
#include "Zombie.h"
#include "SpriteRenderer.h"
#include "TileMap.h"
#include "TileSet.h"
#include "Sound.h"
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
    GameObject* mapObject = new GameObject();
    mapObject->box.x = 0.0f; 
    mapObject->box.y = 0.0f;

    TileSet* tileSet = new TileSet(64, 64, "Recursos/img/Tileset.png");
    TileMap* tileMap = new TileMap(*mapObject, "Recursos/map/map.txt", tileSet);
    mapObject->AddComponent(tileMap);
    AddObject(mapObject);

    // Apenas 2 zombies
    GameObject* zgo1 = new GameObject();
    zgo1->box.x = 100.0f;  // Posição mais visível
    zgo1->box.y = 100.0f;
    zgo1->AddComponent(new Zombie(*zgo1));
    AddObject(zgo1);

    GameObject* zgo2 = new GameObject();
    zgo2->box.x = 200.0f;
    zgo2->box.y = 150.0f;
    zgo2->AddComponent(new Zombie(*zgo2));
    AddObject(zgo2);
}

void State::Update(float dt) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }
    }

    for (size_t i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Update(dt);
    }

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