#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"
#include <string>

using namespace std;

class TileSet {
private:
    Sprite tileSet;
    int tileWidth;
    int tileHeight;
    int rows;
    int columns;
    int tileCount;

public:
    TileSet(int tileWidth, int tileHeight, string file);
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
    int GetTileCount();
};

#endif