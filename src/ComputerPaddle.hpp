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

   public:
    ComputerPaddle()
        : transform({50, 200}), collider(transform, 15, 100, PhysicsObjectTag::Paddle){};
    void Init() override;
    void Draw() override;
    void Update() override;
};
