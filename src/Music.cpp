#include "Music.h"
#include <string>
#include <iostream>

using namespace std;
Music::Music() {
    music = nullptr;
}

Music::Music(string file) {
    Open(file);
}

void Music::Play(int times) {
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr) {
        cerr << "Erro ao abrir a música: " <<  Mix_GetError() << endl;
        exit(1);
    }

}

bool Music::IsOpen() {
    return music == nullptr;
}

Music::~Music() {
    Mix_FreeMusic(music);
}