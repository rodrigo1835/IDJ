#include "Zombie.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "Animation.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

Zombie::Zombie(GameObject& associated) 
    : Component(associated), hitpoints(100), isDead(false) {
    
    // Inicializa o som de morte
    deathSound.Open("Recursos/audio/Dead.wav");

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
    if (isDead) return; // Se já está morto, não faz nada
    
    hitpoints -= damage;
    if (hitpoints <= 0 && !isDead) {
        isDead = true;
        
        // Toca o som de morte
        deathSound.Play(1);
        
        // Troca para animação "morto"
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        if (sr) sr->SetFrame(5);

        Animator* anim = associated.GetComponent<Animator>();
        if (anim) anim->SetAnimation("dead");
        
        
        cout << "Zombie morreu com som!" << endl;
    }
}
void Zombie::Update(float /*dt*/) {
    if (!isDead) 
        Damage(1);
    
}

void Zombie::Render() {
 // Em Breve
}
