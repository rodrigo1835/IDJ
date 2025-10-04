#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>


using namespace std;

class Sprite {
    private:
        SDL_Texture* texture;
        int width,height;
        int frameCountW, frameCountH;
        int currentFrame;
        SDL_Rect clipRect;
        string currentFile;
        
    public:
        Sprite();
        Sprite(string file);
        Sprite(string file, int frameCountW, int frameCountH);
        ~Sprite();

        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void SetFrame(int frame);
        void SetFrameCount(int frameCountW, int frameCountH);
        void Render(int x, int y);
        void Render(int x, int y, int w, int h);

        int GetWidth();
        int GetHeight();
        bool IsOpen();

};

#endif