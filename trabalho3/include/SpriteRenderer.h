#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Component.h"
#include "Sprite.h"
#include <string>

using namespace std;

class SpriteRenderer : public Component {
private:
    Sprite sprite;

public:
    SpriteRenderer(GameObject& associated);
    SpriteRenderer(GameObject& associated, const string& file, int frameCountW = 1, int frameCountH = 1);

    void Open(const string& file);
    void SetFrameCount(int frameCountW, int frameCountH);

    void Update(float dt) override;
    void Render() override;

    void SetFrame(int frame);
};

#endif // SPRITERENDERER_H
