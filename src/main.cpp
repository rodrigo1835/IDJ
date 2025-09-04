#include <iostream>
#include "Game.h"
#include "State.h"

using namespace std;


int main() {

    Game* game = Game::GetInstance("GAME BOM DMS", 1280, 720);

    SDL_Renderer* renderer = game->GetRenderer();

    cout << renderer << endl;

    return 0;
}
