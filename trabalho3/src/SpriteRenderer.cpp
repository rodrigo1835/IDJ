#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Game.h"
#include <iostream>

using namespace std;

SpriteRenderer::SpriteRenderer(GameObject& associated) : Component(associated), sprite() {
}

SpriteRenderer::SpriteRenderer(GameObject& associated, const string& file, int frameCountW, int frameCountH)
    : Component(associated), sprite(file, frameCountW, frameCountH) {
    associated.box.w = (float)sprite.GetWidth();
    associated.box.h = (float)sprite.GetHeight();
    SetFrame(0);
}

void SpriteRenderer::Open(const string& file) {
    sprite.Open(file);
    associated.box.w = (float)sprite.GetWidth();
    associated.box.h = (float)sprite.GetHeight();
}

void SpriteRenderer::SetFrameCount(int frameCountW, int frameCountH) {
    sprite.SetFrameCount(frameCountW, frameCountH);
    associated.box.w = (float)sprite.GetWidth();
    associated.box.h = (float)sprite.GetHeight();
}

void SpriteRenderer::Update(float /*dt*/) {
    //
}

void SpriteRenderer::Render() {
    sprite.Render((int)associated.box.x, (int)associated.box.y, (int)associated.box.w, (int)associated.box.h);
}

void SpriteRenderer::SetFrame(int frame) {
    sprite.SetFrame(frame);
}

