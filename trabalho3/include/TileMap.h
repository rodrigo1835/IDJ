#ifndef TILEMAP_H
#define TILEMAP_H

#include "Component.h"
#include "TileSet.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class TileMap : public Component {
private:
    vector<int> tileMatrix;
    unique_ptr<TileSet> tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

public:
    TileMap(GameObject& associated, string file, TileSet* tileSet);
    void Load(string file);
    void SetTileSet(TileSet* tileSet);
    int& At(int x, int y, int z = 0);
    void Render() override;
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
    void Update(float dt) override {}
    
    int GetWidth();
    int GetHeight();
    int GetDepth();
};

#endif