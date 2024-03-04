#pragma once

#include "IGameObject.hpp"
#include "PaddleGraphicComponent.hpp"
#include "RectangleColliderComponent.hpp"
#include "TransformComponent.hpp"

class ComputerPaddle final : public IGameObject {
   private:
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;
    RectangleColliderComponent collider;
    TransformComponent &ballTransform;

   public:
    ComputerPaddle(TransformComponent &ballTransform)
        : transform({50, 200}),
          collider(transform, 15, 110, PhysicsObjectTag::Paddle),
          ballTransform(ballTransform){};
    void Init() override;
    void Draw() override;
    void Update() override;
};
