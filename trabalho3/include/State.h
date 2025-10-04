#ifndef STATE_H
#define STATE_H

#include <string>
#include <SDL2/SDL.h>
#include <vector>
#include <memory>

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"

using namespace std;

class State {
private:
    Music* music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

public:
    State();
    ~State();

    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void AddObject(GameObject* go);
};

#endif
