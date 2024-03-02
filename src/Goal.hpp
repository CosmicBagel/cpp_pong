#pragma once

#include "IGameObject.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"

class Goal final : public IGameObject {
   private:
    TransformComponent transform;
    RectangleColliderComponent collider;
    bool IsPlayerGoal;

   public:
    Goal(TransformComponent transform, bool isPlayerGoal)
        : transform(transform),
          collider(transform, 20, 600, PhysicsObjectTag::Goal),
          IsPlayerGoal(isPlayerGoal){};

    void Init() override;
    void Draw() override;
    void Update() override;
};
