#include "TileMap.h"
#include "Game.h"
#include <fstream>
#include <iostream>
#include <sstream>  

using namespace std;

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) 
    : Component(associated) {
    this->tileSet.reset(tileSet);
    Load(file);
}

void TileMap::Load(string file) {
    ifstream mapFile(file);
    if (!mapFile.is_open()) {
        cerr << "Erro ao abrir o arquivo do mapa: " << file << endl;
        return;
    }

    string header;
    getline(mapFile, header);
    stringstream ss(header);
    char comma;
    ss >> mapWidth >> comma >> mapHeight >> comma >> mapDepth;

    tileMatrix.clear();

    string content, line;
    while (getline(mapFile, line)) {
        content += line;
    }

    stringstream ssContent(content);
    string token;
    while (getline(ssContent, token, ',')) {
        if (!token.empty()) {
            try {
                int tile = stoi(token);
                tileMatrix.push_back(tile); 
            } catch (const invalid_argument&) {
                continue;
            }
        }
    }

    // Garante que tileMatrix não tenha tiles extras
    int expectedSize = mapWidth * mapHeight * mapDepth;
    if ((int)tileMatrix.size() > expectedSize) {
        tileMatrix.resize(expectedSize);
    }

    cout << "Mapa carregado: " 
         << mapWidth << "x" << mapHeight << "x" << mapDepth 
         << " | Tiles carregados: " << tileMatrix.size() << endl;
}




void TileMap::SetTileSet(TileSet* tileSet) {
    this->tileSet.reset(tileSet);
}

int& TileMap::At(int x, int y, int z) {
    int index = x + (y * mapWidth) + (z * mapWidth * mapHeight);
    return tileMatrix[index];
}

void TileMap::Render() {
    for (int z = 0; z < mapDepth; z++) {
        RenderLayer(z);
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
    if (!tileSet) return;

    int tileWidth = tileSet->GetTileWidth();
    int tileHeight = tileSet->GetTileHeight();

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int tileIndex = At(x, y, layer);
            if (tileIndex > 0) { // 0 = vazio
                // RENDERIZAÇÃO BASEADA EM POSIÇÃO DO MAPA
                float renderX = (float)(x * tileWidth) - cameraX;
                float renderY = (float)(y * tileHeight) - cameraY;

                // Subtrai 1 do índice para corresponder ao TileSet (0-index)
                tileSet->RenderTile(tileIndex - 1, renderX, renderY);
            }
        }
    }
}

int TileMap::GetWidth() {
    return mapWidth;
}

int TileMap::GetHeight() {
    return mapHeight;
}

int TileMap::GetDepth() {
    return mapDepth;
}