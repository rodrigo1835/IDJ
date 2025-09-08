#include <iostream>
#include "Game.h"
#include "State.h"
#include "Music.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = Game::GetInstance("JOGO RÁPIDO", 800, 600);

    State* state = new State();
    game->GetState();
    
    Music bgm("Recursos/audio/BGM.wav");
    bgm.Play(-1);

    game->Run();

    return 0;
}
