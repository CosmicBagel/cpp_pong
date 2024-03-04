#pragma once

#include "IGameObject.hpp"
#include "PhysicsObjectTag.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"

class Ball final : public IGameObject {
   private:
    RectangleColliderComponent collider;
    Color drawColor = RED;
    int velX = 2;
    int velY = 0;

    static const TransformComponent StartingPos;
    static const int StartingVelX = 2;
    static const int StartingVelY = 0;

    void ResetPos();

   public:
    // public so that we can pass it to computer paddle
    TransformComponent transform;

    Ball() : transform(StartingPos), collider(transform, 20, 20, PhysicsObjectTag::Ball){};

    void Init() override;
    void Draw() override;
    void Update() override;
};
