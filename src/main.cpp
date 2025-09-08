#include <iostream>
#include "Game.h"
#include "State.h"
#include "Music.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = Game::GetInstance("JOGO RÁPIDO", 800, 600);
    Music msc("Recursos/audio/BGM.wav");    game->GetState();

    
    msc.Play(-1);
    game->Run();
    
    return 0;
}