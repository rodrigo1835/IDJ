#include "TileSet.h"
#include "Game.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) 
    : tileSet(file), tileWidth(tileWidth), tileHeight(tileHeight) {
    
    if (tileSet.IsOpen()) {
        int spriteWidth = tileSet.GetWidth() * (tileSet.GetWidth() / tileWidth); // Considerando frameCount
        int spriteHeight = tileSet.GetHeight() * (tileSet.GetHeight() / tileHeight);
        
        columns = spriteWidth / tileWidth;
        rows = spriteHeight / tileHeight;
        tileCount = columns * rows;
        
        tileSet.SetFrameCount(columns, rows);
    } else {
        tileCount = 0;
        rows = columns = 0;
    }
}

void TileSet::RenderTile(unsigned index, float x, float y) {
    if (index < (unsigned)tileCount) {
        tileSet.SetFrame(index);
        tileSet.Render(x, y, tileWidth, tileHeight);
    }
}

int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeight() {
    return tileHeight;
}

int TileSet::GetTileCount() {
    return tileCount;
}