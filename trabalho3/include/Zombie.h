#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Component.h"
#include "Sound.h"

class Zombie : public Component {
private:
    int hitpoints;
    Sound deathSound;
    bool isDead;

public:
    Zombie(GameObject& associated);

    void Damage(int damage);
    void Update(float dt) override;
    void Render() override;
};

#endif