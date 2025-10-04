#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Component.h"
#include "Animation.h"
#include <unordered_map>
#include <string>

using namespace std;

class Animator : public Component {
private:
    std::unordered_map<string, Animation> animations;
    int frameStart;
    int frameEnd;
    float frameTime;
    int currentFrame;
    float timeElapsed;

public:
    Animator(GameObject& associated);

    void Update(float dt) override;
    void Render() override;

    void SetAnimation(const string& name);
    void AddAnimation(const string& name, const Animation& anim);
};

#endif
