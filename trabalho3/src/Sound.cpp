#include "Sound.h"
#include <iostream>

using namespace std;

Sound::Sound() : chunk(nullptr), channel(-1) {}

Sound::Sound(string file) : Sound() {
    Open(file);
}

Sound::~Sound() {
    Stop();
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
}

void Sound::Play(int times) {
    if (chunk != nullptr) {
        // times = 1 toca uma vez, times = 0 toca infinitamente
        int loops = (times > 0) ? times - 1 : -1;
        channel = Mix_PlayChannel(-1, chunk, loops);
        if (channel == -1) {
            cerr << "Erro ao tocar som: " << Mix_GetError() << endl;
        }
    }
}

void Sound::Stop() {
    if (channel != -1) {
        Mix_HaltChannel(channel);
        channel = -1;
    }
}

void Sound::Open(string file) {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
    
    chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr) {
        cerr << "Erro ao carregar som: " << file << " - " << Mix_GetError() << endl;
    }
}

bool Sound::IsOpen() {
    return chunk != nullptr;
}