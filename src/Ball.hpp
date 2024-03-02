#pragma once

#include "IGameObject.hpp"
#include "PhysicsObjectTag.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"

class Ball final : public IGameObject {
   private:
    TransformComponent transform;
    RectangleColliderComponent collider;
    Color drawColor = RED;
    int velX = 2;
    int velY = 0;

    const TransformComponent StartingPos = {400, 300};
    const int StartingVelX = 2;
    const int StartingVelY = 0;

    void ResetPos();

   public:
    Ball() : transform(StartingPos), collider(transform, 20, 20, PhysicsObjectTag::Ball){};

    void Init() override;
    void Draw() override;
    void Update() override;
};
