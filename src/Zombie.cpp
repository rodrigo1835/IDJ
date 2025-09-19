#include "Zombie.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "Animation.h"
#include "GameObject.h"
#include <iostream>

Zombie::Zombie(GameObject& associated) : Component(associated), hitpoints(100) {

    SpriteRenderer* sr = new SpriteRenderer(associated, "Recursos/img/Enemy.png", 3, 2);
    sr->SetFrame(1);
    associated.AddComponent(sr);

    Animator* animator = new Animator(associated);
    animator->AddAnimation("walking", Animation(0, 3, 10)); 
    animator->AddAnimation("dead",    Animation(5, 5, 0));  
    animator->SetAnimation("walking");
    associated.AddComponent(animator);
}

void Zombie::Damage(int damage) {
    hitpoints -= damage;
    if (hitpoints <= 0) {
        // troca para frame "morto" (frame 5)
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr) sr->SetFrame(5);

        Animator* anim = associated.GetComponent<Animator>();
        if (anim) anim->SetAnimation("dead");
    }
}

void Zombie::Update(float /*dt*/) {
    // por enquanto sofre 1 de dano por frame
    Damage(1);
}

void Zombie::Render() {
 // Em Breve
}
