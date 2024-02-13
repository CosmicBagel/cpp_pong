#pragma once

#include "IGameObject.hpp"
#include "PaddleGraphicComponent.hpp"
#include "RectangleColliderComponent.hpp"

class PlayerPaddle final : public IGameObject {
   private:
    unsigned int count = 0;
    PaddleGraphicComponent paddleGraphic;
    TransformComponent transform;
    RectangleColliderComponent collider;

   public:
    PlayerPaddle() : transform({735, 200}), collider(transform, 15, 110){};

    void Init() override;
    void Draw() override;
    void Update() override;
};
