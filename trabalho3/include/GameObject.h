#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include "Rect.h"

// Forward declarations em vez de includes(Tava dando erro na hora de compilar)
class Component;
class SpriteRenderer;
class Animator;

class GameObject {
public:
    GameObject();
    ~GameObject();
    
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    
    template<typename T>
    T* GetComponent() {
        for (auto component : components) {
            T* result = dynamic_cast<T*>(component);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }
    
    Rect box;
    
private:
    std::vector<Component*> components;
    bool isDead;
};

#endif