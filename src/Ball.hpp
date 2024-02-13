#pragma once

#include "IGameObject.hpp"
#include "PoolManager.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"

class Ball final : public IGameObject {
   private:
    TransformComponent transform;
    PoolObjectId rectanglePhysicsObjectId;
    RectangleColliderComponent collider;
    Color drawColor = RED;
    int velX = 1;
    int velY = 0;

   public:
    Ball() : transform({250, 250}), collider(transform, 20, 20){};

    void Init() override;
    void Draw() override;
    void Update() override;
};
