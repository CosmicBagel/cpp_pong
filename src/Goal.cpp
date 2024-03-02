#include "Goal.hpp"

#include "Events.hpp"
#include "raylib.h"

void Goal::Init() {}

void Goal::Update() {
    PhysicsSystem& physicsSystem = PhysicsSystem::GetInstance();
    collider.ProcessIntersections([&](PoolObjectId otherId) {
        PhysicsObjectTag otherTag = physicsSystem.GetRectangle(otherId).GetTag();
        if (otherTag != PhysicsObjectTag::Ball) {
            return;
        }
        if (IsPlayerGoal) {
            EventManager::GetInstance().Invoke(EventName::PlayerScored);
        } else {
            EventManager::GetInstance().Invoke(EventName::ComputerScored);
        }
    });
}

void Goal::Draw() { DrawRectangle(transform.x, transform.y, 20, 600, GREEN); }
