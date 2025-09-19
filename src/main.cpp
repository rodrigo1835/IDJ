#include <iostream>
#include "Game.h"
#include "State.h"
#include "Music.h"
#include "Vec2.h"

using namespace std;

int main(int argc, char** argv) {
    //Game* game = Game::GetInstance("JOGO RÁPIDO", 800, 600);
    //Music msc("Recursos/audio/BGM.wav");    game->GetState();

    
    //msc.Play(-1);
    //game->Run();

    // a

    Vec2 v1;
    Vec2 v2;

    v1.x = 10;
    v1.y = 20;

    cout << v1.magnitude() << endl;

    return 0;
}