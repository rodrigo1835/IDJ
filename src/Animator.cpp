#include "Animator.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

Animator::Animator(GameObject& associated)
    : Component(associated),
      frameStart(0),
      frameEnd(0),
      frameTime(0.0f),
      currentFrame(0),
      timeElapsed(0.0f) {
}

void Animator::Update(float dt) {
    if (frameTime <= 0) return; // sem animação
    timeElapsed += dt;

    bool frameChanged = false;
    while (timeElapsed >= frameTime) {
        timeElapsed -= frameTime;
        currentFrame++;
        if (currentFrame > frameEnd) currentFrame = frameStart;
        frameChanged = true;
    }

    if (frameChanged) {
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr) sr->SetFrame(currentFrame);
    }
}

void Animator::Render() {
    // nada a renderizar
}

void Animator::SetAnimation(const string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        frameStart = it->second.frameStart;
        frameEnd   = it->second.frameEnd;
        frameTime  = it->second.frameTime;
        currentFrame = frameStart;
        timeElapsed = 0.0f;

        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr) sr->SetFrame(currentFrame);
    }
}

void Animator::AddAnimation(const string& name, const Animation& anim) {
    if (animations.find(name) == animations.end()) {
        animations.emplace(name, anim);
    }
}
